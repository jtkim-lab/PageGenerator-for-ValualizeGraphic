#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/path.h"
#include "header/max.h"

int main()
{
	FILE* headFile;

	FILE* indexFirstFile;
	FILE* indexSecondFile;
	FILE* indexThirdFile;
	FILE* imageFirstFile;
	FILE* imageSecondFile;

	FILE* allTagsFile;
	FILE* weeksTagsFile;

	FILE* indexFile;
	FILE* imageFile;

	char command[MAX_COMMAND];
	char imagePath[MAX_PATH];

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

	headFile = fopen(PATH_HEAD, "r");

	indexFirstFile = fopen(PATH_INDEX_FIRST, "r");
	indexSecondFile = fopen(PATH_INDEX_SECOND, "r");
	indexThirdFile = fopen(PATH_INDEX_THIRD, "r");

	allTagsFile = fopen(PATH_ALL_TAGS, "r");

	indexFile = fopen(PATH_INDEX, "w");

	while(fgets(htmlReader, MAX_BLOCK, headFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fclose(headFile);

	while(fgets(htmlReader, MAX_BLOCK, indexFirstFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	strcpy(htmlOneWriter, "\n<tr><img onmouseover=\"changePosition('img");
	strcpy(htmlTwoWriter, "')\" id=\"img");
	strcpy(htmlThreeWriter, "\" src=\"images\\");
	strcpy(htmlFourWriter, "\" alt=\"Image Not Loaded\"/></tr>");

	while(fscanf(allTagsFile, "%s", imgWriter) != EOF)
	{
	//	if(imgCount > 5)
	//		break;

		strcpy(htmlWriter, htmlOneWriter);

		sprintf(imgCountWriter, "%d", imgCount);
		
		strcat(htmlWriter, imgCountWriter);
		strcat(htmlWriter, htmlTwoWriter);
		strcat(htmlWriter, imgCountWriter);
		strcat(htmlWriter, htmlThreeWriter);
		strcat(htmlWriter, imgWriter);
		strcat(htmlWriter, htmlFourWriter);

		strcpy(imagePath, PATH_GRAPHIC_IMAGES);
		strcat(imagePath, imgWriter);
		strcat(imagePath, ".html");

		imageFile = fopen(imagePath, "w");

		headFile = fopen(PATH_HEAD, "r");
		imageFirstFile = fopen(PATH_IMAGE_FIRST, "r");
		imageSecondFile = fopen(PATH_IMAGE_SECOND, "r");

		while(fgets(htmlReader, MAX_BLOCK, headFile) != NULL)
		{
			fputs(htmlReader, imageFile);
		}

		fclose(headFile);

		while(fgets(htmlReader, MAX_BLOCK, imageFirstFile) != NULL)
		{
			fputs(htmlReader, imageFile);
		}

		fprintf(imageFile, "%s", "\"images\\");
		fprintf(imageFile, "%s", imgWriter);
		fprintf(imageFile, "%s", "\"");

		while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
		{
			fputs(htmlReader, imageFile);
		}

		if (imgCount == 1)
			strcpy(previewWriter, imgWriter);

		fprintf(indexFile, "%s", htmlWriter);
		imgCount++;

		fclose(imageFile);
		fclose(imageFirstFile);
		fclose(imageSecondFile);
	}

	while(fgets(htmlReader, MAX_BLOCK, indexSecondFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "%s", "\"images/");
	fprintf(indexFile, "%s", previewWriter);
	fprintf(indexFile, "%s", "\" alt=\"No Image Loaded\"/ onclick=\"clickImage()\">\n\n");

	while(fgets(htmlReader, MAX_BLOCK, indexThirdFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fclose(indexFirstFile);
	fclose(indexSecondFile);
	fclose(indexThirdFile);
	fclose(indexFile);
	fclose(allTagsFile);

	return 0;
}

