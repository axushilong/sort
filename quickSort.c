

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


int partition(int *array, int left, int right)
{
    int i, m, temp;

    i = left;
    
    for(m = left;m < right;m++)
    {
        if (array[m] < array[right])
        {
            temp = array[i];
            array[i] = array[m];
            array[m] = temp;
            i++;
        }
    }
    temp = array[right];
    array[right] = array[i];
    array[i] = temp;

    return i;
}

void quickSort(int *array, int left, int right)
{
    int q;

    if (left < right)
    {
        q = partition(array, left, right);
        quickSort(array, q + 1, right);
        quickSort(array, left, q- 1);
        
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
    quickSort(array, 0, size - 1);
    thePrintf(array, size);
    free(array);
    getchar();
    return 0;
}
