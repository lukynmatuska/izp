#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const int MAX_LEN_OF_PASSWORD = 100;
const int ASCII_NEW_LINE = '\n';
const char END_OF_STRING = '\0';

/**
 * Define and initiaze stats
 */
typedef struct Stats
{
	int nchars;
	int min;
	double avg;
	int chars_in_avg;
} stats_t;

const int AVAILABLE_LEN_OF_CHARS = '~' - ' ';
char used_chars['~' - ' '] = "";
int used_chars_len = 0;
int len_of_all_passwords = 0;
int count_of_passwords = 0;
stats_t stats = {0, 0, 0, 0};

bool is_char_in_string(char c, char *string)
{
	for (size_t i = 0; string[i] != END_OF_STRING; i++)
	{
		if (string[i] == c)
		{
			return true;
		}
	}
	return false;
}

void update_stats(char *word)
{
	int i = 0;
	while (word[i] != END_OF_STRING)
	{
		// NCHARS
		if (!is_char_in_string(word[i], used_chars))
		{
			used_chars[used_chars_len++] = word[i];
			used_chars[used_chars_len] = END_OF_STRING;
			stats.nchars = used_chars_len;
		}
		i++;
	}

	// AVG
	len_of_all_passwords += i;
	count_of_passwords++;
	stats.avg = (len_of_all_passwords / count_of_passwords);

	// MIN
	if (i < stats.min || stats.min == 0)
	{
		stats.min = i;
	}
}

void print_stats(stats_t stats)
{
	printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f\n", stats.nchars, stats.min, stats.avg);
}

/**
 * Define helping methods
 */
int is_small_letter(int letter)
{
	const int a = 'a';
	const int z = 'z';
	return a <= letter && letter <= z;
}

int is_big_letter(int letter)
{
	const int a = 'A';
	const int z = 'Z';
	return a <= letter && letter <= z;
}

int is_number(int letter)
{
	const int a = '0';
	const int z = '9';
	return a <= letter && letter <= z;
}

int is_special_char(int letter)
{
	const int start = ' ';
	const int end = '~';
	return start <= letter && letter <= end;
}

bool level_one(char *w)
{
	update_stats(w);
	bool small = false;
	bool big = false;
	for (int i = 0; w[i] != END_OF_STRING; i++)
	{
		if (is_small_letter(w[i]))
		{
			small = true;
		}
		else if (is_big_letter(w[i]))
		{
			big = true;
		}
		if (small && big)
		{
			return true;
		}
	}
	return false;
}

bool level_two(char *w, int PARAM)
{
	update_stats(w);
	bool small = false;
	bool big = false;
	bool number = false;
	bool special_char = false;
	if (PARAM >= 4)
	{
		for (int i = 0; w[i] != END_OF_STRING; i++)
		{
			if (is_small_letter(w[i]))
			{
				small = true;
			}
			else if (is_big_letter(w[i]))
			{
				big = true;
			}
			else if (is_number(w[i]))
			{
				number = true;
			}
			else if (is_special_char(w[i]))
			{
				special_char = true;
			}
			if (small && big && number && special_char)
			{
				return true;
			}
		}
	}
	else if (PARAM == 3)
	{
		for (int i = 0; w[i] != END_OF_STRING; i++)
		{
			if (is_small_letter(w[i]))
			{
				small = true;
			}
			else if (is_big_letter(w[i]))
			{
				big = true;
			}
			else if (is_number(w[i]))
			{
				number = true;
			}
			else if (is_special_char(w[i]))
			{
				special_char = true;
			}
			if (
				(small && big && number) ||
				(small && big && special_char) ||
				(small && special_char && number) ||
				(big && special_char && number))
			{
				return true;
			}
		}
	}
	else if (PARAM == 2)
	{
		for (int i = 0; w[i] != END_OF_STRING; i++)
		{
			if (is_small_letter(w[i]))
			{
				small = true;
			}
			else if (is_big_letter(w[i]))
			{
				big = true;
			}
			else if (is_number(w[i]))
			{
				number = true;
			}
			else if (is_special_char(w[i]))
			{
				special_char = true;
			}
			if (
				(small && big) ||
				(small && special_char) ||
				(small && number) ||
				(big && special_char) ||
				(big && number) ||
				(special_char && number))
			{
				printf("%s\n", w);
				break;
			}
		}
	}
	else if (PARAM == 1)
	{
		for (int i = 0; w[i] != END_OF_STRING; i++)
		{
			if (is_small_letter(w[i]))
			{
				small = true;
			}
			else if (is_big_letter(w[i]))
			{
				big = true;
			}
			else if (is_number(w[i]))
			{
				number = true;
			}
			else if (is_special_char(w[i]))
			{
				special_char = true;
			}
			if (small || big || number || special_char)
			{
				return true;
			}
		}
	}
	return false;
}

bool level_three(char *w, int PARAM)
{
	update_stats(w);
	if (PARAM)
	{
		/* code */
	}
	// int asdf = 0;
	// char tmp[MAX_LEN_OF_PASSWORD] = "";
	return false;
}

bool level_four(char *w, int PARAM)
{
	update_stats(w);
	if (PARAM)
	{
		/* code */
	}

	return false;
}

int main(int argc, char *argv[])
{
	/**
	 * Check count of arguments
	 */
	const int MIN_COUNT_OF_ARGUMENTS = 3;
	if (argc < MIN_COUNT_OF_ARGUMENTS)
	{
		fprintf(stderr, "Too few arguments!\n");
		return 1;
	}

	/**
	 * Define LEVEL from argument
	 */
	const int LEVEL = atoi(argv[1]);
	const int LEVEL_MIN = 1;
	const int LEVEL_MAX = 4;
	if (LEVEL < LEVEL_MIN)
	{
		fprintf(stderr, "Too few LEVEL argument!\n");
		return 2;
	}
	if (LEVEL > LEVEL_MAX)
	{
		fprintf(stderr, "Too big LEVEL argument!\n");
		return 3;
	}

	/**
	 * Define PARAM from arguments
	 */
	const int PARAM = atoi(argv[2]);
	if (PARAM <= 0)
	{
		fprintf(stderr, "Too few PARAM argument! Must be bigger then zero.\n");
		return 4;
	}

	/**
	 * Define show_stats
	 */
	const int STATS_ARGUMENT_POSITION = 4;
	bool show_stats = false;
	if (argc >= STATS_ARGUMENT_POSITION)
	{
		//		if (argv[STATS_ARGUMENT_POSITION] == "--stats") {
		show_stats = true;
		//		}
	}

	/**
	 * MAAAAIN
	 */
	char current_password[MAX_LEN_OF_PASSWORD];
	int position_to_write = 0;
	int character = getchar();

	// Catching all characters of all passwords
	while (character != EOF)
	{

		// Catching one password
		current_password[position_to_write] = character;
		position_to_write++;
		character = getchar();
		if (character != ASCII_NEW_LINE)
		{
			continue;
		}
		current_password[position_to_write] = END_OF_STRING;
		position_to_write = 0;
		character = getchar();
		// End of catching password

		if (LEVEL == 1 && level_one(current_password))
		{
			printf("%s\n", current_password);
		}
		else if (LEVEL == 2)
		{
			if (!level_one(current_password))
			{
				continue;
			}
			if (level_two(current_password, PARAM))
			{
				printf("%s\n", current_password);
			}
		}
		else if (LEVEL == 3)
		{
			if (
				!level_one(current_password) ||
				!level_two(current_password, PARAM))
			{
				continue;
			}
			if (level_three(current_password, PARAM))
			{
				printf("%s\n", current_password);
			}
		}
		else if (LEVEL == 4)
		{
			if (
				!level_one(current_password) ||
				!level_two(current_password, PARAM) ||
				!level_three(current_password, PARAM))
			{
				continue;
			}
			if (level_four(current_password, PARAM))
			{
				printf("%s\n", current_password);
			}
		}
	}

	/*
	 * Print stats at the end
	 */
	if (show_stats)
	{
		print_stats(stats);
	}
	return 0;
}
