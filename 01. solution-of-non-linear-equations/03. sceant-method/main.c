#include <stdio.h>
#include <math.h>

// Define the function whose root is to be found
double fx(double x)
{
  return x * x * x - 4 * x - 9; // Example: f(x) = x^3 - 4x - 9
}

// Function to implement the Secant Method
double secantMethod(double x0, double x1, int precision)
{
  double x2;
  int iteration = 0;

  // Iterate until the result is within the desired precision
  do
  {
    // Check if the denominator is zero (to avoid division by zero)
    if (fabs(fx(x1) - fx(x0)) < 1e-12)
    {
      printf("Denominator too small. The method may not converge.\n");
      return -1; // Return -1 for failure
    }

    // Apply the secant method formula
    x2 = x1 - (fx(x1) * (x1 - x0)) / (fx(x1) - fx(x0));

    // Print each iteration step
    printf("Iteration %d: x0 = %.6f, x1 = %.6f, x2 = %.6f, f(x2) = %.6f\n",
           iteration + 1, x0, x1, x2, fx(x2));

    // Update values for the next iteration
    x0 = x1;
    x1 = x2;

    iteration++;

  } while (fabs(fx(x2)) > pow(10, -precision)); // Check precision condition

  return x2; // Return the root approximation
}

int main()
{
  double x0, x1, root;
  int precision;

  // Take input from the user
  printf("Enter the first initial guess (x0): ");
  scanf("%lf", &x0);
  printf("Enter the second initial guess (x1): ");
  scanf("%lf", &x1);
  printf("Enter the precision (number of decimal places): ");
  scanf("%d", &precision);

  // Call the Secant Method function
  root = secantMethod(x0, x1, precision);

  // Display the root if valid
  if (root != -1)
  {
    printf("\nThe root is approximately: %.6f\n", root);
  }

  return 0;
}
