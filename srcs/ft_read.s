			global		ft_read
			extern		__errno_location
			section		.text
ft_read:	push		rdi
			mov			rax, 0
			syscall
			cmp			rax, 0
			jl			errorret
			pop			rdi
			ret
errorret:	push		rax
			call		__errno_location
			mov			rdi, rax
			pop			rax
			neg			rax
			mov			[rdi], rax
			mov			rax, -1
			pop			rdi
			ret