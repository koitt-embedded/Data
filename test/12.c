#include <stdio.h>

void set_arr(int (*arr)[3], int (*arr1)[3], int (*arr2)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			arr[i][j] = arr1[i][j];
	for(; i < 6; i++)
		for(j = 0; j < 3; j++)
			arr[i][j] = arr2[i - 3][j];
}

void print_arr(int (*arr)[3])
{
	int i, j;

	for(i = 0; i < 6; i++)
		for(j = 0; j < 3; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
}

int sort(int *rec)
{
	int idx[6] = {1, 2, 3, 4, 5, 6};
	int i, j, key, idx_key, len = 6;

	for(i = 1; i < len; i++)
	{
		key = rec[i];
		idx_key = idx[i];
		for(j = i - 1; rec[j] > key; j--)
		{
			rec[j + 1] = rec[j];
			idx[j + 1] = idx[j];
		}
		rec[j + 1] = key;
		idx[j + 1] = idx_key;
	}

	return idx[0];
}

int max_idx(int (*arr1)[3], int (*arr2)[3], int *bidx, int alen, int blen)
{
	int i, j, tmp = 0, first, id;
	int arr[6][3] = {0};
	int rec[6] = {0};

#if 0
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			printf("arr2[%d][%d] = %d\n", i, j, arr2[i][j]);
#endif

	set_arr(arr, arr1, arr2);
	//print_arr(arr);

	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 3; j++)
			tmp += arr[i][j];
		rec[i] = tmp;
		printf("rec[%d] = %d\n", i, rec[i]);
		tmp = 0;
	}

	first = sort(rec);

	switch(first)
	{
		case 1:
			id = 1;
			*bidx = 0;
			break;
		case 2:
			id = 1;
			*bidx = 1;
			break;
		case 3:
			id = 1;
			*bidx = 2;
			break;
		case 4:
			id = 2;
			*bidx = 0;
			break;
		case 5:
			id = 2;
			*bidx = 1;
			break;
		case 6:
			id = 2;
			*bidx = 2;
			break;
	}

	return id;
}

int main(void)
{
	int bidx, alen, blen, id;
	int arr1[3][3] = {{1, 3, 6}, {7, 1, 9}, {3, 7, 5}};
	int arr2[3][3] = {{3, 5, 7}, {9, 1, 8}, {5, 1, 2}};

	alen = sizeof(arr1) / sizeof(int);
	blen = sizeof(arr1[0]) / sizeof(int);

	printf("tot arr size = %d\n", alen);
	printf("arr elem size = %d\n", blen);
	printf("part num = %d\n", alen / blen);

	id = max_idx(arr1, arr2, &bidx, alen, blen);

	if(id == 1)
		printf("arr1[%d]\n", bidx);
	else if(id == 2)
		printf("arr2[%d]\n", bidx);
	
	return 0;
}
