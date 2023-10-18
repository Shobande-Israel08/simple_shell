#include "shell.h"

/**
 * take_histo_file - take the file history
 * @info: parameter structures
 *by nexttosho
 * Return: allocated string containing history file
 */

char *take_histo_file(info_l *info)
{
	char *buf, *dir;

	dir = getenv1(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strancpy(buf, dir);
	_strancat(buf, "/");
	_strancat(buf, HIST_FILE);
	return (buf);
}

/**
 * pen_histo - builds a file, or modify an existing file
 * @info: the parameter structures
 * Return: 1 on success, or else -1
 */
int pen_histo(info_l *info)
{
	ssize_t fd;
	char *filename = take_histo_file(info);
	my_list *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_iput2fd(node->str, fd);
		_iput1fd('\n', fd);
	}
	_iput1fd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * rd_histo - reads history from the file
 * @info: the parameter structures
 * Return: history count on success, 0 otherwise
 */
int rd_histo(info_l *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = take_histo_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			create_histo_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		create_histo_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renum_histo(info);
	return (info->histcount);
}

/**
 * create_histo_list - input entry to a history linked list
 * @info: Structures containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history line count, history count
 * Return: Always 0
 */
int create_histo_list(info_l *info, char *buf, int linecount)
{
	my_list *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renum_histo - renumbers the linked list history after changes
 * @info: Structures possesing potential arguments. Used to maintain
 * Return: the new history count
 */
int renum_histo(info_l *info)
{
	my_list *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
