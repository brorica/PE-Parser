#include <stdlib.h>
#include "SectionHeader.h"


// RAW = RVA - VirtualAddress + PointerToRawData
// VirtualSize > SizeOfRawData �� ���� X

int Section_Header(FILE* fp, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int RVA, unsigned int SectionNumber)
{
	unsigned int SectionSize = sizeof(IMAGE_SECTION_HEADER);
	unsigned int FileOffset = 0;
	PIMAGE_SECTION_HEADER PSECTION_HEADER;
	IMAGE_IMPORT_DESCRIPTOR ImageDirectory;
	PSECTION_HEADER = (PIMAGE_SECTION_HEADER)malloc(SectionSize * SectionNumber);
	for (unsigned int i = 0; i < SectionNumber; i++)
	{
		fread(PSECTION_HEADER + i, SectionSize, 1, fp);
		printf("\n%08X\t\t%-16s\n", RVA, (PSECTION_HEADER + i)->Name);
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->Name), (PSECTION_HEADER + i)->Misc.VirtualSize, "VirtualSize");
		//printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof((PSECTION_HEADER+i)->Name), (PSECTION_HEADER+i)->Misc, "PSECTION_HEADER->Misc");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->Misc.VirtualSize), (PSECTION_HEADER + i)->VirtualAddress, "VirtualAddress(VA)");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->VirtualAddress), (PSECTION_HEADER + i)->SizeOfRawData, "SizeOfRawData");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->SizeOfRawData), (PSECTION_HEADER + i)->PointerToRawData, "PointerToRawData");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->PointerToRawData), (PSECTION_HEADER + i)->PointerToRelocations, "PointerToRelocations");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->PointerToRelocations), (PSECTION_HEADER + i)->PointerToLinenumbers, "PointerToLinenumbers");
		printf("%08X\t%8.4X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->PointerToLinenumbers), (PSECTION_HEADER + i)->NumberOfRelocations, "NumberOfRelocations");
		printf("%08X\t%8.4X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->NumberOfRelocations), (PSECTION_HEADER + i)->NumberOfLinenumbers, "NumberOfLinenumbers");
		printf("%08X\t%08X\t%-16s\n", RVA += sizeof((PSECTION_HEADER + i)->NumberOfLinenumbers), (PSECTION_HEADER + i)->Characteristics, "Characteristics");
		RVA += sizeof(PSECTION_HEADER->Characteristics);
	}
	// FileOffset = getExportOffset(PSECTION_HEADER, &PDirectory[0], SectionNumber);
	FileOffset = getImportOffset(PSECTION_HEADER, &PDirectory[1], SectionNumber);
	fseek(fp, FileOffset, SEEK_SET);
	fread(&ImageDirectory, sizeof(IMAGE_IMPORT_DESCRIPTOR), 1, fp);
	showImportDirectory(&ImageDirectory, FileOffset);
	free(PSECTION_HEADER);
	return RVA;
}