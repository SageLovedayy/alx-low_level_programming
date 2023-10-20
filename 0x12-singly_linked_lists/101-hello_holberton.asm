extern printf   ; Declare printf as an external symbol

section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0  ; %s is the format specifier for a string, 10 is ASCII code for newline, 0 terminates the format string



section .text
    global main

main:
    ; Call printf function
    mov rdi, format  ; Format string
    mov rsi, hello   ; Pointer to the string to be printed
    xor rax, rax     ; Clear RAX register for syscall number 0 (printf)
    call printf      ; Call printf function

    ; Exit the program
    mov rax, 60      ; syscall: exit
    xor rdi, rdi     ; status: 0
    syscall

section .bss
    ; Empty BSS section as printf is being used and does not require additional space
