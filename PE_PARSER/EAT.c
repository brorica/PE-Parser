#include "libs/Header.h"

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_VirtualSize PSECTION_HEADER[i].Misc.VirtualSize
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define EXPORT_RVA PDirectory->VirtualAddress

int showExportDirectoryInfo();

int ExportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection, unsigned int FileAlignment)
{
	unsigned int SectionEND;
	unsigned int realPointerToRawData;
	for (unsigned int i = 0; i < NumberOfSection; i++)
	{
		SectionEND = SECTION_VirtualAddress + SECTION_VirtualSize;

		// RVA가 없으면 함수 종료
		if (EXPORT_RVA == 0)
		{
			printf("\nCan't Find EXPORT RVA's File Offest\n");
			return 0;
		}

		// 해당 RVA가 섹션 범위에 있는지 확인
		else if (EXPORT_RVA > SECTION_VirtualAddress && EXPORT_RVA < SectionEND)
		{
			realPointerToRawData = FileAlignment * (SECTION_PointerToRawData / FileAlignment);
			Offset = EXPORT_RVA - SECTION_VirtualAddress + realPointerToRawData;
			printf("\n\nExport Offest : %08X\n", Offset);
			fseek(fp, Offset, SEEK_SET);
			showExportDirectoryInfo();
			return Offset;
		}

	}
	printf("\nCan't Find EXPORT RVA's File Offest\n");
	return 0;
}


int showExportDirectoryInfo()
{
	IMAGE_EXPORT_DIRECTORY ExportDirectory;
	printf("%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "DESCRIPTION");
	fread(&ExportDirectory, sizeof(IMAGE_EXPORT_DIRECTORY), 1, fp);
	printf("%08X\t%08X\t%-16s\n",Offset, ExportDirectory.Characteristics,"Characteristics");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE),ExportDirectory.TimeDateStamp,"TimeDateStamp");
	printf("%08X\t%08.4X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.MajorVersion,"MajorVersion");
	printf("%08X\t%08.4X\t%-16s\n", (Offset += WORDSIZE), ExportDirectory.MinorVersion,"MinorVersion");
	printf("%08X\t%08X\t%-16s\n", (Offset += WORDSIZE), ExportDirectory.Name,"Name");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.Base,"Base");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.NumberOfFunctions,"NumberOfFunctions");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.NumberOfNames,"NumberOfNames");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.AddressOfFunctions,"AddressOfFunctions");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.AddressOfNames,"AddressOfNames");
	printf("%08X\t%08X\t%-16s\n", (Offset += DWORDSIZE), ExportDirectory.AddressOfNameOrdinals,"AddressOfNameOrdinals");
	return 0;
}