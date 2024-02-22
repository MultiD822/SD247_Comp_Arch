; Programmer: Kai Schenkel
; Class: SD-247 Computer Architecture
; Data: 2/4/2024
; Project 2: Assembly Programming

section .data
    a db 35
    b db 5
    quotient db 0
    remainder db 0
    add_msg db "Addition done", 10, 0
    sub_msg db "Subtraction done", 10, 0
    mul_msg db "Multiplication done", 10, 0
    div_msg db "Division done", 10, 0
    div_zero_msg db "Division by zero error", 10, 0

section .text
    global _start

_start:
    ; Addition
    mov al, [a]
    add al, [b]
    mov [quotient], al ; Store result in quotient
    ; Print result
    call print_result
    ; Print addition done message
    call print_add_msg

    ; Subtraction
    mov al, [a]
    sub al, [b]
    mov [quotient], al ; Store result in quotient
    ; Print result
    call print_result
    ; Print subtraction done message
    call print_sub_msg

    ; Multiplication
    mov al, [a]
    mov bl, [b]
    mul bl
    mov [quotient], al ; Store result in quotient
    ; Print result
    call print_result
    ; Print multiplication done message
    call print_mul_msg

    ; Division
    mov al, [a] ; Load a into al
    mov bl, [b]
    cmp bl, 0 ; Compare b with 0
    je div_zero ; Jump to div_zero if b is 0
    div bl ; Divide al by b, quotient in al, remainder in ah
    mov [quotient], al ; Store quotient in quotient
    mov [remainder], ah ; Store remainder in remainder
    ; Print result
    call print_result
    ; Print division done message
    call print_div_msg
    jmp end ; Jump to end

div_zero:
    ; Print division by zero error message
    mov eax, 1
    mov edi, 1
    lea rsi, [div_zero_msg]
    mov edx, 24
    syscall

end:
    ; Exit
    mov eax, 60
    xor edi, edi
    syscall

print_result:
    ; Print result
    mov eax, 1
    mov edi, 1
    lea rsi, [quotient]
    mov edx, 1 ; Changed to 1 to print byte
    syscall
    ret

print_add_msg:
    ; Print addition done message
    mov eax, 1
    mov edi, 1
    lea rsi, [add_msg]
    mov edx, 14
    syscall
    ret

print_sub_msg:
    ; Print subtraction done message
    mov eax, 1
    mov edi, 1
    lea rsi, [sub_msg]
    mov edx, 17
    syscall
    ret

print_mul_msg:
    ; Print multiplication done message
    mov eax, 1
    mov edi, 1
    lea rsi, [mul_msg]
    mov edx, 20
    syscall
    ret

print_div_msg:
    ; Print division done message
    mov eax, 1
    mov edi, 1
    lea rsi, [div_msg]
    mov edx, 14
    syscall
    ret