#include <stdio.h>

int main ()
{
	int total; // number of Fibonacci numbers.
	printf ("Enter the number of the Fibonacci umbers: ");
	scanf ("%d", &total);
	
	int i, primeIndicator;
	
	unsigned long long int fib, j;
	
	// First two elements of the Fibonacci array:
	unsigned long long int fib_1 = 1;
	unsigned long long int fib_2 = 1;
	
	if (total == 1)
		printf("1.\0"); // first 1 element
	else if (total == 2)
		printf("1, 1.\0"); // first 2 elements
	else if (total == 3)
		printf("1, 1, Buzz.\0"); // first 3 elements
	else if (344 >= total && total > 3) // more than 3 elements
	{
		printf("1, 1, ");
		for (i = 3; i <= total; i++)
		{
			fib = fib_1 + fib_2; // calculate the Fibonacci number of this round
			if (fib % 3 == 0)
			{
				if (i == total)
					printf("Buzz.\0");
				else
					printf("Buzz, ");
			}
			else if (fib % 5 == 0)
			{
				if (i == total)
					printf("Fizz.\0");
				else
					printf("Fizz, ");
			}
			else if (fib % 2 == 0)
			{
				if (i == total)
					printf("%llu.\0", fib);
				else
					printf("%llu, ", fib);
			}
			else
			{
				// Check if the number is a prime number
				primeIndicator = 1; // by default, the number is assumed to be a prime number
				for (j = 7; j*j <= total; j++)
				{
					if (fib % j == 0)
					{
						primeIndicator = 0; // not a prime
						break;
					}
				}
				if (primeIndicator == 1)
				{
					if (i == total)
						printf("BuzzFizz.\0");
					else
						printf("BuzzFizz, ");
				}
				else
				{
					if (i == total)
						printf("%llu.\0", fib);
					else
						printf("%llu, ", fib);
				}
			}
			
			// update the Fibonacci array, so that a new Fibonacci number can be generated later
			fib_1 = fib_2;
			fib_2 = fib;
		}
	}
	else
		printf("Invalid number entered! The umber must be possitive integer, and it must be less than 344! /0"); // some invalid input
	
	return 0;
}
