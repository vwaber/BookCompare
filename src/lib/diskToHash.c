#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

hashTable diskToHash(char* fileName)
	{


		FILE* textFile = fopen(fileName, "r");
		if(textFile == NULL)
			{
			printf("Error: File Not Found\n");
			exit(1);
			}

		char* word = (char*)malloc(sizeof(char) * 100);

		fscanf(textFile, "%s", word);
		fscanf(textFile, "%s", word);
		fseek(textFile, 0, SEEK_SET);

		unsigned int size = atoi(word);

		hashTable H = createEmptyHash(size);

		unsigned int i = 0;

		while(!feof(textFile))
			{
			fscanf(textFile, "%s", word);
			if(strcmp(word, "*-*-*-*"))
				{
				H[i].string = strdup(word);
				}
			fscanf(textFile, "%s", word);
			H[i].count = atoi(word);
			i ++;
			}

		return(H);
	}
