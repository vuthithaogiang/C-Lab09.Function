

#include<stdio.h>
#include<stdbool.h>

int getNumber();

int sum(int number1, int number2);

int sub(int number1, int number2);

int multi(int number1, int number2);

double div(int number1, int number2);

void menu();


int main() {
	menu();
	return 0;
}

int getNumber() {

	int number;
	printf("\nEnter integer number: ");
	scanf("%d", &number);

	return number;

}

int sum(int number1, int number2) {
	return number1 + number2;

}

int sub(int number1, int number2) {
	return number1 - number2;
}

int multi(int number1, int number2) {
	return number1 * number2;
}

double div(int number1, int number2) {
	if(number2 != 0 ) {
		return (double)number1 / number2;
	}
}

void menu() {
	int choice = 0;
	int a, b;
	do
	{
		printf("\n-------------- MENU ---------------------");
		printf("\n1. Get numbers");
		printf("\n2. Calculate sum.");
		printf("\n3. Calculate sub.");
		printf("\n4. Claculate multi.");
		printf("\n5. Calculate div.");
		printf("\n0. Exit.");
		printf("\n-----------------------------------------");

		printf("\nYour choice? ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
		{
			printf("\nThanks for using.");
			break;
		}
		case 1:
		{
			 a = getNumber();
			 b = getNumber();
			break;
		}
		case 2:
		{
			printf("\n%d + %d = %d ", a, b, sum(a, b));
			break;
		}
		case 3:
		{
			printf("\n%d - %d = %d", a, b, sub(a, b));
			break;

		}
		case 4:
		{
			printf("\n%d * %d = %d", a, b, multi(a, b));
			break;

		}
		case 5:
		{
			if (b == 0) {
				printf("\nPlease enter number 2 # 0.");
			}
			else {
				printf("\n%d / %d = %.2lf", a, b, div(a, b));

			}
			break;

		}
		default:
			printf("\nInvalid choice. PLease try again!");
			break;
		}

	} while (choice != 0);
}