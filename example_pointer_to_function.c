/*
 * example_pointer_to_function.c
 *
 *  Created on: 17.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int square(int x);
int hoch3(int x);

int main(void)
{

	strcmp()
	setbuf(stdout, NULL);

	int (*ptr)(int x);
	int choice;
	int zahl;

	fprintf(stdout, "Willst du quadrat ode hoch3?\n1 = quadrat ; 2 = hoch3\n");
	fscanf(stdin, "%d", &choice);
	fflush(stdin);
	if(choice == 1)
	{
		ptr = square;
	}
	else if(choice == 2)
	{
		ptr = hoch3;
	}
	else
	{
		puts("Wrong choice!");
		exit(1);
	}
	fprintf(stdout, "Gib eine Zahl zum verrechnen ein: \n");
	fscanf(stdin, "%d", &zahl);
	fflush(stdin);
	fprintf(stdout, "%d", ptr(zahl));

	return 0;
}

int square(int x)
{
	return x * x;
}

int hoch3(int x)
{
	return x * x * x;
}


