#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	float number ;
	int i;
	if(argc == 1)
		printf("\nNo command line give.\n");
	if(argc>=2)
	{
		for(i=0;i<argc;i++)
			number = number+ atof(argv[i]);
		printf("%.4e",number);
		printf("\n");
	}
	return 0;
}
