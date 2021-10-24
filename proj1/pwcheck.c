#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct Stats {
	int nchars;
	int min;
	int avg;
} stat_t;

int is_small_letter(int letter) {
	const int a = 'a';
	const int z = 'z';
	return a <= letter && letter <= z;
}

int is_big_letter(int letter) {
	const int a = 'A';
	const int z = 'Z';
	return a <= letter && letter <= z;
}

int is_number(int letter) {
	const int a = '0';
	const int z = '9';
	return a <= letter && letter <= z;
}

int is_special_char(int letter) {
	const int start = ' ';
	const int end = '~';
	return start <= letter && letter <= end;
}

int main(int argc, char *argv[]) {
	printf("argc:%d\n", argc);
//	printf("argv:%s\n", *argv);
//	fprintf(stderr,"argv:%s\n", *argv);
	for(int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	
	/**
	 * Check count of arguments
	 */
	const int MIN_COUNT_OF_ARGUMENTS = 3;
	if (argc < MIN_COUNT_OF_ARGUMENTS) {
		fprintf(stderr,"Too few arguments!\n");
		return 1;
	}

	/**
	 * Define LEVEL from argument
	 */
	const int LEVEL = atoi(argv[1]);
	const int LEVEL_MIN = 1;
	const int LEVEL_MAX = 4;
	if (LEVEL < LEVEL_MIN) {
		fprintf(stderr,"Too few LEVEL argument!\n");
		return 2;
	}
	if (LEVEL > LEVEL_MAX) {
		fprintf(stderr,"Too big LEVEL argument!\n");
		return 3;
	}

	/**
	 * Define PARAM from arguments
	 */
	const int PARAM = atoi(argv[2]);
	if (PARAM <= 0) {
		fprintf(stderr,"Too few PARAM argument! Must be bigger then zero.\n");
		return 4;
	}

	/**
	 * Define STATS from arguments
	 */
	const int STATS_ARGUMENT_POSITION = 4;
	bool show_stats = false;
	if (argc >= STATS_ARGUMENT_POSITION) {
//		if (argv[STATS_ARGUMENT_POSITION] == "--stats") {
		show_stats = true;
//		}
	}
	printf("show_stats: %d\n", show_stats);
//	printf("%d\n", is_small_letter('b'));
//	printf("%d\n", is_small_letter('B'));
//	printf("%d\n", is_big_letter('b'));
//	printf("%d\n", is_big_letter('B'));
//	printf("%d\n", is_number('B'));
//	printf("%d\n", is_number('8'));
//	printf("%d\n", is_special_char('!'));
//	printf("%d\n", is_special_char('s'));
	return 0;
}