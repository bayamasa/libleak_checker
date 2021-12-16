/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_leak.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:57:20 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 15:58:04 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_LEAK_H
# define REPLACE_LEAK_H

# define malloc(s) leak_checker_malloc(s, __FILE__, __LINE__, __FUNCTION__)
# define free leak_checker_free
# define exit(n) leak_checker_check(n)

#endif
