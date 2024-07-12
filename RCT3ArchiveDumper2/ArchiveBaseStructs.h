#include <stdint.h>

struct MatrixRow4
{
	float m[4];
};

struct WCA
{
	wchar_t *wstr;
};

struct Research
{
	union {
		unsigned long ul;
		float fl;
		struct {
			short hi;
			short lo;
		};
		unsigned char c[4];
	};

};

struct ARCHeader
{
	unsigned long magic_a;
	unsigned long magic_b;
	uint8_t version_unk_a;
	uint8_t version_unk_b;
	uint8_t version_unk_c;
	uint8_t version_unk_d;
	unsigned long header2_size;
};

struct ARCHeader2
{
	unsigned long* unknown;
};

struct ARCHeader3
{
	unsigned long unknowna;
	unsigned long unknownb;
	unsigned long unknownc;
	unsigned long unknownd;
};

struct ARCVariableDef
{
	unsigned short name_length;
	char* name;
	unsigned short type_length;
	char* datatype;
	unsigned long type_size;
	unsigned long subvariablecount;
	ARCVariableDef* vars;
};

struct ARCClassDefHeader
{
	unsigned short name_length;
	char* name;
	unsigned long root_variable_count;
	unsigned long total_count;
	ARCVariableDef* vars; // Gebruikt subvars
	ARCVariableDef* vars_array; // Slechts 1 lijst
};

struct ARCClassDataHeader2
{
	unsigned long size;
	unsigned long entries;
};

struct ARCClassDataHeader
{
	unsigned long class_num;
	unsigned long unk1;
	unsigned long unk2;
};

struct RCT3Archive
{
	ARCHeader h1;
	ARCHeader2 h2;
	ARCHeader3 h3;
	ARCClassDefHeader *cdh;
	ARCClassDataHeader *cdhd;
	unsigned long num_class_defs;
	unsigned long num_data_blocks;
};