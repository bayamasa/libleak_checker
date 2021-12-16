/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_leak.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:57:20 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 13:05:00 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_LEAK_H
# define REPLACE_LEAK_H

# define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
# define free leak_detect_free
# define exit(n) leak_detect_check(n)

#endif
