%define FUNC_NAME			_ft_memcmp
%define STRING_END	0

section .text
	global FUNC_NAME

FUNC_NAME:
			cld							; clear direction flag
			mov rcx, rdx
			repe cmpsb					; [rdi++] == [rsi++] 
			movzx rax, byte [rdi - 1]
			movzx rbx, byte [rsi - 1]
			sub rax, rbx
			ret
