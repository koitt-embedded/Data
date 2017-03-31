#include <stdio.h>

int (* add(int(*A)[3], int(*B)[3]))[3]
{
	int i, j;
	static int R[3][3] = {0};

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			R[i][j] = A[i][j] + B[i][j];

	return R;
}

int (* mult(int(*A)[3], int(*B)[3]))[3]
{
	static int R[3][3] = {0};

	R[0][0] = (A[0][0]*B[0][0]) + (A[0][1]*B[1][0])+(A[0][2]*B[2][0]);
	R[0][1] = (A[0][0]*B[0][1]) + (A[0][1]*B[1][1])+(A[0][2]*B[2][1]);
	R[0][2] = (A[0][0]*B[0][2]) + (A[0][1]*B[1][2])+(A[0][2]*B[2][2]);
	R[1][0] = (A[1][0]*B[0][0]) + (A[1][1]*B[1][0])+(A[1][2]*B[2][0]);
	R[1][1] = (A[1][0]*B[0][1]) + (A[1][1]*B[1][1])+(A[1][2]*B[2][1]);
	R[1][2] = (A[1][0]*B[0][2]) + (A[1][1]*B[1][2])+(A[1][2]*B[2][2]);
	R[2][0] = (A[2][0]*B[0][0]) + (A[2][1]*B[1][0])+(A[2][2]*B[2][0]);
	R[2][1] = (A[2][0]*B[0][1]) + (A[2][1]*B[1][1])+(A[2][2]*B[2][1]);
	R[2][2] = (A[2][0]*B[0][2]) + (A[2][1]*B[1][2])+(A[2][2]*B[2][2]);

	return R;
}

void print_arr(int(*R)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			printf("R[%d][%d] = %d\n", i, j, R[i][j]);
	printf("\n");
}

int main(void)
{
	int (* (*oper)(int(*)[3], int(*)[3]))[3];

	int (*R)[3];
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

	oper = add;
	R = oper(A, B);
	print_arr(R);

	oper = mult;
	R = oper(A, B);
	print_arr(R);

	return 0;
}