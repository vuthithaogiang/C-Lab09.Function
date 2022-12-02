
#include<stdio.h>

int getNumber();

int multi(int number1, int number2);

void calculateMultiplicationTable(int number);

void menu();
	
 
int main() {
	menu();
	return 0;
}

int getNumber() {
	int number;
	printf("\nEnter integer number: ");
	scanf("%d", &number);

	return  number;
}

int multi(int number1, int number2) {
	return number1 * number2;
}

void calculateMultiplicationTable(int number) {
	if (number <= 0) {
		printf("\nInvalid number. Please try again!");
	}
	else {
		printf("\n============> Multiplication Table %d <==============", number);

		for (int i = 1; i <= 9; i++)
		{
			printf("\n%d * %d = %d", number, i, multi(number, i));

		}
		
	}

	puts(" ");
}

void menu() {
	int choice = 0;
	do {
		printf("\n=====================================");
		printf("\n1. Display Multiplication Table.");
		printf("\n0. Exit.");
		printf("\n======================================");

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
			int number = getNumber();
			calculateMultiplicationTable(number);
			break;
		}
		default:
		{
			printf("\nInvalid choice. Please trya again!");
			break;
		}
		}

	} while (choice != 0);

}
