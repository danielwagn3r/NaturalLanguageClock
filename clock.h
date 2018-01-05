#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <stdbool.h>

int main(int argc, char** argv);

bool parse_number(const char* input, unsigned long* number);

void usage();

char* hour_table[] =
{
	"midnight",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"noon"
};

char* suffix_table[] =
{
	"o'clock in the morning",
	"o'clock in the afternoon"
};

#endif