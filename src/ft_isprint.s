%define FUNC_NAME			_ft_isprint

%define FALSE			0
%define	TRUE			1
%define	ASCII_FIRST		32
%define	ASCII_LAST		126

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
