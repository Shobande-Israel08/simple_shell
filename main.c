#include "shell.h"

/**
 * main - main entry to initialize the variables
 * @argc: number of argument count
 * @argv: values for argument vector
 * @env: count of values taken from command
 * Return: zero on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inisialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisi(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - display prompt in a new line
 * when is signaled for  (ctrl + c) forward to the shell
 * @UNUSED: another option of the prototype
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inisialize_data - initialize the data struct for the shell
 * @data: is a pointer to the data struct
 * @argv: argument array to be parsed
 * @env: parsed environ to be send
 * @argc: received value for argument count
 */
void inisialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int e = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[e]; e++)
		{
			data->env[e] = str_duplicate(env[e]);
		}
	}
	data->env[e] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (e = 0; e < 20; e++)
	{
		data->alias_list[e] = NULL;
	}
}
/**
 * sisi - shows the prompt for infinite loop
 * @prompt: the printed prompt to be showed
 * @data: infinite loop for the prompt
 */
void sisi(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
