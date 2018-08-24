/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:24:43 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:00 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "../../libft/libft.h"

# define P_E "./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

typedef	struct			s_core
{
	char				value[3];
	unsigned char		raw;
	unsigned int		champ_num;
}						t_core;

typedef struct			s_process
{
	int					pc;
	int					player_num;
	char				*player_name;
	int					cycles_to_exec;
	int					carry;
	int					live_calls;
	unsigned char		reg[REG_NUMBER + 1][REG_SIZE + 1];
	struct s_process	*next;
}						t_process;

typedef struct			s_champ
{
	char				*filename;
	int					fd;
	int					player_num;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned int		size;
	unsigned int		stated_size;
	unsigned int		cycles_to_exec;
	int					pc;
	int					carry;
	unsigned int		load_address;
	unsigned char		code[CHAMP_MAX_SIZE + 1];
}						t_champ;

typedef struct			s_env
{
	unsigned int		dump;
	unsigned int		num_players;
	char				player_nums[MAX_PLAYERS];
	t_champ				champs[MAX_PLAYERS];
	t_core				arena[MEM_SIZE];
	t_process			*process;
}						t_env;

typedef struct			s_op_var
{
	int					acb;
	int					p[MAX_ARGS_NUMBER];
	int					t[MAX_ARGS_NUMBER];
}						t_op_var;

typedef union			u_data
{
	int8_t				byte_1;
	int16_t				byte_2;
	int32_t				byte_4;
}						t_data;

void					init_arena(t_env *env);
int						init_env(int argc, char **argv, t_env *env);
int						read_champ_data(t_env *env, int num_players);
void					read_champs_into_core(t_env *env);
void					write_char_to_hex(unsigned char num, char *reg);
void					print_arena(t_env env);
int						is_valid_params(char **params);
int						is_direct(int acb, int param_num);
int						is_indirect(int acb, int param_num);
int						is_register(int acb, int param_num);
int						valid_reg(int num);
int						value_from_core(t_core *arena, int pc, int size);
int						write_to_core(t_core *arena, int pc, int v, int s);
int						value_from_reg(unsigned char *reg);
int						little_to_big_endian(int nb);
int						ft_htoi(char *str, size_t len);
void					write_to_reg(unsigned char *reg, int value);
void					push_proc(t_process **head, t_process *new_p);
void					append_proc(t_process *head, t_process *p);
t_process				*new_proc(t_process *father, int pc);
t_process				*init_process(t_champ *champs, int num_players);
void					del_first_proc(t_process **head);
char					*ft_itoh(int value);
int						game_loop(t_env *env);
int						op_live(t_process *p, t_core *arena);
int						op_ld(t_process *p, t_core *arena);
int						op_st(t_process *p, t_core *arena);
int						op_add(t_process *p, t_core *arena);
int						op_sub(t_process *p, t_core *arena);
int						op_and(t_process *p, t_core *arena);
int						op_or(t_process *p, t_core *arena);
int						op_xor(t_process *p, t_core *arena);
int						op_zjmp(t_process *p, t_core *arena);
int						op_ldi(t_process *p, t_core *arena);
int						op_sti(t_process *p, t_core *arena);
int						op_fork(t_process *p, t_core *arena);
int						op_lld(t_process *p, t_core *arena);
int						op_lldi(t_process *p, t_core *arena);
int						op_lfork(t_process *p, t_core *arena);
int						op_aff(t_process *p, t_core *arena);
int						ft_power(int a, int b);
int						data_var(int pc, t_core *arena, size_t s);
void					init_var(t_op_var *v);
int						data_var_pc(int *pc, t_core *arena, size_t s);
int						pc_counter(int pc, int acb, int param_num);
int						cyc(unsigned char op);
int						exec_proc(t_process *p, t_core *arena);
int						run_processes(t_env *e, int iter);
int						run_processes_dump(t_env *e, int iter);
void					exit_prog(t_env *e);
void					all_zero(char *str, int num);
int						champ_size(void);
typedef int				(*t_op_ptr)(t_process *proc, t_core *arena);
t_op_ptr				g_op_ptr[16];
unsigned int			g_last_alive;

#endif
