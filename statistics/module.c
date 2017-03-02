#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

void make_rand_content(int fd)
{
	int i, j, len, cnt, col = 10000;
	char buf[100000] = "data\n\0";
	int cur_len = 0, tmp = strlen(buf);

	memset(&buf[tmp], 0, sizeof(buf - tmp));

	for(i = 0; i < col; i++)
	{
		len = rand() % 7 + 3;
		for(j = 0; j < len; j++)
			buf[j + cur_len] = rand() % 26 + 97;

		cur_len = strlen(buf);
		buf[cur_len++] = '\n';

		//printf("%s", buf);
	}

	cur_len = strlen(buf);
	buf[cur_len] = '\0';

	write(fd, buf, strlen(buf));
	printf("output gaussian_dist.csv");
}

void make_file(void)
{
	int fd = open("gaussian_dist.csv", O_CREAT | O_TRUNC | O_RDWR, 0644);
	srand(time(NULL));
	make_rand_content(fd);
	close(fd);
}

#if 0
int main(void)
{
	int fd = open("gaussian_dist.csv", O_CREAT | O_TRUNC | O_RDWR, 0644);
	srand(time(NULL));
	make_rand_content(fd);
	close(fd);

	return 0;
}
#endif
