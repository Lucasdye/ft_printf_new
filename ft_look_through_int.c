#include "ft_printf.h"


void	ft_initialise_list(t_ListOfFlags *lof, t_ListOfSizes *los, int arg)
{

	lof->plus = -1;
	lof->zero = -1;
	lof->precis = -1;	
	lof->space = -1;
	lof->hyphen = -1;
	los->bfp = -1;
	los->afp = -1;
	los->padding = -1;
	los->len_nb = ft_count_digits(arg);
}

int		ft_look_through_int(char *brut_data, int arg)
{
	t_ListOfSizes	width;
	t_ListOfFlags 	lof;
	char		str_flags;
	char		sign_arg;
	char	*tmp;

	ft_initialise_list(&lof, &width, arg);
	ft_width(brut_data, &width);
	ft_flag(brut_data, &lof);
	sign_arg = ft_sign(arg);
	ft_process(&lof, &width, arg);
	return (ft_conv_pos(brut_data));
} 