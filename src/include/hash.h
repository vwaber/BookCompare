#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct hashElementStruct
	{
	char* string;
	unsigned int count;
	unsigned int hashSize;
	};
typedef struct hashElementStruct hashElement;
typedef struct hashElementStruct* hashTable;


char* cleanString(char* S_orig);
hashTable textToHash(char* fileName);
hashTable createEmptyHash(unsigned int size);
unsigned int hashFunction(char *key, unsigned int tableSize);
void insertToHash(hashTable H, char* string);
void hashToDisk(hashTable H, char* fileName);
hashTable diskToHash(char* fileName);
double computeSimilarity(hashTable H0, hashTable H1);

