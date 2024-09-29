.model small
.stack 100h
.code 
  main proc
  mov ax,@data
  mov ds,ax
  mov cx,0008h
  mov si,0040h
  mov bl,00h
  mov dl,00h

  l1:
  mov al,[si]
  inc si
  sub al,00h
  jns l2
  dec bl
  inc dl ;negative
  
  l2:
  inc bl ;positive
  loop l1
  
  mov si,0040h
  mov [si],bl
  mov [si+1],dl


  int 03h
  main endp
end
