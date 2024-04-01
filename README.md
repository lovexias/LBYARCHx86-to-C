LBYARCH x86-to-C Interface Programming Project

Bongon, Janina Alexia (S13)

### Specifications
Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector _A_ and vector _B_ and place the result in _sdot_.
- *Required to use functional scalar SIMD registers*
- *Required to use functional scalar SIMD floating-point instructions*
- **Input** - Scalar variable _n_ (integer) contains the length of the vector;  Vectors _A_ and _B_ are both **double-precision float**. Scalar _sdot_ is a double-precision float.
- **Process** - $sdot = \sum_{i=1}^{n} a_ib_i = a_1b_1 + a_2b_2 + ... + a_nb_n$
- **Output** - store the result in memory location _sdot._  Display the result for all versions of the kernel (i.e., C and  x86-64).

- **Sanity Check**
