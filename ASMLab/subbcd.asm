.model small
.stack 100h

.data

.code

main proc
mov ax,@data
mov ds,ax
mov ax,0000h


mov si,0040h
mov al,[si]
mov si,0050h
sub al,[si]
das
mov dl,00h
jnc l1

mov cl,al
mov al,99h
sub al,cl
add al,01h
daa
mov dl,01h

l1:
mov si,0060h
mov [si],al
inc si
mov [si],dl

int 03h
main endp
end main