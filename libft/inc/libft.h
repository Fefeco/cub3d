/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:13:46 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 15:10:48 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t len);
void		*ft_calloc(int count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t size);
int			ft_memcmp(const void *s1, const void *s2, int size);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int n, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Bonus
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *));

// Extra
char		*ft_strnarrcmp(const char *s, const char **arr, size_t size);
bool		ft_isspace(const char c);
char		*ft_rmspaces(const char	*src);
size_t		ft_array_size(const char **array);
void		free_and_null(char **str);

#endif
