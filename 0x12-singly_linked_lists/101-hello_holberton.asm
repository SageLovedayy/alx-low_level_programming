section .data
    msg db "Hello, Holberton", 0
    fmt db "%s", 10, 0  ; Format string: %s (string), newline (10), null terminator (0)

section .text
    extern printf       ; Declare the printf function as an external symbol
    global main         ; Entry point of the program

main:
    push rbp            ; Save the base pointer

    mov rdi, fmt        ; Format string address into rdi register
    mov rsi, msg        ; Message address into rsi register
    xor rax, rax        ; Clear rax register (no SIMD state)
    call printf         ; Call printf function

    pop rbp             ; Restore the base pointer

    xor rax, rax        ; Set return value to 0
    ret                 ; Return from the main function
