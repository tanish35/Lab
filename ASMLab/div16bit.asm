.model small
.stack 100h

.data

.code

main proc
mov ax,@data
mov ds,ax
mov dx,0000h

mov ax,2222h
mov bx,0055h
div bx

mov si,0060h
mov [si],ax
inc si
inc si
mov [si],dx


int 03h
mov ah,4ch
int 21h
main endp
end main