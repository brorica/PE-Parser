#include <Windows.h>
#include <stdio.h>

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_SizeOfRawData PSECTION_HEADER[i].SizeOfRawData
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define IMPORT_RVA PIMPORT_Directory_Table->VirtualAddress
#define IMPORT_SIZE PIMPORT_Directory_Table->Size

extern DWORD OFFSET;

int check_IAT(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PIMPORT_Directory_Table, DWORD NumberOfSection)
{
	DWORD SectionEND;
	DWORD FileOffset;
	for (DWORD i = 0; i < NumberOfSection; i++)
	{
		/*
		Debug Code!
		printf("%08x : VirtualSize\n", PSECTION_HEADER[i].Misc.VirtualSize);
		printf("%08x : VirtualAddress(VA)\n", SECTION_VirtualAddress);
		printf("%08x : SizeOfRawData\n", SECTION_SizeOfRawData);
		printf("%08x : PointerToRawData\n", SECTION_PointerToRawData);
		*/
		SectionEND = SECTION_SizeOfRawData + SECTION_PointerToRawData;
		if (PSECTION_HEADER[i].Misc.VirtualSize > SECTION_SizeOfRawData)
		{
			printf("%s VirtualSzie is bigger than SECTION_SizeOfRawData\n", PSECTION_HEADER[i].Name);
			continue;
		}

		// 해당 IMPORT RVA가 섹션 범위에 있는지 확인
		if (IMPORT_RVA > SECTION_PointerToRawData && IMPORT_RVA < SectionEND)
		{
			FileOffset = IMPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			printf("FileOffset : %08X\n", FileOffset);
			return FileOffset;
		}
		else
		{
			continue;
		}
	}
	printf("Can't Find IMPORT RVA's File Offest\n");
	return 0;
}

int showIAT(PIMAGE_IMPORT_DESCRIPTOR PImportDirectoryTable)
{
	printf("%8X : OriginalFirstThunk(INT)\n", PImportDirectoryTable->OriginalFirstThunk);
	printf("%8X : TimeDateStamp\n", PImportDirectoryTable->TimeDateStamp);
	printf("%8X : ForwarderChain\n", PImportDirectoryTable->ForwarderChain);
	printf("%8X : Name\n", PImportDirectoryTable->Name);
	printf("%8X : FirstThunk(IAT)\n", PImportDirectoryTable->FirstThunk);
	return 0;
}