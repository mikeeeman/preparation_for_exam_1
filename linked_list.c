/*
 * linked_list.c
 *
 *  Created on: 17.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELN 20
#define PHONELN 11
#define MAX 2

struct person
{
	char name[NAMELN];
	char phone[PHONELN];
	struct person *next;
};
typedef struct person PERSON;

int main(void)
{
	setbuf(stdout, NULL);
	PERSON *head = NULL;
	PERSON *new = NULL;
	PERSON *tmpVor = NULL;
	PERSON *tmpRuck = NULL;
	int cnt = 0;

	for(cnt = 0 ; cnt < MAX ; cnt++)
	{
		if((new = (PERSON*)malloc(sizeof(PERSON))) == NULL)
		{
			fprintf(stderr, "Failed to allocate memory!");
			exit(-1);
		}
		printf("Enter a name (Max length is %d)\n", NAMELN);
		fgets(new->name, NAMELN, stdin);
		fflush(stdin);
		strtok(new->name, "\r");
		printf("Enter a phone number (Max length is %d)\n", PHONELN);
		fgets(new->phone, PHONELN, stdin);
		fflush(stdin);
		strtok(new->phone, "\r");

		tmpVor = head;
		if(head == NULL)
		{
			new->next = NULL;
			head = new;
		}
		while(tmpVor->next != NULL)
		{
			if(strcmp(tmpVor->name,new->name) < 0)
			{
				new->next = tmpVor;

			}
		}



		else if(tmpVor->next != NULL)
		{
			while((strcmp(new->name,tmpVor->name)) > 0)
			{
				tmpRuck = tmpVor;
				tmpVor = tmpVor->next;
			}
			new->next = tmpVor;
			tmpRuck->next = new;
		}
		else
		{
			new->next = tmpVor->next;
			tmpVor->next = new;
		}
	}
	for(cnt = 1 ; cnt <= MAX ; cnt++)
	{
		tmpVor = head;
		while(tmpVor->next != NULL)
		{
			fprintf(stdout, "Person %d\nName:\t%s\nPhone:\t%s\n", cnt, tmpVor->name, tmpVor->phone);
			tmpVor = tmpVor->next;
		}
	}

	return EXIT_SUCCESS;
}

