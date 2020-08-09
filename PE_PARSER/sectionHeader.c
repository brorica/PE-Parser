#include <stdio.h>
#include <Windows.h>

extern DWORD OFFSET;

// RAW = RVA - VirtualAddress + PointerToRawData
// VirtualSize > SizeOfRawData ¸é ¼º¸³ X
int show_SECTION_HEADER(FILE* fp, PIMAGE_SECTION_HEADER PSECTION_HEADER, int SECTIONSize, DWORD NumberOfSections)
{
	printf("%d\n", sizeof((PSECTION_HEADER)->Name));
	for (DWORD i = 0; i < NumberOfSections; i++)
	{
		fread(PSECTION_HEADER + i, SECTIONSize, 1, fp);
		printf("\n%08X\t\t%-16s\n", OFFSET, (PSECTION_HEADER + i)->Name);
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->Name), (PSECTION_HEADER + i)->Misc.VirtualSize, "VirtualSize");
		//printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER+i)->Name), (PSECTION_HEADER+i)->Misc, "PSECTION_HEADER->Misc");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->Misc.VirtualSize), (PSECTION_HEADER + i)->VirtualAddress, "VirtualAddress(VA)");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->VirtualAddress), (PSECTION_HEADER + i)->SizeOfRawData, "SizeOfRawData");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->SizeOfRawData), (PSECTION_HEADER + i)->PointerToRawData, "PointerToRawData");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->PointerToRawData), (PSECTION_HEADER + i)->PointerToRelocations, "PointerToRelocations");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->PointerToRelocations), (PSECTION_HEADER + i)->PointerToLinenumbers, "PointerToLinenumbers");
		printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->PointerToLinenumbers), (PSECTION_HEADER + i)->NumberOfRelocations, "NumberOfRelocations");
		printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->NumberOfRelocations), (PSECTION_HEADER + i)->NumberOfLinenumbers, "NumberOfLinenumbers");
		printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER + i)->NumberOfLinenumbers), (PSECTION_HEADER + i)->Characteristics, "Characteristics");
		OFFSET += sizeof(PSECTION_HEADER->Characteristics);
	}
	return 0;
}