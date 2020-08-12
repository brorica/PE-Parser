#include "NT_HEADER_OFFSET.h"
#include "SectionHeader.h"

int File_Header(PIMAGE_FILE_HEADER PFILE_HEADER, unsigned int RVA);
int OPTIONAL_HEADER64(PIMAGE_OPTIONAL_HEADER64 POPTIONAL_HEADER, unsigned int RVA);
int OPTIONAL_HEADER32(PIMAGE_OPTIONAL_HEADER32 POPTIONAL_HEADER, unsigned int RVA);

int NT_Header(FILE *fp, unsigned int RVA)
{
	IMAGE_NT_HEADERS NT_Header;
	int File_Header_Size = sizeof(IMAGE_FILE_HEADER)+sizeof(NT_Header.Signature);
	int MachineCheck;
	
	fread(&NT_Header, File_Header_Size, 1, fp);
	printf("%08X\t%08X\t%-16s\n\n", RVA, NT_Header.Signature, "Signature");
	MachineCheck = File_Header(&(NT_Header.FileHeader), RVA + sizeof(NT_Header.Signature));

	// set Optional header RVA
	RVA += File_Header_Size;
	if (MachineCheck == 1)
	{
		IMAGE_OPTIONAL_HEADER64 Optional_Header;
		fread(&Optional_Header, sizeof(IMAGE_OPTIONAL_HEADER64), 1, fp);
		RVA += OPTIONAL_HEADER64(&Optional_Header, RVA);
		Section_Header(fp, Optional_Header.DataDirectory, RVA, NT_Header.FileHeader.NumberOfSections);
	}
	else if (MachineCheck == 0)
	{
		IMAGE_OPTIONAL_HEADER32 Optional_Header;
		fread(&Optional_Header, sizeof(IMAGE_OPTIONAL_HEADER32), 1, fp);
		RVA += OPTIONAL_HEADER32(&Optional_Header, RVA);
		Section_Header(fp, Optional_Header.DataDirectory, RVA, NT_Header.FileHeader.NumberOfSections);
	}
	
	return RVA;
}

int File_Header(PIMAGE_FILE_HEADER PFILE_HEADER, unsigned int RVA)
{
	FILE_HEADER_ELEMENT_OFFSET ElementOffset;
	setFileHeaderElementOffset(&ElementOffset, RVA);
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.Machine, PFILE_HEADER->Machine, "Machine");
	// Section °¹¼ö
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.NumberOfSections, PFILE_HEADER->NumberOfSections, "NumberOfSections");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.TimeDateStamp, PFILE_HEADER->TimeDateStamp, "TimeDateStamp");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.PointerToSymbolTable, PFILE_HEADER->PointerToSymbolTable, "PointerToSymbolTable");
	//printf("%08X\t%08X\t%-16s\n", ElementOffset.NumberOfSymbols, PFILE_HEADER->NumberOfSymbols, "NumberOfSymbols");
	printf("%08X\t%08.4X\t%-16s\n", ElementOffset.SizeOfOptionalHeader, PFILE_HEADER->SizeOfOptionalHeader, "SizeOfOptionalHeader");
	printf("%08X\t%08.4X\t%-16s\n\n", ElementOffset.Characteristics, PFILE_HEADER->Characteristics, "Characteristics");
	if (PFILE_HEADER->Machine == 0x8664)
		return 1;
	return 0;
}