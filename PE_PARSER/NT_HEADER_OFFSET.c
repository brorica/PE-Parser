#include "NT_HEADER_OFFSET.h"

int setFileHeaderElementOffset(PFILE_HEADER_ELEMENT_OFFSET ElementOffset,int RVA)
{
	unsigned int OFFSET = RVA;
	IMAGE_FILE_HEADER File_Header;
	ElementOffset->Machine = OFFSET;
	ElementOffset->NumberOfSections = (OFFSET += sizeof(File_Header.Machine));
	ElementOffset->TimeDateStamp = (OFFSET += sizeof(File_Header.NumberOfSections));
	ElementOffset->PointerToSymbolTable = (OFFSET += sizeof(File_Header.TimeDateStamp));
	ElementOffset->NumberOfSymbols = (OFFSET += sizeof(File_Header.PointerToSymbolTable));
	ElementOffset->SizeOfOptionalHeader = (OFFSET += sizeof(File_Header.NumberOfSymbols));
	ElementOffset->Characteristics = (OFFSET += sizeof(File_Header.SizeOfOptionalHeader));
	return 0;
}

int setOptionalHeader32_ElementOffset(POPTIONAL_HEADER32_ELEMENT_OFFSET ElementOffset,int RVA)
{
	unsigned int OFFSET = RVA;
	IMAGE_OPTIONAL_HEADER32 Optional_Header32;
	ElementOffset->Magic = OFFSET;
	ElementOffset->MajorLinkerVersion = (OFFSET += sizeof(Optional_Header32.Magic));
	ElementOffset->MinorLinkerVersion = (OFFSET += sizeof(Optional_Header32.MajorLinkerVersion));
	ElementOffset->SizeOfCode = (OFFSET += sizeof(Optional_Header32.MinorLinkerVersion));
	ElementOffset->SizeOfInitializedData = (OFFSET += sizeof(Optional_Header32.SizeOfCode));
	ElementOffset->SizeOfUninitializedData = (OFFSET += sizeof(Optional_Header32.SizeOfInitializedData));
	ElementOffset->AddressOfEntryPoint = (OFFSET += sizeof(Optional_Header32.SizeOfUninitializedData));
	ElementOffset->BaseOfCode = (OFFSET += sizeof(Optional_Header32.AddressOfEntryPoint));
	ElementOffset->BaseOfData = (OFFSET += sizeof(Optional_Header32.BaseOfCode));
	ElementOffset->ImageBase = (OFFSET += sizeof(Optional_Header32.BaseOfData));
	ElementOffset->SectionAlignment = (OFFSET += sizeof(Optional_Header32.ImageBase));
	ElementOffset->FileAlignment = (OFFSET += sizeof(Optional_Header32.SectionAlignment));
	ElementOffset->MajorOperatingSystemVersion = (OFFSET += sizeof(Optional_Header32.FileAlignment));
	ElementOffset->MinorOperatingSystemVersion = (OFFSET += sizeof(Optional_Header32.MajorOperatingSystemVersion));
	ElementOffset->MajorImageVersion = (OFFSET += sizeof(Optional_Header32.MinorOperatingSystemVersion));
	ElementOffset->MinorImageVersion = (OFFSET += sizeof(Optional_Header32.MajorImageVersion));
	ElementOffset->MajorSubsystemVersion = (OFFSET += sizeof(Optional_Header32.MinorImageVersion));
	ElementOffset->MinorSubsystemVersion = (OFFSET += sizeof(Optional_Header32.MajorSubsystemVersion));
	ElementOffset->Win32VersionValue = (OFFSET += sizeof(Optional_Header32.MinorSubsystemVersion));
	ElementOffset->SizeOfImage = (OFFSET += sizeof(Optional_Header32.Win32VersionValue));
	ElementOffset->SizeOfHeaders = (OFFSET += sizeof(Optional_Header32.SizeOfImage));
	ElementOffset->CheckSum = (OFFSET += sizeof(Optional_Header32.SizeOfHeaders));
	ElementOffset->Subsystem = (OFFSET += sizeof(Optional_Header32.CheckSum));
	ElementOffset->DllCharacteristics = (OFFSET += sizeof(Optional_Header32.Subsystem));
	ElementOffset->SizeOfStackReserve = (OFFSET += sizeof(Optional_Header32.DllCharacteristics));
	ElementOffset->SizeOfStackCommit = (OFFSET += sizeof(Optional_Header32.SizeOfStackReserve));
	ElementOffset->SizeOfHeapReserve = (OFFSET += sizeof(Optional_Header32.SizeOfStackCommit));
	ElementOffset->SizeOfHeapCommit = (OFFSET += sizeof(Optional_Header32.SizeOfHeapReserve));
	ElementOffset->LoaderFlags = (OFFSET += sizeof(Optional_Header32.SizeOfHeapCommit));
	ElementOffset->NumberOfRvaAndSizes = (OFFSET += sizeof(Optional_Header32.LoaderFlags));
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		ElementOffset->DataDirectory[i][0] = (OFFSET += sizeof(Optional_Header32.DataDirectory->VirtualAddress));
		ElementOffset->DataDirectory[i][1] = (OFFSET += sizeof(Optional_Header32.DataDirectory->Size));
	}
	return 0;
}

int setOptionalHeader64_ElementOffset(POPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset,int RVA)
{
	unsigned int OFFSET = RVA;
	IMAGE_OPTIONAL_HEADER64 Optional_Header64;
	ElementOffset->Magic = OFFSET;
	ElementOffset->MajorLinkerVersion = (OFFSET += sizeof(Optional_Header64.Magic));
	ElementOffset->MinorLinkerVersion = (OFFSET += sizeof(Optional_Header64.MajorLinkerVersion));
	ElementOffset->SizeOfCode = (OFFSET += sizeof(Optional_Header64.MinorLinkerVersion));
	ElementOffset->SizeOfInitializedData = (OFFSET += sizeof(Optional_Header64.SizeOfCode));
	ElementOffset->SizeOfUninitializedData = (OFFSET += sizeof(Optional_Header64.SizeOfInitializedData));
	ElementOffset->AddressOfEntryPoint = (OFFSET += sizeof(Optional_Header64.SizeOfUninitializedData));
	ElementOffset->BaseOfCode = (OFFSET += sizeof(Optional_Header64.AddressOfEntryPoint));
	ElementOffset->ImageBase = (OFFSET += sizeof(Optional_Header64.BaseOfCode));
	ElementOffset->SectionAlignment = (OFFSET += sizeof(Optional_Header64.ImageBase));
	ElementOffset->FileAlignment = (OFFSET += sizeof(Optional_Header64.SectionAlignment));
	ElementOffset->MajorOperatingSystemVersion = (OFFSET += sizeof(Optional_Header64.FileAlignment));
	ElementOffset->MinorOperatingSystemVersion = (OFFSET += sizeof(Optional_Header64.MajorOperatingSystemVersion));
	ElementOffset->MajorImageVersion = (OFFSET += sizeof(Optional_Header64.MinorOperatingSystemVersion));
	ElementOffset->MinorImageVersion = (OFFSET += sizeof(Optional_Header64.MajorImageVersion));
	ElementOffset->MajorSubsystemVersion = (OFFSET += sizeof(Optional_Header64.MinorImageVersion));
	ElementOffset->MinorSubsystemVersion = (OFFSET += sizeof(Optional_Header64.MajorSubsystemVersion));
	ElementOffset->Win32VersionValue = (OFFSET += sizeof(Optional_Header64.MinorSubsystemVersion));
	ElementOffset->SizeOfImage = (OFFSET += sizeof(Optional_Header64.Win32VersionValue));
	ElementOffset->SizeOfHeaders = (OFFSET += sizeof(Optional_Header64.SizeOfImage));
	ElementOffset->CheckSum = (OFFSET += sizeof(Optional_Header64.SizeOfHeaders));
	ElementOffset->Subsystem = (OFFSET += sizeof(Optional_Header64.CheckSum));
	ElementOffset->DllCharacteristics = (OFFSET += sizeof(Optional_Header64.Subsystem));
	ElementOffset->SizeOfStackReserve = (OFFSET += sizeof(Optional_Header64.DllCharacteristics));
	ElementOffset->SizeOfStackCommit = (OFFSET += sizeof(Optional_Header64.SizeOfStackReserve));
	ElementOffset->SizeOfHeapReserve = (OFFSET += sizeof(Optional_Header64.SizeOfStackCommit));
	ElementOffset->SizeOfHeapCommit = (OFFSET += sizeof(Optional_Header64.SizeOfHeapReserve));
	ElementOffset->LoaderFlags = (OFFSET += sizeof(Optional_Header64.SizeOfHeapCommit));
	ElementOffset->NumberOfRvaAndSizes = (OFFSET += sizeof(Optional_Header64.LoaderFlags));
	for (int i = 0; i < (IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1); i ++)
	{
		ElementOffset->DataDirectory[i][0] = (OFFSET += sizeof(Optional_Header64.DataDirectory->VirtualAddress));
		ElementOffset->DataDirectory[i][1] = (OFFSET += sizeof(Optional_Header64.DataDirectory->Size));
	}
	return 0;
}