#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_dup(char *msg)
{
	int i;

	for(i = 0; msg[i]; i++)
		;
}

int find_space(char *msg, int *idx)
{
	int i, cnt = 0;

	for(i = 0; msg[i]; i++)
		if(!(strncmp(&msg[i], " ", 1)))
			idx[cnt++] = i;

	return cnt + 1;
}

void sort_idx(int *idx, int len, int *min, int *max)
{
	int i, j, key;

	for(i = 1; i < len; i++)
	{
		key = idx[i];
		for(j = i - 1; idx[j] > key; j--)
			idx[j + 1] = idx[j];
	}
	idx[j + 1] = key;

	*max = idx[len - 1];
	*min = idx[0];
}

void word_indexing(int *idx, int *word, int len)
{
	int i;

	word[0] = idx[0];

	for(i = 1; idx[i] != 0; i++)
		word[i] = idx[i] - idx[i - 1] - 1;

	printf("i = %d\n", i);
	printf("idx[i - 1] = %d\n", idx[i - 1]);

	word[i] = len - idx[i - 1] - 1;
}

void print_idx(int *idx)
{
	int i;

	for(i = 0; idx[i]; i++)
		printf("idx[%d] = %d\n", i, idx[i]);
}

int matching(char *msg, char **word, int len)
{
	int i, j, cnt = 0, freq = 0;
	char *tmp[5] = {0};
	int idx[5] = {0};

	for(i = 0; msg[i]; i++)
		for(j = 0; j < len; j++)
			if(!(strncmp(&msg[i], word[j], strlen(word[j]))) && msg[i + strlen(word[j])] != ' ')
			{
				printf("matching = %s\n", word[j]);
				tmp[cnt] = (char *)malloc(sizeof(word[j]));
				strncpy(tmp[cnt++], word[j], strlen(word[j]));
			}

#if 0
	for(i = 0; msg[i]; i++)
		for(j = 0; j < cnt; j++)
		{
			if(!(strncmp(&msg[i], tmp[j], strlen(tmp[j]))))
				idx[j] = freq++;
		}
#endif
	for(i = 0; i < cnt; i++)
	{
		for(j = 0; msg[j]; j++)
			if(!(strncmp(&msg[j], tmp[i], strlen(tmp[i]))))
				idx[i] = freq++;
		freq = 0;
	}

	for(i = 0; i < cnt; i++)
		if(idx[i] > 1)
			printf("%s: freq = %d\n", tmp[i], idx[i] - 1);

	//return cnt;
}

void alloc_word(char *msg, int *space, int *len, char **p, int tot_len, int word_len)
{
	int i;

	char *tmp = (char *)malloc(sizeof(len[0]));
	strncpy(tmp, msg, len[0]);
	p[0] = tmp;

	printf("tmp = %s\n", tmp);

	for(i = 1; i < word_len; i++)
	{
		tmp = (char *)malloc(sizeof(len[i]));
		strncpy(tmp, &msg[space[i - 1] + 1], len[i]);
		printf("tmp = %s\n", tmp);
		//printf("i = %d, tot_len = %d\n", i, tot_len);
		p[i] = tmp;
	}
}

void print_word(char **word, int len)
{
	int i;

	printf("\n");

	for(i = 0; i < len; i++)
		printf("%s\n", word[i]);

	printf("\n");
}

int main(void)
{
	int cnt, len, min, max;
	int word_cnt;
	int space_idx[100] = {0};
	int word_num[100] = {0};
	char *word[100] = {0};
	char msg[124] = "The FAKE NEWS media (failing @nytimes, @NBCNews, @ABC, @CBS, @CNN) is not my enemy, it is the enemy of the American People.";

	word_cnt = find_space(msg, space_idx);
	printf("cnt = %d\n", word_cnt);
	len = strlen(msg);
	word_indexing(space_idx, word_num, len);
	print_idx(word_num);
	//sort_idx(word_num, word_cnt, &min, &max);
	//printf("len = %d, max = %d\n", word_cnt, max);

	alloc_word(msg, space_idx, word_num, word, len, word_cnt);
	print_word(word, word_cnt);

	cnt = matching(msg, word, word_cnt);
	printf("cnt = %d\n", cnt);

	return 0;
}
