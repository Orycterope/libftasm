%define FUNC_NAME			_ft_strcmp
%define STRING_END	0

section .text
	global FUNC_NAME

FUNC_NAME:
.while:
			cmpsb
			jne .exit
			cmp byte [rdi - 1], STRING_END	; was it a zero ?
			je .exit
			cmp byte [rsi - 1], STRING_END
			je .exit
			jmp .while
.exit:
			movzx rax, byte [rdi - 1]
			movzx rbx, byte [rsi - 1]
			sub rax, rbx
			ret
