.global _start

_start:
    mov $10, %edi  
    mov $5, %esi    
    call soma     
    mov %eax, %edi
    mov $60, %eax
    syscall     