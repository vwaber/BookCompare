#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

void hashToDisk(hashTable H, char* fileName)
	{
		int i;

		FILE *textFile;
		textFile = fopen(fileName, "w");
		if(textFile == NULL)
			{
			printf("Error: File Not Found");
			exit(1);
			}

	for(i = 0; i < H[0].count; i ++)
		{
		if(H[i].string != NULL)
			{
			fprintf(textFile, "%s ", H[i].string);
			}
		else
			{
			fprintf(textFile,"*-*-*-* ");
			}

		fprintf(textFile, "%i\n", H[i].count);
		}
	fclose(textFile);
	}

