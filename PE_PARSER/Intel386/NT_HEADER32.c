#include "../libs/NT_HEADER_OFFSET.h"
#include "../libs/Header.h"

#define SectionSize sizeof(IMAGE_SECTION_HEADER)
#define PImportDirectory &NT_Header->OptionalHeader.DataDirectory[1]

int File_Header32(PIMAGE_FILE_HEADER PFILE_HEADER);

int NT_Header32(PIMAGE_NT_HEADERS32 NT_Header)
{
	fread(NT_Header, sizeof(IMAGE_NT_HEADERS32), 1, fp);
	printf("%08X\t%08X\t%-16s\n\n", Offset, NT_Header->Signature, "Signature");
	File_Header32(&NT_Header->FileHeader);
	OPTIONAL_HEADER32(&NT_Header->OptionalHeader);
	//getImportOffse32(PSECTION_HEADER, PImportDirectory, SectionNumber);
	return NT_Header->FileHeader.NumberOfSections;
}

int File_Header32(PIMAGE_FILE_HEADER PFILE_HEADER)
{
	FILE_HEADER_ELEMENT_OFFSET ElementOffset;
	Offset += sizeof(DWORD);	// NT_HEADER Signature
	Offset = setFileHeaderElementOffset(&ElementOffset);
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.Machine, PFILE_HEADER->Machine, "Machine");
	// Section °¹¼ö
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.NumberOfSections, PFILE_HEADER->NumberOfSections, "NumberOfSections");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.TimeDateStamp, PFILE_HEADER->TimeDateStamp, "TimeDateStamp");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.PointerToSymbolTable, PFILE_HEADER->PointerToSymbolTable, "PointerToSymbolTable");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.NumberOfSymbols, PFILE_HEADER->NumberOfSymbols, "NumberOfSymbols");
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.SizeOfOptionalHeader, PFILE_HEADER->SizeOfOptionalHeader, "SizeOfOptionalHeader");
	printf("%08X\t%08.4X\t%-16s\n\n", ElementOffset.Characteristics, PFILE_HEADER->Characteristics, "Characteristics");
	return 0x014c;
}