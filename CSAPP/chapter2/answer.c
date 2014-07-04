#include<stdio.h>

//2_60
unsigned replace_byte(unsigned x, unsigned char b, int i)
{
	unsigned result;
	result = x & (~(0xff << (i << 3))); 
	result += (b << (i << 3));
	return result;
}

//2_61
int is_all_true(unsigned x)
{
	if ((x == 0xffffffff) || (x == 0) || (((char) x) == (char)0xff) || ((x & (0xff << 3 << 3)) == 0xff000000))
		return 1;
	return 0;
}

//2_62
int int_shifts_are_logical()
{
	int x = 0xffffffff;

	if ((x >> 4) == 0x0fffffff)
		return 1;
	return 0;
}

//2_63
int sra(int x, int k){
	int xsrl = (unsigned) x >> k;
	int w = 8 * sizeof(int);
	
	xsrl = xsrl | ((~0x00) << (w-k));

	return xsrl;
}

unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int) x >> k;
	int w = 8 * sizeof(int);

	xsra = xsra & ~((~0x00) << (w-k)); 

	return xsra;
}

//2_64
int any_even_ones(unsigned x)
{
	unsigned x1;
	x1 = x & 0xAAAA;
	if (x1 == x)
		return 0;
	return 1;
}

//2_65
int even_ones(unsigned x)
{
	;
}
//2_66

int lefmost_one(unsigned x)
{
	;
}
//2_67
int bad_int_size_is_32(){
//	int set_msb = 1 << 31;
//	int beyond_msb = 1 << 32;
//
//	return set_msb && !beyond_msb;
	;
}

//2_68
int lower_bits(int x, int n)
{
	return (x & (~((~0x00)<<n)));
}

int main(void)
{
	//2_60
//	unsigned result;

//	result = replace_byte(0x12345678, 0xAB, 2);
//	result = replace_byte(0x12345678, 0xAB, 0);
//
//	printf("%X\n",result);

	//2_61

//	int flag = 0;
//
//	flag = is_all_true(0);
//	flag = is_all_true(0xff00f000);
//	flag = is_all_true(0x000020ff);
//	flag = is_all_true(0x00002000);
//	printf("%d\n", flag);

//	2_62
//	printf("%d\n", int_shifts_are_logical());

	//2_63
//	printf("%X %X %X\n",0x12345678, sra(0x12345678, 4), srl(0x12345678, 4));

	//2_64
//	printf("%d %d\n", any_even_ones(0x0002),any_even_ones(0x1234));

	//2_65
	printf("%d %d\n",even_ones(0x01), even_ones(0xffff));

	//2_66

	//2_68
	printf("%X %X\n", lower_bits(0x78ABCDEF, 8), lower_bits(0x78ABCDEF, 16));

	return 0;
}
