#include <stdio.h>
#include <time.h>

void selectionSort(int array[], int arrayLength);

int main()
{
	// prepare the array with 1001 numbers, 0 included.
	// numbers are from -500 to 500.
	// numbers are added in pairs, one positive and one negative, or the array
	// will be the same after sorting.
	int data[1001] = {0};

	int numbers = 500;
	for (int i = 0; i < numbers; i++)
	{
		int index = 2 * i;
		int number = i + 1;

		data[index] = number;
		data[index + 1] = -number;
	}

	int dataLength = sizeof(data) / sizeof(int);

	// start the timer and sort
	clock_t start = clock();

	selectionSort(data, dataLength);

	clock_t end = clock();

	double time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;

	// we are done

	printf("Sorted in '%.2f' us, result:\n", time);
	for (int i = 0; i < dataLength; i++)
	{
		printf("%d\n", data[i]);
	}
}

// sort the array in place using the selection sort algorithm
// complexity: Θ(n^2): O(n^2) Ω(n^2)
void selectionSort(int array[], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		// find the index of the lesser value, starting from the current value index as
		// we don't need to look before it, the previous values are already sorted

		int lesserIndex = i;

		for (int j = i + 1; j < arrayLength; j++)
		{
			if (array[j] < array[lesserIndex])
			{
				lesserIndex = j;
			}
		}

		// if the index is not the same as the one we are checking, swap the values
		if (lesserIndex != i)
		{
			int current = array[i];

			array[i] = array[lesserIndex];
			array[lesserIndex] = current;
		}
	}
}
