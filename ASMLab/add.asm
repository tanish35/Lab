.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov ax,[si]
mov si,0040h
add ax,[si]
mov si,0050h
mov [si],ax
mov ah,00h
adc ah,ah
add si,0002h
mov [si],ah

int 03h
main endp
end main