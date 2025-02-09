#include <stdio.h>
#include <math.h>

// Define the function g(x) (Rearranged version of f(x) = 0)
double g(double x)
{
  return sqrt(4 * x + 9); // Example: x = sqrt(4x + 9)
}

// Derivative g'(x) to check convergence condition |g'(x)| < 1
double g_derivative(double x)
{
  return (2 / sqrt(4 * x + 9));
}

// Function to implement the Fixed Point Iteration Method
double fixedPointIteration(double x0, int precision)
{
  double x1;
  int iteration = 1;

  // Compute precision tolerance
  double tolerance = pow(10, -precision);

  // Check the convergence condition at the initial guess
  if (fabs(g_derivative(x0)) >= 1)
  {
    printf("The method may not converge. Choose a different initial guess.\n");
    return -1;
  }

  printf("\nIter\t x0\t\t x1\t\t Error\n");

  // Perform iteration until precision is met
  do
  {
    x1 = g(x0);

    // Display iteration details
    printf("%d\t %.6f\t %.6f\t %.6f\n", iteration++, x0, x1, fabs(x1 - x0));

    if (fabs(x1 - x0) < tolerance) // Check precision
    {
      break;
    }

    x0 = x1; // Update x0 for next iteration

  } while (1);

  return x1; // Return the approximate root
}

int main()
{
  double x0, root;
  int precision;

  // Take input from the user
  printf("Enter the initial guess: ");
  scanf("%lf", &x0);
  printf("Enter the precision (number of decimal places): ");
  scanf("%d", &precision);

  // Call Fixed Point Iteration method
  root = fixedPointIteration(x0, precision);

  // Display the root if valid
  if (root != -1)
  {
    printf("\nThe root is approximately: %.6f\n", root);
  }

  return 0;
}
