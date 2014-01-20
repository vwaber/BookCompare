#include <hash.h>
#include <math.h>

//Created by Vaan W. Waber 4/23/2010

#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )

double computeSimilarity(hashTable H0, hashTable H1)
	{

	unsigned int minSize = min(H0[0].count, H1[0].count);

	hashTable minHash;
	hashTable maxHash;

	if(minSize == H0[0].count)
		{
		minHash = H0;
		maxHash = H1;
		}
	else
		{
		minHash = H1;
		maxHash = H0;
		}

	double overlapProd = 0;
	double overlapMax = 0;
	double m = 0;
	int i;

	for(i = 1; i < minHash[0].count; i ++)
	{
		if(minHash[i].string != NULL)
		{
			unsigned int index;
			index = hashFunction(minHash[i].string, minHash[0].count);
			while(maxHash[index].string != NULL)
			{
				if(!strcmp(minHash[i].string, maxHash[index].string))
				{
					overlapProd += (minHash[i].count*maxHash[index].count);
					m = max(minHash[i].count, maxHash[index].count);
					overlapMax += (m*m);
					break;
				}
				else
				{
					index *= 73;
					if(index >= minHash[0].count)
					{
						index = (index % (minHash[0].count-1) ) + 1;
					}
				}
			}
		}
	}

	double similarity = sqrt(overlapProd/overlapMax);

	return(similarity);
	}
