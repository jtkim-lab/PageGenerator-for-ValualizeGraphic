#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/path.h"
#include "header/max.h"

int main()
{
	FILE* indexFrontFile;
	FILE* indexLastFile;

	FILE* indexFile;

	char htmlReader[MAX_READER];

	indexFrontFile = fopen(PATH_INDEX_FRONT, "r");
	indexLastFile = fopen(PATH_INDEX_LAST, "r");

	indexFile = fopen(PATH_INDEX, "w");

	while(fgets(htmlReader, MAX_BLOCK, indexFrontFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	return 0;
}

