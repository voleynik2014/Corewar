#include "main.h"


int			is_error_ld(t_array_string *lex_str, char op)
{
	if (op == (char)0xd0 || op == (char)0x90)
		return (0);
	ft_printf("{red}Error:{eoc} {yellow}wrong argument in line: {eoc}");
	print_string(lex_str);
	ft_printf("\n");
	return (1);
}

void		ld_first_arg(t_array_string *lex_str, int *args, char op, int *i)
{
	if (lex_str->arr[*i][0] == '%')
	{
		args[0] = ft_atoi(lex_str->arr[*i + 1]);
		*i += 2;
	}
	else
	{
		args[0] = ft_atoi(lex_str->arr[*i]);
		*i += 1;
	}
}

void		build_args_ld(t_array_string *lex_str, int *args, char op, int i)
{
	ld_first_arg(lex_str, args, op, &i);
	i++;
	args[1] = ft_atoi(lex_str->arr[i]);
}

void		command_ld(t_array_string *lex_str, t_bcode **bcode, t_label_table *table, int *pc)
{
	int 	i;
	int 	args[3];

	char    op;
	int     ret;

	i = 0;
	ft_bzero(args, sizeof(int) * 3);

	if (lex_str->i >= 1 && !ft_strcmp(lex_str->arr[1], ":"))
		i = 2;

	op = 0;
	ret = get_op_code(lex_str, &op, i + 1, 1);
	print_string(lex_str);
	ft_printf("ret = %d, OP_CODE = %x\n", ret, op);

	if (ret == 0 || is_error_ld(lex_str, op))
		return ;

	build_args_ld(lex_str, args, op, i + 1);
	add_bcode(bcode, new_bcode(2, op, args));
	*pc += 5;

}