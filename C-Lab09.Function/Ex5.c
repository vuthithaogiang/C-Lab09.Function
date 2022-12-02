
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

void init(int* array, int size);

void showElementArray(int* array, int size);

int getMax(int* array, int size);

double getAvg(int* array, int size);

void findValue(int* array, int size);

void menu();


int main() {
	menu();
	return 0;
}

void init(int* array, int size) {
	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 6;
	}

}
void showElementArray(int* array, int size) {
	printf("\nAll of elements in array: \n");

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	puts(" ");
}


int getMax(int* array, int size) {

	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
}

int sumElementArray(int* array, int size) {
	int sum = 0; 

	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum;
}

double getAvg(int* array, int size) {

	int sum = sumElementArray(array, size);

	return (double)sum / size;
}

bool searchNumberInArray(int* array, int size, int value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return true;
		}
	}
	return false;
}


int countElementInArray(int* array, int size, int value) {
	int count = 0;
	if (searchNumberInArray(array, size, value)) {
		for (int i = 0; i < size; i++)
		{
			if (array[i] == value) {
				count++;
			}
		}

	}
	return count;
	
}
void findValue(int* array, int size) {
	int value;
	printf("\nEnter value that you want to search: ");
	scanf("%d", &value);

	if (searchNumberInArray(array, size, value) == false) {
		printf("\nDon't find number %d in array.", value);
	}
	else {
		int count = countElementInArray(array, size, value);

		printf("\nFind %d in array %d position: ", value, count);

		for (int i = 0; i < size; i++) {
			if (array[i] == value) {
				printf("%d  ", i + 1);
			}
		}
	}
	puts(" ");
}

void menu() {

	int size = 20;

	int* array;
	array = (int*)malloc(size * sizeof(int));

	init(array, size);

	showElementArray(array, size);

	printf("\n Max element in array = %d ", getMax(array, size));

	printf("\n Avg all elements array = %.2lf", getAvg(array, size));

	findValue(array, size);



	free(array);
	
}