%define FUNC_NAME			_ft_strdup

section .text
	global FUNC_NAME
	extern _ft_strlen
	extern _malloc

FUNC_NAME:
	push rbp					; save previous rbp
	mov rbp, rsp				; top of the stack is now the new base
	push rdi					; save the original ptr
	call _ft_strlen
	inc rax						; space for the \0
	push rax					; save the length
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je .exit					; malloc returned NULL
	cld							; clear direction flag
	pop rcx
	pop rsi
	mov rdi, rax
	rep movsb					; [rdi++] <- [rsi++]
.exit:
	leave
	ret
