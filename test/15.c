#include <stdio.h>

typedef struct _test
{
	int x;
	int y;
} test;

void swap(test *a, test *b)
{
	test tmp = {a->x, a->y};
	a->x = b->x;
	a->y = b->y;
	b->x = tmp.x;
	b->y = tmp.y;
}

int main(void)
{
	test a = {3, 7};
	test b = {1, 9};

	printf("a.x = %d, a.y = %d, b.x = %d, b.y = %d\n", a.x, a.y, b.x, b.y);
	swap(&a, &b);
	printf("a.x = %d, a.y = %d, b.x = %d, b.y = %d\n", a.x, a.y, b.x, b.y);

	return 0;
}
