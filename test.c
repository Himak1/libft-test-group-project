#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "libft.h"

//Set to 1 to show runned tests, otherwise set to 0
#define SHOW 1

char RED[] = "\033[1;31m";
char GREEN[] = "\033[0;32m";
char BLUE[] = "\033[0;35m";
char RESET[]= "\033[0m";

void	test_atoi(int expected, int actual);

void	test_bzero(char c, size_t n, size_t size);

void	test_memset(char c, size_t size_malloc, size_t size_memset);

void	test_memcpy(void *dst, const void *src, size_t n);
char	*test_memcpy_own(void *dst, const void *src, size_t n);
char	*test_memcpy_c(void *dst, const void *src, size_t n);

void	test_memccpy(void *dst, const void *src, int c, size_t n);
char	*test_memccpy_own(void *dst, const void *src, int c, size_t n);
char	*test_memccpy_c(void *dst, const void *src, int c, size_t n);

void	test_memmove(void *dst, const void *src, size_t n);
char	*test_memmove_own(void *dst, const void *src, size_t n);
char	*test_memmove_c(void *dst, const void *src, size_t n);

void	test_memchr(const void *s, int c, size_t n);

void	test_memcmp(const void *s1, const void *s2, size_t n);

int		main(void)
{
	printf("%sTesting ft_atoi...%s\n", BLUE, RESET);
	test_atoi(atoi("0"), ft_atoi("0"));
	test_atoi(atoi("-0"), ft_atoi("-0"));
	test_atoi(atoi("+0"), ft_atoi("+0"));
	test_atoi(atoi("-1234"), ft_atoi("-1234"));
	test_atoi(atoi("1234"), ft_atoi("1234"));
	test_atoi(atoi("-1234--999"), ft_atoi("-1234--999"));
	test_atoi(atoi("01234"), ft_atoi("01234"));
	test_atoi(atoi("-2147483648"), ft_atoi("-2147483648"));
	test_atoi(atoi("2147483647"), ft_atoi("2147483647"));
	test_atoi(atoi("+-123456789"), ft_atoi("+-123456789"));
	test_atoi(atoi("i+1234"), ft_atoi("i+1234"));
	test_atoi(atoi("-2147483648"), ft_atoi("-2147483648"));
	test_atoi(atoi("2147483647"), ft_atoi("2147483647"));
	test_atoi(atoi("\f\n\r\t\v   -1234"), ft_atoi("\f\n\r\t\v   -1234"));
	test_atoi(atoi("\f\n\r\t\v   -1234aa123"), ft_atoi("\f\n\r\t\v   -1234aa123"));
	test_atoi(atoi("\f\n\r\t\v   - 1234"), ft_atoi("\f\n\r\t\v   - 1234"));
	test_atoi(atoi("\f\n\r\t\v   - \t1234"), ft_atoi("\f\n\r\t\v   - \t1234"));
	test_atoi(atoi("\f\n\r\t\v   - \t1234 a0"), ft_atoi("\f\n\r\t\v   - \t1234 a0"));
	test_atoi(atoi("\f\n\r\t\v   - \t123\n\v4"), ft_atoi("\f\n\r\t\v   - \t123\n\v4"));
	test_atoi(atoi("\f\n\r\t\v   - \t12-34 a0"), ft_atoi("\f\n\r\t\v   - \t12-34 a0"));

	printf("\n%sTesting ft_bzero...%s\n", BLUE, RESET);
	test_bzero('a', 10, 20);
	test_bzero('c', 1, 5);
	test_bzero('-', 13, 30);

	printf("\n%sTesting ft_memset...%s\n", BLUE, RESET);
	test_memset('a', 20, 10);
	test_memset('p', 20, 1);
	test_memset('z', 40, 39);

	printf("\n%sTesting ft_memcpy...%s\n", BLUE, RESET);
	test_memcpy("hilmi", "yilmaz", 1);
	test_memcpy("yooo", "ho", 3);
	test_memcpy("hilmi", "yilmaz", 0);
	test_memcpy("", "yilmaz", 0);
	test_memcpy("", "", 0);
	//test_memcpy(NULL, "", 2);

	printf("\n%sTesting ft_memccpy...%s\n", BLUE, RESET);
	test_memccpy("123456789", "hilmi", 'l', 5);

	printf("\n%sTesting ft_memmove%s\n", BLUE, RESET);
	test_memmove("1234", "ooo", 3);
	test_memmove("ik zit op Codam", "hallo", 5);
	test_memmove("yoo", "ik", 2);
	char str[] = "abcde";
	test_memmove(str, str + 2, 3);
	test_memmove(str, str + 2, 2);

	printf("\n%sTesting ft_memchr...%s\n", BLUE, RESET);
	test_memchr("hilmi", 'm', 5);
	test_memchr("hilmi", 'm', 2);
	test_memchr("hallooo", 'p', 5);
	test_memchr("", 'o', 1);
	test_memchr("", '\0', 1);

	printf("\n%sTesting ft_memcmp...%s\n", BLUE, RESET);
	test_memcmp("hilmi", "hilMi", 5);



	return (0);
}

void	test_atoi(int expected, int actual)
{
    if (expected == actual)
        printf("%sPassed%s", GREEN, RESET);
    else
	{
        printf("%sFailed%s", RED, RESET);
	}

	if (SHOW == 1)
	{
		printf(", own_result = %d", actual);
		printf("c_result = %d\n", expected);
	}
	else
		printf("\n");
}

/* n = how much of size to fill with bzero
 *size = size of malloc */
void	test_bzero(char c, size_t n, size_t size)
{
	unsigned char 	*c_malloc;
	unsigned char	*own_malloc;
	size_t			i;
	size_t			count;

	c_malloc = malloc(size);
	own_malloc = malloc(size);

	memset(c_malloc, c, size);
	memset(own_malloc, c, size);

	bzero(c_malloc, n);
	ft_bzero(own_malloc, n);

	i = 0;
	count = 0;
	while (i < size)
	{
		if (*(c_malloc + i) == *(own_malloc + i))
			count++;
		i++;
	}
	if (i == count)
		printf("%sPassed%s\n", GREEN, RESET);
	else
		printf("%sFailed%s\n", RED, RESET);
	
	free(c_malloc);
	free(own_malloc);
}

void	test_memset(char c, size_t size_malloc, size_t size_memset)
{	
	unsigned char 	*c_malloc;
	unsigned char	*own_malloc;
	size_t			i;
	size_t			count;

	c_malloc = malloc(size_malloc);
	own_malloc = malloc(size_malloc);	
	
	memset(c_malloc, c, size_malloc);
	memset(own_malloc, c, size_malloc);

	memset(c_malloc, c + 2, size_memset);		
	ft_memset(own_malloc, c + 2, size_memset);
	
	i = 0;
	count = 0;
	while (i < size_malloc)
	{
		if (*(c_malloc + i) == *(own_malloc + i))
			count++;
		i++;
	}
	if (i == count)
		printf("%sPassed%s\n", GREEN, RESET);
	else
		printf("%sFailed%s\n", RED, RESET);
	
	free(c_malloc);
	free(own_malloc);
}

void	test_memcpy(void *dst, const void *src, size_t n)
{
	char	*own_result;
	char	*c_result;
	size_t	i;
	size_t	count;
	char	*own_dst_malloc;
	char	*c_dst_malloc;
	char	*src_malloc;

	own_dst_malloc = strdup(dst);
	c_dst_malloc = strdup(dst);
	src_malloc = strdup(src);

	own_result = test_memcpy_own(own_dst_malloc, src_malloc, n);
	c_result = test_memcpy_c(c_dst_malloc, src_malloc, n);

	i = 0;
	count = 0;
	while (i < n)
	{
		if (*(own_result + i) == *(c_result + i))
			count++;
		i++;
	}	
	if (i == count)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", own_result = %s", own_result);
		printf(", c_result = %s\n", c_result);
	}
	else
		printf("\n");

	free(own_dst_malloc);
	free(c_dst_malloc);
	free(src_malloc);
}

char	*test_memcpy_own(void *dst, const void *src, size_t n)
{
	ft_memcpy(dst, src, n);
	return (dst);
}

char	*test_memcpy_c(void *dst, const void *src, size_t n)
{
	//memcpy gives an error when there is no space left in dst.
	memcpy(dst, src, n);
	return (dst);
}

void	test_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*own_result;
	char	*c_result;
	size_t	i;
	size_t	count;
	char	*c_dst_malloc;
	char	*own_dst_malloc;
	char	*src_malloc;

	own_dst_malloc = strdup(dst);
	c_dst_malloc = strdup(dst);
	src_malloc = strdup(src);

	
	own_result = test_memccpy_own(own_dst_malloc, src_malloc, c, n);
	c_result = test_memccpy_c(c_dst_malloc, src_malloc, c, n);

	i = 0;
	count = 0;
	while (i < n)
	{
		if (*(own_result + i) == *(c_result + i))
			count++;
		i++;
	}	
	if (i == count)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", own_result = %s", own_result);
		printf(", c_result = %s\n", c_result);
	}
	else
		printf("\n");

	free(own_dst_malloc);
	free(src_malloc);
	free(c_dst_malloc);
}

char	*test_memccpy_own(void *dst, const void *src, int c, size_t n)
{
	ft_memccpy(dst, src, c, n);
	return (dst);
}

char	*test_memccpy_c(void *dst, const void *src, int c, size_t n)
{
	//memcpy gives an error when there is no space left in dst.
	memccpy(dst, src, c, n);
	return (dst);
}

void	test_memmove(void *dst, const void *src, size_t n)
{	
	char	*own_result;
	char	*c_result;
	size_t	i;
	size_t	count;
	char	*c_dst_malloc;
	char	*own_dst_malloc;
	char	*src_malloc;

	own_dst_malloc = strdup(dst);
	c_dst_malloc = strdup(dst);
	src_malloc = strdup(src);
	
	own_result = test_memmove_own(own_dst_malloc, src_malloc, n);
	c_result = test_memmove_c(c_dst_malloc, src_malloc, n);
	
	i = 0;
	count = 0;
	while (i < n)
	{
		if (*(own_result + i) == *(c_result + i))
			count++;
		i++;
	}	
	if (i == count)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", own_result = %s", own_result);
		printf(", c_result = %s\n", c_result);
	}
	else
		printf("\n");

	free(own_dst_malloc);
	free(src_malloc);
	free(c_dst_malloc);
}

char	*test_memmove_own(void *dst, const void *src, size_t n)
{
	ft_memmove(dst, src, n);
	return (dst);
}

char	*test_memmove_c(void *dst, const void *src, size_t n)
{
	//memcpy gives an error when there is no space left in dst.
	memmove(dst, src, n);
	return (dst);
}

void	test_memchr(const void *s, int c, size_t n)
{
	char	*c_result;
	char	*own_result;
	//size_t	i;
	//size_t	count;

	c_result = strdup(s);
	own_result = strdup(s);
	
	c_result = memchr(s, c, n);
	own_result = ft_memchr(s, c, n);

	if (c_result == own_result)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %s, ", c_result);
		printf("own_result = %s\n", own_result);
	}
	else
		printf("\n");

	//free(c_result);
	//free(own_result);
}

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_malloc;
	char	*s2_malloc;
	int		c_result;
	int		own_result;

	s1_malloc = strdup(s1);
	s2_malloc = strdup(s2);
	
	c_result = memcmp(s1, s2, n);
	own_result = ft_memcmp(s1, s2, n);

	if (c_result > 0 && own_result > 0)
		printf("%sPassed%s\n", GREEN, RESET);
	else if (c_result < 0 && own_result < 0)
		printf("%sPassed%s\n", GREEN, RESET);
	else if (c_result == 0 && own_result == 0)
		printf("%sPassed%s\n", GREEN, RESET);
	else
		printf("%sFailed%s\n", RED, RESET);

	free(s1_malloc);
	free(s2_malloc);
}



