Here’s the `README` for the Regula-Falsi Method implementation:

---

# Regula-Falsi Method (False Position)

## Overview

The **Regula-Falsi Method**, also known as the **False Position Method**, is an iterative numerical technique used to find the root of a function. It is similar to the **Bisection Method** but provides faster convergence by using a linear interpolation between the function values at two initial points. This method requires two points, `a` and `b`, such that the function values at these points have opposite signs (i.e., `f(a) * f(b) < 0`).

The algorithm uses the following formula to calculate the next approximation of the root:

```
c = b - f(b) * (b - a) / (f(b) - f(a))
```

Where:
- `a` and `b` are the initial guesses (interval endpoints).
- `f(a)` and `f(b)` are the function values at `a` and `b`.
- `c` is the new approximation of the root.

The process is repeated until the root is found with a desired level of precision.

## Steps/Algorithm

1. **Initial Interval Selection**: Choose two initial guesses `a` and `b` such that `f(a)` and `f(b)` have opposite signs (i.e., `f(a) * f(b) < 0`).
   
2. **Calculate the Next Approximation (`c`)**:
   - Use the formula:  
     `c = b - f(b) * (b - a) / (f(b) - f(a))`.
   
3. **Check for Convergence**: If `f(c)` is less than the desired precision (i.e., `|f(c)| < 10^(-precision)`), the root is found, and the algorithm stops.
   
4. **Update Interval**: 
   - If `f(c) * f(a) < 0`, then set `b = c` (root lies between `a` and `c`).
   - Otherwise, set `a = c` (root lies between `c` and `b`).

5. **Repeat**: Repeat the process until convergence is reached.

## Code Explanation

The provided C program implements the **Regula-Falsi Method** to find the root of a given function. The function to find the root of is defined as:

```c
double fx(double x)
{
    return x * x * x - 4 * x - 9; // Example: f(x) = x^3 - 4x - 9
}
```

The program follows these steps:
1. It takes the lower and upper bounds `a` and `b`, and the desired precision (number of decimal places) from the user.
2. The function `regulaFalsi` performs the method, iterating until the root is found with the desired precision.
3. The root is displayed once found.

## Compilation & Execution

### Compilation

To compile the program, run the following command in your terminal:

```bash
gcc main.c -o main -lm
```

### Execution

Once compiled, run the program with:

```bash
./main
```

### Sample Input/Output

**Sample Input**:
```
Enter the lower bound (a): 2   
Enter the upper bound (b): 3
Enter the precision (number of decimal places): 4
```

**Sample Output**:
```
a = 2.000000, b = 3.000000, c = 2.600000, f(c) = -1.824000
a = 2.600000, b = 3.000000, c = 2.693252, f(c) = -0.237227
a = 2.693252, b = 3.000000, c = 2.704918, f(c) = -0.028912
a = 2.704918, b = 3.000000, c = 2.706333, f(c) = -0.003495
a = 2.706333, b = 3.000000, c = 2.706504, f(c) = -0.000422
a = 2.706504, b = 3.000000, c = 2.706525, f(c) = -0.000051

The root is approximately: 2.706525
```

## Requirements

- C Compiler (e.g., GCC)
- `math.h` library for mathematical operations like `fabs()` and `pow()`

## Limitations

- The method requires that the function has opposite signs at the initial points `a` and `b`.
- It converges slowly for certain types of functions, especially if the function is nearly linear over the chosen interval.

---

Let me know if you need any more details or modifications to the `README`!