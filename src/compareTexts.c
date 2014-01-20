#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include "hash.h"

int main(int argc, char **argv)
	{
		
	int rank;
        int size;
        MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int i;
	int check = 0;
	char** books = (char**)malloc(sizeof(char*) * 40);
	char* word = (char*)malloc(sizeof(char)*100);
	int BOOK = 0;
	int numBooks = 40;

	FILE* textFile = fopen(argv[1], "r");
	if(textFile == NULL)
		{
		printf("Error: File Not Found\n");
		exit(1);
		}

	int b = 0;
	while(fscanf(textFile, "%s", word) != EOF)
		{
		books[b] = strdup(word);
		b ++;
		}
	fclose(textFile);	

					    

	if(rank != 0)
		{
		for(BOOK = (rank-1); BOOK < numBooks; BOOK += (size - 1))
			{
			char bookName[50] = "C_";
			strcat(bookName, books[BOOK]);
			hashTable textHash = textToHash(books[BOOK]);
			hashToDisk(textHash, bookName);
			free(textHash);
			}
		
		MPI_Send(&check, 1, MPI_INT, 0, 11, MPI_COMM_WORLD);
		}
	else
		{
		for(i = 1; i < size; i ++)
			{
			MPI_Recv(&check, 1, MPI_INT, i, 11, MPI_COMM_WORLD, &status);
			}
		}

		if(rank == 0)
			{
			check = 1;
			}

        	MPI_Bcast(&check, 1, MPI_INT, 0, MPI_COMM_WORLD);

		while(check != 1);

	
		
	if(rank != 0)
		{
		int k;
		for(BOOK = (rank-1); BOOK < numBooks; BOOK += (size - 1))
			{
			for(k = 0; k < numBooks; k ++)
				{
				char bookName0[50] = "C_";
				char bookName1[50] = "C_";
				strcat(bookName0, books[BOOK]);
				strcat(bookName1, books[k]);
				hashTable H0 = diskToHash(bookName0);
				hashTable H1 = diskToHash(bookName1);
				double similarity;
				similarity = computeSimilarity(H0, H1);
				printf("%10s vs %10s: %10f\n", books[BOOK], books[k], similarity);
				free(H0);
				free(H1);
				}
			}
		}
		
		//Start Comparing Books

	//hashTable textHash0 = textToHash(argv[1]);
	//hashTable textHash1 = textToHash(argv[2]);

	//double similarity;

	//similarity = computeSimilairty(textHash0, textHash1);
	//printf("%f\n", similarity);

	//hashToDisk(textHash0, "hash1.txt");

	//hashTable textHash1 = diskToHash("hash1.txt");

	//hashToDisk(textHash1, "hash2.txt");


	MPI_Finalize();
	}


