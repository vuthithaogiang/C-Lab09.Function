
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define PI 3.14

void getSideTriangle(double* a, double* b, double* c);

void getSideRectangle(double* length, double* width);

void getSideTrapezium(double* bigBottom, double* smallBottom, double* height);

void getRadiusCircle(double* radius);

bool isSideTriangle(double a, double b, double c);

double calculateAreaTriangle(double a, double b, double c);

bool isSideRectangle(double length, double width);

double calculateAreRectangle(double length, double width);

bool isSideTrapezium(double bigBottom, double smallBottom, double height);

double calulateAreaTrapezium(double bidBottom, double smallBottom, double height);

bool isRadiusCircle(double radius);

double calculateAreaCircle(double radius);

void menu();

int main() {

	menu();

	return 0;
}

void getSideTriangle(double* a, double* b, double* c) {
	printf("\nEnter length's side first triangle: ");
	scanf("%lf", a);

	printf("\nEnter length's side second triangle: ");
	scanf("%lf", b);

	printf("\nEnter lenght's size third triangle: ");
	scanf("%lf", c);

	puts(" ");
}

void getSideRectangle(double* length, double* width) {

	printf("\nEnter length: ");
	scanf("%lf", length);

	printf("\nEnter width: ");
	scanf("%lf", width);

	puts(" ");

}

void getSideTrapezium(double* bigBottom, double* smallBottom, double* height) {

	printf("\nEnter big bottom: ");
	scanf("%lf", bigBottom);

	printf("\nEnter small bottom: ");
	scanf("%lf", smallBottom);

	printf("\nEnter height: ");
	scanf("%lf", height);

	puts(" ");
}

void getRadiusCircle(double* radius) {
	printf("\nEnter radius: ");
	scanf("%lf", radius);

	puts(" ");

}

bool isSideTriangle(double a, double b, double c) {
	
	if (a <= 0 || b <= 0 || c <= 0) {
		return false;
	}
	else if (a + b > c && a + c > b && b + c > a) {
		return true;
	}
	return false;
	
}

double calculateAreaTriangle(double a, double b, double c) {
	
	if (isSideTriangle(a, b, c) == true) {

		double p = (a + b + c) / 2;

		return (p * (p - a) * (p - b) * (p - c));
		
	}
}

bool isSideRectangle(double length, double width) {
	if (length > 0 && width > 0) {
		return true;
	}
	return false;
}

double calculateAreRectangle(double length, double width) {
	if (isSideRectangle(length, width)) {
		return length * width;
	}
}

bool isSideTrapezium(double bigBottom, double smallBottom, double height) {
	if (bigBottom > 0 && smallBottom > 0 && height > 0) {
		return true;
	}
	return false;
}

double calulateAreaTrapezium(double bigBottom, double smallBottom, double height) {
	if (isSideTrapezium(bigBottom, smallBottom, height)) {
		return height * (bigBottom + smallBottom) / 2;
	}
}

bool isRadiusCircle (double radius) {
	if (radius > 0) {
		return true;
	}
	return false;
}

double calculateAreaCircle(double radius) {
	if (isRadiusCircle(radius)) {
		return radius * radius * PI;
	}
}

void menu() {

	int choice; 
	do {
		printf("\n============= Calculate Area =================");
		printf("\n1. Triangle.");
		printf("\n2. Rectangle.");
		printf("\n3. Trapezium.");
		printf("\n4. Circle.");
		printf("\n0. Exit.");
		printf("\n===============================================");

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
			double a, b, c;
			getSideTriangle(&a, &b, &c);
		
			

			if (isSideTriangle(a, b, c) ) {

				printf("\nAre = %.2lf", calculateAreaTriangle(a, b, c));

			}
			else {
				printf("\nPlease enter value sides valid.");
			}
			break;
		}
		case 2:
		{
			double length, width;
			getSideRectangle(&length, &width);

			if (isSideRectangle(length, width)) {
				printf("\nAres = %.2lf", calculateAreRectangle(length, width));
			}
			else {
				printf("\nPlease enter value sides valid.");

			}
			break;
		}
		case 3:
		{
			double bigBottom, smallBottom, height;

			getSideTrapezium(&bigBottom, &smallBottom, &height);

			if (isSideTrapezium(bigBottom, smallBottom, height)) {
				printf("\nArea = %.2lf", calulateAreaTrapezium(bigBottom, smallBottom, height));
			}
			else {
				printf("\nPlease enter value sides valid.");
			}
			break;

		}
		case 4:
		{
			double radius;
			getRadiusCircle(&radius);

			if (isRadiusCircle(radius)) {
				printf("\nArea = %.2lf", calculateAreaCircle(radius));
			}
			else {
				printf("\nPlease enter value radius valid.");
			}
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