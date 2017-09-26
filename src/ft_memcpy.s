%define FUNC_NAME			_ft_memcpy

section .text
	global FUNC_NAME

FUNC_NAME:
			push rbp					; save previous rbp
			mov rbp, rsp				; top of the stack is now the new base
			push rdi
			cmp rdx, 0					; is n == 0 ?
			je .exit
			mov rcx, rdx
			cld							; clear direction flag
			rep movsb					; [rdi++] <- [rsi++]
.exit:		pop rax
			leave						; restore previous rbp
			ret
