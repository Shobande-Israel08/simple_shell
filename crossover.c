#include "shell.h"

/**
 * i_cmd - decide if a file is an executable command
 * @info: the info structure
 * @path: file path
 * Return: 1 if true, 0 otherwise
 */
int i_cmd(info_l *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dap_chars - clone characters
 * @pathstr: represent the PATH string
 * @start: indicates starting index
 * @stop: indicates stopping index
 * Return: new buffer pointer
 */
char *dap_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * phind_path - finds this cmd in the PATH string
 * @info: the info structure
 * @pathstr: indicate the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 * by nexttosho
 */
char *phind_path(info_l *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (i_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dap_chars(pathstr, curr_pos, i);
			if (!*path)
				_strancat(path, cmd);
			else
			{
				_strancat(path, "/");
				_strancat(path, cmd);
			}
			if (i_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
