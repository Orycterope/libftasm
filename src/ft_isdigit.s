%define FUNC_NAME			_ft_isdigit

%define FALSE			0
%define	TRUE			1
%define	LETTER_0		48
%define	LETTER_9		57

section .text
	global FUNC_NAME

FUNC_NAME:
		mov rax, FALSE				; false by default
		cmp rdi, LETTER_0
		jb .exit
		cmp rdi, LETTER_9
		ja .exit
		mov rax, TRUE
.exit:	ret
