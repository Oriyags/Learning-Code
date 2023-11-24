
global _start

section .data
str_wet_cat: db "I am a wet, wet cat"
str_wc_len: equ $ - str_wet_cat

section .text			; using a text section for code
_start:				; address of first instruction

	mov rax, 1		; sys_write(
	mov rdi, 1		;	stdout,
	mov rsi, str_wet_cat	;	string,
	mov rdx, str_wc_len	;	length
	syscall			;); 
	
	; exit the program
	mov rax, 60		; sys_exit(
	mov rdi, 0		; 	error code
	syscall			; );		
