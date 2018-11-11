#include <stdio.h>

int	ft_verif(char tab[9][9], int col, int line)
{
	int i;

	i = 1;
	while(col - i >= 0 && line - i >= 0)
	{
		if (tab[line - i][col - i] != '0')
			return (0);
		i++;	
	}
	i = 1;
	while(col + i < 8 && line - i >= 0)
	{
		if (tab[line - i][col + i] != '0')
			return (0);
		i++;
	}
	i = 1;
	while(line - i >= 0)
	{
		if (tab[line - i][col] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_recurs(char tab[9][9], int line, int *count)
{
	int	col;

	col = 0;
	while(tab[line][col])
	{
		if (ft_verif(tab, col, line) && line != 7)
		{
			tab[line][col] = '1';
			ft_recurs(tab, line + 1, count);
			tab[line][col] = '0';
		}
		if (ft_verif(tab, col, line) && line == 7)
			*count += 1;
		col++;
	}
	return (0);
}

int main(void)
{
	char	tab[9][9];
	int	i;
	int	j;
	int	count;

	tab[8][0] = 0;
	i = 0;
	count = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			tab[i][j] = '0';
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	ft_recurs(tab, 0, &count);
	printf("%d", count);
}
