#include <argp.h>
#include <stdbool.h>

const char *argp_program_version = "gitpack 1.0";
const char *argp_program_bug_address = "<alexa.ognjanovic@protonmail.com>";
static char doc[] =
	"Gitpack -- a program to install git repos with ease";

static char args_doc[] = "command ...";

static struct argp_option options[] = {
	{"full", 'f', 0, 0, "Ignore sources and use full url"},
	{"master", 'm', 0, 0, "Use master branch"},
	{0}};

struct arguments
{
	char *args[2];
	bool full_url_flag, clone_master;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;

	switch (key)
	{
	case 'f':
		arguments->full_url_flag = true;
		break;
	case 'm':
		arguments->clone_master = true;
		break;

	case ARGP_KEY_ARG:
		arguments->args[state->arg_num] = arg;
		break;

	case ARGP_KEY_END:
		break;

	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}
