#pragma once
#include <windows.h>
#include <stdio.h>
#include "File.h"

int OPTIONAL_HEADER64(PIMAGE_OPTIONAL_HEADER64 POPTIONAL_HEADER);
int OPTIONAL_HEADER32(PIMAGE_OPTIONAL_HEADER32 POPTIONAL_HEADER);

typedef struct _FILE_HEADER_ELEMENT_OFFSET
{
    unsigned int Machine;
    unsigned int NumberOfSections;
    unsigned int TimeDateStamp;
    unsigned int PointerToSymbolTable;
    unsigned int NumberOfSymbols;
    unsigned int SizeOfOptionalHeader;
    unsigned int Characteristics;
}FILE_HEADER_ELEMENT_OFFSET, *PFILE_HEADER_ELEMENT_OFFSET;

typedef struct _OPTIONAL_HEADER32_ELEMENT_OFFSET
{
    unsigned int Magic;
    unsigned int MajorLinkerVersion;
    unsigned int MinorLinkerVersion;
    unsigned int SizeOfCode;
    unsigned int SizeOfInitializedData;
    unsigned int SizeOfUninitializedData;
    unsigned int AddressOfEntryPoint;
    unsigned int BaseOfCode;
    unsigned int BaseOfData;
    unsigned int ImageBase;
    unsigned int SectionAlignment;
    unsigned int FileAlignment;
    unsigned int MajorOperatingSystemVersion;
    unsigned int MinorOperatingSystemVersion;
    unsigned int MajorImageVersion;
    unsigned int MinorImageVersion;
    unsigned int MajorSubsystemVersion;
    unsigned int MinorSubsystemVersion;
    unsigned int Win32VersionValue;
    unsigned int SizeOfImage;
    unsigned int SizeOfHeaders;
    unsigned int CheckSum;
    unsigned int Subsystem;
    unsigned int DllCharacteristics;
    unsigned int SizeOfStackReserve;
    unsigned int SizeOfStackCommit;
    unsigned int SizeOfHeapReserve;
    unsigned int SizeOfHeapCommit;
    unsigned int LoaderFlags;
    unsigned int NumberOfRvaAndSizes;
    unsigned int DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES][2];
}OPTIONAL_HEADER32_ELEMENT_OFFSET, *POPTIONAL_HEADER32_ELEMENT_OFFSET;

typedef struct _OPTIONAL_HEADER64_ELEMENT_OFFSET
{
    unsigned int Magic;
    unsigned int MajorLinkerVersion;
    unsigned int MinorLinkerVersion;
    unsigned int SizeOfCode;
    unsigned int SizeOfInitializedData;
    unsigned int SizeOfUninitializedData;
    unsigned int AddressOfEntryPoint;
    unsigned int BaseOfCode;
    unsigned int ImageBase;     // LONGLONG
    unsigned int SectionAlignment;
    unsigned int FileAlignment;
    unsigned int MajorOperatingSystemVersion;
    unsigned int MinorOperatingSystemVersion;
    unsigned int MajorImageVersion;
    unsigned int MinorImageVersion;
    unsigned int MajorSubsystemVersion;
    unsigned int MinorSubsystemVersion;
    unsigned int Win32VersionValue;
    unsigned int SizeOfImage;
    unsigned int SizeOfHeaders;
    unsigned int CheckSum;
    unsigned int Subsystem;
    unsigned int DllCharacteristics;
    unsigned int SizeOfStackReserve;
    unsigned int SizeOfStackCommit;
    unsigned int SizeOfHeapReserve;
    unsigned int SizeOfHeapCommit;
    unsigned int LoaderFlags;
    unsigned int NumberOfRvaAndSizes;
    unsigned int DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES][2];  // none Copyright
}OPTIONAL_HEADER64_ELEMENT_OFFSET, * POPTIONAL_HEADER64_ELEMENT_OFFSET;

int setFileHeaderElementOffset(PFILE_HEADER_ELEMENT_OFFSET);
int setOptionalHeader32_ElementOffset(POPTIONAL_HEADER32_ELEMENT_OFFSET ElementOffset);
int setOptionalHeader64_ElementOffset(POPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset);