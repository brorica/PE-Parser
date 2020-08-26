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
	unsigned int BYTESIZE = sizeof(BYTE);
	ElementOffset->Magic = Offset;
	ElementOffset->MajorLinkerVersion = (Offset += WORDSIZE);
	ElementOffset->MinorLinkerVersion = (Offset += BYTESIZE);
	ElementOffset->SizeOfCode = (Offset += BYTESIZE);
	ElementOffset->SizeOfInitializedData = (Offset += DWORDSIZE);
	ElementOffset->SizeOfUninitializedData = (Offset += DWORDSIZE);
	ElementOffset->AddressOfEntryPoint = (Offset += DWORDSIZE);
	ElementOffset->BaseOfCode = (Offset += DWORDSIZE);
	ElementOffset->BaseOfData = (Offset += DWORDSIZE);
	ElementOffset->ImageBase = (Offset += DWORDSIZE);
	ElementOffset->SectionAlignment = (Offset += DWORDSIZE);
	ElementOffset->FileAlignment = (Offset += DWORDSIZE);
	ElementOffset->MajorOperatingSystemVersion = (Offset += DWORDSIZE);
	ElementOffset->MinorOperatingSystemVersion = (Offset += WORDSIZE);
	ElementOffset->MajorImageVersion = (Offset += WORDSIZE);
	ElementOffset->MinorImageVersion = (Offset += WORDSIZE);
	ElementOffset->MajorSubsystemVersion = (Offset += WORDSIZE);
	ElementOffset->MinorSubsystemVersion = (Offset += WORDSIZE);
	ElementOffset->Win32VersionValue = (Offset += WORDSIZE);
	ElementOffset->SizeOfImage = (Offset += DWORDSIZE);
	ElementOffset->SizeOfHeaders = (Offset += DWORDSIZE);
	ElementOffset->CheckSum = (Offset += DWORDSIZE);
	ElementOffset->Subsystem = (Offset += DWORDSIZE);
	ElementOffset->DllCharacteristics = (Offset += WORDSIZE);
	ElementOffset->SizeOfStackReserve = (Offset += WORDSIZE);
	ElementOffset->SizeOfStackCommit = (Offset += DWORDSIZE);
	ElementOffset->SizeOfHeapReserve = (Offset += DWORDSIZE);
	ElementOffset->SizeOfHeapCommit = (Offset += DWORDSIZE);
	ElementOffset->LoaderFlags = (Offset += DWORDSIZE);
	ElementOffset->NumberOfRvaAndSizes = (Offset += DWORDSIZE);
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		ElementOffset->DataDirectory[i][0] = (Offset += DWORDSIZE);
		ElementOffset->DataDirectory[i][1] = (Offset += DWORDSIZE);
	}
	Offset += DWORDSIZE;
	return Offset;
}

int setOptionalHeader64_ElementOffset(POPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset)
{
	IMAGE_OPTIONAL_HEADER64 Optional_Header64;
	unsigned int BYTESIZE = sizeof(BYTE);
	unsigned int ULONGLONGSIZE = sizeof(ULONGLONG);
	ElementOffset->Magic = Offset;
	ElementOffset->MajorLinkerVersion = (Offset += WORDSIZE);
	ElementOffset->MinorLinkerVersion = (Offset += BYTESIZE);
	ElementOffset->SizeOfCode = (Offset += BYTESIZE);
	ElementOffset->SizeOfInitializedData = (Offset += DWORDSIZE);
	ElementOffset->SizeOfUninitializedData = (Offset += DWORDSIZE);
	ElementOffset->AddressOfEntryPoint = (Offset += DWORDSIZE);
	ElementOffset->BaseOfCode = (Offset += DWORDSIZE);
	ElementOffset->ImageBase = (Offset += DWORDSIZE);
	ElementOffset->SectionAlignment = (Offset += ULONGLONGSIZE);
	ElementOffset->FileAlignment = (Offset += DWORDSIZE);
	ElementOffset->MajorOperatingSystemVersion = (Offset += DWORDSIZE);
	ElementOffset->MinorOperatingSystemVersion = (Offset += WORDSIZE);
	ElementOffset->MajorImageVersion = (Offset += WORDSIZE);
	ElementOffset->MinorImageVersion = (Offset += WORDSIZE);
	ElementOffset->MajorSubsystemVersion = (Offset += WORDSIZE);
	ElementOffset->MinorSubsystemVersion = (Offset += WORDSIZE);
	ElementOffset->Win32VersionValue = (Offset += WORDSIZE);
	ElementOffset->SizeOfImage = (Offset += DWORDSIZE);
	ElementOffset->SizeOfHeaders = (Offset += DWORDSIZE);
	ElementOffset->CheckSum = (Offset += DWORDSIZE);
	ElementOffset->Subsystem = (Offset += DWORDSIZE);
	ElementOffset->DllCharacteristics = (Offset += WORDSIZE);
	ElementOffset->SizeOfStackReserve = (Offset += WORDSIZE);
	ElementOffset->SizeOfStackCommit = (Offset += ULONGLONGSIZE);
	ElementOffset->SizeOfHeapReserve = (Offset += ULONGLONGSIZE);
	ElementOffset->SizeOfHeapCommit = (Offset += ULONGLONGSIZE);
	ElementOffset->LoaderFlags = (Offset += ULONGLONGSIZE);
	ElementOffset->NumberOfRvaAndSizes = (Offset += DWORDSIZE);
	for (int i = 0; i < (IMAGE_NUMBEROF_DIRECTORY_ENTRIES); i ++)
	{
		ElementOffset->DataDirectory[i][0] = (Offset += DWORDSIZE);
		ElementOffset->DataDirectory[i][1] = (Offset += DWORDSIZE);
	}
	Offset += DWORDSIZE;
	return Offset;
}