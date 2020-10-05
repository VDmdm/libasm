			global		ft_strcpy
			section		.text
ft_strcpy:	
			push		rdi
			push		rsi
copy:		cmp			byte [rsi], 0
			mov			al, [rsi]
			mov			[rdi], al
			jz			done
			inc			rdi
			inc			rsi
			jmp			copy
done:		pop rsi
			pop rdi
			mov	rax, rdi
			ret