// C program for implementation of Bubble sort
#include <stdio.h>
#define SIZE 10
#include <time.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
int i, j,comparision;
for (i = 0; i < n-1; i++)

	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1]){
			swap(&arr[j], &arr[j+1]);
			comparision++;
		}
		return comparision;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d, ", arr[i]);
	printf("n");
}

// Driver program to test above functions
int main()
{
     int arr[SIZE];
     int comp, c1,c2,c3,c4;
    //int *aPtr = malloc(sizeof(int) * size);

    srand(time(NULL));
    int i;
    for (i = 0; i < SIZE; i++){
         arr[i] = rand() % 100;
         //printf("%15d\n", arr[i]);
    }

	//int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted Array\n");
	printArray(arr,n);
	printf("\n\n");

	comp = bubbleSort(arr, n);
	printf("Sorted array using bubble sort: \n");
	printArray(arr, n);
    printf("\n");
    //printf("Comparison completed during bubble sort %d\n\n",comp);

    comp = selectionSort(arr, n);
    printf("Sorted array using selection sort: \n");
    printArray(arr, n);
    printf("\n\n\n");
    //printf("Comparison completed during bubble sort %d\n",comp);

    //c1 = 1951585149;
    //c2 = 6356940;
    printf("Explanation for the relation between number of elements and number of exchanges for different algorithm\n\n");
    printf("Bubble sort algorithm requires a pair of nested loops. The outer loop must iterate once for each element for the given elements i.e, n times. while the inner loop iterates n times for first iteration , n-1 times for second iteration , n-2 times for third iteration and this process continues.\n");

 printf("For the first iteration of the outer loop, when we are trying to place the largest element in its correct position , n - 1 comparisons takes place i.e, the first comparison is made between the first and second elements, the second comparison is made between the second and third elements, and so on until the (n-1)th comparison is made between the (n-1)th and the nth element.\n");

printf("For the second iteration of the outer loop, there is no need to compare the against the last element of the list, because it was put in the correct position on the previous pass. Therefore, the second iteration requires only n-2 comparisons.\n");

printf("Similarly the third iteration requires (n-3) comparisons. and so on…\n\n\n\n");

printf("Selection sort is not difficult to analyze compared to other sorting algorithms since none of the loops depend on the data in the array. Selecting the lowest element requires scanning all n elements (this takes n − 1 comparisons) and then swapping it into the first position.\n Finding the next lowest element requires scanning the remaining n − 1 elements and so on, for (n − 1) + (n − 2) + ... + 2 + 1 = n(n − 1) / 2 ---->  (n^2) comparisons.");




	return 0;
}

int selectionSort(int arr[], int n)
{
    int i, j, min_idx, comparison;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx]){
            min_idx = j;
            comparison++;
          }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    return comparison;
}
