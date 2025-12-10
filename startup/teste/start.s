.global _start

_start:
    call test
    mov $1, %edi
    mov %rax, %rsi
    mov $8, %edx
    mov $1, %eax
    syscall

    mov $0, %edi
    mov $60, %eax
    syscall