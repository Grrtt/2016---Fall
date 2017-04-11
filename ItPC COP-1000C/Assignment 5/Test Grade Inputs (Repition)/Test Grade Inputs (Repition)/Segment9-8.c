#include <stdlib.h>
#include <stdio.h>

main() {

	int numbersEntered = 0;
	int smallestNum = 0;
	int largestNum = 0;
	int numAverage = 0;
	int numSum = 0;
	int userInput = 0;

	while (numbersEntered < 4) {

		scanf_s("Please enter 5 numbers: %i", &userInput);

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

	scanf_s("What do you want to do with these numbers?\n 1. Display the smallest number.\n 2. Display the largest number.\n 3. Display the numbers' sum.\n 4. Display the numbers' average. %i", &userInput);

	switch (userInput) {
	case 1:
		printf("\nThe smallest of your number is: %i", smallestNum);
		break;
	case 2:
		printf("\nThe largest of your numbers is: %i", largestNum);
		break;
	case 3:
		printf("\nThe sum of your numbers is: %i", numSum);
		break;
	case 4:
		printf("\nThe average of your number is: %i", (numSum / 5));
		break;
	default:
		printf("\nPlease enter a valid choice.");
		break;
	}

	system("pause");
}