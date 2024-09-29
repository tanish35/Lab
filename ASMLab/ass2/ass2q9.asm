.model small
.stack 100h
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov si, 0030h
        mov al,01h
        mov [si],al
        inc si
        mov [si],al
        mov cl,08h
        mov bl,00h
        
        l1:
        add bl,[si]
        dec si
        add bl,[si]
        add si,02h
        mov [si],bl
        mov bl,00h
        loop l1

        int 03h
    main endp
    end