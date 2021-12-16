/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:21:04 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 17:09:41 by tkirihar         ###   ########.fr       */
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
		g_mem_info[i].func = NULL;
		i++;
	}
}

/* メモリ確保とそのメモリの情報を記録する関数 */
void	*leak_checker_malloc(size_t size, const char *file, unsigned int line, const char *func)
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
			g_mem_info[i].func = func;
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
			g_mem_info[i].func = NULL;
			break ;
		}
		i++;
	}
	free(ptr);
}

/* 解放が行われていないメモリの情報を表示し、プログラムを終了する関数 */
void	leak_checker_finish_check(int n)
{
	size_t	i;

	printf("\x1b[33m========メモリリークを検出!!!!========\x1b[39m\n");
	i = 0;
	while (i < MAX_NUM)
	{
		if (g_mem_info[i].ptr != NULL)
		{
			printf(" アドレス : %p\n", g_mem_info[i].ptr);
			printf(" サイズ   : %zuバイト\n", g_mem_info[i].size);
			printf(" 場所     : %s:%u行目:%s関数\n", g_mem_info[i].file, g_mem_info[i].line, g_mem_info[i].func);
			printf("\x1b[33m======================================\x1b[39m\n");
		}
		i++;
	}
	exit(n);
}

void	leak_checker_check(const char *file, unsigned int line, const char *func)
{
	size_t	i;

	printf("\x1b[33m==%s:%u行目:%s関数のヒープ領域==\x1b[39m\n", file, line, func);
	i = 0;
	while (i < MAX_NUM)
	{
		if (g_mem_info[i].ptr != NULL)
		{
			printf(" アドレス : %p\n", g_mem_info[i].ptr);
			printf(" サイズ   : %zuバイト\n", g_mem_info[i].size);
			printf(" 場所     : %s:%u行目:%s関数\n", g_mem_info[i].file, g_mem_info[i].line, g_mem_info[i].func);
			printf("\x1b[33m======================================\x1b[39m\n");
		}
		i++;
	}
}
