%define FUNC_NAME			_ft_cat
%define BUFF_SIZE			4096
%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define WRITE				4
%define STDOUT				1

section .text
	global FUNC_NAME

FUNC_NAME:
	enter BUFF_SIZE,0			
	push rdi					; save the fd

.read:
	mov rdi, [rsp]
	lea rsi, [rsp + 8]
	mov rdx, BUFF_SIZE
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc .exit					; read error
	cmp rax, 0
	je .exit					; read EOF

;write
	mov rdi, STDOUT
	lea rsi, [rsp + 8]	
	mov rdx, rax				; previously read len
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc .exit
	jmp .read

.exit:
	leave
	ret

