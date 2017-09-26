%define FUNC_NAME			_ft_putstr_fd
%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4

section .data
null_str:
	.str db "(null)",0
	.len equ $ - null_str.str

section .text
	global FUNC_NAME
	extern _ft_strlen

FUNC_NAME:
	enter 0, 0
	cmp rdi, 0
	jne .endif
	lea rdi, [rel null_str.str] ; we're going to print the null string instead
.endif:
	push rdi					; save str address before call
	push rsi
	call _ft_strlen
	pop rdi
	pop rsi		 				; pop the saved str adress
	mov rdx, rax				; len in rdx
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	leave						; restore previous rbp
	ret
