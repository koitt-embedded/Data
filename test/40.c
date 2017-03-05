#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void set_rand_mat(int(*mat)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mat[i][j] = rand() % 4 + 2;
}

void add(int(*A)[3], int(*B)[3], int(*R)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			R[i][j] = A[i][j] + B[i][j];
}

void print_mat(int(*p)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			printf("arr[%d][%d] = %d\n", i, j, p[i][j]);
}

int main(void)
{
	int A[3][3] = {0};
	int B[3][3] = {0};
	int R[3][3] = {0};

	srand(time(NULL));

	set_rand_mat(A);
	set_rand_mat(B);

	add(A, B, R);

	print_mat(R);

	return 0;
}
