#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_palyndrome(char *str, size_t size)
{
	size_t count = 0;
	size_t end_size = size / 2;

	printf("end size : %lu | %lu --> %c == %c ?\n", end_size, count, str[count], str[size - (count + 1)]);
	while (count < end_size && str[count] == str[size - (count + 1)])
	{
		count++;
		if (count < end_size && str[count] == str[size - (count + 1)])
			printf("%lu --> %c == %c ?\n", count, str[count], str[size - (count + 1)]);
	}
	return (str[count] == str[size - (count + 1)]);
}

/*
** hecker si on a un palyndrome d une taille donnee dans notre string
** size_pal : taille du palyndrome actuel
** size : size total de la string
** retourne -1 si err
*/
ssize_t is_palyndrome_len_in_string(char *str, size_t size_pal, size_t size)
{
	size_t count = 0;

	while (count + size_pal <= size)
	{
		if (is_palyndrome(&(str[count]), size_pal))
		{
			//printf("Palyndrome found :) pos : %lu | %lu\n", count, size_pal);
			return (count);
		}
		count++;
	}
	return (-1);
}

int display_max_palyndrome(char *str, size_t len)
{
	size_t size_pal = len;
	size_t count = 0;
	ssize_t found = -1;

	//printf("---> %s is palynrome? %d\n", str, is_palyndrome(str, len));
	//printf("---> %s is palynrome? %zd\n", str, is_palyndrome_len_in_string(str, len, len));

	while (size_pal && found == -1)
	{
		//printf("||||| size pal : %lu\n", size_pal);
		if ((found = is_palyndrome_len_in_string(str, size_pal, len)) > -1)
		{
			//printf("Palyndrome found :) : %lu | %zd\n", size_pal, found);
			write(1, &(str[found]), size_pal);
			return (0);
		}
		//printf("---> found : %zd\n", found);
		size_pal--;
	}
	write(1, "-1\n", 3);
	return (1);
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		display_max_palyndrome(av[i], strlen(av[i]));
		write(1, "\n", 1);
	}
	return (1);
}
