#include "SectionHeader.h"
#pragma warning(disable : 4996)

int main()
{
	unsigned int RVA = 0;
	fp = fopen("notepad.exe", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen failed\n");
		return -1;
	}
	printf("%8s\t%8s\t%-16s\n", "OFFSET", "VALUE", "DESCRIPTION");
	// get NT header offset
	RVA = Dos_Header(fp);
	fseek(fp, RVA, SEEK_SET);
	RVA = NT_Header(RVA);
	
	fclose(fp);
	return 0;
}

