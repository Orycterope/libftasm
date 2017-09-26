%define FUNC_NAME			_ft_memalloc

section .text
	global FUNC_NAME
	extern _malloc
	extern _ft_bzero

FUNC_NAME:
	enter 0, 0
	sub rsp, 8			; stack alignment : 16 - sizeof(rdi)

	push rdi			; save the original len
	call _malloc
	cmp rax, 0
	je .exit			; malloc returned NULL
	mov rdi, rax	
	pop rsi
	add rsp, 8 			; restore stack alignment
	call _ft_bzero
.exit:
	leave
	ret
