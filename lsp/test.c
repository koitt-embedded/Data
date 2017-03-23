#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void fd_open(char **fname, int *fd)
{
	fd[0] = open(fname[0], O_RDONLY);
	fd[1] = open(fname[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}

void mod_contents(char *con, char *find, char *mod, int fd)
{
	int i, save, c_len, f_len, m_len;
	char tmp[1024] = "";

	f_len = strlen(find);
	m_len = strlen(mod);
	c_len = strlen(con);

	for(i = 0; con[i]; i++)
		if(!(strncmp(&con[i], find, f_len)))
			save = i;

	strncpy(tmp, con, save);
	strncpy(&tmp[save], mod, m_len);
	strncpy(&tmp[save + m_len], &con[save + f_len], c_len - save - f_len);

	write(0, tmp, strlen(tmp));

	write(fd, tmp, strlen(tmp));	
}

void analysis_contents(int *fd)
{
	int nr;
	char buf[1024] = "";
	char *mod = "C6678 DSP";
	char *find = "Cortex-R5F Safety MCU";

	nr = read(fd[0], buf, sizeof(buf));

	write(0, buf, strlen(buf));

	mod_contents(buf, find, mod, fd[1]);
}

int main(void)
{
	int fd[2] = {0};
	char *fname[2] = {"cortex-r5f.txt", "c6678.txt"};

	fd_open(fname, fd);

	analysis_contents(fd);

	return 0;
}
