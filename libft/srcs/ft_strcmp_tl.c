
#include "../libft.h"

int	ft_strcmp_tl(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)ft_tolower(s1[i]) - \
		(unsigned char)ft_tolower(s2[i]));
}
