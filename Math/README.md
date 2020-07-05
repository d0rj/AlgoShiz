# AlgoShiz/Math

## Functions list

---

### DCT

Discrete cosine transform. Included *transform II* for one-dimentional array.

---

### Differentiation

Numerical differentiation. Two-sided(bilateral) differentiation of the first and second degree is now available.

---

### Factorial

Just factorial ))0).

---

### Fibonacci

Implemented optimized non-cached algorithm.

---

### GCD

Euclidean algorithm for finding the greatest common factor.

---

### Integration

Numerical integration. Available options: 

* Trapezoidal;
* Rectangle;
* Simpson's integration.

---

### Interpolation

Numerical interpolation of functions based on known argument-value pairs. Now available is the Lagrange method interpolation.

**Lagrange method**

$$ 
\psi_i(x) = \frac{(x - x_0)...(x - x_{i-1})(x - x_{i+1})...(x - x_n)}{(x_i - x_0)...(x_i - x_{i-1})(x_i - x_{i+1})...(x_i - x_n)};
$$
\- is basis Lagrange polynomial for *i* node.

And in the end, the final formula has the form:

$$
P_n(x) = \sum_{i=0}^{n} y_i\psi_i(x) = \sum_{i=0}^{n} y_i\frac{\prod_{j \neq i}(x - x_j)}{\prod_{j \neq i}(x_i - x_j)}
$$

---

### Power

Fast exponentiation (for integers).

---

### Sqrt

Calculation of the square root of a number.

---
