%define FUNC_NAME			_ft_isascii

%define FALSE			0
%define	TRUE			1
%define	ASCII_FIRST		0
%define	ASCII_LAST		127

section .text
	global FUNC_NAME

FUNC_NAME:
		mov rax, FALSE				; false by default
		cmp rdi, ASCII_FIRST
		jb .exit
		cmp rdi, ASCII_LAST
		ja .exit
		mov rax, TRUE
.exit:	ret
