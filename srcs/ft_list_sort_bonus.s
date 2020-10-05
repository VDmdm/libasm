						global		ft_list_sort
						section		.text
ft_list_sort:			cmp			rdi, 0
						je			null_ptr
						cmp			qword [rdi], 0
						je			null_ptr
						push		rcx
						push 		rdx
						push		rsi
						push		r8
						push		r9
						push		rdi
						mov			r8, rsi
						mov			r9, [rdi]
compare:				xor			rax, rax
						xor			rcx, rcx
						xor			rdx, rdx
						xor			rsi, rsi
						xor			rdi, rdi
						mov			rax, qword [r9 + 8]
						cmp			rax, 0
						je			exit
						mov			rdx, qword [r9]
						mov			rdi, qword [rax]
						mov			rax, r8
						mov			rsi, rdx
						call		rax
						cmp			rax, 0
						jl			sort
increment:				mov			rax, qword [r9 + 8]
						mov			r9, rax
						jmp			compare
sort:					mov			rax, [r9]
						mov			rsi, qword [r9 + 8]
						mov			rdx, qword [rsi]
						mov			qword [rsi], rax
						mov			qword [r9], rdx
						pop			rdi
						mov			r9, [rdi]
						push		rdi
						jmp			compare
exit:					pop			rdi
						pop			r9
						pop			r8
						pop 		rsi
						pop 		rdx
						pop 		rcx
null_ptr:				ret