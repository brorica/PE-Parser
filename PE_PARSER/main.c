#include "showHeader.h"
#pragma warning(disable : 4996)

DWORD OFFSET = 0;
int main()
{
	IMAGE_DOS_HEADER DOS_HEADER;
	// NT
	IMAGE_NT_HEADERS NT_HEADER;
	unsigned int NTSize = sizeof(IMAGE_NT_HEADERS);
	// SECTION_HEADER
	PIMAGE_SECTION_HEADER PSECTION_HEADER;
	unsigned int SECTIONSize = sizeof(IMAGE_SECTION_HEADER);
	DWORD NumberOfSection;
	// IAT
	DWORD IAT_FILE_OFFSET;
	IMAGE_IMPORT_DESCRIPTOR ImportDirectoryTable;

	FILE* fp = fopen("target.exe", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen failed\n");
		return -1;
	}

	/*
	printf("%d\n", sizeof(IMAGE_NT_HEADERS64)); // 264
	printf("%d\n", sizeof(IMAGE_NT_HEADERS32)); // 248
	*/

	printf("%8s\t%8s%16s\n", "Offset", "value", "Mean");
	// e_flanew offset
	fread(&DOS_HEADER, sizeof(IMAGE_DOS_HEADER), 1, fp);
	OFFSET = sizeof(IMAGE_DOS_HEADER) - sizeof(DOS_HEADER.e_lfanew);
	printf("%08X\t%08X\t%-16s\n", OFFSET, DOS_HEADER.e_lfanew, "e_lfanew");

	// get NT header offset
	fseek(fp, DOS_HEADER.e_lfanew, SEEK_SET);
	fread(&NT_HEADER, NTSize, 1, fp);
	NumberOfSection = NT_HEADER.FileHeader.NumberOfSections;
	OFFSET = DOS_HEADER.e_lfanew;
	show_NT_HEADER(&NT_HEADER);

	// SECTION header
	PSECTION_HEADER = (PIMAGE_SECTION_HEADER)malloc(SECTIONSize * NumberOfSection);
	// @params : file pointer, Header, HeaderSize, SectionCount
	show_SECTION_HEADER(fp, PSECTION_HEADER, SECTIONSize, NumberOfSection);

	/*
	 * get IAT(Import Address Table)
	 * 0 means not found IAT file offset
	 * @params : Header Pointer, IAT Direcotry, SectionCount
	*/
	IAT_FILE_OFFSET = check_IAT(PSECTION_HEADER, &NT_HEADER.OptionalHeader.DataDirectory[1], NumberOfSection);
	if (IAT_FILE_OFFSET != 0)
	{
		fseek(fp, IAT_FILE_OFFSET, SEEK_CUR);
		fread(&ImportDirectoryTable, sizeof(ImportDirectoryTable), 1, fp);
	}
	free(PSECTION_HEADER);
	fclose(fp);
	return 0;
}

