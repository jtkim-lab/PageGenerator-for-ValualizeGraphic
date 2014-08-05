#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/path.h"
#include "header/max.h"

int main()
{
	FILE* indexFrontFile;
	FILE* indexMiddleFile;
	FILE* indexLastFile;

	FILE* allTagsFile;
	FILE* weeksTagsFile;

	FILE* indexFile;

	char command[MAX_COMMAND];

	char htmlReader[MAX_READER];

	char htmlOneWriter[MAX_WRITER];
	char htmlTwoWriter[MAX_WRITER];
	char htmlThreeWriter[MAX_WRITER];
	char htmlFourWriter[MAX_WRITER];

	char htmlWriter[MAX_WRITER];
	char previewWriter[MAX_WRITER];
	char imgCountWriter[MAX_WRITER];
	char imgWriter[MAX_WRITER];
	
	int imgCount = 1;

	strcpy(command, "cp -r ");
	strcat(command, PATH_IMAGES);
	strcat(command, "* ");
	strcat(command, PATH_GRAPHIC_IMAGES);
	system(command);

	indexFrontFile = fopen(PATH_INDEX_FRONT, "r");
	indexMiddleFile = fopen(PATH_INDEX_MIDDLE, "r");
	indexLastFile = fopen(PATH_INDEX_LAST, "r");

	allTagsFile = fopen(PATH_ALL_TAGS, "r");

	indexFile = fopen(PATH_INDEX, "w");

	while(fgets(htmlReader, MAX_BLOCK, indexFrontFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	strcpy(htmlOneWriter, "\n<img onmouseover=\"changePosition('img");
	strcpy(htmlTwoWriter, "')\" id=\"img");
	strcpy(htmlThreeWriter, "\" src=\"images\\");
	strcpy(htmlFourWriter, "\" alt=\"Image Not Loaded\"/>");

	while(fscanf(allTagsFile, "%s", imgWriter) != EOF)
	{
		strcpy(htmlWriter, htmlOneWriter);

		sprintf(imgCountWriter, "%d", imgCount);
		
		strcat(htmlWriter, imgCountWriter);
		strcat(htmlWriter, htmlTwoWriter);
		strcat(htmlWriter, imgCountWriter);
		strcat(htmlWriter, htmlThreeWriter);
		strcat(htmlWriter, imgWriter);
		strcat(htmlWriter, htmlFourWriter);

		if (imgCount == 1)
			strcpy(previewWriter, imgWriter);

		fprintf(indexFile, "%s", htmlWriter);
		imgCount++;
	}

	while(fgets(htmlReader, MAX_BLOCK, indexMiddleFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "%s", "\"images/");
	fprintf(indexFile, "%s", previewWriter);
	fprintf(indexFile, "%s", "\" alt=\"No Image Loaded\"/ onclick=\"clickImage()\">\n\n");

	while(fgets(htmlReader, MAX_BLOCK, indexLastFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	return 0;
}

