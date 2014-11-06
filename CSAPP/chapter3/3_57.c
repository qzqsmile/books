int cread(int *xp)
{
	return (xp? *xp: 0);
}

int main(void)
{
	int *xp;
	cread(xp);

	return 0;
}
