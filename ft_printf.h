#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef GREEN
#  define GREEN "\033[0;32m" 
# endif
# ifndef RESET_COLOR
#  define RESET_COLOR "\x1b[0m"
# endif
# ifndef YELLOW
#  define YELLOW "\033[0;33m"
# endif
# ifndef RED
#  define RED "\033[0;31m"
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef FOUND 
#  define FOUND 1
# endif
# ifndef FREE 
#  define FREE 0
# endif 

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

union Arg 
{
	int	i;
	unsigned int ui;
	unsigned long long int ulli; //ulli compatibility at least 64 bits, does not depend on architecture. 
	char	*str;
	void	*p;
	char	c;
};

typedef struct s_ListOfSizes
{
	int	bfp;
	int	afp;
	int	padding;
	int	len_nb;
}				t_ListOfSizes;

typedef struct s_ListOfFlags
{
	int	zero;
	int	plus;
	int	hashtag;
	int	precis;
	int	space;
	int	hyphen;
} 				t_ListOfFlags;

int		ft_atoi(const char *str);
int		ft_atoi_printf(int nb, const char *flag);
int		ft_char_cmp(char src, char cmp);
char	ft_conv_id(char *str);
int		ft_count_args(char *format);
char	ft_checkid_conv_spec(char *str);
char	ft_checkid_flags(char *str);
int		ft_checkid_width(char *brut);
int		ft_count_digits(int arg);
void	ft_clean(char **tab);
//int		main();
int		ft_flag_detect(t_ListOfFlags *lof);
void	ft_format_spec(char *brut_data, int conv);
void 	ft_flag(char *brut, t_ListOfFlags *lof);
char	*ft_go_to_conv(char *brut_data);
int		ft_look_through_int(char *brut_data, int arg);
char	*ft_itoa(int n);
int		ft_nbchar(int n);
int		ft_printf(char *format, ...);
void	ft_process(t_ListOfFlags *flag, t_ListOfSizes *width, int arg);
void	ft_printf_format_spec(int conv, int pad, char *raw);
int		ft_putchar(char a);
void	ft_putformat(char *str);
int		ft_char_conv_id(char a);
void	ft_putstr_free(char *str);

char	*ft_memset(char *ptr, char c, size_t n);
void	ft_putlenchar(char to_print, int len);
char	ft_sign(int nb);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_tab(const char **tab);
size_t	ft_strlen_break(const char *s, char *stop);
int		ft_strlen_p_brut(const char *str);
int		ft_strlen_arg(int n);
char	*ft_strdup(char *source);
char	*ft_strdup_bytes_free(char *source, int n);
void	ft_width(char *brut, t_ListOfSizes *width);
int		ft_conv_pos(char *format);

#endif