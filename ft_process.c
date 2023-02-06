#include "ft_printf.h"

void	ft_process_no_width(t_ListOfFlags *flag, t_ListOfSizes *width, int arg) // Cas 1 et Cas 2
{
	if(ft_flag_detect(flag) == FOUND)
	{
		if (flag->plus != -1 && arg >= 0)// flag + ou + and ' '
			write(1, "+", 1);
		else if (flag->space != -1 && flag->plus == -1) // flag ' '
			write(1, " ", 1);
	}
	return (ft_putstr_free(ft_itoa(arg)));
}


void	ft_write_appending_flags(t_ListOfFlags *lof, int arg)
{
	if (lof->plus != -1 && arg > 0)
		write(1, "+", 1);
	else if (lof->space != -1 && lof->plus == -1)
		write(1, " ", 1);

}
void	ft_process_one_width(t_ListOfFlags *flag, t_ListOfSizes *width, int arg) // Cas 3 et 4
{
	if(width->padding > ft_count_digits(arg)) // cas commun cas 3 et cas 4
	{	
		if (ft_flag_detect(flag) == FOUND)
		{
			ft_write_appending_flags(flag, arg);
			if (flag->zero != -1 || flag->precis != -1) // '||' operator for call from ft_process_two_widths_flag
			{
				ft_putlenchar('0', (width->afp - ft_count_digits(arg)));
				ft_putstr_free(ft_itoa(arg));
			}
			else if (flag->hyphen != -1)
			{
				ft_putstr_free(ft_itoa(arg));
				ft_putlenchar(' ', width->afp - ft_count_digits(arg));
			}
		}
		else 
		{
			//if ( flag->precis == -1) // to differenciate from externe function.
			ft_putlenchar(' ', (width->padding - ft_count_digits(arg)));
			ft_putstr_free(ft_itoa(arg));
		}
	}
	else 
		return(ft_putstr_free(ft_itoa(arg)));
}

void	ft_process_two_widths_no_flag(t_ListOfFlags *flag, t_ListOfSizes *width, int arg)
{
	if (width->bfp > ft_count_digits(arg) && width->bfp > width->afp)
	{
		if (width->afp > ft_count_digits(arg))
		{
			ft_putlenchar(' ', (width->bfp - width->afp));
			ft_putlenchar('0', (width->afp - ft_count_digits(arg)));
		}
		else 
			ft_putlenchar(' ', width->bfp - width->afp);
	}
	else if (width->afp > ft_count_digits(arg))
			ft_putlenchar('0', (width->afp - ft_count_digits(arg)));
	return (ft_putstr_free(ft_itoa(arg)));
}

void	ft_process_two_widths_flag(t_ListOfFlags *flag, t_ListOfSizes *width, int arg)
{
	if (width->bfp > ft_count_digits(arg) && width->bfp > width->afp
		&& width->afp > ft_count_digits(arg)) // REDUCEEEEEEE
	{
		ft_write_appending_flags(flag, arg);
		if (flag->hyphen != -1)
		{	
			ft_putlenchar('0', (width->afp - ft_count_digits(arg)));
			ft_putstr_free(ft_itoa(arg));
			ft_putlenchar(' ', (width->bfp - width->afp));
		}
		else 
		{
			ft_putlenchar(' ', (width->bfp - width->afp));
			ft_putlenchar('0', (width->afp - ft_count_digits(arg)));
			ft_putstr_free(ft_itoa(arg)); 
		}
	}
	else if (width->afp > ft_count_digits(arg)) 
		ft_process_one_width(flag, width, arg);
	return ;	
}

void	ft_process(t_ListOfFlags *flag, t_ListOfSizes *width, int arg)
{

	if (width->bfp == -1 && width->padding == -1) // No widths 
		ft_process_no_width(flag, width, arg);
	else if (width->padding != -1) // One width
		ft_process_one_width(flag, width, arg);
	else if (width->afp != -1 && width->bfp != 1) // Two widths
	{	
		if (ft_flag_detect(flag) == FOUND)
			ft_process_two_widths_flag(flag, width, arg);
		else 
			ft_process_two_widths_no_flag(flag, width, arg);
	}
	return ;	
}