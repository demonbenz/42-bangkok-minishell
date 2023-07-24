/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cmds.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 06:24:51 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/10 21:40:44 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BI_CMDS_H
# define BI_CMDS_H

# include "../src_benz/exec.h"

# define ERR_EXC0 "env: detect unsupported opt"

//int	is_builtin(t_exec *exec); this is make makefile conflict(double declare)
int		run_bcho(char **cmd);
void	bcho_with_text(char **cmd, int first);
int		run_env(char **cmd, char **env);
int		run_pwd(void);

#endif
