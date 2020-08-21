#include "SectionHeader.h"
#pragma warning(disable : 4996)

int main()
{
//	PIMAGE_NT_HEADERS32 PImage_Nt_Header32;
//	PIMAGE_NT_HEADERS64 PImage_Nt_Header32;
	if ((fp = fopen("notepad.exe", "rb")) == NULL)
	{
		fprintf(stderr, "File open error\n");
		return 1;
	}
	printf("%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "DESCRIPTION");
	// get NT header offset
	Offset = Dos_Header(fp);
	fseek(fp, Offset, SEEK_SET);
	Offset = NT_Header64();
	fclose(fp);
	return 0;
}

