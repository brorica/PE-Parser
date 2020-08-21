#include "NT_HEADER_OFFSET.h"
#include "SectionHeader.h"

#define SectionNumber NT_Header.FileHeader.NumberOfSections
#define SectionSize sizeof(IMAGE_SECTION_HEADER)
#define PImportDirectory &NT_Header.OptionalHeader.DataDirectory[1]

int File_Header64(PIMAGE_FILE_HEADER PFILE_HEADER);

int NT_Header64()
{
	IMAGE_NT_HEADERS64 NT_Header;
	PIMAGE_SECTION_HEADER PSECTION_HEADER;
	fread(&NT_Header, sizeof(IMAGE_NT_HEADERS64), 1, fp);
	printf("%08X\t%08X\t%-16s\n\n", Offset, NT_Header.Signature, "Signature");
	File_Header64(&NT_Header.FileHeader);
	OPTIONAL_HEADER64(&NT_Header.OptionalHeader);
	PSECTION_HEADER = (PIMAGE_SECTION_HEADER)malloc(SectionSize * SectionNumber);
	Section_Header64(PSECTION_HEADER);
	getImportOffset64(PSECTION_HEADER, PImportDirectory, SectionNumber);
	free(PSECTION_HEADER);
	return Offset;
}

int File_Header64(PIMAGE_FILE_HEADER PFILE_HEADER)
{
	FILE_HEADER_ELEMENT_OFFSET ElementOffset;
	Offset += sizeof(DWORD);	// NT_HEADER Signature
	Offset += setFileHeaderElementOffset(&ElementOffset, Offset);
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.Machine, PFILE_HEADER->Machine, "Machine");
	// Section °¹¼ö
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.NumberOfSections, PFILE_HEADER->NumberOfSections, "NumberOfSections");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.TimeDateStamp, PFILE_HEADER->TimeDateStamp, "TimeDateStamp");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.PointerToSymbolTable, PFILE_HEADER->PointerToSymbolTable, "PointerToSymbolTable");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.NumberOfSymbols, PFILE_HEADER->NumberOfSymbols, "NumberOfSymbols");
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.SizeOfOptionalHeader, PFILE_HEADER->SizeOfOptionalHeader, "SizeOfOptionalHeader");
	printf("%08X\t%08.4X\t%-16s\n\n", ElementOffset.Characteristics, PFILE_HEADER->Characteristics, "Characteristics");
	return 0;
}