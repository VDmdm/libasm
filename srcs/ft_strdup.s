			global		ft_strdup
			extern		ft_strlen
			extern		ft_strcpy
			extern		malloc
			section		.text
ft_strdup:	call		ft_strlen
			inc			rax
			push		rdi
			push		rsi
			mov			rdi, rax
			call		malloc
			pop			rsi
			pop			rdi
			cmp			rax, 0
			jz			exit
			push		rsi
			mov			rsi, rdi
			mov			rdi, rax
			call		ft_strcpy
			pop 		rsi
			ret
exit:		mov			rax, 0
			ret