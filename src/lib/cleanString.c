#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

//Created by Vaan W. Waber
//Usage: char* = cleanString(char*);

char* cleanString(char* S_orig)
	{
	char* S_new = (char*)malloc(sizeof(char) * 100);
	int i = 0;
	int i2 = 0;

	for( i = 0; i <= strlen(S_orig); i++ )
		{
		if( ! (S_orig[i] == '.'
					|| S_orig[i] == '\"'
					|| S_orig[i] == '!'
					|| S_orig[i] == '?'
					|| S_orig[i] == '('
					|| S_orig[i] == ')'
					|| S_orig[i] == '['
					|| S_orig[i] == ']'
					|| S_orig[i] == '{'
					|| S_orig[i] == '}'
					|| S_orig[i] == ':'
					|| S_orig[i] == ';'
					|| S_orig[i] == '_'
					|| S_orig[i] == ',') )

			{
			S_orig[i] = tolower(S_orig[i]);
			S_new[i2] = S_orig[i];
			i2++;
			}
		}
	free(S_orig);
	return(S_new);
	}
