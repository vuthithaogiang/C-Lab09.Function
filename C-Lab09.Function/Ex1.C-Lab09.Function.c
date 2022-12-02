// C-Lab09.Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>

int getInputNumber();

int power(int a, int b);

int main() {
	int a, b;

	a = getInputNumber();
	b = getInputNumber();

	printf("\n%d ^ %d  = %d \n", a, b, power(a, b));
	puts(" ");


	return 0;
}

int getInputNumber() {
	int number;
	printf("\nEnter integer number: ");
	scanf("%d", &number);
	puts(" ");

	return number;

}

int power(int a, int b) {
	int result = 1;
	if (a == 0) {
		return 0;
	}
	if (b == 0) {
		return 1;
	}

	if (b < 0) {
		b = -b;

		for (int i = 1; i <= b; i++)
		{
			result *= a;
		}

		result = 1 / result;
	}

	if (b > 0) {
		for (int i = 1; i <= b; i ++ ) {
			result *= a;
		}
	}
	return result;
}