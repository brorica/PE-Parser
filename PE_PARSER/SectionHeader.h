#pragma once
#include <Windows.h>
#include <stdio.h>
#include "File.h"

int NT_Header32(PIMAGE_NT_HEADERS32 NT_Header);
int NT_Header64(PIMAGE_NT_HEADERS64 NT_Header);
int Dos_Header(FILE *fp);
int Section_Header(PIMAGE_SECTION_HEADER PSECTION_HEADER, unsigned int SectionNumber);
/*
 * IAT Function
 * success return : file offset
 * error return : 0
 */
int ImportDirectory(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int ExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);