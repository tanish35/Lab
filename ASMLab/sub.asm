.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov al,[si]
not al
inc al
mov si ,0040h
add al,[si]

jc L1
not al
inc al

L1:
mov si,0050h
mov [si],al
cmc
mov ah,00h
adc ah,ah
inc si
mov [si],ah


int 03h
main endp
end main