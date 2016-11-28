#include <stdio.h>

void thePrintf(int array[], int size)
{
    int i;

    for (i = 0;i < size;i++)
    {
        printf ("%d ", array[i]);
    }
    printf ("\r\n\r\n");
}



void shellSort (int array[], int size)
{
    int gap, i,n, valueFlag;

    for (gap = size >> 1;gap > 0;gap >>= 1)
    {
        for (i = gap;i < size;i++)
        {
            valueFlag = array[i];
            for (n = i - gap;n >= 0 && array[n] > valueFlag;n -= gap)
            {
                array[n + gap] = array[n];
            }   
            array[n + gap] = valueFlag;
        }
    }
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
    shellSort(array, size);
    thePrintf(array, size);
    free(array);
    getchar();
    return 0;
}
