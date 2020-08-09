#include <stdio.h>
#include <Windows.h>

extern DWORD OFFSET;

int show_NT_HEADER(PIMAGE_NT_HEADERS PNT_HEADER)
{
	int Characteristics_Size;
	printf("%08X\t%08X\t%-16s\n", OFFSET, PNT_HEADER->Signature, "Signature");
	Characteristics_Size = show_PFILE_HEADER(&(PNT_HEADER->FileHeader), sizeof(PNT_HEADER->Signature));
	show_OPTIONAL_HEADER(&(PNT_HEADER->OptionalHeader), Characteristics_Size);
	return 0;
}

int show_PFILE_HEADER(PIMAGE_FILE_HEADER PFILE_HEADER, int Signature_Size)
{
	printf("%08X\t%8.4X\t%-16s\n", OFFSET += Signature_Size, PFILE_HEADER->Machine, "Machine");
	printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(PFILE_HEADER->Machine), PFILE_HEADER->NumberOfSections, "NumberOfSections");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(PFILE_HEADER->NumberOfSections), PFILE_HEADER->TimeDateStamp,"TimeDateStamp");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(PFILE_HEADER->TimeDateStamp), PFILE_HEADER->PointerToSymbolTable,"PointerToSymbolTable");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(PFILE_HEADER->PointerToSymbolTable), PFILE_HEADER->NumberOfSymbols,"NumberOfSymbols");
	OFFSET += (sizeof(DWORD) << 1) + (sizeof(WORD));
	printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(PFILE_HEADER->NumberOfSymbols), PFILE_HEADER->SizeOfOptionalHeader, "SizeOfOptionalHeader");
	printf("%08X\t%8.4X\t%-16s\n\n", OFFSET += sizeof(PFILE_HEADER->SizeOfOptionalHeader), PFILE_HEADER->Characteristics, "Characteristics");
	return sizeof(PFILE_HEADER->Characteristics);
}

int show_OPTIONAL_HEADER(PIMAGE_OPTIONAL_HEADER POPTIONAL_HEADER, int Characteristics_Size)
{
	printf("%08X\t%8.4X\t%-16s\n", OFFSET += Characteristics_Size, POPTIONAL_HEADER->Magic, "Magic");
	// printf("%08X\t%8.2X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->Magic), POPTIONAL_HEADER->MajorLinkerVersion, "MajorLinkerVersion");
	// printf("%08X\t%8.2X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MajorLinkerVersion), POPTIONAL_HEADER->MinorLinkerVersion, "MinorLinkerVersion");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MinorLinkerVersion), POPTIONAL_HEADER->SizeOfCode, "SizeOfCode");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfCode), POPTIONAL_HEADER->SizeOfInitializedData, "SizeOfInitializedData");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfInitializedData), POPTIONAL_HEADER->SizeOfUninitializedData, "SizeOfUninitializedData");
	OFFSET += (sizeof(BYTE) << 1) + (sizeof(DWORD) << 1) + sizeof(WORD);
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfUninitializedData), POPTIONAL_HEADER->AddressOfEntryPoint, "AddressOfEntryPoint");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->AddressOfEntryPoint), POPTIONAL_HEADER->BaseOfCode, "BaseOfCode");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->BaseOfCode), POPTIONAL_HEADER->BaseOfData, "BaseOfData");
	OFFSET += (sizeof(DWORD) << 1);
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->BaseOfData), POPTIONAL_HEADER->ImageBase, "ImageBase");
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->ImageBase), POPTIONAL_HEADER->SectionAlignment, "SectionAlignment");
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SectionAlignment), POPTIONAL_HEADER->FileAlignment, "FileAlignment");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->FileAlignment), POPTIONAL_HEADER->MajorOperatingSystemVersion, "MajorOperatingSystemVersion");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MajorOperatingSystemVersion), POPTIONAL_HEADER->MinorOperatingSystemVersion, "MinorOperatingSystemVersion");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MinorOperatingSystemVersion), POPTIONAL_HEADER->MajorImageVersion, "MajorImageVersion");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MajorImageVersion), POPTIONAL_HEADER->MinorImageVersion, "MinorImageVersion");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MinorImageVersion), POPTIONAL_HEADER->MajorSubsystemVersion, "MajorSubsystemVersion");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MajorSubsystemVersion), POPTIONAL_HEADER->MinorSubsystemVersion, "MinorSubsystemVersion");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->MinorSubsystemVersion), POPTIONAL_HEADER->Win32VersionValue, "Win32VersionValue");
	OFFSET += (sizeof(DWORD) << 2);
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->Win32VersionValue), POPTIONAL_HEADER->SizeOfImage, "SizeOfImage");
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfImage), POPTIONAL_HEADER->SizeOfHeaders, "SizeOfHeaders");
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfHeaders), POPTIONAL_HEADER->CheckSum, "CheckSum");

	printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->CheckSum), POPTIONAL_HEADER->Subsystem, "Subsystem");
	// printf("%08X\t%8.4X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->Subsystem), POPTIONAL_HEADER->DllCharacteristics, "DllCharacteristics");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->DllCharacteristics), POPTIONAL_HEADER->SizeOfStackReserve, "SizeOfStackReserve");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfStackReserve), POPTIONAL_HEADER->SizeOfStackCommit, "SizeOfStackCommit");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfStackCommit), POPTIONAL_HEADER->SizeOfHeapReserve, "SizeOfHeapReserve");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfHeapReserve), POPTIONAL_HEADER->SizeOfHeapCommit, "SizeOfHeapCommit");
	// printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->SizeOfHeapCommit), POPTIONAL_HEADER->LoaderFlags, "LoaderFlags");
	OFFSET += (sizeof(DWORD) << 2) + sizeof(DWORD);
	printf("%08X\t%08X\t%-16s\n", OFFSET += sizeof(POPTIONAL_HEADER->LoaderFlags), POPTIONAL_HEADER->NumberOfRvaAndSizes, "NumberOfRvaAndSizes");
	show_DATA_DIRECTORY(POPTIONAL_HEADER->DataDirectory);
	return 0;
}

int show_DATA_DIRECTORY(PIMAGE_DATA_DIRECTORY PDATA_DIRECTORY)
{

	char DIRECTORY_TYPE[16][16] = {
		{ "EXPORT" },{ "IMPORT" }, {"RESOURCE"},{ "EXCEPTION" },
		{ "SECURITY" },{ "BASERELOC" },{ "DEBUG" },{ "COPYRIGHT" },
		{ "GLOBALPTR" }, { "TLS" }, { "LOAD_CONFIG" }, { "BOUND_IMPORT"},
		{ "IAT" }, { "DELAY_IMPORT" }, { "COM_DESCRIPTOR" }, { "Reserved" } };

	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		printf("%08X\t%08X\t%-16s(RVA)\n", OFFSET += sizeof(PDATA_DIRECTORY[i].VirtualAddress), PDATA_DIRECTORY[i].VirtualAddress, DIRECTORY_TYPE[i]);
		printf("%08X\t%08X\t%-16s(SIZE)\n", OFFSET += sizeof(PDATA_DIRECTORY[i].Size), PDATA_DIRECTORY[i].Size, DIRECTORY_TYPE[i]);
	}
	printf("\n");
	return 0;
}