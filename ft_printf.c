#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	
	va_list			next;
	union			Arg arg;
	int				i;
	int				pos_mod;

	i = 0;
	// WHEN NO ARGS
	if (ft_count_args(format) == 0) 
	{
		ft_putformat(format);
		return ((int)ft_strlen(format));
	}

	// WHEN ARGS EXIST
	va_start(next, format);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%') // got to modulo
			ft_putchar(format[i++]);
		pos_mod = i;
		i = ft_conv_pos(format + pos_mod) + i;
		if (format[i] == 'd' || format[i] == 'i')
		{	
			arg.i = va_arg(next, int);
			ft_look_through_int(format + pos_mod , arg.i);
		}
		/*
		if (find_conv == 'u')
		{
			args = (int)va_arg(args, unsigned int)
			args_converted = ft_format_spec()
			ft_putstr(arg_convertd);

		}
		//CHAR TYPE
		if (conv_encountered == 'c')
		{	
			va_arg(args, char);
			arg_converted = ft_chartochar(args);
		}
		//POINTER TYPE
		if (conv_encountered == 's')
		{
			va_args(args, char *);
			arg_converted = ft_strtostr(args);
		}
		ft_putstr(arg_converted);
		//i += ft_strlen(arg_converted); */
		i++;	
	}
	return (i);
}