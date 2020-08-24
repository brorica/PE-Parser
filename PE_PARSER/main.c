#include "libs/Header.h"
#pragma warning(disable : 4996)

#define SectionSize sizeof(IMAGE_SECTION_HEADER)
#define PExoortDirecotry64 &Image_Nt_Header64.OptionalHeader.DataDirectory[0]
#define PExoortDirecotry32 &Image_Nt_Header32.OptionalHeader.DataDirectory[0]
#define PImportDirectory64 &Image_Nt_Header64.OptionalHeader.DataDirectory[1]
#define PImportDirectory32 &Image_Nt_Header32.OptionalHeader.DataDirectory[1]


int Machine64();
int Machine32();


int main()
{

	if ((fp = fopen("notepad.exe","rb")) == NULL)
	{
		fprintf(stderr, "File open error\n");
		return 1;
	}
	printf("%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "DESCRIPTION");

	Offset = Dos_Header(fp);
	fseek(fp, Offset + sizeof(DWORD), SEEK_SET);
	fread(&Machine, sizeof(WORD), 1, fp);
	fseek(fp, Offset, SEEK_SET);
	// 64bit
	if (Machine == 0x8664)
		Machine64();
	// 32bit
	else if (Machine == 0x014c)
		Machine32();
	fclose(fp);
	return 0;
}

int Machine64()
{
	PIMAGE_SECTION_HEADER PSECTION_HEADER;
	IMAGE_NT_HEADERS64 Image_Nt_Header64;
	unsigned int SectionNumber = 0;
	SectionNumber = NT_Header64(&Image_Nt_Header64);

	PSECTION_HEADER = (PIMAGE_SECTION_HEADER)malloc(SectionSize * SectionNumber);
	Section_Header(PSECTION_HEADER, SectionNumber);
	ExportDirectory(PSECTION_HEADER, PExoortDirecotry64, SectionNumber);
	ImportDirectory(PSECTION_HEADER, PImportDirectory64, SectionNumber);
	free(PSECTION_HEADER);
	return 0;
}

int Machine32()
{
	PIMAGE_SECTION_HEADER PSECTION_HEADER;
	IMAGE_NT_HEADERS32 Image_Nt_Header32;
	unsigned int SectionNumber = 0;
	SectionNumber = NT_Header32(&Image_Nt_Header32);

	PSECTION_HEADER = (PIMAGE_SECTION_HEADER)malloc(SectionSize * SectionNumber);
	Section_Header(PSECTION_HEADER, SectionNumber);
	ExportDirectory(PSECTION_HEADER, PExoortDirecotry32, SectionNumber);
	ImportDirectory(PSECTION_HEADER, PImportDirectory32, SectionNumber);
	free(PSECTION_HEADER);
	return 0;
}