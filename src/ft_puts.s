%define FUNC_NAME			_ft_puts
%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4
%define STDOUT				1
%define NEW_LINE			10

section .data
null_str:
	.str db "(null)",0
	.len equ $ - null_str.str

section .text
	global FUNC_NAME
	extern _ft_strlen
	extern _ft_putchar

FUNC_NAME:
	push rbp					; save previous rbp
	mov rbp, rsp				; top of the stack is now the new base
	cmp rdi, 0
	jne .endif
	lea rdi, [rel null_str.str] ; we're going to print the null string instead
.endif:
	push rdi					; save str address before call
	call _ft_strlen
	mov rdi, STDOUT
	pop rsi		 				; pop the saved str adress
	mov rdx, rax				; len in rdx
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc .error					; there was a write error, rax contains errno
	mov	rdi, NEW_LINE			; write once again for the \n
	call _ft_putchar			; returning the value of ft_putchar
	leave						; restore previous rbp
	ret

.error:
	mov rax, -1
	leave
	ret
