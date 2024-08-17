
.model small
.stack 100h

.data
num1 db 02h
num2 db 06h
num3 db 03h
max_num db 0

.code
main proc
mov ax,@data
mov ds,ax

mov bl,num1
mov al,num2

cmp al,bl
jbe skip1
mov bl,al

skip1:
mov al,num3
cmp al,bl
jbe skip2
mov bl,al

skip2:
mov max_num,bl

mov al,bl
add al,30h
mov ah,02h
int 21h

mov ah,4ch
int 21h

main endp
end main