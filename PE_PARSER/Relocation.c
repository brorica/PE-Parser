#include "libs/Header.h"

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_VirtualSize PSECTION_HEADER[i].Misc.VirtualSize
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define RELOC_RVA PDirectory->VirtualAddress
int showRelocationDirectoryInfo(unsigned int VA_PointerToRawData);
int RelocationDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
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

		if (RELOC_RVA == 0)
		{
			printf("Can't Find IMPORT RVA's File Offest\n");
			return 0;
		}
		// 해당 IMPORT RVA가 섹션 범위에 있는지 확인
		else if (RELOC_RVA >= SECTION_VirtualAddress && RELOC_RVA <= SectionEND)
		{
			Offset = RELOC_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			fseek(fp, Offset, SEEK_SET);
			printf("\nImport Section : %s\n", PSECTION_HEADER[i].Name);
			printf("OFFSET : %08X\n", RELOC_RVA);
			printf("VA : %08X\n", SECTION_VirtualAddress);
			printf("PointerToRawData : %08X\n", SECTION_PointerToRawData);
			printf("OFFSET - VA + PointerToRawData = RVA\n");
			printf("RVA : %08X\n", Offset);
			showRelocationDirectoryInfo(SECTION_VirtualAddress - SECTION_PointerToRawData);
			return Offset;
		}
	}
	printf("Can't Find IMPORT RVA's File Offest\n");
	return 0;
}

int showRelocationDirectoryInfo(unsigned int VA_PointerToRawData)
{
	IMAGE_BASE_RELOCATION RelocDirectory;
	WORD item;
	unsigned int WORDSIZE = sizeof(WORD);
	unsigned int DWORDSIZE = sizeof(DWORD);
	unsigned int relocsize = sizeof(IMAGE_BASE_RELOCATION);
	unsigned char type[12][32] = { {"ABSOLUTE"},{"HIGH"},{"LOW"},
		{"HIGHLOW"},{"HIGHADJ"},{"MACHINE_SPECIFIC_5"},{"RESERVED"},
		{"MACHINE_SPECIFIC_7"},{"MACHINE_SPECIFIC_8"},{"MACHINE_SPECIFIC_9"},{"DIR64"} };
	
	while (1)
	{
		fread(&RelocDirectory, relocsize, 1, fp);
		if (RelocDirectory.VirtualAddress == 0)
			break;
		printf("\n\n%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "DESCRIPTION");
		printf("%08X\t%08X\t%-16s\n", Offset, RelocDirectory.VirtualAddress, "VirtualAddress");
		printf("%08X\t%08X\t%-16s\n\n", (Offset += sizeof(RelocDirectory.VirtualAddress)),
			RelocDirectory.SizeOfBlock, "SizeOfBlock");
		Offset += DWORDSIZE;
		printf("%8s\t%8s\t%-32s\n", "Offset","item","type");
		while (1)
		{
			fread(&item, WORDSIZE, 1, fp);
			if ((item >> 12) > 10)
			{
				fseek(fp, Offset, SEEK_SET);
				break;
			}
			printf("%08X\t%08.4X\t%-32s\n", Offset, item, type[item>>12]);
			Offset += WORDSIZE;
			if (item == 0 )
				break;			
		}		
	}
	return 0;
}