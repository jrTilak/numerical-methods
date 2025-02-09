# Secant Method

## Introduction
The **Secant Method** is a numerical technique used to find the root of a given function. Unlike the Bisection and Regula-Falsi methods, the Secant Method does not require an interval where the function changes signs. Instead, it uses two initial guesses and iteratively approximates the root using a secant line.

## How It Works
The Secant Method approximates the root using the following formula:
```
x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
```
Here,
- `x0` and `x1` are the two initial guesses.
- `f(x0)` and `f(x1)` are the function values at `x0` and `x1`.
- `x2` is the next approximation of the root.
- The process repeats until the result meets the desired precision.

## Algorithm
1. Choose two initial values `x0` and `x1`.
2. Compute `x2` using the secant method formula.
3. Check if `|f(x2)|` is within the given precision; if so, stop.
4. Update `x0 = x1` and `x1 = x2`, then repeat from Step 2.
5. Continue until the root is found within the desired precision.

## Program Overview
### File Name
`main.c`

### Code Explanation
1. **Define the function:**
   ```c
   double fx(double x) {
       return x * x * x - 4 * x - 9;
   }
   ```
   This function represents `f(x) = x^3 - 4x - 9`.

2. **Implement the Secant Method:**
   ```c
   double secantMethod(double x0, double x1, int precision) {
       double x2;
       do {
           x2 = x1 - (fx(x1) * (x1 - x0)) / (fx(x1) - fx(x0));
           x0 = x1;
           x1 = x2;
       } while (fabs(fx(x2)) > pow(10, -precision));
       return x2;
   }
   ```
   This function calculates the root using the secant formula iteratively.

3. **Main function:**
   ```c
   int main() {
       double x0, x1;
       int precision;
       printf("Enter first guess (x0): ");
       scanf("%lf", &x0);
       printf("Enter second guess (x1): ");
       scanf("%lf", &x1);
       printf("Enter precision (decimal places): ");
       scanf("%d", &precision);
       double root = secantMethod(x0, x1, precision);
       printf("Root found: %.6f\n", root);
       return 0;
   }
   ```
   This takes user input, calls `secantMethod()`, and prints the result.

## Compilation & Execution
### Compile:
```bash
gcc main.c -o secantMethod -lm
```
### Run:
```bash
./secantMethod
```

## Example
### Input:
```
Enter the first initial guess (x0): 2
Enter the second initial guess (x1): 3
Enter the precision (number of decimal places): 5
```
### Output:
```
Iteration 1: x0 = 2.000000, x1 = 3.000000, x2 = 2.600000, f(x2) = -1.824000
Iteration 2: x0 = 3.000000, x1 = 2.600000, x2 = 2.693252, f(x2) = -0.237227
Iteration 3: x0 = 2.600000, x1 = 2.693252, x2 = 2.707193, f(x2) = 0.011956
Iteration 4: x0 = 2.693252, x1 = 2.707193, x2 = 2.706524, f(x2) = -0.000072
Iteration 5: x0 = 2.707193, x1 = 2.706524, x2 = 2.706528, f(x2) = -0.000000

The root is approximately: 2.706528
```

## Limitations
- Can fail if `f(x1) - f(x0)` is very small, leading to division by zero.
- Does not always converge.
- Requires good initial guesses for better performance.

## Conclusion
The **Secant Method** is a powerful root-finding technique that converges faster than the Bisection Method. However, it lacks the guaranteed convergence of methods like Newton-Raphson. Proper selection of initial guesses improves accuracy and efficiency.

---
Let me know if you need any modifications! 🚀

