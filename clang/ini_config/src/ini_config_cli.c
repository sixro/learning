#include <stdio.h>
#include <stdlib.h>

#include "ini_config.h"

int main() {
	FILE * file = fopen("test/example.ini", "r");
	char * property = ini_read(file, "owner", "name");
	printf("READ FINISHED");
	printf("%s", property);
	return EXIT_SUCCESS;
}
