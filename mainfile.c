#include "shell.h"

/**
 * main – entry point to the function
 * @ac: Is an arguements count
 * @av: Is an arguements vector
 * by nexttosho
 * Return: 1 on error and 0 on success
 */

int main(int ac, char **av)
{
	info_l info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eputs1(av[0]);
				eputs1(": 0: Can't open ");
				eputs1(av[1]);
				_eputcha1('\n');
				_eputcha1(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	env_pop_list(info);
	rd_histo(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
