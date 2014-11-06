int absdiff(int x, int y)
{
	return x < y? y - x : x - y;
}

int main(void)
{	
	int x = 0, y = 0;
	int z = 0;

	z = absdiff(x , y);

	return 0;
}
