#include <stdio.h>
#include <math.h>

/**
 * Function equivalent to f(x)
 * Example: f(x) = x^3 - 4x - 9 = 0
 */
double fx(double x)
{
  return x * x * x - 4 * x - 9;
}

/**
 * Function to check if two floating-point numbers are equal up to 'precision' decimal places
 */
int isEqual(double x, double y, int precision)
{
  double factor = pow(10, precision);
  return (round(x * factor) == round(y * factor));
}

/**
 * Bisection Method with precision control
 */
void bisection(double a, double b, int precision)
{
  if (fx(a) * fx(b) >= 0)
  {
    printf("Invalid interval. f(%lf) = %lf and f(%lf) = %lf must have opposite signs.\n", a, fx(a), b, fx(b));
    return;
  }

  double c, prev_c = 0.0; // Midpoint and previous midpoint
  int iteration = 1;

  printf("\nIter\t a\t\t b\t\t c\t\t f(c)\n");

  while (1)
  {
    c = (a + b) / 2.0;

    printf("%d\t %.*f\t %.*f\t %.*f\t %.*f\n", iteration++, precision + 2, a, precision + 2, b, precision + 2, c, precision + 2, fx(c));

    if (isEqual(c, prev_c, precision)) // Stop when two consecutive midpoints match up to the precision
    {
      break;
    }

    prev_c = c;

    if (fx(a) * fx(c) < 0)
    {
      b = c;
    }
    else
    {
      a = c;
    }
  }

  printf("\nApproximate root: %.*f\n", precision, c);
}

// Main function
int main()
{
  double a, b;
  int precision;

  printf("Enter the interval [a, b]: ");
  scanf("%lf %lf", &a, &b);

  printf("Enter the number of decimal places for precision: ");
  scanf("%d", &precision);

  bisection(a, b, precision);

  return 0;
}
