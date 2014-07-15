#include<stdio.h>
#include<string.h>

#define TMIN 0x80000000
#define TMAX 0x7fffffff
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
	unsigned a;
	a = x >> 16; x ^= a;
	a = x >> 8; x ^= a;
	a = x >> 4; x ^= a;
	a = x >> 2; x ^= a;

	return (x & 0x000001);
}
//2_66

int leftmost_one(unsigned x)
{
	unsigned a = x;
	a |= (a >> 1);
	a |= (a >> 2);
	a |= (a >> 4);
	a |= (a >> 8);
	a |= (a >> 16);
	a += 1; a >>= 1;
	
	((x & 0x80000000) == 0x80000000) && (a = 0x80000000);

	return a;
}
//2_67
int bad_int_size_is_32(){
	int set_msb = 1 << 31;
	int beyond_msb = 1 << 31 << 1;

	return set_msb && !beyond_msb;
}

//2_68
int lower_bits(int x, int n)
{
	return (x & (~((~0x00)<<n)));
}

//2_69
unsigned rotate_right(unsigned x, int n)
{
	unsigned a  = 0;
	a = x >> n;
	x <<= (32 - n);
	a = a + x;

	return a;
}

//2_70

int fits_bits(int x, int n)
{
	unsigned a = 0;
	a = (~0x00) << (n-1);
	
	return (((x&a) == a) || ((x&a) == 0x00));
}

//2_71
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
	return (word >> (bytenum << 3)) & 0xFF;
}

//2_72
void copy_int(int val, void *buf, int maxbytes){
	if(maxbytes-(int)sizeof(val) >= 0)
	{
		memcpy(buf, (void*) &val, sizeof(val));
	}
}
//2_73
int saturating_add(int x, int y)
{
	int a = 0;
	int b = 0;
	int c = 0;
	b = x + y;
	c = b;
	a = x ^ y;
	a &= 0x80000000;

	(a != 0x80000000) && ((x & 0x80000000) == 0x80000000) && ((b & 0x80000000) == 0x00) && (c = TMIN);
	(a != 0x80000000) && ((x & 0x80000000) != 0x80000000) && ((b & 0x80000000) == 0x80000000) && (c = TMAX);

	return c;
}

//2_74
int tsub_ovf(int x, int y)
{
	int a = 0;
	a = x ^ y;
	a &= 0x80000000;
	
	return 	((a == 0x80000000) && (((y == 0x80000000) && (x == 0x0)) || ((TMIN == saturating_add(x, -y)) || (
					TMAX == saturating_add(x, -y)))));
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
//	printf("%d %d\n",even_ones(0x01), even_ones(0xffff));

	//2_66
	//printf("0x%X 0x%X\n", leftmost_one(0xFF00),leftmost_one(0x80000000));

	//2_67
//	printf("%d\n", bad_int_size_is_32());
	
	//2_68
//	printf("%X %X\n", lower_bits(0x78ABCDEF, 8), lower_bits(0x78ABCDEF, 16));

	//2_69
//	printf("0x%x, 0x%x\n", rotate_right(0x12345678,8), rotate_right(0x0,10));
	//2_70
//	printf("0x%d, 0x%d\n", fits_bits(4, 4), fits_bits(-9, 4));

	//2_71
//	printf("0x%x\n", xbyte(0x12345678, 1));
	//2_72
//	copy_int(10, buf, -1);
	//2_73
//	printf("0x%x 0x%x\n", saturating_add(0x7fffffff, 0x12), saturating_add(0x80000000,0xf0000000));
	//2_74
	printf("%d %d\n", tsub_ovf(0x0, 0x7fffffff), tsub_ovf(0x8fffffff,0x7fffffff));

	return 0;
}
