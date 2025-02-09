# Bisection Method

## Introduction
The **Bisection Method** is a numerical technique used to find the root of a non-linear equation of the form:

f(x) = 0

It is a simple and reliable method that works by iteratively dividing an interval in half and selecting the subinterval in which the function changes sign. This process continues until the solution converges within a specified tolerance level.

## How the Bisection Method Works
The method follows these steps:

1. **Select an interval [a, b] where the function changes sign:**
   - The function values at the endpoints must satisfy f(a) * f(b) < 0
   - This ensures there is at least one root in the interval.

2. **Calculate the midpoint c:**
   c = (a + b)/2

3. **Evaluate f(c):**
   - If f(c) is close to zero (within the specified tolerance), then c is the root.
   - Otherwise, determine the next interval:
     - If f(a) * f(c) < 0, the root is in [a, c], so set b = c
     - Otherwise, the root is in [c, b], so set a = c

4. **Repeat the process** until the interval width (b - a) is less than the tolerance level.

## Example Problem
Find the root of the function:

f(x) = x³ - 4x - 9

in the interval [2, 3] using the Bisection Method with a tolerance level of **0.001**.

## Program Explanation
This C program implements the Bisection Method for solving non-linear equations.

### Code Breakdown

1. **Define the function f(x):**
   ```c
   double fx(double x) {
       return x * x * x - 4 * x - 9;
   }
   ```
   This function represents the equation x³ - 4x - 9 = 0

2. **Bisection Method Implementation:**
   - Checks if the interval is valid (f(a) * f(b) < 0)
   - Iteratively computes the midpoint and evaluates f(c)
   - Adjusts the interval based on the sign of f(c) and continues until the solution meets the tolerance criterion.

3. **Main Function:**
   - Takes user input for the interval [a, b]
   - Calls the `bisection()` function to find the root.
   - Prints the result.

### Sample Output
```
Enter the interval [a, b]: 2 3
```
---
| Iter   |  a             |  b               |  c               |  f(c)          |
| ---   |  ---           |  ---             |  ---             |  ---           |
| 1     |  2.000000      |  3.000000       |  2.500000       |  -3.375000    |
| 2     |  2.500000      |  3.000000       |  2.750000       |  0.796875     |
| 3     |  2.500000      |  2.750000       |  2.625000       |  -1.412109    |
| 4     |  2.625000      |  2.750000       |  2.687500       |  -0.339111    |
| 5     |  2.687500      |  2.750000       |  2.718750       |  0.220917     |
| 6     |  2.687500      |  2.718750       |  2.703125       |  -0.061077    |
| 7     |  2.703125      |  2.710938       |  2.707031       |  0.009049     |
| 8     |  2.703125      |  2.707031       |  2.705078       |  -0.026045    |
| 9     |  2.705078      |  2.707031       |  2.706055       |  -0.008506    |

```
Approximate root: 2.706055
```

## Conclusion
- The Bisection Method is an easy and reliable approach for root-finding.
- It is **guaranteed to converge** if the interval is chosen correctly.
- However, it may be **slow** compared to other methods like Newton-Raphson.
- This program demonstrates how to apply the method effectively in C.

Happy Coding! 🚀

