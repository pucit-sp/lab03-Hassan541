/*
**	This program is a template for SP lab 3 task 3 you are 
**	required to implement its one function.
*/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
*/
void mygrep(FILE*, char*);

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
** 	and char pointer as an third argument to replace the string finded with it.
*/
void myreplace(FILE *fp,char *find, char * replace);


int  main(int argc,char *argv[])
{


	/*	creating variables	*/

	int behaviour;
	int GREP = 10;
	int REPLACE = 11;
	FILE *fp;
	char *name = argv[0];
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	/*	check if mygrep is called or myreplace	*/

	/* check if the name of executable is mygrep */ 

	if(strcmp(name,"mygrep") == 0 || strcmp(name,"./mygrep") == 0)
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = GREP;
	}
	/*	check if the name of executable is myreplace	*/
	else if(strcmp(name,"myreplace") == 0 || strcmp(name,"./myreplace") == 0)
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = REPLACE;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}



	/* opening file	*/	
	fp=fopen(filename,"rt");

	if(behaviour == GREP)
	{
		mygrep(fp,find);		/*	caling function	*/
	}
	else if ( behaviour == REPLACE )
	{
		myreplace(fp,find,replace);		/*	calling myreplace	*/
	}
	
	fclose(fp);		/*	closing file	*/
	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];

	/*	Add code to get strings from file	*/ 
	
	/*	read a string from file	*/
	while(fgets(c1,500,fp) != NULL)
	{
	/*      Add your code here to search a string find on string c1 readed from file        */
		for(int i = 0; i < strlen(c1); i++)
			if(*find == c1[i])
				printf("%s\n",c1);
	}
}





void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500];
	int flen = strlen(find);

	while(fgets(c1, 500, fp) != NULL)
	{
	/*	Add your code here to search a string find on string c1 readed from file	*/
		for (int i = 0; i < strlen(c1); i++)
		{
			if (*find == c1[i])
			{
			/*	replace the finded string with replace string	*/
				char* word = (char*)malloc(strlen(c1) - flen + strlen(replace));
					
				printf("%s\n", c1);  //print original line in file
				strncpy(word, c1, i);
				strncpy(word + i, replace, strlen(replace));
				strncpy(word + i + strlen(replace), c1 + i + flen, strlen(c1) - (i + flen));
				
				printf("%s\n", word); //print after change word
			}
		}
	}
}


