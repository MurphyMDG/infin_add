/* ----- HEADER ---- */

#include <unistd.h>
#include <stdlib.h>

char ft_itoa(int i)
{
	return(i + '0');
}

int ft_atoi(char c)
{
	return (c - '0');
}

int ft_strlen(char *s)
{
	return(*s ? ft_strlen(++s) + 1 : 0);
}

void  infin_add(char *s1, char *s2)
{
	int i = ft_strlen(s1) - 1;
	int j = ft_strlen(s2) - 1;
	int max = (i > j) ? i : j;
	char *result;
	int tenth = 0;
	int rest = 0;
	int a = 0;
	int b = 0;
	

	result = malloc(max + 1);
	while (s1[i] || s2[j])
	{
		a = ft_atoi(s1[i]);
		b = ft_atoi(s2[j]);
		((a + b + tenth) > 9) ? (tenth = 1) : (tenth = 0);
		result[max] = ft_itoa((a + b + tenth) % 10);
		write(1, &result[max], 1);
		i--;
		j--;
		max--;
		//write(1, "plop", 4);
	}
	result = &result[max - 2];
	//write(1, result - 1, ft_strlen(result));
}


int main(int ac, char **av)
{
	if (ac == 3)
		infin_add(av[1], av[2]);
	write(1, "\n", 1);
	return(0);
}

