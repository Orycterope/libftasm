%define FUNC_NAME			_ft_bzero

section .text
	global FUNC_NAME

FUNC_NAME:
			cmp rsi, 0					; is n == 0 ?
			je .exit
			mov rcx, rsi				; move n to counter reg
.repeat:	mov BYTE [rdi], 0			
			inc rdi
			loop .repeat
.exit:		ret
