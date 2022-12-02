
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 200

void toUpperCase(char* str);

void toLowerCase(char* str);

int main() {

	char str[SIZE];

	printf("\nEnter string: ");
	scanf("%[^\n]", str);

	printf("\nthe string that you just enter from keyboard: %s\n", str);

	toLowerCase(str);

	printf("\nThe string after to lower all characters: %s\n", str);

	toUpperCase(str);

	printf("\nThe string after to upper all characters: %s\n", str);

	puts(" ");

	

	return 0;
}

void toUpperCase(char* str) {
	int i; 
	int size = strlen(str);

	for (i = 0; i < size; i++) {
		str[i] = toupper(str[i]);
	}

}

void toLowerCase(char* str) {
	int i = 0; 
	int size = strlen(str);
	for (i = 0; i < size; i++) {
		str[i] = tolower(str[i]);
	}
}