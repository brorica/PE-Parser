#include "NT_HEADER_OFFSET.h"
#include "SectionHeader.h"


int File_Header64(PIMAGE_FILE_HEADER PFILE_HEADER);

int NT_Header64(PIMAGE_NT_HEADERS64 NT_Header)
{
	fread(NT_Header, sizeof(IMAGE_NT_HEADERS64), 1, fp);
	printf("%08X\t%08X\t%-16s\n\n", Offset, NT_Header->Signature, "Signature");
	File_Header64(&NT_Header->FileHeader);
	OPTIONAL_HEADER64(&NT_Header->OptionalHeader);
	return NT_Header->FileHeader.NumberOfSections;
}

int File_Header64(PIMAGE_FILE_HEADER PFILE_HEADER)
{
	FILE_HEADER_ELEMENT_OFFSET ElementOffset;
	Offset += sizeof(DWORD);	// NT_HEADER Signature
	setFileHeaderElementOffset(&ElementOffset);
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