#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buff;


void flag()
{

	printf("{\\__/}\n");
    printf("( • . •)\n");
    printf("/ >(flag)   - u want this?\n\n");
}
void hmm()
{
	setjmp(buff);
}

void hmmm()
{
	char lol[0x200];
	hmm();
}

void jump_buffer()
{
	longjmp(buff, 1);
}

void shoo()
{
	char name[0x250];
	printf("What the... \n");
	printf("You shouldn't be here! \n");
	printf("What are you doing at %p\n", name);
	read(0, name, 0x250 - 1);
	name[0x250 - 1] = 0;

	printf("Shoo! Shoo! %s\n", name);
}

void options()
{

	printf("Will you skip, will you jump, or will you go away? \n");
	printf("Input 1 to skip: \n");
	printf("Input 2 to jump: \n");
	printf("Input 3 to go away: \n");
}

int main()
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	while (1)
	{
		int selected;
		options();
		printf(">>> ");
		scanf("%d%*c", &selected);

		
		switch (selected)
		{
		case 1:
		{
			hmmm();
			break;
		}
		case 2:
		{
			jump_buffer();
			break;
		}
		case 3:
		{
			shoo();
			break;
		}
		default:
		{
			exit(0);
		}
		}
	}
}
