
//Contributors
//G. Poppe

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

char *randomString(char *p);
char *shiftString(char *p, int choice);

int main(int argc, char *argv[])
{
	int choice;
	char name[256];
	
	srand(time(NULL));
	printf("Please enter your name: "); //Input any number of array inputs
	scanf("%s",name);

	printf("Hello %s welcome to the rpgGame!\n",name);

	while(choice != 99)
	{
		puts("You find yourself in a dark room and you are not sure how you got here.");
        	puts("As you look around you see the room has 40 doors, each labeled with a number. You are not sure how such a small room can have 40 doors, sooo magic...");
        	puts("The room starts filling with water and you must choose a door to open or you will likely drown. you may quit anytime by selecting option 99");
        	puts("What door do you choose?");
        	scanf("%d",&choice);

		switch(choice)
		{
			case 32:
			{
				while(choice != 99)
				{
					int total, countA, countB;
					double avg;
					puts("You are safe from the water, but strange random strings start to attack. What do you do?");
					while(choice != 99)
					{
						char *ptr;
						char randStr[11] = "";
						puts("1. Smack the string in the leftmost bit");
						puts("2. Kick the string in the rightmost bit");
						puts("99. Exit Room");
						scanf("%d", &choice);
						switch(choice)
						{
							case 1:
								ptr = randomString(randStr);
								printf("String %s approaches you and you smack it!\n", ptr);
								ptr = shiftString(ptr, 1);
								printf("The string is confused and altered to %s \n", ptr);
								countA++;
								total++;
								avg = (double)countA/(double)total;
								printf("Your average choice for smacking strings is %.2f \n", avg);
								break;
							case 2:
								ptr = randomString(randStr);
								printf("String %s approaches you and you kick it!\n", ptr);
								ptr = shiftString(ptr, 2);
								printf("The string is confused and altered to %s \n", ptr);
								countB++;
								total++;
								avg = (double)countB/(double)total;
								printf("Your average choice for kicking strings is %.2f \n", avg);
								break;
							case 99:
								break;
							default:
								puts("You can't do that.");
								break;
						}
					}
				}
				break;
			}
		}	
	}
	return EXIT_SUCCESS;
}

char *randomString(char *p)
{
	int randLine = rand() % 100;
	int i = 0;
	FILE *rfPtr;

	if((rfPtr = fopen("randomStrings.txt", "r")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		while(fgets(p, 11, rfPtr) != NULL)
		{
			if(i == randLine)
			{
				fclose(rfPtr);
				return p;
			}
			else
			{
				i++;
			}
		}
		fclose(rfPtr);
	}
	return p;
}

char *shiftString(char *p, int choice)
{
	int i;
	if(choice == 1)
	{
		for(i = 0; i < strlen(p); i++)
		{
			p[i] = p[i] + 4;
		}
	}
	if(choice == 2)
	{
		for(i = 0; i < strlen(p); i++)
		{
			p[i] = p[i] - 4;
		}
	}
	return p;
}
