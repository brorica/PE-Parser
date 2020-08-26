#pragma once
#include <Windows.h>
#include <stdio.h>
#include "File.h"

int NT_Header32(PIMAGE_NT_HEADERS32 NT_Header);
int NT_Header64(PIMAGE_NT_HEADERS64 NT_Header);
int Dos_Header(FILE *fp);
int Section_Header(PIMAGE_SECTION_HEADER PSECTION_HEADER, unsigned int SectionNumber);

int ExportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int ImportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int RelocationDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
