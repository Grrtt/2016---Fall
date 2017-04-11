#include <stdlib.h>
#include <stdio.h>

main() {

	int numbersEntered = 0;
	int smallestNum = 0;
	int largestNum = 0;
	int numAverage = 0;
	int numSum = 0;
	int userInput = 0;

	printf("Please enter 5 numbers:\n");
	while (numbersEntered < 5) {

		scanf_s("%i", &userInput);

		if (numbersEntered == 0) {
			smallestNum = userInput;
			largestNum = userInput;
		}
		else {
			if (smallestNum > userInput) {
				smallestNum = userInput;
			}
			else if (largestNum < userInput) {
				largestNum = userInput;
			}	
		}

		numSum += userInput;

		numbersEntered++;
	}

	printf("\nWhat do you want to do with these numbers?\n 1. Display the smallest number.\n 2. Display the largest number.\n 3. Display the numbers' sum.\n 4. Display the numbers' average.\n");
	scanf_s("%i", &userInput);

	switch (userInput) {
	case 1:
		printf("\nThe smallest of your number is: %i\n", smallestNum);
		break;
	case 2:
		printf("\nThe largest of your numbers is: %i\n", largestNum);
		break;
	case 3:
		printf("\nThe sum of your numbers is: %i\n", numSum);
		break;
	case 4:
		printf("\nThe average of your numbers is: %i\n", (numSum / 5));
		break;
	default:
		printf("\nInvalid choice.");
		break;
	}

	system("pause");
}