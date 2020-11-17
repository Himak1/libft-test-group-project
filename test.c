#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
//#include <string.h>
#include <ctype.h>
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

void	test_strlen(const char *s);

void	test_strlcpy(char *dst, const char *src, size_t size);

void	test_strlcat(char *dst, const char *src, size_t size);

void	test_strchr(const char *s, int c);

void	test_strrchr(const char *s, int c);

void	test_strnstr(const char *big, const char *little, size_t len);

void	test_strncmp(const char *s1, const char *s2, size_t n);

void	test_isalpha(int c);

void	test_isdigit(int c);

void	test_isalnum(int c);

void	test_isascii(int c);

void	test_isprint(int c);

void	test_toupper(int c);

void	test_tolower(int c);

void	test_ft_split(char *str, char c);

void	test_ft_substr(char const *str, unsigned int start, size_t len);

void	test_ft_strtrim(char const *str, char const *rm);

void	test_ft_strjoin(char const *str1, char const *str2);

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
	test_memchr("           ", '\t', 6);

	printf("\n%sTesting ft_memcmp...%s\n", BLUE, RESET);
	test_memcmp("hilmi", "hilMi", 5);
	test_memcmp("hallo broo", "yo", 0);
	test_memcmp("", "", 1);
	test_memcmp("Codam","codam", 5);

	printf("\n%sTesting ft_strlen...%s\n", BLUE, RESET);
	test_strlen("");
	test_strlen("codam students\n");
	test_strlen(" yoyoyoyoyoyoyoyoyoyoyo");
	test_strlen("\t\v\f\r     ");

	printf("\n%sTesting ft_strlcpy...%s\n", BLUE, RESET);
	test_strlcpy("yooo", "hilmi", 3);
	test_strlcpy("ewaa", "ooo", 1);
	test_strlcpy("", "hilmi", 1);
	test_strlcpy("Codammer", "hilmi", 5);
	test_strlcpy("yooo", "hilmi", 0);
	test_strlcpy("ewa", "", 1);
	test_strlcpy("qwerty", "hallocodam", 7);
	test_strlcpy("hallocodam", "qwerty", 1000);
	
	printf("\n%sTesting ft_strlcat...%s\n", BLUE, RESET);
	test_strlcat("hilmi", "yilmaz", 13);
	test_strlcat("Codam", "Amsterdam", 6);
	test_strlcat("", "yilmaz", 1);
	test_strlcat("hilmi", "yilmaz", 0);
	test_strlcat("hilmi", "", 100);

	printf("\n%sTesting ft_strchr...%s\n", BLUE, RESET);
	test_strchr("hilmi", 'i');
	test_strchr("hilmi", 'p');
	test_strchr("", '\0');
	test_strchr("hilmi", '\0');
	test_strchr("h", 'h');
	test_strchr("h", 'i');

	printf("\n%sTesting ft_strrchr...%s\n", BLUE, RESET);
	test_strrchr("hilmi", 'i');
	test_strrchr("codamcurry", 'c');
	test_strrchr("hilmi", 'p');
	test_strrchr("", '\0');
	test_strrchr("hilmi", '\0');
	test_strrchr("h", 'h');
	test_strrchr("h", 'i');

	printf("\n%sTesting ft_strnstr...%s\n", BLUE, RESET);
	test_strnstr("codam students", "student", 35);
	test_strnstr("codam students", "student", 13);
	test_strnstr("codam students", "student", 12);
	test_strnstr("codam students", "", 17);
	test_strnstr("codam students students", "student", 24);
	test_strnstr("", "hello", 5);
	test_strnstr("hello man", "man", 0);	
	test_strnstr("", "", 1);

	printf("\n%sTesting ft_strncmp...%s\n", BLUE, RESET);
	test_strncmp("codam", "coDam", 2);
	test_strncmp("codam", "coDam", 3);
	test_strncmp("codam", "coDam", 10);
	test_strncmp("", "", 1);
	test_strncmp("", "i", 1);
	test_strncmp("", "", 0);
	test_strncmp("W", "w", 100);

	printf("\n%sTesting ft_isalpha...%s\n", BLUE, RESET);
	test_isalpha('A');
	test_isalpha('Z');
	test_isalpha('-');
	test_isalpha('a');
	test_isalpha('z');
	test_isalpha('p');
	test_isalpha('P');
	test_isalpha('@');
	test_isalpha('[');
	test_isalpha('{');

	printf("\n%sTesting ft_isdigit...%s\n", BLUE, RESET);
	test_isdigit('1');
	test_isdigit('0');
	test_isdigit('9');
	test_isdigit('5');
	test_isdigit('/');
	test_isdigit(':');

	printf("\n%sTesting ft_isalnum...%s\n", BLUE, RESET);
	test_isalnum('1');
	test_isalnum('0');
	test_isalnum('9');
	test_isalnum('5');
	test_isalnum('/');
	test_isalnum(':');
	test_isalpha('A');
	test_isalpha('Z');
	test_isalpha('-');
	test_isalpha('a');
	test_isalpha('z');
	test_isalpha('p');
	test_isalpha('P');
	test_isalpha('@');
	test_isalpha('[');
	test_isalpha('{');
	
	printf("\n%sTesting ft_isascii...%s\n", BLUE, RESET);
	test_isascii('1');
	test_isascii('0');
	test_isascii('9');
	test_isascii('5');
	test_isascii('/');
	test_isascii(':');
	test_isascii('A');
	test_isascii('Z');
	test_isascii('-');
	test_isascii(127);
	test_isascii(0);
	test_isascii(-1);
	test_isascii(130);

	printf("\n%sTesting ft_isprint...%s\n", BLUE, RESET);
	test_isprint(127);
	test_isprint(30);
	test_isprint(1);
	test_isprint(126);
	test_isprint('/');
	test_isprint(':');
	test_isprint('A');
	test_isprint('Z');
	test_isprint('-');

	printf("\n%sTesting ft_toupper...%s\n", BLUE, RESET);
	test_toupper('a');
	test_toupper('z');
	test_toupper('o');
	test_toupper('{');
	test_toupper(96);
	test_toupper('A');
	test_toupper('Z');
	test_toupper('-');
	test_toupper('@');
	
	printf("\n%sTesting ft_tolower...%s\n", BLUE, RESET);
	test_toupper('A');
	test_toupper('Z');
	test_toupper('O');
	test_toupper('[');
	test_toupper(64);
	test_toupper('a');
	test_toupper('z');
	test_toupper('-');
	test_toupper('@');
	
	printf("\n%sTesting ft_split...%s\n", BLUE, RESET);
	printf("---ft_split cannot be compared to an offical library function---\n");
	test_ft_split("  Hello World Look It's Working   ", ' ');
	test_ft_split("sssssssHellosssWorldssssss", 's');
	test_ft_split("HellosWorldss", 's');
	test_ft_split("sHelloWorlds", 's');
	test_ft_split("      split       this for   me  !       ", ' ');

	printf("\n%sTesting ft_substr...%s\n", BLUE, RESET);
	printf("---ft_substr cannot be compared to an offical library function---\n");
	test_ft_substr("Hello World I need to find the needle in the haystack", 22, 4);
	test_ft_substr("Hello World", 0, 5);
	test_ft_substr("WoooowHello", 6, 5);
	test_ft_substr("HelloHelloWorldHello", 11, 0);
	test_ft_substr("", 0, 2);
	
	printf("\n%sTesting ft_strtrim...%s\n", BLUE, RESET);
	printf("---ft_strtrim cannot be compared to an offical library function---\n");
	test_ft_strtrim("sssssHelloWorldsss", "s");
	test_ft_strtrim("skHelloskskWorld", "sk");
	test_ft_strtrim("What is  this supposed to return?", "ss");

	printf("\n%sTesting ft_strjoin...%s\n", BLUE, RESET);
	printf("---ft_strjoin cannot be compared to an offical library function---\n");
	test_ft_strjoin("Joined", "succesfully");
	test_ft_strjoin("", "");
	test_ft_strjoin("1string", "");
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
		printf(", own_result = %d, ", actual);
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
	char	*c_malloc;
	char	*own_malloc;


	c_malloc = strdup(s);
	own_malloc = strdup(s);
	
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

	free(c_malloc);
	free(own_malloc);
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
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result < 0 && own_result < 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");

	free(s1_malloc);
	free(s2_malloc);
}

void	test_strlen(const char *s)
{
	size_t	own_result;
	size_t	c_result;

	own_result = ft_strlen(s);
	c_result = strlen(s);

	if (own_result == c_result)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %lu, ", c_result);
		printf("own_result = %lu\n", own_result);
	}
	else
		printf("\n");
}

void	test_strlcpy(char *dst, const char *src, size_t size)
{
	char	*c_dst_malloc;
	char	*own_dst_malloc;
	char	*src_malloc;
	size_t	c_result;
	size_t	own_result;
	size_t	i;
	size_t	count;

	c_dst_malloc = strdup(dst);
	own_dst_malloc = strdup(dst);
	src_malloc = strdup(src);

	c_result = strlcpy(c_dst_malloc, src_malloc, size);
	own_result = ft_strlcpy(own_dst_malloc, src_malloc, size);

	i = 0;
	count = 0;
	while(*(c_dst_malloc + i) != '\0')
	{
		if (*(c_dst_malloc + i) == *(own_dst_malloc + i))
			count++;
		i++;
	}

	if (c_result == own_result && i == count)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);
	
	if (SHOW == 1)
	{
		printf(", c_result = %lu, ", c_result);
		printf("own_result = %lu, ", own_result);
		printf("c_dst = %s, ", c_dst_malloc);
		printf("own_dst = %s\n", own_dst_malloc);
	}
	else
		printf("\n");
	
	free(c_dst_malloc);
	free(own_dst_malloc);
	free(src_malloc);
}

void	test_strlcat(char *dst, const char *src, size_t size)
{
	char	*c_dst_malloc;
	char	*own_dst_malloc;
	char	*src_malloc;
	size_t	c_result;
	size_t	own_result;
	size_t	i;
	size_t	count;

	//Allocate memory with length size. This will hold the results.
	c_dst_malloc = (char*)malloc(50 * sizeof(char));
	own_dst_malloc = (char*)malloc(50 * sizeof(char));
	src_malloc = strdup(src);

	//Set the malloc with dst
	memset(c_dst_malloc, 'p', 50);
	memset(own_dst_malloc, 'p', 50);

	/* Print after memset
	i = 0;
	while (i < 50)
	{
		printf("%c", *(c_dst_malloc + i));
		i++;
	}
	printf("\n");*/

	//Put dst in c_dst_malloc and own_dst_malloc
	i = 0;
	while (i < 50)
	{
		if (i < strlen(dst) + 1)
		{
			*(c_dst_malloc + i) = *(dst + i);
			*(own_dst_malloc + i) = *(dst + i);
		}
		//printf("%c ", *(c_dst_malloc + i));
		//printf("%c", *(own_dst_malloc + i));
		//printf("\n");
		i++;
	}
	c_result = strlcat(c_dst_malloc, src_malloc, size);
	own_result = ft_strlcat(own_dst_malloc, src_malloc, size);

	i = 0;
	count = 0;
	while(i < 50)
	{
		printf("%c %c\n", *(c_dst_malloc + i), *(own_dst_malloc + i));
		if (*(c_dst_malloc + i) == *(own_dst_malloc + i))
			count++;
		i++;
	}

	if (c_result == own_result && i == count)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);
	
	if (SHOW == 1)
	{
		printf(", c_result = %lu, ", c_result);
		printf("own_result = %lu, ", own_result);
		printf("c_dst = %s, ", c_dst_malloc);
		printf("own_dst = %s\n", own_dst_malloc);
	}
	else
		printf("\n");
	
	free(c_dst_malloc);
	free(own_dst_malloc);
	free(src_malloc);
}

void	test_strchr(const char *s, int c)
{
	char	*c_result;
	char	*own_result;

	c_result = strchr(s, c);
	own_result = ft_strchr(s, c);

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
}

void	test_strrchr(const char *s, int c)
{
	char	*c_result;
	char	*own_result;

	c_result = strrchr(s, c);
	own_result = ft_strrchr(s, c);

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
}

void	test_strnstr(const char *big, const char *little, size_t len)
{
	char	*c_result;
	char	*own_result;

	c_result = strnstr(big, little, len);
	own_result = ft_strnstr(big, little, len);

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
}

void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	int	c_result;
	int	own_result;

	c_result = strncmp(s1, s2, n);
	own_result = ft_strncmp(s1, s2, n);

	if (c_result > 0 && own_result > 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result < 0 && own_result < 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_isalpha(int c)
{
	int	c_result;
	int	own_result;

	c_result = isalpha(c);
	own_result = ft_isalpha(c);

	if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result != 0 && own_result != 0)
		printf("%sPassed%s", GREEN, RESET);	
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_isdigit(int c)
{
	int	c_result;
	int	own_result;

	c_result = isdigit(c);
	own_result = ft_isdigit(c);

	if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result != 0 && own_result != 0)
		printf("%sPassed%s", GREEN, RESET);	
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_isalnum(int c)
{
	int	c_result;
	int	own_result;

	c_result = isalnum(c);
	own_result = ft_isalnum(c);

	if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result != 0 && own_result != 0)
		printf("%sPassed%s", GREEN, RESET);	
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_isascii(int c)
{
	int	c_result;
	int	own_result;

	c_result = isascii(c);
	own_result = ft_isascii(c);

	if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result != 0 && own_result != 0)
		printf("%sPassed%s", GREEN, RESET);	
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_isprint(int c)
{
	int	c_result;
	int	own_result;

	c_result = isprint(c);
	own_result = ft_isprint(c);

	if (c_result == 0 && own_result == 0)
		printf("%sPassed%s", GREEN, RESET);
	else if (c_result != 0 && own_result != 0)
		printf("%sPassed%s", GREEN, RESET);	
	else
		printf("%sFailed%s", RED, RESET);

	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_toupper(int c)
{
	int	c_result;
	int	own_result;

	c_result = toupper(c);
	own_result = ft_toupper(c);

	if (c_result == own_result)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);
		
	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_tolower(int c)
{
	int	c_result;
	int	own_result;

	c_result = tolower(c);
	own_result = ft_tolower(c);

	if (c_result == own_result)
		printf("%sPassed%s", GREEN, RESET);
	else
		printf("%sFailed%s", RED, RESET);
		
	if (SHOW == 1)
	{
		printf(", c_result = %d, ", c_result);
		printf("own_result = %d\n", own_result);
	}
	else
		printf("\n");
}

void	test_ft_split(char *str, char c)
{
	char	**returnval;//return value
	int	iter;//for iterating through 2d array

	returnval = ft_split(str, c);

	iter = 0;
	printf("%sft_split's output:\n%s", BLUE, RESET);
	while (returnval[iter] != 0)
	{
		printf("%s|\n", returnval[iter]);
		free(returnval[iter]);
		iter++;
	}
	free(returnval);
	printf("\n");
}

void	test_ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*returnval;
	//int		i;

	printf("%sft_substr's output:\n%s", BLUE, RESET);
	returnval = ft_substr(str, start, len);
	printf("%s|\n", returnval);
	free(returnval);
}

void	test_ft_strtrim(char const *str, char const *rm)
{
	char	*trimmed;

	printf("%sft_strtrim's output:\n%s", BLUE, RESET);
	trimmed = ft_strtrim(str, rm);
	printf("%s|\n", trimmed);
	free(trimmed);
}

void	test_ft_strjoin(char const *str1, char const *str2)
{
	char	*joined;

	printf("%sft_strjoin's output:\n%s", BLUE, RESET);
	joined = ft_strjoin(str1, str2);
	printf("%s|\n", joined);
}
