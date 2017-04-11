#include <stdio.h>
#include <stdlib.h>

main() {
	int firstNum, secondNum, result;

	printf("Enter a first number: ");
	scanf_s("%i", &firstNum);
	printf("You entered: %i.\n", firstNum);

	printf("Enter a second number: ");
	scanf_s("%i", &secondNum);
	printf("You entered: %i.\n", secondNum);

	result = firstNum + secondNum;
	printf("The addition of the numbers is %i.\n", result);

	result = firstNum * secondNum;
	printf("The multiplication of the number is %i.\n", result);
	
	result = firstNum * firstNum;
	printf("The square of %i is %i.\n", firstNum, result);

	result = secondNum * secondNum;
	printf("The square of %i is %i.\n", secondNum, result);

	system("pause");
}