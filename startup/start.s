.data
greeting: 
    .asciz "Digite seu nome: "
    greeting_len = . - greeting - 1

name_buffer:
    .space 64

.text
.global _start

_start:
    mov $1, %rax
    mov $1, %rdi
    lea greeting(%rip), %rsi
    mov $greeting_len, %rdx
    syscall

    mov $0, %rax
    xor %rdi, %rdi
    lea name_buffer(%rip), %rsi
    mov $64, %rdx
    syscall

    mov $1, %rax
    mov $1, %rdi
    lea name_buffer(%rip), %rsi
    mov $64, %rdx
    syscall

    mov $60, %eax
    xor %rdi, %rdi
    syscall