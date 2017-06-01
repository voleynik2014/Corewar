#include "main.h"

int 		is_error_live(t_array_string *lex_str)
{
	int 	i;

	i = 0;
	if (lex_str->i >= 1 && !ft_strcmp(lex_str->arr[1], ":"))
		i = 2;
	if (lex_str->i > 3 + i && lex_str->arr[i + 3][0] != '#')
	{
		ft_printf("{red}Error:{eoc} {yellow}wrong argument in line: {eoc}");
		print_string(lex_str);
		ft_printf("\n");
		return (1);
	}
	if (lex_str->i < 2 + i || ft_strcmp(lex_str->arr[i + 1], "%"))
	{
		ft_printf("{red}Error:{eoc} {yellow}wrong argument in line: {eoc}");
		print_string(lex_str);
		ft_printf("\n");
		return (1);
	}
	if (!is_number(lex_str->arr[i + 2]))
	{
		ft_printf("{red}Error:{eoc} {yellow}it is not a number in line: {eoc}");
		print_string(lex_str);
		ft_printf("\n");
		return (1);
	}
	return (0);
}

void		command_live(t_array_string *lex_str, t_bcode **bcode, t_label_table *table, int *pc)
{
	int 	i;
	int 	args[3];

    char    op;
    int     ret;

	i = 0;
	ft_bzero(args, sizeof(int) * 3);
	//if (is_error_live(lex_str))
	//	return;
	if (lex_str->i >= 1 && !ft_strcmp(lex_str->arr[1], ":"))
		i = 2;

	op = 0;
	ret = get_op_code(lex_str, &op, i + 1, 1);
	print_string(lex_str);
	ft_printf("ret = %d, OP_CODE = %x\n", ret, op);

	if (ret == 0)
		return ;

	args[0] = ft_atoi(lex_str->arr[i + 2]);
	add_bcode(bcode, new_bcode(1, 0, args));
    *pc += 5;
}
