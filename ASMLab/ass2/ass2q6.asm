.model small
.stack 100h
.code 
  main proc
    mov ax, @data
    mov ds, ax
    mov es, ax
    mov bx,0030h
    mov si,0040h
    mov di,0050h
    mov cx,0007h

    l4:
    mov al,[bx]
    ror al,01h
    jnc l1
    rol al,01h
    mov [di],al ; for odd
    inc di

    jmp l3
    
    l1:
    rol al,01h
    mov [si],al ; for even
    inc si
    
    l3:
    inc bx
    loop l4


  int 03h
  main endp
end
