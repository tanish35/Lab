.model small
.stack 100h

.data

.code

main proc
mov ax,@data
mov ds,ax
mov ax,0000h
mov bl,00h
mov cl,05h
mov si,0030h

l1:
add ax,[si]
adc bl,00h
inc si
inc si
loop l1

mov si,0050h
mov [si],ax
inc si
inc si
mov [si],bl

int 03h
main endp
end main