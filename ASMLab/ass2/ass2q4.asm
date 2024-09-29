.model small
.stack 100h
.code 
  main proc
  mov ax, @data
  mov DS, ax
  mov ES, ax

  mov si, 0030h
  mov ch, 00h
  mov cl , [si]
  inc si
  mov di, si
  add di, cx
  dec di
  mov ah, 00h
  mov al, cl
  mov bl , 02h
  div bl
  mov cl, al


  looping:
    mov bl, [di] 
    cmp [si], bl 
    jz l1
  failed:
    mov si, 0050h
    mov bx,1111h
    mov [si], bx
    jmp exit
  l1:
    inc si
    dec di
    loop looping
    mov si, 0050h
    mov bx,0ffffh
    mov [si], bx
  exit:
  int 03h
  main endp
end
