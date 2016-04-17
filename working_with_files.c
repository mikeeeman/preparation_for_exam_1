/*
 * working_with_files.c
 *
 *  Created on: 17.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

int main(void)
{
	setbuf(stdout, NULL);

	FILE *fp;
	char string[SIZE];

	if((fp = fopen("list2.txt", "r+")) == NULL)
	{
		fprintf(stderr, "\nError opening file");
		exit(1);
	}
	fprintf(stdout, "Enter some data:\n");
	fgets(string, SIZE, stdin);
	strtok(string, "\r");
	fflush(stdin);
	fprintf(fp, "%s", string);
	fread()



	fclose(fp);
	return EXIT_SUCCESS;
}

