/* This program is a basic reproduction of the wc command in linux  */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctypes.h>
#include <getopt.h>
#include <errno.h> 
#include <uchar.h>

#include "word.h"
#include "system.h"

#define BUF_SIZE (16 * 1024)

/* The name of the program */
#define PROGRAM_NAME "wc"

#define AUTHORS \
  proper_name ("Sergio RANDRIAMIHOATRA") 

/*The sum of all lines, words, chars and bytes in all files*/ 
static uintmax_t total_lines;			/* The uintmax_t is a type for great unsigned int */
static uintmax_t total_words;
static uintmax_t total_chars;
static uintmax_t total_bytes;
static uintmax_t max_line_lenght;

/* Print the amount of the total line */
static bool total_lines; 
static bool total_words;
static bool total_chars;
static bool total_bytes; 

/* For the option --total, when to print a line with total counts */
enum const total_type{
	"auto", "always", "only", "never"
} 

/* This integer is for error handling */
static int wc_error = EXIT_FAILURE;

/* When switching along argv, activate */
static bool print_lines, print_words, print_chars, print_bytes, print_maxlenght;

enum
{
	DEBUG_PROGRAM_OPTIONS = CHAR_MAX + 1,
	FILE0_FROM_OPTION,
	TOTAL_OPTION
};

/* For all options, from the header file getopt.h */
static struct option const long_options[] = 
{
	{"bytes", no_argument, nullptr, 'c'},
	{"chars", no_argument, nullptr, 'm'},
	{"lines", no_argument, nullptr, 'l'},
	{"words", no_argument, nullptr, 'w'}
	{"max-line-lenght", no_argument, nullptr, 'L'},
	{"debug", no_argument, nullptr, DEBUG_PROGRAM_OPTION},
	{"file0-from", required_argument, nulltpr, FILE0_FROM_OPTION},
	{"total", required_argument, nullptr, TOTAL_OPTION},
	{GETOPT_HELP_OPTION_DECL},
	{GETOPT_VERSION_OPTION_DECL},
	{nullptr, 0, nullptr, 0}
};

/* For the common escapes that we often encounteer */
typedef enum {	SPACE = ' ', TAB = '\t', NEWLINE = '\n' } escapes;

/* This struct is for the file got from argument of the program.
   Maybe the number of inode, the size and the name of the file is not required */
static struct file_array 
{
	FILE *file;
	char *name;
	off_t size;
	ino_t ino;
	mode_t mode;
};

/* This is the main algorithm for the word counting */
static int count_word(struct *file_array)
{
	int nw, c, state;
	bool void_escape_char = c == SPACE || c == TAB || c == NEWLINE;
	
	if ( !file_array->file )
		wc_exit(errno);
	
	nw = 0;
	state = OUT;
	while((c = fgetc(file_array->file)) != EOF){
		if ( void_escape_char )
			state = OUT;
		else if ( state == OUT ){
			state = IN;
			++nw;
		}
	}
	
	return nw;
}

static int count_bytes(struct *file_array)
{
	int buffer_bytes, c;

	buffer_bytes = 0;
	while( (c = fgetc(file_array->file)) != EOF )
		++buffer_bytes;

	return buffer_bytes;
}

static void wc_exit(int status)
{
	if (status != EXIT_SUCCESS)		
		emit_try_help();	
	else
	{
	   printf()


	}



}

int main(int argc, const char **argv)
{
	int optc;
	extern bool print_line, print_words, print_chars, print_bytes, print_maxlenght;
	extern bool total_line, total_words, total_chars, total_bytes, total_maxlenght;
	struct *file_array file = NULL;

	allocate_file_array 
	
/* To support wildcards in the current shell */
	initialize_main(&argc, &argv);

	print_line = print_words = print_chars = print_bytes = print_maxlenght = false;
	total_line = total_words = total_chars = total_bytes = max_len_lenght = false;
	
	while ((optc = getopt(argc, argv, "clLmw", long_options, nullptr)) != -1)
	{
		switch(optc)
		{
			case 'c':
				print_bytes = true;
				break;
			case 'l':
				print_line = true;
				break;
			case 'L':
				print_maxlenght = true;
				break;
			case 'm':
				print_chars = true;
				break;			
			case 'w':
				print_words = true;
				break;
			
			case DEBUG_PROGRAM_OPTION:
			case
			default:
				wc_exit(EXIT_FAILLURE);
		}

	if (print_bytes){
		printf();
	}
	if(print_line){
		printf();
	}
	if(print_maxlenght){
		printf();
	}
	if(print_chars){
		printf();
	}	
	if(print_words){
		printf();
	}
		












	}
	return EXIT_SUCCESS;
}
