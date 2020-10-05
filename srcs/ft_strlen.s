			global		ft_strlen
			section		.text
ft_strlen:
			mov			rax, 0
			push		rdi
compare:	cmp			byte [rdi], 0
			jz			done
			inc			rax
			inc			rdi
			jmp			compare
done:		pop rdi
			ret