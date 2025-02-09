#include <stdio.h>
#include <math.h>

// Function equivalent to f(x)
// This function defines the equation whose root we need to find.
double fx(double x)
{
  return x * x * x * x - x - 10; // Example equation: x^4 - x - 10 = 0
}

// Function equivalent to f'(x)
// This function defines the derivative of the equation.
double dfx(double x)
{
  return (4 * x * x * x) - 1; // Derivative of the example equation: 4x^3 - 1
}

// Function equivalent to f''(x)
// This function defines the second derivative of the equation.
double d2fx(double x)
{
  return 12 * x * x; // Second derivative of the example equation: 12x^2
}

// Function to check if two numbers are equal up to a specified number of decimal places
int isEqual(double x1, double x2, int precision)
{
  double factor = pow(10, precision);              // Multiply by 10^precision to shift decimal point
  return (int)(x1 * factor) == (int)(x2 * factor); // Compare the shifted integers
}

// Function to check convergence condition
int checkConvergence(double x)
{
  double f_x = fx(x);          // f(x)
  double f_single_x = dfx(x);  // f'(x)
  double f_double_x = d2fx(x); // f''(x)

  // Convergence condition: |f(x) * f''(x)| < (f'(x))^2
  if (fabs(f_x * f_double_x) < pow(f_single_x, 2))
  {
    return 1; // Converges
  }
  else
  {
    return 0; // Does not converge
  }
}

// Function to perform the Newton-Raphson Method
// It finds the root of f(x) = 0 starting from an initial guess.
void newtonRaphson(double initialGuess, int precision)
{
  double x0 = initialGuess; // Initial guess for the root
  double x1;                // Next approximation of the root
  int iteration = 1;        // Counter for iterations

  // Display table header for iterations
  printf("\nIter\t x0\t\t x1\t\t f(x1)\n");

  // Step 2: Iterate until the precision condition is met
  while (1)
  {
    // Step 3: Compute the next approximation using the Newton-Raphson formula
    x1 = x0 - (fx(x0) / dfx(x0));

    // Print the values of the current iteration
    printf("%d\t %.6f\t %.6f\t %.6f\n", iteration++, x0, x1, fx(x1));

    // Step 4: Check if the result has converged based on precision
    if (isEqual(x0, x1, precision))
    {
      break; // Exit if the results have converged with the required precision
    }

    // Update the current approximation for the next iteration
    x0 = x1;
  }

  // Step 6: Print the final result
  printf("\nApproximate root: %.6f\n", x1);
}

// Main function to drive the program
int main()
{
  double initialGuess;
  int precision;

  // Prompt user to enter the initial guess for the root
  printf("Enter the initial guess for the root: ");
  scanf("%lf", &initialGuess);

  // Check if the convergence condition is met for the initial guess
  if (checkConvergence(initialGuess) == 0)
  {
    printf("Warning: Convergence condition not met, the method may not converge.\n");
    printf("Please enter a new guess: ");
    scanf("%lf", &initialGuess);
    if (checkConvergence(initialGuess) == 0)
    {
      printf("Warning: Convergence condition still not met, terminating.\n");
      return 1; // Exit the program if convergence condition is not satisfied
    }
  }

  // Ask for precision (number of decimal places)
  printf("Enter the precision (number of decimal places): ");
  scanf("%d", &precision);

  // Call the Newton-Raphson method with the given initial guess and precision
  newtonRaphson(initialGuess, precision);

  return 0;
}
