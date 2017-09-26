%define FUNC_NAME			_ft_tolower

%define FALSE			0
%define	TRUE			1
%define	ASCII_FIRST		65
%define	ASCII_LAST		90
%define MAJ_MIN_DIFF	32

section .text
	global FUNC_NAME

is_maj:								; returns 1 if 'a' <= value <= 'z'
		mov rax, FALSE				; false by default
		cmp rdi, ASCII_FIRST
		jb .exit
		cmp rdi, ASCII_LAST
		ja .exit
		mov rax, TRUE
.exit	ret

FUNC_NAME:
		call is_maj
		cmp rax, 0
		mov rax, rdi
		je .exit	
		add rax, MAJ_MIN_DIFF
.exit	ret
