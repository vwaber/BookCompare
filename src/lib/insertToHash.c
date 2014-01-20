#include <hash.h>

//Created by Vaan W. Waber 4/23/2010

void insertToHash(hashTable H, char* string)
{
	unsigned int tableSize = H[0].count;
	unsigned int index = hashFunction(string, tableSize);

	while(H[index].string != NULL)
	{
		if(!strcmp(H[index].string, string))
		{
			H[index].count ++;
			return;
		}
		index *= 73;
		if(index >= tableSize)
		{
			index = (index % (tableSize-1) ) + 1;
		}
	}

	H[index].string = strdup(string);
	H[index].count = 1;
}

