/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:21:04 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 15:36:30 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leak_checker.h"

/* メモリ情報を格納する構造体の配列 */
t_mem	g_mem_info[MAX_NUM];

/* メモリ管理配列を初期化する関数 */
void	leak_checker_init(void)
{
	size_t	i;

	i = 0;
	while (i < MAX_NUM)
	{
		g_mem_info[i].ptr = NULL;
		g_mem_info[i].size = 0;
		g_mem_info[i].file = NULL;
		g_mem_info[i].line = 0;
		i++;
	}
}

/* メモリ確保とそのメモリの情報を記録する関数 */
void	*leak_checker_malloc(size_t size, const char *file, unsigned int line)
{
	size_t	i;
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < MAX_NUM)
	{
		if (g_mem_info[i].ptr == NULL)
		{
			g_mem_info[i].ptr = ptr;
			g_mem_info[i].size = size;
			g_mem_info[i].file = file;
			g_mem_info[i].line = line;
			break ;
		}
		i++;
	}
	return (ptr);
}

/* メモリの確保とそのアドレスのメモリ情報を記録から削除する関数 */
void	leak_checker_free(void *ptr)
{
	size_t	i;

	i = 0;
	while (i < MAX_NUM)
	{
		if (g_mem_info[i].ptr == ptr)
		{
			g_mem_info[i].ptr = NULL;
			g_mem_info[i].size = 0;
			g_mem_info[i].file = NULL;
			g_mem_info[i].line = 0;
			break ;
		}
		i++;
	}
	free(ptr);
}

/* 解放が行われていないメモリの情報を表示し、プログラムを終了する関数 */
void	leak_checker_check(int n)
{
	size_t	i;

	i = 0;
	while (i < MAX_NUM)
	{
		if (g_mem_info[i].ptr != NULL)
		{
			printf("\x1b[33m==メモリリークを検出!!!!!==\x1b[39m\n");
			printf(" アドレス:%p\n", g_mem_info[i].ptr);
			printf(" サイズ:%zu\n", g_mem_info[i].size);
			printf(" 場所:%s:%u\n", g_mem_info[i].file, g_mem_info[i].line);
			printf("\x1b[33m===========================\x1b[39m\n");
		}
		i++;
	}
	exit(n);
}
