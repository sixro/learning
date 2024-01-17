#include "ini_config.h"

#include <stdio.h>
#include <string.h>

typedef struct Entry {
	char property[50];
	char value[50];
} entry;

void fill(entry e, char * line)
{
	char * f;
	int idx;
	int len;
	
	len = strlen(line);
	f = strchr(line, (int) '=');
	
	idx = f - line;
	memcpy(e.property, &line[0], idx);
	e.property[idx] = '\0';

	memcpy(e.value, &f[1]);
}

char * ini_read(FILE * file, char * section, char * property)
{
	char * line = NULL;
	size_t line_cap = 0;
	ssize_t line_len;
	entry tmp_entry;

	while ((line_len = getline(&line, &line_cap, file)) > 0) {
		printf("Line length: %zu\n", line_len);
		printf("Line: %s\n", line);

		fill(tmp_entry, line);
		printf("prop: %s, value: %s", tmp_entry.property, tmp_entry.value);
	}

	printf("Returning %s\n", line);
	return line;
}

