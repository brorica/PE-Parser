#include "libs/NT_HEADER_OFFSET.h"

int setFileHeaderElementOffset(PFILE_HEADER_ELEMENT_OFFSET ElementOffset)
{
	IMAGE_FILE_HEADER File_Header;
	ElementOffset->Machine = Offset;
	ElementOffset->NumberOfSections = (Offset += sizeof(File_Header.Machine));
	ElementOffset->TimeDateStamp = (Offset += sizeof(File_Header.NumberOfSections));
	ElementOffset->PointerToSymbolTable = (Offset += sizeof(File_Header.TimeDateStamp));
	ElementOffset->NumberOfSymbols = (Offset += sizeof(File_Header.PointerToSymbolTable));
	ElementOffset->SizeOfOptionalHeader = (Offset += sizeof(File_Header.NumberOfSymbols));
	ElementOffset->Characteristics = (Offset += sizeof(File_Header.SizeOfOptionalHeader));
	Offset += sizeof(File_Header.Characteristics);
	return Offset;
}

int setOptionalHeader32_ElementOffset(POPTIONAL_HEADER32_ELEMENT_OFFSET ElementOffset)
{
	IMAGE_OPTIONAL_HEADER32 Optional_Header32;
	ElementOffset->Magic = Offset;
	ElementOffset->MajorLinkerVersion = (Offset += sizeof(Optional_Header32.Magic));
	ElementOffset->MinorLinkerVersion = (Offset += sizeof(Optional_Header32.MajorLinkerVersion));
	ElementOffset->SizeOfCode = (Offset += sizeof(Optional_Header32.MinorLinkerVersion));
	ElementOffset->SizeOfInitializedData = (Offset += sizeof(Optional_Header32.SizeOfCode));
	ElementOffset->SizeOfUninitializedData = (Offset += sizeof(Optional_Header32.SizeOfInitializedData));
	ElementOffset->AddressOfEntryPoint = (Offset += sizeof(Optional_Header32.SizeOfUninitializedData));
	ElementOffset->BaseOfCode = (Offset += sizeof(Optional_Header32.AddressOfEntryPoint));
	ElementOffset->BaseOfData = (Offset += sizeof(Optional_Header32.BaseOfCode));
	ElementOffset->ImageBase = (Offset += sizeof(Optional_Header32.BaseOfData));
	ElementOffset->SectionAlignment = (Offset += sizeof(Optional_Header32.ImageBase));
	ElementOffset->FileAlignment = (Offset += sizeof(Optional_Header32.SectionAlignment));
	ElementOffset->MajorOperatingSystemVersion = (Offset += sizeof(Optional_Header32.FileAlignment));
	ElementOffset->MinorOperatingSystemVersion = (Offset += sizeof(Optional_Header32.MajorOperatingSystemVersion));
	ElementOffset->MajorImageVersion = (Offset += sizeof(Optional_Header32.MinorOperatingSystemVersion));
	ElementOffset->MinorImageVersion = (Offset += sizeof(Optional_Header32.MajorImageVersion));
	ElementOffset->MajorSubsystemVersion = (Offset += sizeof(Optional_Header32.MinorImageVersion));
	ElementOffset->MinorSubsystemVersion = (Offset += sizeof(Optional_Header32.MajorSubsystemVersion));
	ElementOffset->Win32VersionValue = (Offset += sizeof(Optional_Header32.MinorSubsystemVersion));
	ElementOffset->SizeOfImage = (Offset += sizeof(Optional_Header32.Win32VersionValue));
	ElementOffset->SizeOfHeaders = (Offset += sizeof(Optional_Header32.SizeOfImage));
	ElementOffset->CheckSum = (Offset += sizeof(Optional_Header32.SizeOfHeaders));
	ElementOffset->Subsystem = (Offset += sizeof(Optional_Header32.CheckSum));
	ElementOffset->DllCharacteristics = (Offset += sizeof(Optional_Header32.Subsystem));
	ElementOffset->SizeOfStackReserve = (Offset += sizeof(Optional_Header32.DllCharacteristics));
	ElementOffset->SizeOfStackCommit = (Offset += sizeof(Optional_Header32.SizeOfStackReserve));
	ElementOffset->SizeOfHeapReserve = (Offset += sizeof(Optional_Header32.SizeOfStackCommit));
	ElementOffset->SizeOfHeapCommit = (Offset += sizeof(Optional_Header32.SizeOfHeapReserve));
	ElementOffset->LoaderFlags = (Offset += sizeof(Optional_Header32.SizeOfHeapCommit));
	ElementOffset->NumberOfRvaAndSizes = (Offset += sizeof(Optional_Header32.LoaderFlags));
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		ElementOffset->DataDirectory[i][0] = (Offset += sizeof(Optional_Header32.DataDirectory->VirtualAddress));
		ElementOffset->DataDirectory[i][1] = (Offset += sizeof(Optional_Header32.DataDirectory->Size));
	}
	Offset += sizeof(DWORD);
	return Offset;
}

int setOptionalHeader64_ElementOffset(POPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset)
{
	IMAGE_OPTIONAL_HEADER64 Optional_Header64;
	ElementOffset->Magic = Offset;
	ElementOffset->MajorLinkerVersion = (Offset += sizeof(Optional_Header64.Magic));
	ElementOffset->MinorLinkerVersion = (Offset += sizeof(Optional_Header64.MajorLinkerVersion));
	ElementOffset->SizeOfCode = (Offset += sizeof(Optional_Header64.MinorLinkerVersion));
	ElementOffset->SizeOfInitializedData = (Offset += sizeof(Optional_Header64.SizeOfCode));
	ElementOffset->SizeOfUninitializedData = (Offset += sizeof(Optional_Header64.SizeOfInitializedData));
	ElementOffset->AddressOfEntryPoint = (Offset += sizeof(Optional_Header64.SizeOfUninitializedData));
	ElementOffset->BaseOfCode = (Offset += sizeof(Optional_Header64.AddressOfEntryPoint));
	ElementOffset->ImageBase = (Offset += sizeof(Optional_Header64.BaseOfCode));
	ElementOffset->SectionAlignment = (Offset += sizeof(Optional_Header64.ImageBase));
	ElementOffset->FileAlignment = (Offset += sizeof(Optional_Header64.SectionAlignment));
	ElementOffset->MajorOperatingSystemVersion = (Offset += sizeof(Optional_Header64.FileAlignment));
	ElementOffset->MinorOperatingSystemVersion = (Offset += sizeof(Optional_Header64.MajorOperatingSystemVersion));
	ElementOffset->MajorImageVersion = (Offset += sizeof(Optional_Header64.MinorOperatingSystemVersion));
	ElementOffset->MinorImageVersion = (Offset += sizeof(Optional_Header64.MajorImageVersion));
	ElementOffset->MajorSubsystemVersion = (Offset += sizeof(Optional_Header64.MinorImageVersion));
	ElementOffset->MinorSubsystemVersion = (Offset += sizeof(Optional_Header64.MajorSubsystemVersion));
	ElementOffset->Win32VersionValue = (Offset += sizeof(Optional_Header64.MinorSubsystemVersion));
	ElementOffset->SizeOfImage = (Offset += sizeof(Optional_Header64.Win32VersionValue));
	ElementOffset->SizeOfHeaders = (Offset += sizeof(Optional_Header64.SizeOfImage));
	ElementOffset->CheckSum = (Offset += sizeof(Optional_Header64.SizeOfHeaders));
	ElementOffset->Subsystem = (Offset += sizeof(Optional_Header64.CheckSum));
	ElementOffset->DllCharacteristics = (Offset += sizeof(Optional_Header64.Subsystem));
	ElementOffset->SizeOfStackReserve = (Offset += sizeof(Optional_Header64.DllCharacteristics));
	ElementOffset->SizeOfStackCommit = (Offset += sizeof(Optional_Header64.SizeOfStackReserve));
	ElementOffset->SizeOfHeapReserve = (Offset += sizeof(Optional_Header64.SizeOfStackCommit));
	ElementOffset->SizeOfHeapCommit = (Offset += sizeof(Optional_Header64.SizeOfHeapReserve));
	ElementOffset->LoaderFlags = (Offset += sizeof(Optional_Header64.SizeOfHeapCommit));
	ElementOffset->NumberOfRvaAndSizes = (Offset += sizeof(Optional_Header64.LoaderFlags));
	for (int i = 0; i < (IMAGE_NUMBEROF_DIRECTORY_ENTRIES); i ++)
	{
		ElementOffset->DataDirectory[i][0] = (Offset += sizeof(Optional_Header64.DataDirectory->VirtualAddress));
		ElementOffset->DataDirectory[i][1] = (Offset += sizeof(Optional_Header64.DataDirectory->Size));
	}
	Offset += sizeof(DWORD);
	return Offset;
}