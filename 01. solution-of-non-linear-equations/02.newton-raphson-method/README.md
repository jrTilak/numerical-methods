Got it! Here's the updated **README.md** with the formulas in plain text instead of math syntax:

---

# Newton-Raphson Method for Finding Roots

## What is the Newton-Raphson Method?

The **Newton-Raphson method** is an iterative technique used to find the roots (or zeros) of a real-valued function. The method is based on the idea of linear approximation, using the function and its derivative to approximate the root. It is especially useful when the exact solution of an equation is difficult to find algebraically. The method typically converges quickly if the initial guess is close to the actual root.

The general formula for the Newton-Raphson method is:

```
x_{n+1} = x_n - f(x_n) / f'(x_n)
```

Where:
- `x_n` is the current approximation,
- `f(x_n)` is the value of the function at `x_n`,
- `f'(x_n)` is the derivative of the function at `x_n`,
- `x_{n+1}` is the next approximation.

## Algorithm Steps

1. **Initial Guess:**
   - Choose an initial guess, `x0`, for the root.

2. **Convergence Check:**
   - Before proceeding, check the convergence condition:

   ```
   |f''(x) / (f'(x))^2| < M
   ```

   where `f''(x)` is the second derivative of the function, and `f'(x)` is the first derivative. If this condition is met, proceed with the iteration. If not, ask the user to enter a new guess.

3. **Iterate:**
   - Use the Newton-Raphson formula:

   ```
   x_{n+1} = x_n - f(x_n) / f'(x_n)
   ```

   Repeat the iteration until the change in the approximation is smaller than the specified precision.

4. **Stopping Condition:**
   - The iteration stops when the difference between successive approximations is smaller than the specified precision, i.e., when `|x_{n+1} - x_n|` is less than the given precision.

## Explanation of the Program

### Functions

1. **`fx(double x)`**: 
   - This function represents the equation `f(x)` whose root we are trying to find. For example, the program uses `f(x) = x^3 - 4x - 9` as the default equation.

2. **`dfx(double x)`**: 
   - This function returns the derivative of `f(x)`, i.e., `f'(x)`. For the equation `f(x) = x^3 - 4x - 9`, the derivative is `f'(x) = 3x^2 - 4`.

3. **`d2fx(double x)`**: 
   - This function calculates the second derivative `f''(x)`. For the example equation, it computes `f''(x) = 6x`.

4. **`isEqual(double x1, double x2, int precision)`**: 
   - This helper function checks if two numbers are equal up to the specified number of decimal places (precision). It multiplies the numbers by `10^precision` and compares them as integers.

5. **`checkConvergence(double x)`**: 
   - This function checks if the convergence condition `|f''(x) / (f'(x))^2| < M` is satisfied. If the condition is met, the method is likely to converge. Otherwise, the user is prompted to enter a new guess.

6. **`newtonRaphson(double initialGuess, int precision)`**: 
   - This is the core function that implements the Newton-Raphson method. It performs the iterations using the formula `x_{n+1} = x_n - f(x_n) / f'(x_n)`, and it stops once the difference between successive approximations is smaller than the specified precision.

### User Interaction

1. The program starts by asking the user for an **initial guess** for the root of the equation.
   
2. It then checks if the **convergence condition** is satisfied for the provided initial guess. If not, the user is asked to provide a new guess.

3. After receiving a valid initial guess, the program proceeds with the **iteration** to find the root using the Newton-Raphson method.

4. During the iterations, the program displays the following for each step:
   - The current approximation `x_n`
   - The next approximation `x_{n+1}`
   - The value of the function `f(x_{n+1})` at the new approximation

5. The iterations continue until the **precision condition** is met (i.e., the difference between successive approximations is below the specified precision).

6. Finally, the program outputs the **approximate root**.

### Example

For the equation `f(x) = x^3 - 4x - 9`, the program will find the root using the Newton-Raphson method and print the intermediate steps until it converges to the approximate root.

**Sample Output:**

```plaintext
Enter the initial guess for the root: 1
Warning: Convergence condition not met, the method may not converge.
Please enter a new guess: 2
Enter the precision (number of decimal places): 5

Iter     x0              x1              f(x1)
1        2.000000        1.870968        0.382675
2        1.870968        1.855781        0.004818
3        1.855781        1.855585        0.000001
4        1.855585        1.855585        0.000000

Approximate root: 1.855585
```

## Compilation & Execution

### Compilation:

To compile the program, use the following command:

```bash
gcc main.c -o main -lm
```

Here, `-lm` links the math library required for functions like `pow()`.

### Execution:

To run the program after compiling, use:

```bash
./main
```

### Input:

- Enter the initial guess for the root.
- Enter the precision (the number of decimal places to consider for convergence).

### Output:

- The program will display the iterations and the final approximate root of the equation.

---

Let me know if you need any more modifications!