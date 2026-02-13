.intel_syntax noprefix
.text
.global context_switch
.extern hello

context_switch:
    mov rsp, rdi
    sub rsp, 8
    lea rax, hello[rip]
    mov [rsp], rax
    ret
