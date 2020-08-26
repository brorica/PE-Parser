#include "libs/Header.h"

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_VirtualSize PSECTION_HEADER[i].Misc.VirtualSize
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define IMPORT_RVA PDirectory->VirtualAddress

// VA_PointerToRawData = SECTION_VirtualAddress - SECTION_PointerToRawData;
int showImportDirectoryInfo(unsigned int VA_PointerToRawData);
int showImportFunctions64(unsigned int FirstThunkOffset, unsigned int VA_PointerToRawData);
int showImportFunctions32(unsigned int FirstThunkOffset, unsigned int VA_PointerToRawData);

int ImportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
{
	unsigned int SectionEND;
	
	for (unsigned int i = 0; i < NumberOfSection; i++)
	{
		SectionEND = SECTION_VirtualAddress + SECTION_VirtualSize;
		if (PSECTION_HEADER[i].SizeOfRawData < SECTION_VirtualSize)
		{
			printf("%s VirtualSzie is bigger than SECTION_SizeOfRawData\n", PSECTION_HEADER[i].Name);
			continue;
		}

		if (IMPORT_RVA == 0)
		{
			printf("Can't Find IMPORT RVA's File Offest\n");
			return 0;
		}
		// 해당 IMPORT RVA가 섹션 범위에 있는지 확인
		else if (IMPORT_RVA > SECTION_VirtualAddress && IMPORT_RVA < SectionEND)
		{
			Offset = IMPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			fseek(fp, Offset, SEEK_SET);
			printf("\nImport Section : %s\n", PSECTION_HEADER[i].Name);
			printf("OFFSET : %08X\n", IMPORT_RVA);
			printf("VA : %08X\n", SECTION_VirtualAddress);
			printf("PointerToRawData : %08X\n", SECTION_PointerToRawData);
			printf("OFFSET - VA + PointerToRawData = RVA\n");
			printf("RVA : %08x\n", Offset);
			showImportDirectoryInfo(SECTION_VirtualAddress - SECTION_PointerToRawData);
			return Offset;
		}
	}
	printf("Can't Find IMPORT RVA's File Offest\n");
	return 0;	
}

int showImportDirectoryInfo(unsigned int VA_PointerToRawData)
{
	IMAGE_IMPORT_DESCRIPTOR ImageDirectory;
	// 모듈의 함수 리스트 위치
	unsigned int FirstThunkOffset;
	unsigned int ImportModuleNameOffset;
	// 스트림 위치 저장용
	unsigned int OriginFpPosition;
	char ImportModuleName[64];
	while(1)
	{
		fread(&ImageDirectory, sizeof(IMAGE_IMPORT_DESCRIPTOR), 1, fp);
		if (ImageDirectory.Name == 0)
			break;
		// Offset 계산
		ImportModuleNameOffset = (ImageDirectory.Name - VA_PointerToRawData);
		OriginFpPosition = ftell(fp);
		fseek(fp, ImportModuleNameOffset, SEEK_SET);
		fread(ImportModuleName, 64, 1, fp);
		printf("\n\nModule Name : %s\n", ImportModuleName);

		FirstThunkOffset = (ImageDirectory.FirstThunk - VA_PointerToRawData);

		printf("\n%8s\t%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "RVA", "DESCRIPTION");
		printf("%08X\t%08X\t%08X\t%-16s\n", Offset, ImageDirectory.OriginalFirstThunk,
			(ImageDirectory.OriginalFirstThunk - VA_PointerToRawData), "OriginalFirstThunk(INT)");
		printf("%08X\t%08X\t%08X\t%-16s\n", (Offset += sizeof(ImageDirectory.OriginalFirstThunk)), 
			ImageDirectory.TimeDateStamp, 0, "TimeDateStamp");
		printf("%08X\t%08X\t%08X\t%-16s\n", (Offset += sizeof(ImageDirectory.TimeDateStamp)), 
			ImageDirectory.ForwarderChain, 0, "ForwarderChain");
		printf("%08X\t%08X\t%08X\t%-16s(%s)\n", (Offset += sizeof(ImageDirectory.ForwarderChain)), ImageDirectory.Name,
			ImportModuleNameOffset, "Name", ImportModuleName);
		printf("%08X\t%08X\t%08X\t%-16s\n\n", (Offset += sizeof(ImageDirectory.Name)), ImageDirectory.FirstThunk,
			FirstThunkOffset, "FirstThunk(IAT)");
		Offset += sizeof(ImageDirectory.FirstThunk);
		// 64bit
		if (Machine == 0x8664)
			showImportFunctions64(FirstThunkOffset, VA_PointerToRawData);
		// 32bit
		else if (Machine == 0x014c)
			showImportFunctions32(FirstThunkOffset, VA_PointerToRawData);
		
		// fp 위치 복원
		fseek(fp, OriginFpPosition, SEEK_SET);
	}
	return 0;
}

int showImportFunctions64(unsigned int FirstThunkOffset, unsigned int VA_PointerToRawData)
{

	LONGLONG ImportFunctionOffset;
	unsigned int OriginFpPosition = FirstThunkOffset;
	// 이거 두 개 구조체로 묶든가 하기
	WORD HINT;
	unsigned char ImportFunctionName[64];
	printf("%8s\t%8s\t%-16s\n", "HINT", "OFFSET", "NAME");
	// print functions from import library
	while(1) 
	{
		fseek(fp, OriginFpPosition, SEEK_SET);
		fread(&ImportFunctionOffset, sizeof(ULONGLONG), 1, fp);
		OriginFpPosition = ftell(fp);
		if (ImportFunctionOffset == 0)
			break;
		else if (ImportFunctionOffset < 0)
		{
			printf("%8s\t%8s\tOrdinal : %04X\n", "NULL","NULL", (int)ImportFunctionOffset & 0xFFFF);
			fseek(fp, OriginFpPosition, SEEK_SET);
			continue;
		}
		// save origin fp
		ImportFunctionOffset = ImportFunctionOffset - VA_PointerToRawData;
		// fp move to import function offset
		fseek(fp, (unsigned int)ImportFunctionOffset, SEEK_SET);
		fread(&HINT, sizeof(WORD), 1, fp);
		fread(ImportFunctionName, 64, 1, fp);
		printf("%08.4X\t%08X\t%-16s\n", HINT, (unsigned int)ImportFunctionOffset, ImportFunctionName);
	}
	return 0;
}

int showImportFunctions32(unsigned int FirstThunkOffset, unsigned int VA_PointerToRawData)
{

	unsigned int ImportFunctionOffset;
	unsigned int OriginFpPosition = FirstThunkOffset;
	// 이거 두 개 구조체로 묶든가 하기
	WORD HINT;
	unsigned char ImportFunctionName[64];
	printf("%8s\t%8s\t%-16s\n", "HINT", "OFFSET", "NAME");
	// print functions from import library
	while (1)
	{
		fseek(fp, OriginFpPosition, SEEK_SET);
		fread(&ImportFunctionOffset, sizeof(int), 1, fp);
		OriginFpPosition = ftell(fp);
		if (ImportFunctionOffset == 0)
			break;
		else if (ImportFunctionOffset < 0)
		{
			printf("%8s\t%8s\tOrdinal : %04X\n", "NULL", "NULL", ImportFunctionOffset & 0xFFFF);
			fseek(fp, OriginFpPosition, SEEK_SET);
			continue;
		}
		// save origin fp
		ImportFunctionOffset = ImportFunctionOffset - VA_PointerToRawData;
		// fp move to import function offset
		fseek(fp, (unsigned int)ImportFunctionOffset, SEEK_SET);
		fread(&HINT, sizeof(WORD), 1, fp);
		fread(ImportFunctionName, 64, 1, fp);
		printf("%08.4X\t%08X\t%-16s\n", HINT, (unsigned int)ImportFunctionOffset, ImportFunctionName);
	}
	return 0;
}