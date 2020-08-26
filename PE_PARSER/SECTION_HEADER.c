#include <stdlib.h>
#include "libs/Header.h"

// RAW = Offset - VirtualAddress + PointerToRawData
// VirtualSize > SizeOfRawData ¸é ¼º¸³ X

int Section_Header(PIMAGE_SECTION_HEADER PSECTION_HEADER, unsigned int SectionNumber)
{	
	unsigned int SectionSize = sizeof(IMAGE_SECTION_HEADER);
	for (unsigned int i = 0; i < SectionNumber; i++)
	{
		fread(PSECTION_HEADER + i, SectionSize, 1, fp);
		printf("\n%08X\t\t%-16s\n", Offset, (PSECTION_HEADER + i)->Name);
		printf("%08X\t%08X\t%-16s\n", (Offset += sizeof((PSECTION_HEADER + i)->Name)), (PSECTION_HEADER + i)->Misc.VirtualSize, "VirtualSize");
		//printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER+i)->Name), (PSECTION_HEADER+i)->Misc, "PSECTION_HEADER->Misc");
		printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->VirtualAddress, "VirtualAddress(VA)");
		printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->SizeOfRawData, "SizeOfRawData");
		printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->PointerToRawData, "PointerToRawData");
		printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->PointerToRelocations, "PointerToRelocations");
		printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->PointerToLinenumbers, "PointerToLinenumbers");
		printf("%08X\t%8.4X\t%-16s\n", (Offset += DWORDSIZE), (PSECTION_HEADER + i)->NumberOfRelocations, "NumberOfRelocations");
		printf("%08X\t%8.4X\t%-16s\n", (Offset += WORDSIZE), (PSECTION_HEADER + i)->NumberOfLinenumbers, "NumberOfLinenumbers");
		printf("%08X\t%08X\t%-16s\n", (Offset += WORDSIZE), (PSECTION_HEADER + i)->Characteristics, "Characteristics");
		Offset += DWORDSIZE;
	}
	return Offset;
}
