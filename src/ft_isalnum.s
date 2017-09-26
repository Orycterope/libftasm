%define FUNC_NAME			_ft_isalnum

%define FALSE			0
%define	TRUE			1
%define	LETTER_0		48
%define	LETTER_9		57
%define	LETTER_A		65
%define	LETTER_Z		90
%define	LETTER_a		97
%define	LETTER_z		122

section .text
	global FUNC_NAME
	extern _ft_isalpha
	extern _ft_isdigit

FUNC_NAME:
			call _ft_isalpha
			cmp rax, 1					; was it a letter ?
			je .success
			call _ft_isdigit
			cmp rax, 1					; was it a digit ?
			jne .exit
.success:	mov rax, TRUE
.exit:		ret
