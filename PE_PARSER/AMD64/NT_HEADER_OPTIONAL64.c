#include "../libs/NT_HEADER_OFFSET.h"
int DATA_DIRECTORY64(PIMAGE_DATA_DIRECTORY PDirectory, unsigned int DataDirectory[][2], unsigned int NumberOfRvaAndSizes);

int OPTIONAL_HEADER64(PIMAGE_OPTIONAL_HEADER64 POPTIONAL_HEADER)
{
	OPTIONAL_HEADER64_ELEMENT_OFFSET ElementOffset;
	setOptionalHeader64_ElementOffset(&ElementOffset);
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.Magic, POPTIONAL_HEADER->Magic, "Magic");
	//printf("%08X\t%08.2X\t%-16s\n", ElementOffset.MajorLinkerVersion, POPTIONAL_HEADER->MajorLinkerVersion, "MajorLinkerVersion");
	//printf("%08X\t%08.2X\t%-16s\n", ElementOffset.MinorLinkerVersion, POPTIONAL_HEADER->MinorLinkerVersion, "MinorLinkerVersion");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.SizeOfCode, POPTIONAL_HEADER->SizeOfCode, "SizeOfCode");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.SizeOfInitializedData, POPTIONAL_HEADER->SizeOfInitializedData, "SizeOfInitializedData");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.SizeOfUninitializedData, POPTIONAL_HEADER->SizeOfUninitializedData, "SizeOfUninitializedData");
	printf("%08X\t%08X\t%-16s\n", ElementOffset.AddressOfEntryPoint, POPTIONAL_HEADER->AddressOfEntryPoint, "AddressOfEntryPoint");
	//¤Ärintf("%08X\t%08X\t%-16s\n", ElementOffset.BaseOfCode, POPTIONAL_HEADER->BaseOfCode, "BaseOfCode");
	printf("%08X\t%016llX\t%-16s\n", ElementOffset.ImageBase, POPTIONAL_HEADER->ImageBase, "ImageBase");
	printf("%08X\t%08X\t%-16s\n", ElementOffset.SectionAlignment, POPTIONAL_HEADER->SectionAlignment, "SectionAlignment");
	printf("%08X\t%08X\t%-16s\n", ElementOffset.FileAlignment, POPTIONAL_HEADER->FileAlignment, "FileAlignment");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MajorOperatingSystemVersion, POPTIONAL_HEADER->MajorOperatingSystemVersion, "MajorOperatingSystemVersion");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MinorOperatingSystemVersion, POPTIONAL_HEADER->MinorOperatingSystemVersion, "MinorOperatingSystemVersion");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MajorImageVersion, POPTIONAL_HEADER->MajorImageVersion, "MajorImageVersion");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MinorImageVersion, POPTIONAL_HEADER->MinorImageVersion, "MinorImageVersion");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MajorSubsystemVersion, POPTIONAL_HEADER->MajorSubsystemVersion, "MajorSubsystemVersion");
	//printf("%08X\t%8.4X\t%-16s\n", ElementOffset.MinorSubsystemVersion, POPTIONAL_HEADER->MinorSubsystemVersion, "MinorSubsystemVersion");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.Win32VersionValue, POPTIONAL_HEADER->Win32VersionValue, "Win32VersionValue");
	printf("%08X\t%08X\t%-16s\n", ElementOffset.SizeOfImage, POPTIONAL_HEADER->SizeOfImage, "SizeOfImage");
	printf("%08X\t%08X\t%-16s\n", ElementOffset.SizeOfHeaders, POPTIONAL_HEADER->SizeOfHeaders, "SizeOfHeaders");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.CheckSum, POPTIONAL_HEADER->CheckSum, "CheckSum");
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.Subsystem, POPTIONAL_HEADER->Subsystem, "Subsystem");
	//printf("%08X\t%08.4X\t%-16s\n", ElementOffset.DllCharacteristics, POPTIONAL_HEADER->DllCharacteristics, "DllCharacteristics");
	//printf("%08X\t%016llX\t%-16s\n", ElementOffset.SizeOfStackReserve, POPTIONAL_HEADER->SizeOfStackReserve, "SizeOfStackReserve");
	//printf("%08X\t%016llX\t%-16s\n", ElementOffset.SizeOfStackCommit, POPTIONAL_HEADER->SizeOfStackCommit, "SizeOfStackCommit");
	//printf("%08X\t%016llX\t%-16s\n", ElementOffset.SizeOfHeapReserve, POPTIONAL_HEADER->SizeOfHeapReserve, "SizeOfHeapReserve");
	//printf("%08X\t%016llX\t%-16s\n", ElementOffset.SizeOfHeapCommit, POPTIONAL_HEADER->SizeOfHeapCommit, "SizeOfHeapCommit");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.LoaderFlags, POPTIONAL_HEADER->LoaderFlags, "LoaderFlags");
	printf("%08X\t%08X\t%-16s\n\n", ElementOffset.NumberOfRvaAndSizes, POPTIONAL_HEADER->NumberOfRvaAndSizes, "NumberOfRvaAndSizes");
	DATA_DIRECTORY64(POPTIONAL_HEADER->DataDirectory, ElementOffset.DataDirectory, POPTIONAL_HEADER->NumberOfRvaAndSizes);
	return sizeof(IMAGE_OPTIONAL_HEADER64);
}

int DATA_DIRECTORY64(PIMAGE_DATA_DIRECTORY PDirectory, unsigned int DataDirectory[][2],unsigned int NumberOfRvaAndSizes)
{

	char DIRECTORY_TYPE[IMAGE_NUMBEROF_DIRECTORY_ENTRIES][16] = {
		{ "EXPORT" },{ "IMPORT" }, {"RESOURCE"},{ "EXCEPTION" },
		{ "SECURITY" },{ "BASERELOC" },{ "DEBUG" },
		{ "ARCHITECTURE" }, { "GLOBALPTR " }, { "TLS" }, { "LOAD_CONFIG"},
		{ "BOUND_IMPORT" }, { "IAT" }, { "DELAY_IMPORT" }, { "COM_DESCRIPTOR" },{"NULL"} };

	for (unsigned int i = 0; i < NumberOfRvaAndSizes; i++)
	{
		printf("%08X\t%08X\t%-16s(RVA)\n", DataDirectory[i][0], PDirectory[i].VirtualAddress, DIRECTORY_TYPE[i]);
		printf("%08X\t%08X\t%-16s(SIZE)\n", DataDirectory[i][1], PDirectory[i].Size, DIRECTORY_TYPE[i]);
	}
	printf("\n");
	return 0;
}
