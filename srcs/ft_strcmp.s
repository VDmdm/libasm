			global		ft_strcmp
			section		.text
ft_strcmp:
			mov			rax, 0
			push		rdi
			push		rsi
compare:	cld
			cmpsb
			jne			done
			cmp			byte [rdi - 1], 0
			je			done
			jmp			compare
done:		mov			al, byte [rdi - 1]
			sub			al, byte [rsi - 1]
			movsx		rax, al
			pop			rsi
			pop			rdi
			ret