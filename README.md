LBYARCH x86-to-C Interface Programming Project

Bongon, Janina Alexia (S13)

### Specifications
Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector _A_ and vector _B_ and place the result in _sdot_.
- *Required to use functional scalar SIMD registers*
- *Required to use functional scalar SIMD floating-point instructions*
- **Input** - Scalar variable _n_ (integer) contains the length of the vector;  Vectors _A_ and _B_ are both **double-precision float**. Scalar _sdot_ is a double-precision float.
- **Process** - $sdot = \sum_{i=1}^{n} a_ib_i = a_1b_1 + a_2b_2 + ... + a_nb_n$
- **Output** - store the result in memory location _sdot._  Display the result for all versions of the kernel (i.e., C and  x86-64).

### Code
The C kernel is written as a function that is within the same file as the `main.c` program. It uses a for loop to iterate the vectors' elements and performs multiplication and addition on the same line. The kernel is 7 lines long.

![image](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/f8bd771a-b4f7-424a-9e43-fc06ddf1cb37)

**Figure 01.** C Kernel

The Assembly kernel is written in a separate `.asm` file entitled `assembly.asm` and is called using the function declaration `extern double dot_product_asm(double* A, double* B, int n);` and function call `sdot = dot_product_asm(A, B, n);` found in line 56 of `main.c`. The Assembly file is 26 lines long and it receives the parameters from C and passes it on to the following registers...
- A - Vector A (RCX)
- B - Vector B (RDX)
- n - number of elements per vector (R8)

A, B, and n are the C parameters and they are passed onto the Assembly registers RCX, RDX, and R8 respectively.

![image](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/4525e904-1fad-4a22-9668-6a4912f91a5e)

**Figure 02.** Assembly Kernel

The user is prompted to input an integer for the size/length of vectors A and B. Any number that is below +1 will prompt an error message "Invalid input. Please enter a positive integer." and the user will be prompted to input another integer. malloc was utilized to dynamically allocate memory for arrays (vectors) A and B. This facilitates better handling of larger array sizes which is to be done in this project. The memory will be deallocated at the end of the program. Functions under the `stdlib.h` and `time.h` libraries were utilized to generate random values to be inputted in the vectors and to calculate the execution time of each kernel.

### Correctness Check
Before doing a comprehensive analysis between the two (2) kernels, C and Assembly, the outputs of both C and Assembly were compared to the manual computation of the programmer. A small sample input was used (n = 3) and the randomly generated values were printed out for checking. As seen in Figure 01, both the C and Assembly kernels were able to compute the correct answer.

- Vector A = (0.97, 0.46, 0.47)
- Vector B = (0.46, 0.99, 0.53)
- sdot = (0.97 x 0.46) + (0.46 x 0.99) + (0.47 x 0.53)
     = (0.4462) + (0.4554) + (0.2491)
     = 1.1507 or 1.15

![image](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/fb22024d-8796-4fcd-b59e-8c1f7c4b1290)
**Figure 03.** Correctness Check

### Analysis of Data
For each kernel version, the chosen values for n (vector size) are $2^{20}, 2^{24}, and 2^{29}$. For each version (debug and release mode), each vector size value will be run 30 times to get the average execution time per programming language kernel (C and Assembly).

#### Debug Version

For the debug version, the Assembly kernel has a much faster execution across all vector size values. In inputting $2^{20}$ as the vector size, there are instances where the Assembly kernel takes about 0 seconds to run compared to its C counterpart wherein the lowest execution time is 0.003. Some outliers may occur within the code as seen in the $2^{29}$ wherein an iteration has a C execution time of 20.149 and an Assembly execution time of 0.958, which deviates from the usual mean of 3.9349 and 0.81523333 respectively.

_Note: In the line charts, the blue line represents C execution times and the orange line represents Assembly execution times._

![Debug 20](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/908e5c4b-63a1-4562-9cf5-67d7c02235c3)
**Figure 04.** Debug Version $2^{20}$ Execution Times Across Iterations Line Chart

![Debug 24](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/20fe9516-2ee4-4264-8545-d9221bad11f8)
**Figure 05.** Debug Version $2^{24}$ Execution Times Across Iterations Line Chart

![Debug 29](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/ac8c353b-fd17-4526-98ee-1d4e41cbfd6d)
**Figure 06.** Debug Version $2^{29}$ Execution Times Across Iterations Line Chart

#### Release Version 

For the release version, there are instances where the C kernel runs faster or equal to its Assembly counterpart. This occurs only on some iterations using the vector size values $2^{20}$ and $2^{24}$, the Assembly kernel is consistently faster than the C kernel in the $2^{29}$ iterations. Despite these instances, the Assembly kernel remains the faster kernel as it has the lower execution time mean across all vector sizes and versions/modes (debug and release).

![Release 20](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/9a94fc44-f817-4c16-85e2-cce77e982047)
**Figure 07.** Release Version $2^{20}$ Execution Times Across Iterations Line Chart

![Release 24](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/28adebb9-c3e1-42d8-a898-dade3d268deb)
**Figure 08.** Release Version $2^{24}$ Execution Times Across Iterations Line Chart

![Release 29](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/3bb33203-25f5-4b53-b1e0-a485ebeffd64)
**Figure 09.** Release Version $2^{29}$ Execution Times Across Iterations Line Chart

#### Average Execution Time

As seen in Figures 10 and 11, the Assembly kernel's average execution time is much faster than the C kernel. As the vector size increases, the longer it takes for both kernels to execute. Thus, we can conclude that using Assembly is much more time-efficient compared to using C.

![20 and 24 Execution Time Mean](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/776aaa51-2d26-415b-889c-7bb0ceb70945)
**Figure 10.** Average Execution Time for Vector Sizes $2^{20}$ and $2^{24}$ Bar Chart

![29 Execution Time Mean](https://github.com/lovexias/LBYARCHx86-to-C/assets/134917158/23df1acb-ead7-470f-b3ea-5157f1260c64)
**Figure 11.** Average Execution Time for Vector Size $2^{29}$ Bar Chart
