/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:21:02 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 11:59:48 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAK_CHECKER_H
# define LEAK_CHECKER_H

# include <stdlib.h>
# include <stdio.h>

/* 管理数の上限 */
# define MAX_NUM 500

/* メモリ管理構造体 */
typedef struct s_mem
{
	void			*ptr;
	size_t			size;
	const char		*file;
	unsigned int	line;
}	t_mem;

/* 関数のプロトタイプ宣言 */
void	leak_detect_init(void);
void	*leak_detelc_malloc(size_t size, const char *file, unsigned int line);
void	leak_detect_free(void *ptr);
void	leak_detect_check(int n);

#endif
