#include <stdio.h>

void look_arr(void)
{
	int arr[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
	printf("arr = 0x%x\n", arr);
	printf("arr[0] = 0x%x\n", arr[0]);
	printf("arr[1] = 0x%x\n", arr[1]);
}

int main(void)
{
	look_arr();
	return 0;
}
