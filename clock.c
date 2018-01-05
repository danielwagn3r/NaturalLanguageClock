// pwgen.c : Defines the entry point for the console application.
//

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "clock.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("wrong parameters!\n");

		usage();

		return EXIT_FAILURE;
	}

	unsigned long hours;
	unsigned long minutes;

	bool hours_valid = parse_number(argv[1], &hours);
	bool minutes_valid = parse_number(argv[2], &minutes);

	printf("hours: %lu(%s), minutes: %d(%s)\n", hours, hours_valid ? "true" : "false", minutes,
	       minutes_valid ? "true" : "false");

	if (!hours_valid || !minutes_valid)
	{
		usage();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


void usage()
{
	printf("Usage: clock.exe HOURS MINUTES\n");
}


bool parse_number(const char* input, unsigned long* number)
{
	const char* beginPtr = input;
	char* endPtr = NULL;

	*number = strtoul(beginPtr, &endPtr, 10);

	if (beginPtr == endPtr)
	{
		/* invalid  (no digits found, 0 returned */
		return false;
	}
	if (errno != 0)
	{
		/* some error occured */
		return false;
	}
	if (errno == 0 && beginPtr && !*endPtr)
	{
		/* valid  (and represents all characters read) */
		return true;
	}
	else if (errno == 0 && beginPtr && *endPtr != 0)
	{
		/* valid  (but additional characters remain) */
		return false;
	}

	return false;
}
