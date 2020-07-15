#include <stdio.h>
#include <math.h>

void polynomial_function(int ar[], int val)
{
	int i;
	
	if (val < 0) // It prints '0' value if there is no x values to calculate. 
	printf("0");
	
	for (i = val; 0 <= i; i--) // Thanks to this loop, it can be assigned the values to correct places.
	{
		if (i != 0) // It is used to separate whether the coefficient has to 'x' or not. 
		{
			printf("%dx^%d ", ar[i], i);

			if (ar[i - 1] > 0) // It checks the input's value and put '+' if it is positive number.
				printf("+ ");
		}
		else
			printf("%d", ar[i]);
	}
	printf("\n");
	
}
void find_derivative_function(int ar[], int val,int x)
{
	int i,j;

	for (i = 1; i <= x; i++) // It decides how many times derivation will be calculated.
	{

		for (j = 1; j <= val; j++) // It makes derivation.
		{
			ar[j-1] = j * ar[j];
		}
		val--; // It decreases the value for degree.

	}
	
	polynomial_function(ar, val); // It outputs the polynomial.

}

int main()
{
	int x, ar[10], val, i;

	// User inputs a polynomial degree (between 1 and 10)
	do {
		printf("Enter the degree of polynomial equation(1-10): ");
		scanf("%d", &val);
	} while (val < 1 || val >10);


	for (i = val; 0 <= i; i--) // This loop takes the coefficient values to place behind the 'x' values. 
	{
		printf("Enter the coefficient of x to the power %d: ", i);
		scanf("%d", &ar[i]);
	}
	
	printf("Entered polynomial: \n");
	
	printf("f(x) = ");
	polynomial_function(ar, val); // It calls the entered polynomial to print.

	printf("Which degree of derivative you want to calculate? "); // User inputs the number to decide how many times calculation of derivative will be. 
	scanf("%d", &x);

	printf("%d.Derivative: df(x) = ", x);
	find_derivative_function(ar, val, x); // It calls the final derivative calculation to print.

	return 0;

}
