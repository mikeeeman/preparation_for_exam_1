/*
 * bobble_sort.c
 *
 *  Created on: 17.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define NAMELENGTH 20

int main(void)
{
	setbuf(stdout, NULL);

	char *names[SIZE];
	char input[NAMELENGTH];
	int cnt, cnt2;
	char *tmp;

	fprintf(stdout, "Enter %d Names, sperated by enter. (All in lower case and Max Name length is %d)\n", SIZE, NAMELENGTH);
	for(cnt = 0 ; cnt < SIZE ; cnt++)
	{
		fgets(input, NAMELENGTH , stdin);
		fflush(stdin);
		strtok(input, "\r");
		if((names[cnt] = (char*)malloc(strlen(input)+1)) == NULL)
		{
			puts("Error allocating memory");
			exit(-1);
		}
		strcpy(names[cnt], input);
	}

	for(cnt = 0 ; cnt < SIZE ; cnt++)
	{
		for(cnt2 = 0 ; cnt2 < SIZE-1 ; cnt2++)
		{
			if((strcmp(names[cnt2],names[cnt2+1])) > 0)
			{
				tmp = names[cnt2];
				names[cnt2] = names[cnt2+1];
				names[cnt2+1] = tmp;
			}
		}
	}
	for(cnt = 0 ; cnt < SIZE ; cnt++)
	{
		fprintf(stdout, "%s\n", names[cnt]);
	}


	return EXIT_SUCCESS;
}

