#include <stdlib.h>
#include <stdio.h>

main() {
	printf("--------------------------\n");
	printf("   - Grade Data Entry -   \n");
	printf("--------------------------\n\n");
	
	printf("Directions: Enter grades from 1 - 100, followed by pressing 'Enter'. Enter '-1' to complete data entry.\n\n");

	printf("Enter Grade(s):\n");
	
	int counter = 0;
	int grade, passingGrade = 0;
	double passingPerc;

	do {											// Do-While chosen to set 'grade' value
		scanf_s("%i", &grade);						// before first loop condition check.
													
		if (grade >= 0 && grade <= 100) {
			counter++;
			if (grade >= 70)
				passingGrade++;
		}
		else {
			if(grade != -1)							// Exclude -1 from main if-condition to
													// prevent incrementing 'counter'.
				printf("\nInvalid grade! Please re-enter value.\n\n");
		}
	} while (grade != -1);

	printf("\nData entry complete.\n\n");
	
	if (counter != 0) {
		passingPerc = (passingGrade / (double)counter);	// Type-cast 'counter' to double to give percentage as decimal < 1.
		passingPerc *= 100;								// Transform to percentage.
	}															
	else {
		passingPerc = 0.0;								// Set to 0.0 to prevent divide by 0 answer.
		printf("No grade(s) entered.\n\n");
	}

	printf("--------------------------\n");
	printf("       - Result(s) -      \n");
	printf("--------------------------\n\n");

	printf("Passing Grade(s): %i (of %i) | %.1lf%%\n", passingGrade, counter, passingPerc);

	system("pause");
}