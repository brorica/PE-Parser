#include <Windows.h>
#include <stdio.h>

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_SizeOfRawData PSECTION_HEADER[i].SizeOfRawData
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define EXPORT_RVA PEXPORT_Directory_Table->VirtualAddress
#define EXPORT_SIZE PEXPORT_Directory_Table->Size

extern DWORD OFFSET;

int getExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
{
	//IMAGE_EXPORT_DIRECTORY
	/*
	DWORD SectionEND;
	DWORD FileOffset;
	for (DWORD i = 0; i < NumberOfSection; i++)
	{
		SectionEND = SECTION_SizeOfRawData + SECTION_PointerToRawData;
		if (PSECTION_HEADER[i].Misc.VirtualSize > SECTION_SizeOfRawData)
		{
			printf("%s VirtualSzie is bigger than SECTION_SizeOfRawData\n", PSECTION_HEADER[i].Name);
			continue;
		}

		// 해당 IMPORT RVA가 섹션 범위에 있는지 확인
		if (EXPORT_RVA > SECTION_PointerToRawData && EXPORT_RVA < SectionEND)
		{
			FileOffset = EXPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			printf("FileOffset : %08X\n", FileOffset);
			return FileOffset;
		}
		else
		{
			continue;
		}
	}
	printf("Can't Find EXPORT RVA's File Offest\n");
	*/
	return 0;
}


int showEAT(PIMAGE_EXPORT_DIRECTORY PImportDirectoryTable)
{
	printf("%8X : Characteristics\n", PImportDirectoryTable->Characteristics);
	printf("%8X : TimeDateStamp\n", PImportDirectoryTable->TimeDateStamp);
	printf("%8.4X : MajorVersion\n", PImportDirectoryTable->MajorVersion);
	printf("%8.4X : MinorVersion\n", PImportDirectoryTable->MinorVersion);
	printf("%8X : Name\n", PImportDirectoryTable->Name);
	printf("%8X : Base\n", PImportDirectoryTable->Base);
	printf("%8X : NumberOfFunctions\n", PImportDirectoryTable->NumberOfFunctions);
	printf("%8X : NumberOfNames\n", PImportDirectoryTable->NumberOfNames);
	printf("%8X : AddressOfFunctions\n", PImportDirectoryTable->AddressOfFunctions);
	printf("%8X : AddressOfNames\n", PImportDirectoryTable->AddressOfNames);
	printf("%8X : AddressOfNameOrdinals\n", PImportDirectoryTable->AddressOfNameOrdinals);
	return 0;
}