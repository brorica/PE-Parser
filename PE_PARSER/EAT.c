#include "libs/Header.h"

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_VirtualSize PSECTION_HEADER[i].Misc.VirtualSize
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define EXPORT_RVA PDirectory->VirtualAddress

int showExportDirectoryInfo();

int ExportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
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

		// RVA�� ������ �Լ� ����
		if (EXPORT_RVA == 0)
		{
			printf("\nCan't Find EXPORT RVA's File Offest\n");
			return 0;
		}

		// �ش� IMPORT RVA�� ���� ������ �ִ��� Ȯ��
		else if (EXPORT_RVA > SECTION_VirtualAddress && EXPORT_RVA < SectionEND)
		{
			Offset = EXPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
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
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.Characteristics)),ExportDirectory.TimeDateStamp,"TimeDateStamp");
	printf("%08X\t%08.4X\t%-16s\n", (Offset += sizeof(ExportDirectory.TimeDateStamp)), ExportDirectory.MajorVersion,"MajorVersion");
	printf("%08X\t%08.4X\t%-16s\n", (Offset += sizeof(ExportDirectory.MajorVersion)), ExportDirectory.MinorVersion,"MinorVersion");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.MinorVersion)), ExportDirectory.Name,"Name");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.Name)), ExportDirectory.Base,"Base");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.Base)), ExportDirectory.NumberOfFunctions,"NumberOfFunctions");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.NumberOfFunctions)), ExportDirectory.NumberOfNames,"NumberOfNames");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.NumberOfNames)), ExportDirectory.AddressOfFunctions,"AddressOfFunctions");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.AddressOfFunctions)), ExportDirectory.AddressOfNames,"AddressOfNames");
	printf("%08X\t%08X\t%-16s\n", (Offset += sizeof(ExportDirectory.AddressOfNames)), ExportDirectory.AddressOfNameOrdinals,"AddressOfNameOrdinals");
	return 0;
}