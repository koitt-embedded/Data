#include <stdio.h>

int find_series(int *data, int find)
{
	int i = 3;

	for(; i < 24; i++)
		data[i] = data[i - 3] + data[i - 1];

	return data[i - 1];
}

int main(void)
{
	int res;
	int data[24] = {1, 3, 4};

	res = find_series(data, 23);
	printf("res = %d\n", res);

	return 0;
}
