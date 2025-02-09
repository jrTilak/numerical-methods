/**
 * 01. Solution of Non-Linear Equations
 *  0.1 Bisection Method
 */

#include <stdio.h>
#include <math.h>

#define TOLERANCE_LEVEL 0.0000001 // Precision level for stopping criteria

/**
 * Function equivalent to f(x)
 * This function defines the equation whose root we need to find.
 * Example: f(x) = x^2 - 2x - 5 = 0
 */
double fx(double x)
{
  return x * x * x - 4 * x - 9;
}

/**
 * Function to perform the Bisection Method
 * It finds the root of f(x) = 0 in the interval [a, b]
 */
void bisection(double a, double b)
{
  // Step 1: Check if the provided interval is valid
  // The function values at 'a' and 'b' must have opposite signs (f(a) * f(b) < 0)
  if (fx(a) * fx(b) >= 0)
  {
    printf("Invalid interval. f(%lf) = %lf and f(%lf) = %lf must have opposite signs.\n", a, fx(a), b, fx(b));
    return;
  }

  double c;          // Midpoint of the interval
  int iteration = 1; // Counter for iterations

  // Display table header for iterations
  printf("\nIter\t a\t\t b\t\t c\t\t f(c)\n");

  // Step 2: Iterate until the interval width is smaller than the tolerance level
  while ((b - a) >= TOLERANCE_LEVEL)
  {
    // Step 3: Compute the midpoint
    c = (a + b) / 2.0;

    // Print the values of the current iteration
    printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iteration++, a, b, c, fx(c));

    // Step 4: Determine the new subinterval
    if (fx(a) * fx(c) < 0) // Root is in [a, c]
    {
      b = c;
    }
    else // Root is in [c, b]
    {
      a = c;
    }
  }

  // Step 5: Print the final result
  printf("\nApproximate root: %.6f\n", c);
  printf("Absolute error: %.10f\n", fabs(b - a));
}

// Main function to drive the program
int main()
{
  double a, b;

  // Prompt user to enter the interval [a, b]
  printf("Enter the interval [a, b]: ");
  scanf("%lf %lf", &a, &b);

  // Call the bisection method with the given interval
  bisection(a, b);

  return 0;
}
