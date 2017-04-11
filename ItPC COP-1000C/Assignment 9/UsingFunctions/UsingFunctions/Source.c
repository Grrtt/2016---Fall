#include <stdlib.h>
#include <stdio.h>


main() {
	int total = 0;
	int i, j;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			total++;
		}
	}

	printf("%i\n", total); system("pause");
}