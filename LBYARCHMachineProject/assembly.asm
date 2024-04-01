section .text
bits 64
default rel

global dot_product_asm

; A - Vector A (RCX)
; B - Vector B (RDX)
; n - number of elements per vector (R8)

dot_product_asm:
    xor r9, r9       ; counter
    xorpd xmm2, xmm2 ; sdot
dot_product_loop:
    movsd xmm0, qword [rcx + r9 * 8] ; A[i]
    movsd xmm1, qword [rdx + r9 * 8] ; B[i]

    mulsd xmm0, xmm1
    addsd xmm2, xmm0

    inc r9
    cmp r9, r8
    jl dot_product_loop
finish:
    movsd xmm0, xmm2
    ret