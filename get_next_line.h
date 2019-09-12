/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:29:09 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/12 16:02:05 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32

int						get_next_line(const int fd, char **line);

typedef struct			s_rfile
{
	int					cfd;
	char				*content;
	struct s_rfile		*next;
}						t_rfile;

#endif
