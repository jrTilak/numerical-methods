
### **Bisection Method - Non-Linear Equation Solver**

#### **Description:**
This program implements the **Bisection Method** to solve a non-linear equation. The user can specify the interval \([a, b]\) and the required precision (number of decimal places) for the root. The program iterates through the Bisection Method until the solution converges to the desired precision.

#### **Functionality:**
- **User Input:**
  - Interval \([a, b]\) where the root is expected.
  - Precision (number of decimal places) for the root's accuracy.
- **Output:**
  - Iterations with the values of a, b, midpoint c, and f(c).
  - Approximate root to the desired precision.
  
#### **Key Functions:**
- **fx(x):** Defines the function f(x) = x³ - 4x - 9.
- **isEqual(x, y, precision):** Checks if two floating-point numbers are equal up to the given precision.
- **bisection(a, b, precision):** Implements the Bisection Method.

#### **Compilation and Running Instructions:**

1. **Compile the Program:**
   To compile the program, ensure you link the math library by using the `-lm` flag with `gcc`.

   ```bash
   gcc main.c -o main -lm
   ```

2. **Run the Program:**
   After compiling, run the executable as follows:

   ```bash
   ./main
   ```

3. **Input:**
   - Enter the interval \([a, b]\) when prompted.
   - Enter the desired precision (number of decimal places).

#### **Example:**

- **Input:**
  ```plaintext
  Enter the interval [a, b]: 2 3
  Enter the number of decimal places for precision: 4
  ```

- **Output:**
  
| Iter   | a              | b              | c              | f(c)
| ---| ---| ---| ---| ---
| 1      | 2.000000       | 3.000000       | 2.500000       | -3.375000
| 2      | 2.500000       | 3.000000       | 2.750000       | 0.796875
| 3      | 2.500000       | 2.750000       | 2.625000       | -1.412109
| 4      | 2.625000       | 2.750000       | 2.687500       | -0.339111
| 5      | 2.687500       | 2.750000       | 2.718750       | 0.220917
| 6      | 2.687500       | 2.718750       | 2.703125       | -0.061077
| 7      | 2.703125       | 2.718750       | 2.710938       | 0.079423
| 8      | 2.703125       | 2.710938       | 2.707031       | 0.009049
| 9      | 2.703125       | 2.707031       | 2.705078       | -0.026045
| 10     | 2.705078       | 2.707031       | 2.706055       | -0.008506
| 11     | 2.706055       | 2.707031       | 2.706543       | 0.000270
| 12     | 2.706055       | 2.706543       | 2.706299       | -0.004118
| 13     | 2.706299       | 2.706543       | 2.706421       | -0.001924
| 14     | 2.706421       | 2.706543       | 2.706482       | -0.000827
| 15     | 2.706482       | 2.706543       | 2.706512       | -0.000279
| ---| ---| ---| ---| ---

```
Approximate root: 2.7065
```

#### **Notes:**
- The program continues iterating until the midpoint converges to the desired precision.
- You can modify the `fx(x)` function to solve a different non-linear equation.

