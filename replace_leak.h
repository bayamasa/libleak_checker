/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_leek.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:57:20 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 11:59:44 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_LEEK_H
# define REPLACE_LEEK_H

# define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
# define free leak_detect_free
# define exit(n) leak_detect_check(n)

#endif
