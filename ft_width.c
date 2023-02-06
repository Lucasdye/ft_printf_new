#include "ft_printf.h"

int		ft_go_to_width(char *brut)
{
	int		i;

	i = 0;
	while (brut[i] != '\0' && ft_char_conv_id(brut[i]) == FALSE && (brut[i] <= '0' || brut[i] > '9'))
		i++;
	if (brut[i] == '\0' ||  ft_char_conv_id(brut[i]) == TRUE)
		return (i);
	if (brut[i] == '0') //ignore '0' flag
		i++;
	while (brut[i] && (brut[i] <= '0' || brut[i] > '9') && ft_char_conv_id(brut[i]) == FALSE)
		i++;
	return (i);
}

void			ft_width(char *brut, t_ListOfSizes *width)
{
	char			*width_char;
	int				i;
	int 			j;

	i = 0;
	brut = brut + ft_go_to_width(brut);
	if (*brut == '\0' || ft_char_conv_id(*brut) == TRUE)
		return ;
	width_char = ft_strdup("           ");
	while (brut[i] >= '0' && brut[i] <= '9' && i <= 11)
	{
		width_char[i] = brut[i];
		if (brut[i] == '.')
		{
			width_char[++i] = '\0';
			width->bfp = ft_atoi(width_char);
			width_char = ft_memset(width_char, 0, 12);
		}	
		i++;
	}
	width_char[i] = '\0';
	if (width->bfp != -1 && width_char[0] != '\0')
		width->afp = ft_atoi(width_char);
	else 
		width->padding = ft_atoi(width_char);
	return (free(width_char)) ;
}