LBYARCH x86-to-C Interface Programming Project

Bongon, Janina Alexia (S13)

### Specifications
Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector _A_ and vector _B_ and place the result in _sdot_.
- *Required to use functional scalar SIMD registers*
- *Required to use functional scalar SIMD floating-point instructions*
- **Input** - Scalar variable _n_ (integer) contains the length of the vector;  Vectors _A_ and _B_ are both **double-precision float**. Scalar _sdot_ is a double-precision float.
- **Process** - $sdot = \sum_{i=1}^{n} a_ib_i = a_1b_1 + a_2b_2 + ... + a_nb_n$
- **Output** - store the result in memory location _sdot._  Display the result for all versions of the kernel (i.e., C and  x86-64).

### Correctness Check
Before doing a comprehensive analysis between the two (2) kernels, C and Assembly, the outputs of both C and Assembly were compared to manual computation of the programmer. A small sample input was used (n = 3) and the randomly generated values were printed out for checking. As seen in Figure 01, both the C and Assembly kernels were able to compute the correct answer.

- Vector A = (0.52, 0.64, 0.08)
- Vector B = (0.35, 0.62, 0.20)
- sdot = (0.52 x 0.35) + (0.64 x 0.62) + (0.08 x 0.20)
     = (0.182) + (0.3968) + (0.016)
     = 0.5948 or 0.59

![image](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/87faa1bf-1995-47b8-b31f-9518e0c7cae0)
**Figure 01.** Correctness Check
