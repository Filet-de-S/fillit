#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 20

void	print_char(char **arr, int i, int j)
{
	int a;
	int b;
	
	a = 0;
	b = 0;
	while (a < i)
	{
		while (b < j)
		{
			write(1, &arr[a][b], 1);
			b++;
		}
		write(1, "\n", 1);
		b = 0;
		a++;
	}
}

char	**create_arr(int i, int j)
{
	int index;
	char **arr;
	
	index = 0;
	arr = (char**)malloc(i * sizeof(char*));
	while (index < j)
	{
		arr[index] = (char*)malloc(j * sizeof(char));
		index++;
	}
	return (arr);
}

char	**clip_figure(char **cnt, int *min, int *max)
{
	int	i;
	int	j;
	int x;
	int y;
	char **new_map;
	
	i = min[0];
	j = min[1];
	x = 0;
	y = 0;
	printf("%d\n", max[1]);
	new_map = create_arr(max[0] - min[0] + 1, max[1] - min[1] + 1);
	while (i <= max[0] - min[0])
	{
		write(1, "OK\n", 3);
		while (j <= max[1] - min[1])
			new_map[x][y++] = cnt[i][j++];
		j = min[1];
		y = 0;
		x++;
		i++;
	}
	return (new_map);
}

char    **deleft(char **cnt, int *min, int *max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{

			if (cnt[i][j] != '.')
			{
				if ((min[0] > i) || (min[0] == -1))
					min[0] = i;
				if ((min[1] > j) || (min[1] == -1))
					min[1] = j;
				if (max[0] < i)
					max[0] = i;
				if (max[1] < j)
					max[1] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	cnt = clip_figure(cnt, min, max);
	return (cnt);
}



int main(void)
{
	int		i;
	int		j;
	char	**mas;
	int		*arr1;
	int		*arr2;

	arr1 = (int*)malloc(sizeof(int) * 2);
	arr1[0] = -1;
	arr1[1] = -1;
	arr2 = (int*)malloc(sizeof(int) * 2);
	arr2[0] = -1;
	arr2[1] = -1;
	i = 0;
	j = 0;
	mas = create_arr(4,4);
	while (i < 4)
	{
		while (j < 4)
		{
			mas[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	mas[0][0] = 'A';
	mas[1][0] = 'A';
	mas[2][0] = 'A';
	mas[3][0] = 'A';
	mas = deleft(mas, arr1, arr2);
	write(1, "OK\n", 3);
	print_char(mas, 4, 4);
}
