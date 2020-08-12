#include "ImageHeader.h"
#pragma warning(disable : 4996)

DWORD OFFSET = 0;
int main()
{
	unsigned int RVA = 0;
	FILE* fp = fopen("notepad.exe", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen failed\n");
		return -1;
	}

	// get NT header offset
	RVA = Dos_Header(fp);
	fseek(fp, RVA, SEEK_SET);
	RVA = NT_Header(fp, RVA);
	
	fclose(fp);
	return 0;
}

