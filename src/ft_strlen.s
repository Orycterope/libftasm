%define FUNC_NAME			_ft_strlen
%define STRING_END	0

section .text
	global FUNC_NAME

FUNC_NAME:
			cld							; clear direction flag
			mov rcx, -1
			mov rax, STRING_END
			repne scasb					; [rdi++] != rax 
			mov rax, rcx
			neg rax
			sub rax, 2					; began at -1, and final ecx
			ret
