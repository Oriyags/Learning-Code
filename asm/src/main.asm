; Write a print function that... prints!
; Use progloge and epilogue.
; The function will take the string and string's length from variables you define in the .data section.

global _start

section .text
_start:
	
	call print
	mov rax, 60	; sys_exit
	mov rdi, 0	; Ok
	syscall		; ma sheilon amar


print:
	
	push rbp
	mov rbp, rsp
		
	mov rax, 1
	mov rdi, 0
	mov rsi, string
	mov rdx, length
	syscall

	mov rsp, rbp	
	pop rbp
	ret


section .data

string: db "Oriya Loves Cats (Eylon)"	
length: equ $ - string
