#include <Windows.h>
#include <stdio.h>
int show_NT_HEADER(PIMAGE_NT_HEADERS NT_Header);
int show_SECTION_HEADER(FILE* fp, PIMAGE_SECTION_HEADER PSECTION_HEADER, int SECTIONSize, DWORD NumberOfSections);

int check_IAT(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PIMPORT_Directory_Table, DWORD NumberOfSection);
int showIAT(PIMAGE_IMPORT_DESCRIPTOR PImportDirectoryTable);