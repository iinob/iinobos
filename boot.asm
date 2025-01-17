; bios ints take memory, so start here
[org 0x7c00]
; we only need 8 bit registers working with ascii
mov bx, startPhrase


stringDisplay:
	mov ah, 0x0e
	mov al, [bx]
	; check if you're at the end of the string
	cmp al, 0
	je input
	int 0x10
	inc bx
	jmp stringDisplay

newline:
	mov ah, 0x0e
	mov al, 10
	int 0x10
	mov al, 13
	int 0x10
	ret

startPhrase:
	db "bios boot complete, redirecting to input function", 0

horseDesc:
	db "horses are the ugliest creatures in the world", 0

horseInit:
	call newline
	mov bx, horseDesc
	jmp stringDisplay

grilledCheeseDesc:
	db "grilled cheese is the most mysterious sandwich", 0

gcInit:
	call newline
	mov bx, grilledCheeseDesc
	jmp stringDisplay

unknownDesc:
	db "this does not exist", 0

unknownInit:
	call newline
	mov bx, unknownDesc
	jmp stringDisplay

input:
	call newline
	mov ah, 0
	int 0x16
	cmp al, "h"
	je horseInit
	cmp al, "g"
	je gcInit
	jne unknownInit
	jmp input

times 510-($-$$) db 0
db 0x55, 0xaa
