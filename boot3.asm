ORG 0
BITS 16
_start
	jmp short start
	nop 

times 33 db 0

start:
	jmp 0x7C0:step2


step2:
	cli ; clear interrupt
	mov ax, 0x7C0
	mov ds, ax
	mov es, ax
	mov ax, 0x00
	mov sp, 0x7C00
	sti ; Enable interrupt

	mov si, message
	call print
	jmp $

print:
	mov bx, 0
.loop:
	lodsb
	cmp al, 0