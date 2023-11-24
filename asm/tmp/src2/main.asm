
global _start


section .data 
str: 	 db "Hello world"
str_len: equ $ - str


section .text
_start:
	call dummy		; push the return address -> jump to the function

	; exit the program
	mov rax, 60		; sys_exit(
	mov rdi, 0		; 	error_code
	syscall			; );


dummy:
	push rbp		; saves the base poniter of the function that called me. yes I am a nice function.
	mov rbp, rsp 
	
	push 567     
	push 6789    
	call print ; <CALL>

	mov rsp, rbp
	pop rbp
	ret

;; Print a string
print:	
	; prologue
	push rbp
	mov rbp, rsp
				; pop =
	push 20			; push = sub rsp, 8 -> mov [rsp], 20
	push 30
	mov rax, 1		; sys_write(
	mov rdi, 1		;	stdout,
	mov rsi, str		;	string,
	mov rdx, str_len	;	length
	syscall			;); 
	
	; epilogue
	mov rsp, rbp
	pop rbp

	ret			; pop the return address -> jump to the return address

; > pretty stack
; ret address     36 <
; last rbp value  28 <	[rbp] 
; 20              20 
; 30	 	  12 


