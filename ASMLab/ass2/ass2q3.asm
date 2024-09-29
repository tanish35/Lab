.model small
.stack 100h
.code 
  main proc
  mov ax, @data
  mov DS, ax
  mov ES, ax

  mov si, 0030h
  mov di, 0040h
  mov cl , [si]
  cmp [di], cl
  jnz failed 
  inc si
  inc di
  mov ch, 00h

  cld;
  looping:
    cmpsb 
    jz l1
  failed:
    mov si, 0050h
    mov bx,1111h
    mov [si], bx
    jmp exit
  l1:
    loop looping
    mov si, 0050h
    mov bx,0ffffh
    mov [si], bx
  exit:
  int 03h
  main endp
end
