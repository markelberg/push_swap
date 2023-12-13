#include "push_swap.h"

static int	strsnum(char const *s, char c)
{
	int	strs;
	int	i;

	strs = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			strs++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (strs);
}

static char	**eachmstr(char *s, char c, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
				j++;
			}
			strs[k] = (char *)ft_calloc((j + 1), (sizeof(char)));
			if (!strs[k])
				return (0);
			k++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (strs);
}

static char	**cpystrs(char *s, char c, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				strs[k][j] = s[i];
				i++;
				j++;
			}
			strs[k][j] = '\0';
			k++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		snum;
	char	**mstrs;

	snum = strsnum(s, c);
	mstrs = (char **)ft_calloc((snum + 1), (sizeof(char *)));
	if (!mstrs)
		return (0);
	return (cpystrs((char *)s, c, eachmstr((char *)s, c, mstrs)));
}