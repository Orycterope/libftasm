%define FUNC_NAME			_ft_strncmp
%define STRING_END	0

section .text
	global FUNC_NAME

FUNC_NAME:
			mov rcx, rdx
			cmp rcx, 0
			je .zero
.while:
			cmpsb
			jne .exit
			cmp byte [rdi - 1], STRING_END	; was it a zero ?
			je .exit
			cmp byte [rsi - 1], STRING_END
			je .exit
			loop .while
.exit:
			movzx rax, byte [rdi - 1]
			movzx rbx, byte [rsi - 1]
			sub rax, rbx
			ret

.zero:
			mov rax, 0
			ret
