#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/max.h"
#include "../header/path.h"

int main()
{
	FILE* imageFile;
	FILE* imageInfoFile;
	FILE* allTagsFile;

	char tagsReader[MAX_READER];
	char htmlReader[MAX_READER];
	char infoReader[MAX_READER];

	char titleWriter[MAX_WRITER];

	char imagePath[MAX_PATH];

	allTagsFile = fopen(PATH_ALL_TAGS, "r");
	imageInfoFile = fopen(PATH_ALL_INFO, "r");

	while(fscanf(allTagsFile, "%s", tagsReader) != EOF)
	{
		fgets(infoReader, MAX_READER, imageInfoFile);

		strcpy(imagePath, PATH_GRAPHIC_IMAGES);
		strcat(imagePath, tagsReader);
		strcat(imagePath, ".html");

		imageFile = fopen(imagePath, "rb+");

		while(fgets(htmlReader, MAX_READER, imageFile) != NULL)
		{
			if(strstr(htmlReader, "<title>") != NULL)
			{
				int i;

				i = strlen(infoReader);
				infoReader[i-1] = '\0';

				strcpy(titleWriter, infoReader);
				strcat(titleWriter, " | Valualize Graphic\n</title>");

				fprintf(imageFile, "%s", titleWriter);
			}
		}
	}

	return 0;
}
