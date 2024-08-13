section .data
    hello db 'Hello, World!', 0x0A  ; The string to be printed, followed by a newline character

section .text
    global _start  ; This is required for the linker

_start:
    ; sys_write (write the string to stdout)
    mov eax, 4          ; syscall number for sys_write (4)
    mov ebx, 1          ; file descriptor 1 is stdout
    mov ecx, hello      ; pointer to the string
    mov edx, 13         ; length of the string (13 characters)
    int 0x80            ; call the kernel

    ; sys_exit (exit the program)
    mov eax, 1          ; syscall number for sys_exit (1)
    xor ebx, ebx        ; return code 0
    int 0x80            ; call the kernel
