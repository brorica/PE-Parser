#include <stdlib.h>
#include "SectionHeader.h"
#define SectionSize sizeof(IMAGE_SECTION_HEADER)

// RAW = Offset - VirtualAddress + PointerToRawData
// VirtualSize > SizeOfRawData �� ���� X

int Section_Header64(PIMAGE_SECTION_HEADER PSECTION_HEADER)
{
	for (unsigned int i = 0; i < (IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1); i++)
	{
		fread(PSECTION_HEADER + i, SectionSize, 1, fp);
		printf("\n%08X\t\t%-16s\n", Offset, (PSECTION_HEADER + i)->Name);
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->Name), (PSECTION_HEADER + i)->Misc.VirtualSize, "VirtualSize");
		//printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER+i)->Name), (PSECTION_HEADER+i)->Misc, "PSECTION_HEADER->Misc");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->Misc.VirtualSize), (PSECTION_HEADER + i)->VirtualAddress, "VirtualAddress(VA)");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->VirtualAddress), (PSECTION_HEADER + i)->SizeOfRawData, "SizeOfRawData");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->SizeOfRawData), (PSECTION_HEADER + i)->PointerToRawData, "PointerToRawData");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->PointerToRawData), (PSECTION_HEADER + i)->PointerToRelocations, "PointerToRelocations");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->PointerToRelocations), (PSECTION_HEADER + i)->PointerToLinenumbers, "PointerToLinenumbers");
		printf("%08X\t%8.4X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->PointerToLinenumbers), (PSECTION_HEADER + i)->NumberOfRelocations, "NumberOfRelocations");
		printf("%08X\t%8.4X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->NumberOfRelocations), (PSECTION_HEADER + i)->NumberOfLinenumbers, "NumberOfLinenumbers");
		printf("%08X\t%08X\t%-16s\n", Offset += sizeof((PSECTION_HEADER + i)->NumberOfLinenumbers), (PSECTION_HEADER + i)->Characteristics, "Characteristics");
		Offset += sizeof(PSECTION_HEADER->Characteristics);
	}
	// FileOffset = getExportOffset(PSECTION_HEADER, &PDirectory[0], SectionNumber);
	return Offset;
}
