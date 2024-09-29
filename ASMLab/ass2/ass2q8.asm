.model small
.stack 100h
.code 
  main proc
    mov ax, @data
    mov ds, ax
    
    mov si,0030h
    mov al,[si]
    mov cl,99h
    mov dl,00h
    mov bl,01h
    
    l1:
    inc dl
    sub al,bl
    jz end1
    add bl,02h
    loop l1

  end1:
  mov si,0040h
  mov [si],dl
  
  
  int 03h
  main endp
end
