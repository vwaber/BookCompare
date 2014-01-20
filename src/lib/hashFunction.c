#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

unsigned int hashFunction(char *key, unsigned int tableSize)
	{
	unsigned int hashVal = 0;

	while( *key != '\0' )
		{
		hashVal += *key++;
		}
	hashVal *= 43;
	unsigned int index =(hashVal % (tableSize-1) ) + 1;
	return(index);
	}

