#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void writeFile()
{
	FILE *fp;
	char buffer[1000];
	fp = fopen("paragraph.txt","w+");
	if(fp != NULL) 
	{
		printf("Enter the contents you wish to write to file :: \n");
		fgets(buffer, sizeof(buffer), stdin);
		fprintf(fp,"%s",buffer);
	}
	fclose(fp);
}

void readFile()
{
	FILE *fp;
	char buffer[1000];
	fp = fopen("paragraph.txt","r+");
	if(fp != NULL)
	{
		printf("The contents of the file are :: \n");
		while (fgets(buffer, 1000, fp) != NULL)
        	printf("%s", buffer);
	}
	fclose(fp);
}

void copyWords()
{
	FILE *fp,*wfp;
	char ch;
	char word[20];
	int i = 0;
	fp = fopen("paragraph.txt","r+");
	wfp = fopen("wordFile.txt","w+");
	if((fp != NULL) && (wfp != NULL))
	{
		while((ch=fgetc(fp)) != EOF)
		{
			if((ch == ' ') || (ch == '.') || (ch == ','))
			{
				word[i] = '\0';
				fprintf(wfp,"%s\n",word);
				i = 0;
			}
			else
			{
				word[i] = ch;
				i++;
			}
		}
	}
	fclose(fp);
	fclose(wfp);
}

void searchWord()
{
	FILE *fp;
	char searchWord[20];
	char word[20];
	char ch;
	int i = 0;
	int lineNumber = 1;
	printf("Enter the word you want to search :: ");
	scanf("%s",searchWord);
	fp = fopen("wordFile.txt","r+");
	if(fp != NULL)
	{
		while((ch=fgetc(fp)) != EOF)
		{
			if((ch == '\n'))
			{
				word[i] = '\0';
				if(strcmp(word,searchWord) == 0)
				{
					printf("Word found at line %d\n",lineNumber);
					return;
				}
				else
				{
					i = 0;
					lineNumber++;
				}
			}
			else
			{
				word[i] = ch;
				i++;
			}
		}
		printf("Word not found\n");
	}
}

int main()
{
	searchWord();
}
