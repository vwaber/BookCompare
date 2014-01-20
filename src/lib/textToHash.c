#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

hashTable textToHash(char* fileName)
	{

	FILE* textFile = fopen(fileName, "r");
	if(textFile == NULL)
		{
		printf("Error: File Not Found\n");
		exit(1);
		}

	fseek(textFile, 0, SEEK_END);
	unsigned int size = ftell(textFile);
	fseek(textFile, 0, SEEK_SET);

	hashTable H = createEmptyHash(size);

	char* word = (char*)malloc(sizeof(char) * 100);

	while(fscanf(textFile, "%s", word) != EOF)
		{
		word = cleanString(word);
		if(strcmp("", word))
			{
			insertToHash(H, word);
			}
		}
	fclose(textFile);
	return(H);
	}

