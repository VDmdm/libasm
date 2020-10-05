				global		ft_atoi_base
				section		.text
ft_atoi_base:	push		rdi
				push		rsi
				push		rcx
				cmp			rdi, 0
				je			exit_null
				cmp			rsi, 16
				jg			exit_null
				cmp			rsi, 0
				jle			exit_null
				mov			rax, 1
skip_ws:		cmp			byte [rdi], 9
				jl			exit_null
				cmp			byte [rdi], 13
				jle			inc_skip
				cmp			byte [rdi], 32
				je			inc_skip
				jmp			check_sign
inc_skip:		inc			rdi
				jmp			skip_ws
check_sign:		cmp			byte [rdi], 43
				je			sign
				cmp			byte [rdi], 45
				jne			main_prog
				mov			rax, -1
sign:			inc			rdi
main_prog:		mov			dword [res], 0
				push		rax
				mov			rax, 0
				mov			rcx, 0
check_valid: 	cmp			byte [rdi], 0
				je			exit
				mov			al, byte [rdi]
				cmp			al, [base_low + rcx]
				je			check_num
				cmp			al, [base_up + rcx]
				je			check_num
				inc			rcx
				cmp			rsi, rcx
				jne			check_valid
				jmp			exit
check_num:		cmp			al, 48
				jl			exit
				cmp			al, 57
				jle			found_num
check_al_low:	cmp			al, 65
				jl			exit
				cmp			al, 70
				jle			found_al_low
check_al_up:	cmp			al, 97
				jl			exit
				cmp			al, 102
				jg			exit
found_al_up:	sub			rax, 87
				jmp			res_add
found_al_low:	sub			rax, 55
				jmp			res_add	
found_num:		sub			rax, 48	
res_add:		push		rax
				mov			rax, [res]
				imul		rax, rsi
				mov			[res], rax
				pop			rax
				add			[res], rax
				inc			rdi
				mov			rcx, 0
				jmp			check_valid
				inc			rdi
				mov			rcx, 0
				jmp			check_valid
exit:			pop			rcx
				mov			rax, [res]
				cmp			rcx, -1
				jne			exit_plus
				neg			rax
exit_plus:		pop			rcx
				pop			rsi
				pop			rdi
				ret
exit_null:		pop 		rcx
				pop 		rsi
				pop 		rdi
				mov 		rax, 0
				ret

				section 	.data
base_low:		db 			"0123456789abcdef", 0
base_up:		db 			"0123456789ABCDEF", 0
				section		.bss
res:			resb		32