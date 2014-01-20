#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

hashTable createEmptyHash(unsigned int size)
	{

	double prime = size/73.0;
	if(prime == (int)prime)
		{
		size ++;
		}

	hashTable H = malloc(sizeof(hashElement) * size);
	if(H == NULL)
		{
		printf("Hash Malloc Failed");
		exit(1);
		}

	int i;
	for(i = 0; i < size; i ++)
		{
		H[i].string = NULL;
		H[i].count = 0;
		}
	H[0].count = size;
	return(H);
	}

