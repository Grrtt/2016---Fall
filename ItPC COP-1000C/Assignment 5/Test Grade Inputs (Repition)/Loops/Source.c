#include <stdlib.h>
#include <stdio.h>

main() {

	printf("Integers divisible by 5; 0 < i < 60.\n");
	int i = 1;
	while (i < 60) {
		if ((i % 5) == 0) {
			printf("%i ", i);
		}
		i++;
	}

	printf("\n\n");

	printf("Integers divisible by 2 and 7; 1 < i < 200.\n");
	for (int i = 1; i < 200; i++)
	{
		if (((i % 2) == 0) && ((i % 7)) == 0) {
			printf("%i ", i);
		}
	}

	printf("\n\n");

	printf("The sum of integers divisible by 8; 100 < i < 500.\n");
	int sum = 0;
	for (int i = 100; i < 500; i++)
	{
		if ((i % 8) == 0)
			sum += i;
	}
	printf("%i", sum);

	printf("\n\n");

	printf("The sum of odd integers; 50 < i < 100.\n");
	sum = 0;
	for (int i = 50; i < 100; i++)
	{
		if ((i % 2) == 1)
			sum += i;
	}
	printf("%i", sum);

	printf("\n\n");

	system("pause");
}