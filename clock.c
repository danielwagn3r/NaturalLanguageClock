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
		fputs("Wrong parameters specified!\n", stdout);
		usage();
		return EXIT_FAILURE;
	}

	unsigned long hours;
	unsigned long minutes;

	bool hours_valid = parse_number(argv[1], &hours);
	bool minutes_valid = parse_number(argv[2], &minutes);

	printf("hours: %lu(%s), minutes: %lu(%s)\n", hours, hours_valid ? "true" : "false", minutes,
	       minutes_valid ? "true" : "false");

	if (!hours_valid || hours < 0 || hours >= 24)
	{
		fputs("Invalid hour specified!\n", stdout);
		usage();
		return EXIT_FAILURE;
	}

	if (!minutes_valid || minutes < 0 || minutes >= 60)
	{
		fputs("Invalid minute specified!\n", stdout);
		usage();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


void usage()
{
	fputs("Usage: clock.exe HOURS MINUTES\n", stdout);
}


bool parse_number(const char* input, unsigned long* number)
{
	const char* beginPtr = input;
	char* endPtr = NULL;

	errno = 0;
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
	if (errno == 0 && beginPtr && *endPtr != 0)
	{
		/* valid  (but additional characters remain) */
		return false;
	}

	return false;
}
