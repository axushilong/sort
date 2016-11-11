

#include <stdio.h>
#include <math.h>


void thePrintf(int array[], int size)
{
    int i;

    for (i = 0;i < size;i++)
    {
        printf ("%d ", array[i]);
    }
    printf ("\r\n\r\n");
}


int insertSort(int *array, int arraySize)
{
    int i, m, temp;

    for (i = 1;i < arraySize;i++)
    {
        temp = array[i];
        m = i - 1;
        for(;m >= 0 && temp < array[m];m--)
        {
           array[m + 1] = array[m];
        }
        array[m + 1] = temp;
    }
    return 1;
}


int main (void)
{
    FILE *thisArray;
    int *array, size, i, value;
    char thisString[128];
    
    thisArray = fopen("randNums.txt", "rb");
    if (NULL == thisArray)
    {
        fprintf (stderr, "File Open Error.\r\n");
        return -1;
    }

    fscanf(thisArray, "%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if (NULL == array)
    {
        fprintf (stderr, "Malloc Array Error.\r\n");
        return -1;
    }
    for (i = 0;i < size;i++)
    {
        fscanf (thisArray, "%d", &value);
        array[i] = value;
    }

    thePrintf(array, size);
    insertSort(array, size);
    thePrintf(array, size);
    free(array);
    getchar();
    return 0;
}
