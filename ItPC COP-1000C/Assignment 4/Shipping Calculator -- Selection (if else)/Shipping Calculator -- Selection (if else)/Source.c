#include <stdlib.h>
#include <stdio.h>

/*
Programmer: Garrett Shepherd
Date: 11/2/2016

Problem Description:

Write a shipping calculator for Global Courier Services
per package weight and shipping distance.

Package Weight                                        				Rate per 500 miles shipped
Less than or equal to 10 pounds												$2.00
More than 10 pounds but less than or equal to 50 pounds						$4.50


*/

main() {

	double weight, shippingRate, total;
	int miles;

	shippingRate, total = 0;

	printf("     GCS Shipping Calculator     \n");
	printf("---------------------------------\n\n");

	printf("How much does your package weigh?\n");
	printf("Weight (lbs.): ");
	scanf_s("%lf", &weight);

	printf("You entered: %.2lf lbs.\n\n", weight);

	printf("How far do you want to ship your package?\n");
	printf("Distance (miles): ");
	scanf_s("%i", &miles);

	printf("You entered: %i miles.\n\n", miles);

	if (weight <= 50) {								// Main condition.
		shippingRate = 4.5;							
													// Condition works primarily within 80% of
		if (weight < 10)							// the allowable weights. Treating >= 50 lbs
			shippingRate = 2.0;						// and < 10 treated as extremes.

		if (miles < 500) {							// No need for other calculations if < 500 miles.
			total = shippingRate;					
		}
		else {
			total = (miles / 500) * shippingRate;	// Removes full 500-mile segments.

			if ((miles % 500) > 0) 					// Determines if there are remaining miles
				total = total + shippingRate;		// running into another 500-mile segment.
		}

		printf("Your total shipping charge is: $%.2lf\n\n", total);
	}
	else {
		printf("Sorry, we cannot ship any package over 50 lbs. We apologize for any inconvenience.\n\n");
	}

	system("pause");
}