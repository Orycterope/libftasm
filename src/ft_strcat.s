%define FUNC_NAME			_ft_strcat

section .text
	global FUNC_NAME

FUNC_NAME:
			push rbp					; save previous rbp
			mov rbp, rsp				; top of the stack is now the new base
			push rdi
.run:		cmp BYTE [rdi], 0			; while loop
			je .copy
			inc rdi
			jmp .run

.copy		mov al, [rsi]				; do while loop
			mov [rdi], al
			inc rsi
			inc rdi
			cmp al, 0					; did we just copy a 0 ?
			jne .copy

.exit:		pop rax
			leave						; restore previous rbp
			ret
