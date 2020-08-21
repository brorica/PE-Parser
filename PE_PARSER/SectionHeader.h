#pragma once
#include <Windows.h>
#include <stdio.h>
#include "File.h"

int NT_Header32();
int NT_Header64();
int Dos_Header(FILE *fp);
int Section_Header64(PIMAGE_SECTION_HEADER PSECTION_HEADER);
/*
 * IAT Function
 * success return : file offset
 * error return : 0
 */
int getImportOffset64(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);
int getExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection);