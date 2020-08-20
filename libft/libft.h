/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:24:59 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:16:35 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

uint32_t			ft_abs(int32_t n);
int32_t				ft_max(int32_t n1, int32_t n2);
void				ft_assert(int_fast32_t to_check, const char *func,
					const char *message);
void				*ft_calloc(size_t n_elem, size_t elem_size);
int32_t				ft_divmod(int32_t dividend, int32_t divisor,
					int32_t *remainder);
size_t				ft_intlen(register int32_t n);
long double			ft_long_pow(long double base,
					register int_fast16_t power);
size_t				ft_longlen(register int64_t n);
int32_t				ft_moddiv(int32_t dividend, int32_t divisor,
					int32_t *quotient);
double				ft_pow(double base, register int_fast16_t power);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void				ft_strrev(register char *begin, register char *end);
size_t				ft_uitoa_base(uint32_t value, char *buff,
					int_fast16_t base, int_fast16_t is_upper);
size_t				ft_uitoa_dec(uint32_t val, char *buff);
size_t				ft_uitoa_hex(uint32_t value, char *buff,
					int_fast16_t is_upper);
size_t				ft_ultoa_base(uint64_t value, char *buff,
					int_fast16_t base, int_fast16_t is_upper);
size_t				ft_ultoa_hex(uint64_t value, char *buff,
					int_fast16_t is_upper);
void				*ft_memset(void *b, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memswap(void *mem1, void *mem2, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmpi(char const *s1, char const *s2);
char				*ft_strndup(const char *s1, size_t n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
double				ft_atof(const char *str);
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strrew(char const *str, int (*cmp)(int));
char				*ft_strnew(size_t size);
void				ft_strdel(char **ar);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strequ_ignore_case(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_words_count(char const *s, char delimiter);
char				*ft_strtolower(char *str);
int					ft_strany(char const *str, int c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_put_unicode(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstprint(t_list *list, int isstr);
int					ft_lst_getinx(t_list *list, void *content, size_t size);
void				ft_lstdelinx(t_list **alst, int inx,
					void (*del)(void*, size_t));
void				ft_lstrev(t_list **alst);
void				ft_log_error(const char *message, const char *cause,
					const char *func, const char *file);
void				ft_log_info(const char *message, const char *desc,
					const char *func, const char *file);
#endif
