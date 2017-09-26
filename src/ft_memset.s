%define FUNC_NAME			_ft_memset

section .text
	global FUNC_NAME

FUNC_NAME:
			push rbp					; save previous rbp
			mov rbp, rsp				; top of the stack is now the new base
			push rdi
			cmp rdx, 0					; is n == 0 ?
			je .exit
			mov rcx, rdx
			mov rax, rsi
			cld							; clear direction flag
			rep stosb					; [rdi++] <- rax
.exit:		pop rax
			leave						; restore previous rbp
			ret
