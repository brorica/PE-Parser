#include "SectionHeader.h"

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_SizeOfRawData PSECTION_HEADER[i].SizeOfRawData
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define IMPORT_RVA PDirectory->VirtualAddress
#define IMPORT_SIZE PDirectory->Size
int showImportDirectory(PIMAGE_IMPORT_DESCRIPTOR PImageDirectory, unsigned int FileOffset, unsigned int VA, unsigned int PointerToRawData);

int getImportOffset64(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
{
	IMAGE_IMPORT_DESCRIPTOR ImageDirectory;
	unsigned int SectionEND;
	unsigned int FileOffset;
	for (unsigned int i = 0; i < NumberOfSection; i++)
	{
		SectionEND = SECTION_SizeOfRawData + SECTION_PointerToRawData;
		int FunctionOffset = 0;
		if (PSECTION_HEADER[i].Misc.VirtualSize > SECTION_SizeOfRawData)
		{
			printf("%s VirtualSzie is bigger than SECTION_SizeOfRawData\n", PSECTION_HEADER[i].Name);
			continue;
		}

		// 해당 IMPORT RVA가 섹션 범위에 있는지 확인
		if (IMPORT_RVA > SECTION_PointerToRawData && IMPORT_RVA < SectionEND)
		{
			FileOffset = IMPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			fseek(fp, FileOffset, SEEK_SET);
			printf("\nVA : %08X\n", FileOffset);
			printf("PointerToRawData : %08X\n", SECTION_PointerToRawData);
			printf("VALUE - VA + PointerToRawData = RVA\n");
			printf("\n%8s\t%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "RVA", "DESCRIPTION");
			fread(&ImageDirectory, sizeof(IMAGE_IMPORT_DESCRIPTOR), 1, fp);
			FunctionOffset = showImportDirectory(&ImageDirectory, FileOffset, SECTION_VirtualAddress, SECTION_PointerToRawData);
			return FileOffset;
		}
		// RVA가 없거나, RVA가 section범위를 초과하면 함수 종료
		else if (IMPORT_RVA == 0 || IMPORT_RVA < SECTION_PointerToRawData)
		{
			printf("Can't Find IMPORT RVA's File Offest\n");
			return 0;
		}
		// 없으면 건너뜀
		else
		{
			continue;
		}
	}
	printf("Can't Find IMPORT RVA's File Offest\n");
	return 0;	
}

int showImportDirectory(PIMAGE_IMPORT_DESCRIPTOR PImageDirectory, unsigned int FileOffset, unsigned int VA, unsigned int PointerToRawData)
{
	ULONGLONG ImportFunctionOffset;
	unsigned int FunctionOffset = (PImageDirectory->FirstThunk - VA + PointerToRawData);
	unsigned int Tempfp;
	WORD HINT;
	char ImportFunctionName[64];

	printf("%08X\t%08X\t%08X\t%-16s\n", FileOffset, PImageDirectory->OriginalFirstThunk,
		(PImageDirectory->OriginalFirstThunk - VA + PointerToRawData),"OriginalFirstThunk(INT)");
	printf("%08X\t%08X\t%08X\t%-16s\n", FileOffset +=sizeof(PImageDirectory->OriginalFirstThunk), PImageDirectory->TimeDateStamp,0, "TimeDateStamp");
	printf("%08X\t%08X\t%08X\t%-16s\n", FileOffset += sizeof(PImageDirectory->TimeDateStamp), PImageDirectory->ForwarderChain,0, "ForwarderChain");
	printf("%08X\t%08X\t%08X\t%-16s\n", FileOffset += sizeof(PImageDirectory->ForwarderChain), PImageDirectory->Name,
		(PImageDirectory->Name - VA + PointerToRawData), "Name");
	printf("%08X\t%08X\t%08X\t%-16s\n\n", FileOffset += sizeof(PImageDirectory->Name), PImageDirectory->FirstThunk,
		FunctionOffset, "FirstThunk(IAT)");

	fseek(fp, FunctionOffset, SEEK_SET);
	fread(&ImportFunctionOffset, sizeof(ULONGLONG), 1, fp);
	printf("\n\n%8s\t%8s\t%-16s\n", "HINT", "OFFSET","NAME");
	// print functions from import library
	while (ImportFunctionOffset != 0)
	{
		// save origin fp
		Tempfp = ftell(fp);
		ImportFunctionOffset = ImportFunctionOffset - VA + PointerToRawData;
		// fp move to import function offset
		fseek(fp, (unsigned int)ImportFunctionOffset, SEEK_SET);
		fread(&HINT, sizeof(WORD), 1, fp);
		fread(ImportFunctionName, 64, 1, fp);
		printf("%08.4X\t%08X\t%-16s\n", HINT, (unsigned int)ImportFunctionOffset,  ImportFunctionName);
		// back origin fp
		fseek(fp, Tempfp, SEEK_SET);
		fread(&ImportFunctionOffset, sizeof(ULONGLONG), 1, fp);
	}

	return FunctionOffset;
}