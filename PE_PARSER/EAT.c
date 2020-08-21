#include <Windows.h>
#include <stdio.h>

#define SECTION_VirtualAddress PSECTION_HEADER[i].VirtualAddress
#define SECTION_SizeOfRawData PSECTION_HEADER[i].SizeOfRawData
#define SECTION_PointerToRawData PSECTION_HEADER[i].PointerToRawData

#define EXPORT_RVA PEXPORT_Directory_Table->VirtualAddress
#define EXPORT_SIZE PEXPORT_Directory_Table->Size

extern DWORD OFFSET;

int ExportOffset(PIMAGE_SECTION_HEADER PSECTION_HEADER, PIMAGE_DATA_DIRECTORY PDirectory, unsigned int NumberOfSection)
{
	//IMAGE_EXPORT_DIRECTORY
	return 0;
}


int showEAT(PIMAGE_EXPORT_DIRECTORY PImportDirectoryTable)
{
	printf("%8X : Characteristics\n", PImportDirectoryTable->Characteristics);
	printf("%8X : TimeDateStamp\n", PImportDirectoryTable->TimeDateStamp);
	printf("%8.4X : MajorVersion\n", PImportDirectoryTable->MajorVersion);
	printf("%8.4X : MinorVersion\n", PImportDirectoryTable->MinorVersion);
	printf("%8X : Name\n", PImportDirectoryTable->Name);
	printf("%8X : Base\n", PImportDirectoryTable->Base);
	printf("%8X : NumberOfFunctions\n", PImportDirectoryTable->NumberOfFunctions);
	printf("%8X : NumberOfNames\n", PImportDirectoryTable->NumberOfNames);
	printf("%8X : AddressOfFunctions\n", PImportDirectoryTable->AddressOfFunctions);
	printf("%8X : AddressOfNames\n", PImportDirectoryTable->AddressOfNames);
	printf("%8X : AddressOfNameOrdinals\n", PImportDirectoryTable->AddressOfNameOrdinals);
	return 0;
}