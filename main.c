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
	FILE* indexFourthFile;
	FILE* indexFifthFile;
	FILE* indexSixthFile;
	FILE* indexSeventhFile;
	FILE* indexEigthFile;

	FILE* indexLastFile;
	
	FILE* imageFirstFile;
	FILE* imageSecondFile;

	FILE* allInfoFile;

	FILE* allTagsFile;
	FILE* weeksTagsFile;

	FILE* indexFile;
	FILE* imageFile;

	char command[MAX_COMMAND];
	char imagePath[MAX_PATH];

	char htmlReader[MAX_READER];
	char imageReader[MAX_READER];
	char imageInfoReader[MAX_READER];

	char htmlOneWriter[MAX_WRITER];
	char htmlTwoWriter[MAX_WRITER];
	char htmlThreeWriter[MAX_WRITER];
	char htmlFourWriter[MAX_WRITER];

	char htmlAddOneWriter[MAX_WRITER];
	char htmlAddTwoWriter[MAX_WRITER];
	char htmlAddThreeWriter[MAX_WRITER];
	char htmlAddFourWriter[MAX_WRITER];

	char thumbWriter[MAX_WRITER];
	char htmlWriter[MAX_WRITER];
	char previewWriter[MAX_WRITER];
	char imgCountWriter[MAX_WRITER];
	char imgWriter[MAX_WRITER];
	char imgInfoWriter[MAX_WRITER];

	char imgStackWriter1[MAX_STORAGE];
	char imgStackWriter2[MAX_STORAGE];
	char imgStackWriter3[MAX_STORAGE];
	char imgStackWriter4[MAX_STORAGE];
	char imgStackWriter5[MAX_STORAGE];
	char imgStackWriter6[MAX_STORAGE];

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
	indexFourthFile = fopen(PATH_INDEX_FOURTH, "r");
	indexFifthFile = fopen(PATH_INDEX_FIFTH, "r");
	indexSixthFile = fopen(PATH_INDEX_SIXTH, "r");
	indexSeventhFile = fopen(PATH_INDEX_SEVENTH, "r");
	indexEigthFile = fopen(PATH_INDEX_EIGTH, "r");

	indexLastFile = fopen(PATH_INDEX_LAST, "r");

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

	strcpy(htmlOneWriter, "\n<tr><img onclick=\"changePosition('img");
	strcpy(htmlTwoWriter, "')\" id=\"img");
	strcpy(htmlThreeWriter, "\" src=\"images/");
	strcpy(htmlFourWriter, "\" alt=\"Image Not Loaded\"/></tr>");

	strcpy(htmlAddOneWriter, "\\n<tr><img onclick=\\\"changePosition(\\'img");
	strcpy(htmlAddTwoWriter, "\\')\\\" id=\\\"img");
	strcpy(htmlAddThreeWriter, "\\\" src=\\\"images/");
	strcpy(htmlAddFourWriter, "\\\" alt=\\\"Image Not Loaded\\\"/></tr>");

	strcpy(thumbWriter, "Thumb/Thumb_");

	memset(imgStackWriter1, '\0', MAX_STORAGE);
	memset(imgStackWriter2, '\0', MAX_STORAGE);
	memset(imgStackWriter3, '\0', MAX_STORAGE);
	memset(imgStackWriter4, '\0', MAX_STORAGE);
	memset(imgStackWriter5, '\0', MAX_STORAGE);
	memset(imgStackWriter6, '\0', MAX_STORAGE);

	while(fscanf(allTagsFile, "%s", imgWriter) != EOF)
	{
		if(imgCount > 30)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter6, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else if(imgCount > 25)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter5, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else if(imgCount > 20)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter4, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else if(imgCount > 15)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter3, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else if(imgCount > 10)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter2, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else if(imgCount > 5)
		{
			strcpy(htmlWriter, htmlAddOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlAddThreeWriter);
			strcat(htmlWriter, thumbWriter);
			strcat(htmlWriter, imgWriter);
			strcat(htmlWriter, htmlAddFourWriter);

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

			fprintf(imageFile, "%s", "\"images/");
			fprintf(imageFile, "%s", imgWriter);
			fprintf(imageFile, "%s", "\"");

			while(fgets(htmlReader, MAX_BLOCK, imageSecondFile) != NULL)
			{
				fputs(htmlReader, imageFile);
			}

			if (imgCount == 1)
				strcpy(previewWriter, imgWriter);

			strcat(imgStackWriter1, htmlWriter);
			imgCount++;

			fclose(imageFile);
			fclose(imageFirstFile);
			fclose(imageSecondFile);
		}
		else
		{
			strcpy(htmlWriter, htmlOneWriter);

			sprintf(imgCountWriter, "%d", imgCount);
		
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlTwoWriter);
			strcat(htmlWriter, imgCountWriter);
			strcat(htmlWriter, htmlThreeWriter);
			strcat(htmlWriter, thumbWriter);
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
	
			fprintf(imageFile, "%s", "\"images/");
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

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter1);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexFourthFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter2);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexFifthFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter3);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexSixthFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter4);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexSeventhFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter5);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexEigthFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fprintf(indexFile, "\"");
	fprintf(indexFile, "%s", imgStackWriter6);
	fprintf(indexFile, "\";");

	while(fgets(htmlReader, MAX_BLOCK, indexLastFile) != NULL)
	{
		fputs(htmlReader, indexFile);
	}

	fclose(indexFirstFile);
	fclose(indexSecondFile);
	fclose(indexThirdFile);
	fclose(indexFourthFile);
	fclose(indexFifthFile);
	fclose(indexSixthFile);
	fclose(indexSeventhFile);
	fclose(indexEigthFile);

	fclose(indexLastFile);
	fclose(indexFile);
	fclose(allTagsFile);

	allTagsFile = fopen(PATH_ALL_TAGS, "r");
	allInfoFile = fopen(PATH_ALL_INFO, "r");

	while(fscanf(allTagsFile, "%s", imageReader) != EOF)
	{
		int i;

		fgets(imageInfoReader, MAX_READER, allInfoFile);
		
		i = strlen(imageInfoReader);
		imageInfoReader[i-1] = '\0';

		memset(imagePath, '\0', MAX_PATH);

		strcpy(imagePath, PATH_GRAPHIC_IMAGES);
		strcat(imagePath, imageReader);
		strcat(imagePath, ".html");

		imageFile = fopen(imagePath, "a");

		fprintf(imageFile, "\n\n<script>document.title = \"%s | Valualize Graphic\";</script>", imageInfoReader);
	}

	fclose(allTagsFile);

	return 0;
}

