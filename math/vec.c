#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define VEC_MAX		3

void vec_init(float *v3)
{
	int i;
	float temp[10] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

	for(i = 0; i < VEC_MAX; i++)
	{
		v3[i] = rand() % 3 + 3;
		v3[i] += temp[rand() % 10];
	}
}

void print_vec(float *v3)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		printf("v3[%d] = %f\n", i, v3[i]);
	printf("\n");
}

void vec_add(float *x, float *y, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] + y[i];
}

void vec_sub(float *x, float *y, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] - y[i];
}

void vec_scalar(float *x, float rate, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] * rate;
}

float inner(float *x, float *y)
{
	int i;
	float tmp = 0.0;

	for(i = 0; i < VEC_MAX; i++)
		tmp += x[i] * y[i];

	return tmp;
}

void outer(float *x, float * y, float *r)
{
	r[0] = x[1] * y[2] - x[2] * y[1];
	r[1] = x[2] * y[0] - x[0] * y[2];
	r[2] = x[0] * y[1] - x[1] * y[0];
}

int main(void)
{
	float res;
	float x[3] = {0};
	float y[3] = {0};
	float r[3] = {0};

	srand(time(NULL));

	vec_init(x);
	vec_init(y);

	print_vec(x);
	print_vec(y);

	vec_add(x, y, r);
	print_vec(r);

	vec_sub(x, y, r);
	print_vec(r);

	vec_scalar(x, 2.3, r);
	print_vec(r);

	res = inner(x, y);
	printf("res = %f\n", res);

	outer(x, y, r);
	print_vec(r);

	return 0;
}
