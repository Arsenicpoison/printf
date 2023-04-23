#include "main.h"
#include <stdio.h>

int test_string(char *string)
{
	int test = 0;
	int vari = 0;
	
	if(string)
	{
		while(string[test] != '\0')
		{
			putchar(string[test]);
			vari += 1;
			test++;
		}
	}
	return (vari);
}

