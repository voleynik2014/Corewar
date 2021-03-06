#ifndef MAIN_H
#define MAIN_H

#include "op.h"
#include "../new_libft/srcs/libft.h"
#include <fcntl.h>

typedef struct			s_data
{
	char				**arr;
	int					i;
	size_t				size;
}						t_data;

typedef struct			s_array_string
{
	char 				**arr;
	int 				i;				//str count
	size_t 				size;
}						t_array_string;

typedef struct			s_label_table
{
	char 				*link;
	int 				offset;
	void				*next;
}						t_label_table;

typedef struct			s_bcode
{
	char 				*op;
	char 				*op_code;
	int 				*args;
	void				*next;
}						t_bcode;


//typedef enum e_op
//{
//	live = 1, ld, st, add ,sub, and, or, xor, zjmp,
//	ldi, sti, _fork, lld, lldi, lfork, aff
//};

/*
**	array_string.c
*/
t_array_string	*new_array_string(size_t size);
int				realloc_array_string(t_array_string **arr);
void			del_array_string(t_array_string **arr);
int 			add_str_to_array_string(t_array_string *arr, char *str);
void 			print_array_string(t_array_string *arr);
void			print_string(t_array_string *arr);

/*
**	split_line.c
*/
t_array_string	*split_line(char *code);

/*
**	data_constructor.c
*/
void		realloc_data(t_data **src);
void		del_all_data(t_data **data);
void		del_data(t_data *data);
t_data		*new_data(size_t size);
void		print_data(t_data *data);
void		read_data(int fd, t_data **data);

/*
** lex_analyze.c
*/
t_array_string		**lex_analyze(t_data *code);
void				print_lex(t_array_string **lex_strs);
void				del_lex_strs(t_array_string ***str);

/*
** syntax_analyze.c
*/
void		syntax_analyze(t_array_string **lex_strs);

/*
** label_table.c
*/
t_label_table		*new_label_table(char *name, int offset);
void				del_label_table(t_label_table **table);
void				print_label_table(t_label_table *table);
void				add_label_to_table(t_label_table **table, t_label_table *label);
t_label_table		*find_label_by_name(t_label_table *table, char *name);

/*
** bcode.c
*/
t_bcode				*new_bcode(char op, char op_code, int *args);
void				del_bcode(t_bcode **bcode);
void				print_bcode(t_bcode *bcode);
void				add_bcode(t_bcode **table, t_bcode *code);

/*
** command_live.c
*/
void				command_live(t_array_string *lex_str, t_bcode **bcode, t_label_table *table, int *pc);

/*
** command_ld.c
*/
void				command_ld(t_array_string *lex_str, t_bcode **bcode, t_label_table *table, int *pc);

/*
* is_number.c
*/
int 				is_number(const char *str);
int 				is_empty_line(const char *str);
int 				is_link(const char *str);
int 				is_register(const char *str);

/*
** get_op_code.c
*/
int 		get_op_code(t_array_string *lex_str, char *op, int i, int pair_bit);

#endif
