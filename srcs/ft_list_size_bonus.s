						global		ft_list_size
						extern		malloc
						section		.text
ft_list_size:			mov			rax, 0
						push		rdi
start_loop:				cmp			rdi, 0
						je			exit
						mov			rdi, [rdi + 8]
						inc			eax
						jmp			start_loop
exit					pop			rdi
						ret