#pragma once
#include <Windows.h>
#include <stdio.h>
int Section_Header(FILE* fp, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int RVA, unsigned int SectionNumber);

/*
 * IAT Function
 * success return : file offset
 * error return : 0
 */
int getImportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int getExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);

int showImportDirectory(PIMAGE_IMPORT_DESCRIPTOR PImageDirectory, unsigned int FileOffset);
int showExportDirectory(PIMAGE_IMPORT_DESCRIPTOR PImageDirectory, unsigned int FileOffset);