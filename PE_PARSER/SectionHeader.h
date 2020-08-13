#pragma once
#include <Windows.h>
#include <stdio.h>

FILE* fp;

int NT_Header(unsigned int RVA);
int Dos_Header(FILE *fp);
int Section_Header(PIMAGE_DATA_DIRECTORY PDirectory, unsigned int RVA, unsigned int SectionNumber);
/*
 * IAT Function
 * success return : file offset
 * error return : 0
 */
int getImportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int getExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);