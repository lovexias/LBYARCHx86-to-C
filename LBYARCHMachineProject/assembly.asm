section .text
bits 64
default rel
global dot_product_asm
extern printf
dot_product_asm:
    ; valA = xmm0
    ; valB = xmm1
    mulsd xmm0, xmm1
    movsd xmm0, xmm0
    ret