						global		ft_list_remove_if
						extern		free
						section		.text
ft_list_remove_if:		cmp			rdi, 0
						je			null_ptr
						cmp			qword [rdi], 0
						je			null_ptr
						cmp			rsi, 0
						je			null_ptr
						push		r8
						push		r9
						push		rcx
						push		rdi
						push		rsi
						push		rdx
						xor			r9, r9
						xor			r8, r8
						mov			r8, rdi
						mov			r9, qword [rdi]
compare:				cmp			r9, 0
						je			exit
						mov			rax, qword [r9]
						cmp			rax, 0
						je			exit
						mov			rdi, rax
						pop			rdx
						pop			rsi
						push		rsi
						push		rdx
						call		rdx
						cmp			rax, 0
						jne			different
						call 		free
						mov			rcx, qword [r9 + 8]
						push		rcx
						mov			rdi, r9
						call 		free
						pop			rcx
						pop			rdx
						pop			rsi
						pop			rdi
						push		rdi
						push		rsi
						push		rdx
						cmp			r8, rdi
						jne			not_first
						mov			qword [r8], rcx
						mov			r9, qword [r8]
						jmp			compare
not_first:				mov			[r8 + 8], rcx
						mov			r9, [r8 + 8]
						jmp			compare
different:				mov			r8, r9
						mov			r9, qword [r9 + 8]
						jmp			compare
exit					pop			rdx
						pop			rsi
						pop			rdi
						pop			rcx
						pop			r9
						pop			r8
null_ptr:				ret