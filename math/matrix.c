#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define COL	3
#define ROW	3

void init_matrix(float (*A)[3])
{
	int i, j;
	
	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			A[i][j] = rand() % 4 + 1;
}

void print_mat(float (*A)[3])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			printf("res[%d][%d] = %f\n", i, j, A[i][j]);
	printf("\n");
}

void trans_mat(float (*A)[3], float (*R)[3])
{
	R[0][0] = A[0][0];
	R[0][1] = A[1][0];
	R[0][2] = A[2][0];

	R[1][0] = A[0][1];
	R[1][1] = A[1][1];
	R[1][2] = A[2][1];

	R[2][0] = A[0][2];
	R[2][1] = A[1][2];
	R[2][2] = A[2][2];
}

void add_mat(float (*A)[3], float (*B)[3], float (*R)[3])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			R[i][j] = A[i][j] + B[i][j];
}

void add_sub(float (*A)[3], float (*B)[3], float (*R)[3])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			R[i][j] = A[i][j] - B[i][j];
}

void scalar_mat(float (*A)[3], float rate, float (*R)[3])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			R[i][j] = A[i][j] * rate;
}

void mult_mat(float (*A)[3], float (*B)[3], float (*R)[3])
{
	R[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
	R[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1];
	R[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2];

	R[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0];
	R[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1];
	R[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2];

	R[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0];
	R[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1];
	R[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2];
}

float det(float (*A)[3])
{
	float tmp = 0.0;

	tmp = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
	    + A[1][1] * (A[1][2] * A[2][0] - A[1][0] * A[2][2])
	    + A[2][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

	return tmp;
}

void adj_mat(float (*A)[3], float (*adj)[3])
{
	adj[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
	adj[0][1] = A[1][2] * A[2][0] - A[1][0] * A[2][2];
	adj[0][2] = A[1][0] * A[2][1] - A[1][1] * A[2][0];

	adj[1][0] = A[0][2] * A[2][1] - A[0][1] * A[2][2];
	adj[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
	adj[1][2] = A[0][1] * A[2][0] - A[0][0] * A[2][1];

	adj[2][0] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
	adj[2][1] = A[0][2] * A[1][0] - A[0][0] * A[1][2];
	adj[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

void inv(float (*A)[3], float (*R)[3])
{
	float determinant = det(A);
	float adj[3][3] = {0};
	float tmp[3][3] = {0};

	if(det)
	{
		adj_mat(A, adj);
		printf("adjoint:\n");
		print_mat(adj);
		scalar_mat(adj, 1.0/determinant, tmp);
		trans_mat(tmp, R);
	}
}

int main(void)
{
	float A[3][3] = {0};
	float B[3][3] = {0};
	float R[3][3] = {0};
	float detA, detB;

	srand(time(NULL));

	init_matrix(A);
	init_matrix(B);

	print_mat(A);
	print_mat(B);

	trans_mat(A, R);
	printf("Transpose:\n");
	print_mat(R);

	add_mat(A, B, R);
	printf("Addition:\n");
	print_mat(R);

	add_sub(A, B, R);
	printf("Subtraction:\n");
	print_mat(R);

	scalar_mat(A, 1/3, R);
	printf("Scalar:\n");
	print_mat(R);

	mult_mat(A, B, R);
	printf("Multiplication:\n");
	print_mat(R);

	detA = det(A);
	detB = det(B);
	printf("detA = %f\n", detA);
	printf("detB = %f\n", detB);

	if(detA)
	{
		inv(A, R);
		printf("inverse A:\n");
		print_mat(R);
	}
	else
		printf("detA == 0\n");

	if(detB)
	{
		inv(B, R);
		printf("inverse B:\n");
		print_mat(R);
	}
	else
		printf("detB == 0\n");

	return 0;
}
