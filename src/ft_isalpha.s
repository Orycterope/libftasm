%define FUNC_NAME			_ft_isalpha

%define FALSE			0
%define	TRUE			1
%define	LETTER_A		65
%define	LETTER_Z		90
%define	LETTER_a		97
%define	LETTER_z		122

section .text
	global FUNC_NAME

FUNC_NAME:
			mov rax, FALSE				; false by default
			cmp rdi, LETTER_A
			jb .exit
			cmp rdi, LETTER_z
			ja .exit
			cmp rdi, LETTER_Z
			jbe .success
			cmp rdi, LETTER_a
			jb .exit
.success:	mov rax, TRUE
.exit:		ret
