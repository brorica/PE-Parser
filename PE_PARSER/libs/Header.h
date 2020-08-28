#pragma once
#include <Windows.h>
#include <stdio.h>
#include "File.h"

int NT_Header32(PIMAGE_NT_HEADERS32 NT_Header);
int NT_Header64(PIMAGE_NT_HEADERS64 NT_Header);
int Dos_Header(FILE *fp);
int Section_Header(PIMAGE_SECTION_HEADER PSECTION_HEADER, unsigned int SectionNumber, unsigned int FileAlignment);

int ExportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection, unsigned int FileAlignment);
int ImportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection, unsigned int FileAlignment);
int RelocationDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
