.model small
.stack 100h

.data
num db ?
input_msg db 'Enter number between 0-9: $'      
even_msg db 'The number is even.$'
odd_msg db 'The number is odd.$'

.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx,input_msg
    mov ah,09h
    int 21h

    mov ah, 01h  
    int 21h
    sub al, 30h  
    mov num, al 

    mov al, num
    and al, 01h

    jz even
    mov ah, 09h
    lea dx, odd_msg
    int 21h
    jmp end_prog

even:
    mov ah, 09h
    lea dx, even_msg
    int 21h

end_prog:
    mov ah, 4Ch
    int 21h

main endp
end main

