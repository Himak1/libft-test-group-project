#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "libft.h"

#define SHOW 1

void	test_atoi(int expected, int actual, const char *test_case);

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

int		main(void)
{
	printf("Testing ft_atoi...\n");
	test_atoi(atoi("0"), ft_atoi("0"), "0");
	test_atoi(atoi("-0"), ft_atoi("-0"), "-0");
	test_atoi(atoi("+0"), ft_atoi("+0"), "+0");
	test_atoi(atoi("-1234"), ft_atoi("-1234"), "-1234");
	test_atoi(atoi("1234"), ft_atoi("1234"), "1234");
	test_atoi(atoi("-1234--999"), ft_atoi("-1234--999"), "-1234--999");
	test_atoi(atoi("01234"), ft_atoi("01234"), "01234");
	test_atoi(atoi("-2147483648"), ft_atoi("-2147483648"), "-2147483648");
	test_atoi(atoi("2147483647"), ft_atoi("2147483647"), "2147483647");
	test_atoi(atoi("+-123456789"), ft_atoi("+-123456789"), "+-123456789");
	test_atoi(atoi("i+1234"), ft_atoi("i+1234"), "i+1234");
	test_atoi(atoi("-2147483648"), ft_atoi("-2147483648"), "-2147483648");
	test_atoi(atoi("2147483647"), ft_atoi("2147483647"), "2147483647");
	test_atoi(atoi("\f\n\r\t\v   -1234"), ft_atoi("\f\n\r\t\v   -1234"), "\\f\\n\\r\\t\\v   -1234");
	test_atoi(atoi("\f\n\r\t\v   -1234aa123"), ft_atoi("\f\n\r\t\v   -1234aa123"), "\\f\\n\\r\\t\\v   -1234aa123");
	test_atoi(atoi("\f\n\r\t\v   - 1234"), ft_atoi("\f\n\r\t\v   - 1234"), "\\f\\n\\r\\t\\v   - 1234");
	test_atoi(atoi("\f\n\r\t\v   - \t1234"), ft_atoi("\f\n\r\t\v   - \t1234"), "\\f\\n\\r\\t\\v   - \\t1234");
	test_atoi(atoi("\f\n\r\t\v   - \t1234 a0"), ft_atoi("\f\n\r\t\v   - \t1234 a0"), "\\f\\n\\r\\t\\v   - \\t1234 a0");
	test_atoi(atoi("\f\n\r\t\v   - \t123\n\v4"), ft_atoi("\f\n\r\t\v   - \t123\n\v4"), "\\f\\n\\r\\t\\v   - \\t123\\n\\v4");
	test_atoi(atoi("\f\n\r\t\v   - \t12-34 a0"), ft_atoi("\f\n\r\t\v   - \t12-34 a0"), "\\f\\n\\r\\t\\v   - \\t12-34 a0");

	printf("\nTesting ft_bzero...\n");
	test_bzero('a', 10, 20);
	test_bzero('c', 1, 5);
	test_bzero('-', 13, 30);

	printf("\nTesting ft_memset...\n");
	test_memset('a', 20, 10);
	test_memset('p', 20, 1);
	test_memset('z', 40, 39);

	printf("\nTesting ft_memcpy...\n");
	test_memcpy("hilmi", "yilmaz", 1);
	test_memcpy("yooo", "ho", 3);
	test_memcpy("hilmi", "yilmaz", 0);
	test_memcpy("", "yilmaz", 0);
	test_memcpy("", "", 0);
	//test_memcpy(NULL, "", 2);

	printf("\nTesting ft_memccpy...\n");
	test_memccpy("123456789", "hilmi", 'l', 5);

	printf("\nTesting ft_memmove\n");
	test_memmove("1234", "ooo", 3);
	test_memmove("ik zit op Codam", "hallo", 5);
	test_memmove("yoo", "ik", 2);
	char str[] = "abcde";
	test_memmove(str, str + 2, 3);
	test_memmove(str, str + 2, 2);

	printf("\nTesting ft_memchr...\n");
	test_memchr("hilmi", 'm', 5);
	test_memchr("hilmi", 'm', 2);
	test_memchr("hallooo", 'p', 5);
	test_memchr("", 'o', 1);
	test_memchr("", '\0', 1);


	return (0);
}

void	test_atoi(int expected, int actual, const char *test_case)
{
	printf("Input=%s, ", test_case);
    if (expected == actual)
        printf("Passed\n");
    else
	{
        printf("Failed\n");
	}
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
		printf("Passed\n");
	else
		printf("Failed\n");
	
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
		printf("Passed\n");
	else
		printf("Failed\n");
	
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
		printf("Passed");
	else
		printf("Failed");

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
		printf("Passed");
	else
		printf("Failed");

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
		printf("Passed");
	else
		printf("Failed");

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
		printf("Passed");
	else
		printf("Failed");

	if (SHOW == 1)
	{
		printf(", c_result = %s, ", c_result);
		printf("own_result = %s\n", own_result);
	}
	else
		printf("\n");
}



