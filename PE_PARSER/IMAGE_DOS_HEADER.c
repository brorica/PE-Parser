#include <stdio.h>
#include <Windows.h>

int Dos_Header(FILE* fp)
{
	IMAGE_DOS_HEADER Dos_Header;
	const int Dos_Header_Size = sizeof(IMAGE_DOS_HEADER);
	const int e_lfanew_RVA = Dos_Header_Size - sizeof(Dos_Header.e_lfanew);

	fread(&Dos_Header, Dos_Header_Size, 1, fp);
	printf("%08X\t%8.4X\t%-16s\n", e_lfanew_RVA, Dos_Header.e_lfanew, "e_lfanew");
	return Dos_Header.e_lfanew;
}