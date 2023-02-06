#include "ft_printf.h"

//OUTPUT
int		ft_putchar(char a)
{
		return (write(1, &a, 1));
}
void	ft_putstr_free(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
	return(free(str));
}
void	ft_putformat(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == '\\')
		{	
			write(1, "\\", 1);
			i++;
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

void	ft_putlenchar(char to_print, int len)
{
	while (len)
	{
		write(1, &to_print, 1);
		len--;
	}
	return; 
}


//CONVERSIONS
char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		end;
	long	nb;

	end = 0;
	nb = n;
	i = ft_nbchar(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		end = 1;
	}
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}

char		*ft_llitoa(long long int n)
{
	char	*res;
	int		i;
	int		end;
	long long int	nb;

	end = 0;
	nb = n;
	i = ft_nbchar(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		end = 1;
	}
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{		
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}
//DATA 

	//LEN

int	ft_nbchar(int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nb = 1;
		n = -n;
	}
	while (n / 10 > 0)
	{
		nb++;
		n = n / 10;
	}
	nb++;
	return (nb);
}

size_t		ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	
	return (i);
}

size_t		ft_strlen_break(const char *s, char *stop)
{	
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if(s[i] == *stop)
			break ;
		i++;
	}
	
	return (i);
}

int			ft_strlen_p_brut(const char *str)
{
	char	*conv_spec;
	int		i;
	int		j;

	i = 0;
	j = 0;
	conv_spec = ft_strdup("diuxXcsp");
	while (str[i])
	{
		while (conv_spec[j] != '\0')
		{
			if (str[i] == conv_spec[j])
				return(i);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

size_t		ft_strlen_tab(const char **tab)
{	
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int			ft_count_digits(int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nb = 1;
		n = -n;
	}
	while (n / 10 > 0)
	{
		nb++;
		n = n / 10;
	}
	nb++;
	return (nb);
}

int			ft_strlen_arg(int n)
{
	size_t	size;
	
	size = ft_strlen(ft_itoa(n));
	return (size);


}
	//COUNT
int			ft_count_args(char *str)
{
	int		i;
	int		two_modulos_in_a_row;
	int		count;

	i = 0;
	two_modulos_in_a_row = 0;
	count = 0;
	if (!str)
		return 0;
	while (str[i])
	{
		if (str[i] == '%')
		{	
			count++;
			two_modulos_in_a_row++;
			if (two_modulos_in_a_row == 2)
				count -= 2;
		}
		if (i % 2 == 0)
			two_modulos_in_a_row = 0;	
		i++;
	}
	return (count);
}

	//ID

char	ft_sign(int nb)
{
	if (nb < 0)
		return ('-');
	return ('\0');
}
char		ft_conv_id(char *str)
{
	char	*conv_spec;
	int		i;
	int 	j;

	conv_spec = ft_strdup("diuxXcsp");
	i  = 0;
	j = 0;
	while (str[i])
	{
		while (conv_spec[j] != '\0')
		{
			if (str[i] == conv_spec[j])
				return(free(conv_spec), str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (free(conv_spec), '\0');
}
void 		ft_flag(char *brut, t_ListOfFlags *lof)
{
	int		i;

	i = 0;
	while (brut[i])
	{
		if (brut[i] == '0')
			lof->zero = 1;
		if (brut[i] == '-')
			lof->hyphen = 1;
		if (brut[i] == '+')
			lof->plus = 1;
		if (brut[i] == '#')
			lof->hashtag = 1;
		if (brut[i] == ' ')
			lof->space = 1;
		if (brut[i] == '.')
			lof->precis = 1; 	
		i++;
	}
	return ;
}

int		ft_conv_pos(char *format)
{
	char 	*set_conv;
	int 	i;
	int		j;

	j = 0;
	i = 0;
	set_conv = strdup("iduxXscp");
	while (format[j] && format[j] != '%') //?? got_to_modulo
		j++;
	while (format[j])
	{
		while (set_conv[i] != '\0')
		{
			if (format[j] == set_conv[i])
				return (free(set_conv), j);
			i++;
		}
		i = 0;
		j++;
	}
	return (free(set_conv), -1);
}
int			ft_flag_detect(t_ListOfFlags *lof)
{

	if (lof->plus != -1)
		return (FOUND);
	if (lof->zero != -1)
		return (FOUND);
	if (lof->precis != -1)
		return (FOUND);	
	if (lof->space != -1)
		return (FOUND);
	if (lof->hyphen != -1)
		return (FOUND);
	else 
		return (FREE);	
}
int		ft_check_dot(char *brut)
{
	while(*brut)
	{
		if(*brut == '.')
			return (TRUE);
		brut++;
	}
	return (FALSE);
}

/*int		ft_width_dot_tot(char *brut)
{
	int		i;
	int		j;
	int		itot;
	char	*chartot;


	chartot = malloc(12);
	i = 0;
	j = 0;
	while (*brut >= '0' && *brut <= '9')
		i--;
	while (*brut >= '0' && *brut <= '9')
		chartot[j++] = brut[i++]; 
	chartot[++j] = '\0';
	itot = ft_atoi(chartot);
	return (itot);
}*/
int		ft_char_conv_id(char a)
{
	char 	*set_conv;
	int		i;
	
	i = 0;
	set_conv = strdup("iduxXscp");
	while (set_conv[i] != '\0')
	{
		if (set_conv[i] == a)
			return (free(set_conv), TRUE);
		i++;
	}
	return (free(set_conv), FALSE);
}


//CREATE / MODIF
char		*ft_strdup_bytes_free(char *source, int n)
{
	char	*dest;
	int	i;

	i = 0;
	dest = malloc(ft_strlen(source) + 1);
	if (!dest || !source)
		return (NULL);
	while (source[i] && i < n)
	{
		dest[i] = source[i];
		i++;
	}
	free(source);
	return (dest);
}

char		*ft_strdup(char *source)
{
	char	*dest;
	int	i;

	i = 0;
	dest = malloc(ft_strlen(source) + 1);
	if (!dest || !source)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char		*ft_memset(char *ptr, char c, size_t n)
{	
	size_t	i;

	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (ptr);
}

//DIVERS

void		ft_clean(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
} 



