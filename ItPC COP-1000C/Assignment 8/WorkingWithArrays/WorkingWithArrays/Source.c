#include <stdlib.h>
#include <stdio.h>

main() {

	int numbers[50] = { 0 };	
	int userInput;

	printf("Input up to 50 numbers. Input -999 to complete number entries.\n\n");

	int counter = 0;	// Counts number of inputs.
	do {
		scanf_s("%i", &userInput);

		if (userInput != -999) {
			numbers[counter] = userInput;
			counter++;	// Counter within if-clause prevents -999
						// from incrementing 'counter';
		}
	} while (userInput != -999 && counter != 50);	// Checks for completion entry,
													// or if number amount has been reached.
	printf("\n");

	for (int i = 0; i < counter; i++) // Prints how many elements were entered.
	{
			printf("%i. %i\n", (i + 1), numbers[i]);	// (i + 1) : Ensures that print enumeration starts at 1,
														// although 'i' might equal 0.
	}

	system("pause");
}