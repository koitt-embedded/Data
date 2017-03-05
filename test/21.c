#include <stdio.h>

void print_mat(int (*p)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			printf("R[%d][%d] = %d\n", i, j, p[i][j]);
}

void mat_add(int (*A)[3], int (*B)[3], int (*R)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			R[i][j] = A[i][j] + B[i][j];
}

int main(void)
{
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int B[3][3] = {{18, 17, 16}, {15, 14, 13}, {12, 11, 10}};
	int R[3][3] = {0};

	mat_add(A, B, R);
	print_mat(R);

	return 0;
}
