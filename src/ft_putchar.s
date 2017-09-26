%define FUNC_NAME			_ft_putchar
%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4
%define STDOUT				1

section .text
	global FUNC_NAME

FUNC_NAME:
	push rbp					; save previous rbp
	mov rbp, rsp				; top of the stack is now the new base
	push rdi					; push the char in the stack
	mov rax, MACH_SYSCALL(WRITE)
	mov rdi, STDOUT
	lea rsi, [rsp] 				; load effective address of char in the stack
	mov rdx, 1					; len is 1 char
	syscall
	jc .error					; there was a write error, rax contains errno
	pop rax						; return the int passed
	leave						; restore previous rbp
	ret

.error:
	mov rax, -1
	leave
	ret	
