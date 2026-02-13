.intel_syntax noprefix
.text
.global context_switch
.global trampoline
.extern hello

trampoline:
    call hello

context_switch:
    mov rsp, rdi
    ret
