
#include<stdio.h>
#include<stdlib.h>

void getElementArray(int* array, int size);

void showElementArray(int* array, const int size);

void sortArrayByASC(int* array, const int size);

int maxElementInArray(int* array, const int size);

double avgElementArray(int* array, const int size);

int findElementArray(int* array, int leftIndex, int rightIndex, int value);

void menu();



int main() {
	menu();
	return 0;
}

void getElementArray(int* array, int size) {
	printf("\nEnter value's elementsa in array: \n");

	for (int i = 0; i < size; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}

	puts(" ");
}

void showElementArray(int* array, const int size) {

	printf("\nAll of elements array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

}

void swap(int* number1, int* number2) {
	int tmp = *number1;
	*number1 = *number2;
	*number2 = tmp;
}

void sortArrayByASC(int* array, const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j >= i; j--) {
			if (array[j - 1] > array[j]) {
				swap(&array[j - 1], &array[j]);
			}
		}
	}

}



int maxElementInArray(int* array, const int size) {
	sortArrayByASC(array, size);
	return array[size - 1];
}

double avgElementArray(int* array, const int size) {
	int sum = sumElementArray(array, size);
	return (double)sum / size;
}

int sumElementArray(int* array, const int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

int findElementArray(int* array, int leftIndex, int rightIndex, int value) { // gia su array da sx tang dan

	while (leftIndex <= rightIndex) {
		int mid = leftIndex + (rightIndex - leftIndex) / 2;

		if (array[mid] == value) {
			return mid;
		}
		else if (array[mid] > value) {
			rightIndex = mid - 1;
		}
		else if (array[mid] < value) {
			leftIndex = mid + 1;
		}
	
	}
}



void menu() {

	int choice = 0;
	int size;
	int* array;

	printf("\nEnter size of array > 0 : ");
	scanf("%d", &size);

	if (size > 0) {

		array = (int*)malloc(size * sizeof(int));

		do {
			printf("\n================= ARRAY MANAGER =====================");
			printf("\n1. Get elements array.");
			printf("\n2. Display all elements array.");
			printf("\n3. Find max element in array.");
			printf("\n4. Calculate avg elements arrays.");
			printf("\n5. Find value in array.");
			printf("\n0. Exit.");
			printf("\n======================================================");

			printf("\nYour choice? ");
			scanf("%d", &choice);

			switch (choice) {
			case 0:
			{
				printf("\nThanks for using!");
				break;
			}
			case 1:
			{
				getElementArray(array, size);

				break;
			}
			case 2:
			{

  			   showElementArray(array, size);

				break;

			}
			case 3:
			{

				printf("\nMax element = %d", maxElementInArray(array, size));

				break;

			}
			case 4:
			{

				printf("\nAvg all elements array = %.2lf", avgElementArray(array, size));

				break;
			}
			case 5:
			{

				sortArrayByASC(array, size);

				int value;
				printf("\nEnter value that you want to search in array: ");
				scanf("%d", &value);

				int position = findElementArray(array, 0, size - 1, value);

				if (position == -1) {
					printf("\nDon't find %d in array.", value);
				}
				else {
					printf("\n%d has in array.", value);
				}

				break;
			}
			default:
			{
				printf("\nInvalid choice. Please try again!");
				break;
			}

			}

			

		} while (choice != 0);
	
		free(array);

	}
	else {
		printf("\nInvalid size of array. Please try again!");

	}

	}
	