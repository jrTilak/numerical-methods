#include <stdio.h>
#include <math.h>

// Define the function whose root is to be found
double fx(double x)
{
  return x * x * x - 4 * x - 9; // Example: f(x) = x^3 - 4x - 9
}

// Function to implement Regula-Falsi (False Position) method
double regulaFalsi(double a, double b, int precision)
{
  double c = a; // Initialize c to store the root

  // Check if f(a) and f(b) have opposite signs
  if (fx(a) * fx(b) >= 0)
  {
    printf("The function has the same sign at a and b. Please choose different values.\n");
    return -1; // Invalid interval
  }

  // Iterate until the root is found with the desired precision
  do
  {
    // Calculate the value of c
    c = b - fx(b) * (b - a) / (fx(b) - fx(a));

    // Print the current iteration's result
    printf("a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", a, b, c, fx(c));

    // If the result is close enough to 0, break the loop
    if (fabs(fx(c)) < pow(10, -precision))
    {
      break;
    }

    // Update the boundaries
    if (fx(c) * fx(a) < 0)
    {
      b = c; // Root lies between a and c
    }
    else
    {
      a = c; // Root lies between c and b
    }
  } while (fabs(fx(c)) > pow(10, -precision)); // Precision-based condition

  return c; // The root
}

int main()
{
  double a, b, root;
  int precision;

  // Take input from the user
  printf("Enter the lower bound (a): ");
  scanf("%lf", &a);
  printf("Enter the upper bound (b): ");
  scanf("%lf", &b);
  printf("Enter the precision (number of decimal places): ");
  scanf("%d", &precision);

  // Call the Regula-Falsi method
  root = regulaFalsi(a, b, precision);

  // Display the root if valid
  if (root != -1)
  {
    printf("\nThe root is approximately: %.6f\n", root);
  }

  return 0;
}
