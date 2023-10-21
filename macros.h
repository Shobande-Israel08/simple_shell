#ifndef HELPERS_H
#define HELPERS_H

#define PROMPT_MSG "myshell$"


#define UNUSED __attribute__((unused))


#define BUFFER_SIZE 1024

#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"	Change myshell working directory.\n\n"\
"	The command will be interpreted if no argument is passed to cd\n"\

#define HELP_EXIT_MSG "exit=\n"\
"exit:\texit [STATUS]\n\n"\
"	Exit my simple-shell.\n\n"\
"	Exits my shell with a status of N.  If N is omitted, the exit status\n"\

#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"	Print the environment.\n\n"\

#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"	Switch or add an environ variable.\n\n"\
"	initialize a new environment variable in the shell\n"\

#define HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"	This function deletes one variable from the environment in the shell.\n\n"\

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"	Display information about builtin commands in my shell.\n\n"\
"	Displays summary displayas. If BUILTIN_NAME is\n"\
"	specified, gives detailed help on all commands matching BUILTIN_NAME,\n"\
"	otherwise the list of help topics is printed BUILTIN_NAME list.\n"\
"	Arguments:\n\n"\
"	BUILTIN_NAME specifiying a help topic.\n\n"\
"	cd\t[dir]\n"\
"	exit\t[status]\n"\
"	env\n"\
"	setenv\t[variable value]\n"\
"	unset\t[variable]\n"\
"	help\t[built_name]\n\n"

#endif
