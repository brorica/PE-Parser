#include <Windows.h>
#include <stdio.h>

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_SizeOfRawData PSECTION_HEADER[i].SizeOfRawData
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define IMPORT_RVA PDirectory->VirtualAddress
#define IMPORT_SIZE PDirectory->Size

int getImportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
{
	unsigned int SectionEND;
	unsigned int FileOffset;
	for (unsigned int i = 0; i < NumberOfSection; i++)
	{
		SectionEND = SECTION_SizeOfRawData + SECTION_PointerToRawData;
		if (PSECTION_HEADER[i].Misc.VirtualSize > SECTION_SizeOfRawData)
		{
			printf("%s VirtualSzie is bigger than SECTION_SizeOfRawData\n", PSECTION_HEADER[i].Name);
			continue;
		}

		// �ش� IMPORT RVA�� ���� ������ �ִ��� Ȯ��
		if (IMPORT_RVA > SECTION_PointerToRawData && IMPORT_RVA < SectionEND)
		{
			FileOffset = IMPORT_RVA - SECTION_VirtualAddress + SECTION_PointerToRawData;
			printf("\n\nFileOffset : %08X\n", FileOffset);
			return FileOffset;
		}
		// RVA�� ���ų�, RVA�� section������ �ʰ��ϸ� �Լ� ����
		else if (IMPORT_RVA == 0 || IMPORT_RVA < SECTION_PointerToRawData)
		{
			printf("Can't Find IMPORT RVA's File Offest\n");
			return 0;
		}
		// ������ �ǳʶ�
		else
		{
			continue;
		}
	}
	printf("Can't Find IMPORT RVA's File Offest\n");
	return 0;
}

int showImportDirectory(PIMAGE_IMPORT_DESCRIPTOR PImageDirectory, unsigned int FileOffset)
{
	printf("%08X\t%08X\t%-16s\n", FileOffset, PImageDirectory->OriginalFirstThunk,"OriginalFirstThunk");
	printf("%08X\t%08X\t%-16s\n", FileOffset +=sizeof(PImageDirectory->OriginalFirstThunk), PImageDirectory->TimeDateStamp, "TimeDateStamp");
	printf("%08X\t%08X\t%-16s\n", FileOffset += sizeof(PImageDirectory->TimeDateStamp), PImageDirectory->ForwarderChain, "ForwarderChain");
	printf("%08X\t%08X\t%-16s\n", FileOffset += sizeof(PImageDirectory->ForwarderChain), PImageDirectory->Name, "Name");
	printf("%08X\t%08X\t%-16s\n\n", FileOffset += sizeof(PImageDirectory->Name), PImageDirectory->FirstThunk, "FirstThunk");
}