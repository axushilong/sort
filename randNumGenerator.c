

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE *thisFile;
	int size, flag = 1, *array, value, i;

	thisFile = fopen("randNums.txt", "wb");
	if (NULL == thisFile)
	{
		fprintf (stderr, "File Open Error.\r\n");

		return -1;
	}
	while(flag)
	{
		printf ("Rand Numbers: ");
		scanf("%d", &size);
		if (size < 1)
		{
			printf ("Error Size, Input ");
		}
		else
		{	
			fprintf (thisFile, "%d \r\n", size);
			for (i = 0;i < size;i++)
			{
				value = rand() % size;
				fprintf (thisFile, "%d ", value);
			}
			break;
		}
	}

	fclose(thisFile);
	return 0;
}
