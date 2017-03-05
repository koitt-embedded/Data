#include <stdio.h>

int **test(int **p)
{
	return p;
}

int main(void)
{
	int num = 3;
	int *p = &num;
	int **pp = &p;

	printf("test = %d\n", **test(pp));
	return 0;
}
