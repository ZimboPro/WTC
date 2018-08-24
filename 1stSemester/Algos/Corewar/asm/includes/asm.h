/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 20:42:04 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "op.h"
# include "../../libft/libft.h"

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_binary
{
	t_header		header;
	int				fd;
	int				cursor;
	char			*name;
}					t_binary;

typedef	struct		s_src_line
{
	int				num;
	char			*label;
	int				acb;
	char			*params[MAX_ARGS_NUMBER];
	int				param_type[MAX_ARGS_NUMBER];
	int				opcode;
	int				bytes;
}					t_src_line;

typedef struct		s_norm
{
	int				i;
	int				p;
	int				j;
	int				label_found;
	int				op_code_found;
	int				params_found;
	char			*exe;
	char			**split;
}					t_norm;

int					is_valid_fd(int fd);
int					is_comment(char *line);
int					is_opcode(char *line);
int					is_label_address(char *line);
int					get_size(int fd);
void				print_struct(t_src_line*lines);
void				champ_size(t_src_line *lines, t_binary *bin);
void				write_bytes(int fd, t_src_line *lines);
t_src_line			*build_line_data_struct(int fd, int n);
char				**core_line_split(char const *s);
int					is_param(char *line);
int					get_params(t_src_line *lines);
int					get_acb(t_src_line *lines);
int					get_bytes(t_src_line *lines);
int					init_bin_var(t_binary *bin, int fd, char *name);
int					is_code_line(char **line);
int					write_cor(t_src_line *lines, t_binary *bin);
int					check_idx(int op);
int					check_errors(t_src_line *lines);
int					get_offset(t_src_line *lines, char *line);
int					ft_abs(int n);
int					set_params(t_src_line *lines);
int					check_registers(t_src_line line, int p);
void				free_lines(t_src_line *lines);
void				reverse_bytes(int *mem, size_t size);
void				write_bytes(int fd, t_src_line *lines);
void				write_opcode_and_acb(t_src_line line, int fd);
void				write_register(char *line, int fd);
void				write_direct(t_src_line line, int fd, int p);
void				print_error(char *str, int line_num);
void				write_indirect(char *line, int fd);
void				write_label_adrs(t_src_line *lines,
		char *line, int fd, int i);

#endif
