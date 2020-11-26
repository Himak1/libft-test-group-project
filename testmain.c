/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:08:29 by jhille        #+#    #+#                 */
/*   Updated: 2020/11/21 20:31:34 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
//#include <bsstring.h>
#include "libft.h"

void	*iapply(void *content)
{
	//int		*ret;

	(void)content;
	//ret = (int*)malloc(1 * sizeof(int*));
	//*ret = *(int*)content;
	//*ret += 1;
	//printf("%p\n", ret);
	return ("Hello");
}

void	delete(void *rmvar)
{
	free(rmvar);
}

int	main(void)//ft_lstmap
{
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*ptr3;
	t_list	*ptr4;
	t_list	*result;

	ptr1 = ft_lstnew((void*)1);
	ptr2 = ft_lstnew((void*)2);
	ptr3 = ft_lstnew((void*)3);
	ptr4 = ft_lstnew((void*)4);

	ft_lstadd_back(&ptr1, ptr2);
	ft_lstadd_back(&ptr1, ptr3);
	ft_lstadd_back(&ptr1, ptr4);

	result = ft_lstmap(ptr1, iapply, delete);
	while (result != 0)
	{
		//printf("yeet|");
		printf("%s\n", (char*)result->content);
		result = result->next;
	}
	return (0);
}

/*
int	main(void//ft_itoa)
{
	char	*ret;

	ret = ft_itoa(-623);
	printf("%s", ret);
	return (0);
}
*/
/*
int	main() //ft_is* 
{
	char	c;

	c = 31;
	printf("%d", isprint(c));
	return (0);
}
*/
/*
int	main()//ft_substr
{
	char	str[] = {"blablablaUseful-infoblablabla"};
	char	*ptr;

	ptr = ft_substr(str, 9, 11);
	printf("%s", ptr);
	//free(ptr);
	return (0);
}
*/
/*
int	main()//strtrim
{
	char	str[] = {"   , Hello World      \0, , ,  i"};
	char	set[3] = {" ,\0"};
	char	*ptr;
	
	ptr = ft_strtrim(str, set);
	printf("%s", ptr);
	return (0);
}
*/
/*
int	main()// ft_strrchr
{
	char	str[] = {"HelloWorld "};
	char	*ptr;
	char	c;

	c = 'x';
	ptr = strrchr(str, c);
	printf("%s", ptr);
	return (0);
}
*/
/*
int	main()
{
	char	haystack[21] = {"Hello World, I can't"};
	char	needle[6] = {", I"};
	
	printf("%s", ft_strnstr(haystack, needle, 20));
	return (0);
}
*/
/*
int	main()// strncmp
{
	char	str1[12] = {"Hello11"};
	char	str2[12] = {"Hello12"};

	printf("%d\n", ft_strncmp(str1, str2, 7));
	printf("%d\n", strncmp(str1, str2, 7));	
	return (0);
}
*/
/* 
char	applychar(unsigned int i, char c)
{
	if (i % 2 != 0)
		c += 1;
	else
		c += 2;
	return (c);
}

int	main(void) //strmapi
{
	char	str[12] = {"11111111111"};
	char	*ptr;
	int	i = 0;
	char (*f)(unsigned int, char) = &applychar;
	ptr = ft_strmapi(str, (*f));
	//printf("%s",  ft_strmapi(str, (*f)));
	while (ptr[i] != '\0')
	{
		write(1, &ptr[i], 1);
		i++;
	}
	//printf("%d", i);
	free(ptr);
	return (0);
}
*/
/*
int	main()
{
	size_t	i;
	char	str[12] = {"1"};
	
	i = ft_strlen(str);
	printf("%zu", i);
	return (0);
}
*/
/*
int	main()// strlcpy & strlcat
{
	char	dest[12] = {"Hello World"};
	char	src[12] = {"Bakka Bakka"};

	ft_strlcpy(dest, src, 12);
	printf("%s", dest);
	return (0);
}
*/
/*
int	main()
{
	char	str1[11] = {""};
	char	str2[11] = {""};
	char	*ptr;

	printf("%s\n", str1);
	ptr = ft_strjoin(str1, str2);
	printf("%p", ptr);
	return (0);
}
*/
/*
int	main()//strdup
{
	char	str[0] = {"Hello World"};
	char	*ptr;
	
	ptr = ft_strdup(str);
	printf("%p", ptr);
	return (0);
}
*/
/*
int	main()
{
	char	str[12] = {""};
	
	printf("%s", ft_strchr(str, ' '));
	return (0);
}
*/
/*
int	main()
{
	char	str[] = {"Bakka Hello World"};
	char	**ptr;
	int	i;

	i = 0;
	ptr = ft_split(str, ' ');

	//printf("%s", ptr[2]);
	while (ptr[i] != 0)
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}
*/
/*
int	main() // putnbr
{
	ft_putnbr_fd(23131, 1);
	return (0);
}
*/
/*
int	main() //putchar/putstr
{
	char	c[12] = {"Hello World"};


	ft_putstr_fd(c, 1);
	return (0);
}
*/
/*
int	main() // ft_memset
{	
	char	str[5];
	
	ft_memset(str, 51, 5);
	printf("%s", str);
	return (0);
}
*/
/*
int	main()//memmove
{
	char	dest[31] = {"HelloWorldHelloWorldHelloWorld"};
	memmove(dest, &dest[5], 5);
	printf("%s", dest);
	return (0);
}
*/
/*
int	main() //ft_memcpy and memccpy
{
	//char	dest[12] = {""};
	//char	src[6] = {""};
	//char	c;

	//c = ' ';
	printf("%s", memcpy(((void*)0), ((void*)0), 3));

	//printf("%s", dest);
	return (0);
}
*/

/*
int	main(void)// ft_split
{
	char	**ret;
	char	str[] = {"HelloWorldsssss"};
	char	c;
	int	i;

	i = 0;
	c = 's';

	ret = ft_split(str, c);
	while (ret[i] != 0)
	{
		//printf("%p |", ret[i]);
		printf("%s\n", ret[i]);
		free(ret[i]);
		i++;
	}
	return (0);
}
*/
