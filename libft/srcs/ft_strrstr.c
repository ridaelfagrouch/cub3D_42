

#include "../libft.h"

/* -------------------------------------------------------------------------- */

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] || needle[j] == '\0')
			if (needle[j++] == '\0')
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */
