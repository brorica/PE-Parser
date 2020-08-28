#include "libs/NT_HEADER_OFFSET.h"

int setFileHeaderElementOffset(PFILE_HEADER_ELEMENT_OFFSET ElementOffset)
{
	ElementOffset->Machine = Offset;
	ElementOffset->NumberOfSections = (Offset += WORDSIZE);
	ElementOffset->TimeDateStamp = (Offset += WORDSIZE);
	ElementOffset->PointerToSymbolTable = (Offset += DWORDSIZE);
	ElementOffset->NumberOfSymbols = (Offset += DWORDSIZE);
	ElementOffset->SizeOfOptionalHeader = (Offset += DWORDSIZE);
	ElementOffset->Characteristics = (Offset += WORDSIZE);
	Offset += WORDSIZE;
	return Offset;
}

int setOptionalHeader32_ElementOffset(POPTIONAL_HEADER32_ELEMENT_OFFSET ElementOffset)
{
	unsigned int OptionalHeaderOffset = Offset;
	unsigned int BYTESIZE = sizeof(BYTE);
	ElementOffset->Magic = OptionalHeaderOffset;
	ElementOffset->MajorLinkerVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorLinkerVersion = (OptionalHeaderOffset += BYTESIZE);
	ElementOffset->SizeOfCode = (OptionalHeaderOffset += BYTESIZE);
	ElementOffset->SizeOfInitializedData = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfUninitializedData = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->AddressOfEntryPoint = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->BaseOfCode = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->BaseOfData = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->ImageBase = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SectionAlignment = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->FileAlignment = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->MajorOperatingSystemVersion = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->MinorOperatingSystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MajorImageVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorImageVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MajorSubsystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorSubsystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->Win32VersionValue = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfImage = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfHeaders = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->CheckSum = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->Subsystem = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->DllCharacteristics = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfStackReserve = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfStackCommit = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfHeapReserve = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfHeapCommit = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->LoaderFlags = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->NumberOfRvaAndSizes = (OptionalHeaderOffset += DWORDSIZE);
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		ElementOffset->DataDirectory[i][0] = (OptionalHeaderOffset += DWORDSIZE);
		ElementOffset->DataDirectory[i][1] = (OptionalHeaderOffset += DWORDSIZE);
	}
	return 0;
}

int setOptionalHeader64_ElementOffset(POPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset)
{
	unsigned int OptionalHeaderOffset = Offset;
	unsigned int BYTESIZE = sizeof(BYTE);
	unsigned int ULONGLONGSIZE = sizeof(ULONGLONG);
	
	ElementOffset->Magic = OptionalHeaderOffset;
	ElementOffset->MajorLinkerVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorLinkerVersion = (OptionalHeaderOffset += BYTESIZE);
	ElementOffset->SizeOfCode = (OptionalHeaderOffset += BYTESIZE);
	ElementOffset->SizeOfInitializedData = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfUninitializedData = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->AddressOfEntryPoint = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->BaseOfCode = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->ImageBase = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SectionAlignment = (OptionalHeaderOffset += ULONGLONGSIZE);
	ElementOffset->FileAlignment = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->MajorOperatingSystemVersion = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->MinorOperatingSystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MajorImageVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorImageVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MajorSubsystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->MinorSubsystemVersion = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->Win32VersionValue = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfImage = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->SizeOfHeaders = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->CheckSum = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->Subsystem = (OptionalHeaderOffset += DWORDSIZE);
	ElementOffset->DllCharacteristics = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfStackReserve = (OptionalHeaderOffset += WORDSIZE);
	ElementOffset->SizeOfStackCommit = (OptionalHeaderOffset += ULONGLONGSIZE);
	ElementOffset->SizeOfHeapReserve = (OptionalHeaderOffset += ULONGLONGSIZE);
	ElementOffset->SizeOfHeapCommit = (OptionalHeaderOffset += ULONGLONGSIZE);
	ElementOffset->LoaderFlags = (OptionalHeaderOffset += ULONGLONGSIZE);
	ElementOffset->NumberOfRvaAndSizes = (OptionalHeaderOffset += DWORDSIZE);
	for (int i = 0; i < (IMAGE_NUMBEROF_DIRECTORY_ENTRIES); i ++)
	{
		ElementOffset->DataDirectory[i][0] = (OptionalHeaderOffset += DWORDSIZE);
		ElementOffset->DataDirectory[i][1] = (OptionalHeaderOffset += DWORDSIZE);
	}
	return 0;
}