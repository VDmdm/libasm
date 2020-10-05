						global		ft_list_push_front
						extern		malloc
						section		.text
ft_list_push_front:		cmp			rdi, 0
						je			exit_null
						push		rcx
						push		rdi
						push		rsi
						mov			rdi, 16
						mov			rax, 0
						call		malloc
						pop 		rsi
						pop			rdi
						push		rdi
						push		rsi
						cmp			rax, 0
						je			exit
						mov			rcx, 0
						mov			qword [rax], rsi
						mov			rcx, qword [rdi]
						mov			qword [rax + 8], rcx
						mov			qword [rdi], rax
exit					pop			rsi
						pop			rdi
						pop			rcx
exit_null:				ret