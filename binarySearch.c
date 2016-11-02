

#include <stdio.h>

int binarySearch(int a[], int size, int k)
{
	int left, right, mid;
	int count = 0;

	left = 0;
	right = size - 1;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if (k < a[mid])
		{
			right = mid - 1;
		}
		else if (k > a[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	printf ("Not Found.\r\n");
	return -1;
}


int main(void)
{
	int array[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,  12, 13, 16};
	int i;

	for (i = 0;i < sizeof(array)/sizeof(array[0]);i++)
	{
		printf ("Key value:%d\r\n", array[i]);
		binarySearch(array, sizeof(array) / sizeof(array[0]), array[i]);
		printf ("\r\n\r\n");
	}
	binarySearch(array, sizeof(array) / sizeof(array[0]), 14);
	binarySearch(array, sizeof(array) / sizeof(array[0]), 17);
	binarySearch(array, sizeof(array) / sizeof(array[0]), 0);
	getchar();

}
