.model small
.stack 100h
.code 
  main proc
    mov ax, @data
    mov ds, ax
    mov si,0030h
    mov al,[si]
    mov ah,al
    and al,0fh
    cmp al,0ah
    jc l1
    add al,07h

    l1:
    add al,30h
    mov bx,0050h
    mov [bx],al
    mov al,ah
    and al,f0h
    rol al,04h
    cmp al,0ah
    jc l2
    add al,07h
    
    l2:
    add al,30h
    inc bx
    mov [bx],al



  int 03h
  main endp
end
