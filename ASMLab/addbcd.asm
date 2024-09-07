.model small
.stack 100h

.data

.code

main proc
mov ax,@data
mov ds,ax
mov ax,0000h
mov cx,0005h
mov si,0030h

l1:
add al,[si]
daa
adc ah,00h
inc si
loop l1

mov si,0050h
mov [si],ax

int 03h
main endp
end main