
#include<stdio.h>
#include<stdbool.h>
#include<math.h>


int getInputNumber();

bool isPrime(int number);

void checkNumber(int number);

void menu();



int main() {

	menu();

	return 0;
}

int getInputNumber() {
	int number;
	printf("\nEnter integer number: ");
	scanf("%d", &number);

	return number;
}

bool isPrime(int number) {

	if (number < 2) {
		return false;
	}
	else {
		int  p = sqrt(number);
		for (int i = 2; i <= p; i++) {
			if (number % i == 0) {
				return false;
			}
		}

	}
	return true;
}

void checkNumber(int number) {

	if (isPrime(number) == true) {
		printf("\n%d is prime number.", number);
	}
	else {
		printf("\n%d is not prime number.", number);
	}
	puts(" ");
}

void menu() {
	int choice = 0; 
	do {

		printf("\n----- Check prime numbers --------------.");
		printf("\n1. Check number.");
		printf("\n0. Exit.");

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
			int number = getInputNumber();

			checkNumber(number);
			break;

		}
		default:
		{
			printf("\nInvalid choice. Please try again!");
			break;
		}
		}
	} while (choice != 0);
}
