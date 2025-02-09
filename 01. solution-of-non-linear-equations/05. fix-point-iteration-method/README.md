# **Fixed Point Iteration Method**  

## **Introduction**  
The **Fixed Point Iteration Method** is a numerical technique used to find the root of an equation **f(x) = 0** by rewriting it in the form **x = g(x)** and iteratively solving for x.  

This method requires a properly chosen function **g(x)** such that it satisfies the **convergence condition**:  
\[
|g'(x)| < 1
\]  

---

## **Algorithm / Steps**  

1. **Rearrange** the given equation **f(x) = 0** into the form **x = g(x)**.  
2. **Choose an initial guess** \( x_0 \).  
3. **Check the convergence condition** \( |g'(x_0)| < 1 \). If this condition is not satisfied, select a different guess.  
4. Use the iterative formula:  
   \[
   x_{n+1} = g(x_n)
   \]
5. Repeat the process until the absolute error **|x(n+1) - x(n)|** is within the required **precision**.  
6. The value of **x** at the end of iterations is the approximate root.  

---

## **Code Explanation**  

### **Function Definitions**
- **`g(x)`**: Defines the transformed function \( x = g(x) \).  
- **`g_derivative(x)`**: Computes \( g'(x) \) to verify the convergence condition.  
- **`fixedPointIteration(x0, precision)`**: Performs the iteration process.  
- **`main()`**: Takes user input for initial guess and precision, then calls the function.  

### **Output Format**
The program prints each iteration step:
```
Iter     x0           x1           Error
1      2.000000     2.738613     0.738613
2      2.738613     2.935444     0.196831
...
The root is approximately: 2.99988
```

---

## **How to Compile and Run**
### **Compilation Command**
Use GCC to compile the program:  
```sh
gcc main.c -o fixed_point -lm
```
### **Run the Program**
```sh
./fixed_point
```

---

## **Example Input/Output**
### **Input:**
```
Enter the initial guess: 0
Enter the precision (number of decimal places): 5
```
### **Output:**
```
Iter     x0              x1              Error
1        0.000000        3.000000        3.000000
2        3.000000        4.582576        1.582576
3        4.582576        5.227839        0.645264
4        5.227839        5.469128        0.241288
5        5.469128        5.556664        0.087536
6        5.556664        5.588081        0.031418
7        5.588081        5.599315        0.011233
8        5.599315        5.603326        0.004011
9        5.603326        5.604757        0.001431
10       5.604757        5.605268        0.000511
11       5.605268        5.605450        0.000182
12       5.605450        5.605515        0.000065
13       5.605515        5.605538        0.000023
14       5.605538        5.605547        0.000008

The root is approximately: 5.605547
```

---

## **Limitations**
- If the function is not properly rearranged, the method may not converge.  
- The initial guess must satisfy **|g'(x)| < 1** for the method to work.  

---

## **Conclusion**
The **Fixed Point Iteration Method** is an effective numerical approach for finding roots of equations when the function is properly chosen and the convergence condition is met.
