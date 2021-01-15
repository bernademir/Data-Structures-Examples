#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//insertion sort
void insertionSort(int arr[]) {

	clock_t start = clock();

	int temp;
	for (int i = 1; i < 1000; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}else
				break;
		}
	}
	for (int a = 0; a < 1000; a++) {
		printf("%d ", arr[a]);
	}
	clock_t finish = clock();
	double time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nInsertion Sort %f saniye surdu\n", time);
	system("pause");
}



//straight insertion sort
void straightInsSort(int arr[]){

	clock_t start = clock();
	for (int i = 1; i < 1000; i++) {
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
	for (int a = 0; a < 1000; a++) {
		printf("%d ", arr[a]);
	}
	clock_t finish = clock();
	double time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nStraight Insertion Sort %f saniye surdu\n", time);
	system("pause");
}

//binary insertion sort
void binaryInsSort(int arr[]) {

	clock_t start = clock();

	for (int i = 1; i < 1000; i++) {
		int x = arr[i];
		int down = 0;
		int top = i - 1;
		while (down <= top) {
			int pivot = (down + top) / 2;
			if (x < arr[pivot])
				top = pivot - 1;
			else
				down = pivot + 1;
		}
		for (int j = i - 1; j >= down; j--) {
			arr[j + 1] = arr[j];
			arr[down] = x;
		}
	}
	for (int a = 0; a < 1000; a++) {
		printf("%d ", arr[a]);
	}
	clock_t finish = clock();
	double time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nBinary Insertion Sort %f saniye surdu\n", time);
	system("pause");
}

//selection sort
void selectionSort(int arr[]) {

	clock_t start = clock();

	int temp;
	for (int i = 0; i < 1000; i++) {
		int min = i;
		for (int j = i + 1; j < 1000; j++) {
			if (arr[j] < arr[min])
				min = j;
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	for (int a = 0; a < 1000; a++) {
		printf("%d ", arr[a]);
	}
	clock_t finish = clock();
	double time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nSelection Insertion Sort %f saniye surdu\n", time);
	system("pause");
}

//bubble sort
void bubbleSort(int arr[]) {

	clock_t start = clock();

	int temp;
	for (int i = 1000; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int a = 0; a < 1000; a++) {
		printf("%d ", arr[a]);
	}
	clock_t finish = clock();
	double time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nBubble Sort %f saniye surdu\n", time);
	system("pause");
}

int main() {

	int arr[1000];

	for (int i = 0; i < 1000; i++) {
		arr[i] = rand() % 500;
	}

	printf("insertion sort: ");
	insertionSort(arr);
	
	printf("\nstraight insertion sort: ");
	straightInsSort(arr);
	
	printf("\nbinary insertion sort: ");
	binaryInsSort(arr);
	
	printf("\nselection sort: ");
	selectionSort(arr);
	
	printf("\nbubble sort: ");
	bubbleSort(arr);

	system("pause");
	return 0;
}