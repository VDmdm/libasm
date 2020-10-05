#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include "includes/ft_bonus.h"
#include "includes/ft.h"

void	test_atoi_base(void)
{
	int		base = -1;

	printf("====START ATOI_BASE TEST====\n");
	while (base < 18)
	{
		printf("base: %d, str: \"aaa\", ret: %d\n",base, ft_atoi_base("aaa", base));
		printf("base: %d, str: \"-222\", ret: %d\n",base, ft_atoi_base("-222", base));
		printf("base: %d, str: \"+222\", ret: %d\n",base, ft_atoi_base("+222", base));
		printf("base: %d, str: \"+-222\", ret: %d\n",base, ft_atoi_base("+-222", base));
		printf("base: %d, str: \"-+222\", ret: %d\n",base, ft_atoi_base("-+222", base));
		printf("base: %d, str: \"            -222\", ret: %d\n",base, ft_atoi_base("            -222", base));
		printf("base: %d, str: \"-            222\", ret: %d\n",base, ft_atoi_base("-            222", base));
		printf("base: %d, str: \"\n\t\v\f\r 222\", ret: %d\n",base, ft_atoi_base("\n\t\v\f\r 222", base));
		printf("base: %d, str: \"12345\", ret: %d\n",base, ft_atoi_base("12345", base));
		printf("base: %d, str: \"abcdef\", ret: %d\n",base, ft_atoi_base("abcdef", base));
		printf("base: %d, str: \"ABCDEF\", ret: %d\n",base, ft_atoi_base("abcdef", base));
		printf("base: %d, str: \"-abcdef\", ret: %d\n",base, ft_atoi_base("-abcdef", base));
		printf("base: %d, str: \"0110010101\", ret: %d\n",base, ft_atoi_base("0110010101", base));
		printf("base: %d, str: \"bcvm\", ret: %d\n",base, ft_atoi_base("bcvm", base));
		printf("base: %d, str: \"            \", ret: %d\n",base, ft_atoi_base("            ", base));
		printf("\n--------\n");
		base++;
	}
	printf("====END ATOI_BASE TEST====\n");
}

void	print_list(t_list *list)
{
	t_list		*temp;

	temp = list;
	while(list)
	{
		printf("%s \n", (char *)list->data);
		list = list->next;
	}
	list = temp;
}

int		bonus_test(void)
{
	t_list		*test = 0;

	printf("=======BONUS TEST=======\n");
	test_atoi_base();
	printf("\n====START LST TEST====\n");
	printf("lst-size on start: %d\n", ft_list_size(test));
	ft_list_push_front(&test, ft_strdup("k"));
	ft_list_push_front(&test, ft_strdup("g"));
	ft_list_push_front(&test, ft_strdup("a"));
	ft_list_push_front(&test, ft_strdup("b"));
	ft_list_push_front(&test, ft_strdup("d"));
	ft_list_push_front(&test, ft_strdup("s"));
	printf("После push: size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_sort(&test, ft_strcmp);
	printf("После sort: size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "b", ft_strcmp);
	printf("После удаления \"b\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "h", ft_strcmp);
	printf("После удаления \"h\" (ее и не было): size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "a", ft_strcmp);
	printf("После удаления \"a\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "s", ft_strcmp);
	printf("После удаления \"s\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "g", ft_strcmp);
	printf("После удаления \"g\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "d", ft_strcmp);
	printf("После удаления \"d\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	ft_list_remove_if(&test, "k", ft_strcmp);
	printf("После удаления \"k\": size: %d, элементы:\n", ft_list_size(test));
	print_list(test);
	printf("\n====END LST TEST====\n");
	return (0);
}

void	main_wr_test(void)
{
	int		fd;
	ssize_t	ret = 0;
	char	buff[100];
	
	printf("\n======MAIN TEST: RW======\n");
	printf("\n======MAIN TEST: READ======\n");

	errno = 0;
	bzero(buff, 100);
	fd = open("test", O_RDONLY);
	ret = read(fd, buff, 100);
	buff[ret] = 0;
	printf("read: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	fd = open("test", O_RDONLY);
	errno = 0;
	bzero(buff, 100);
	ret = ft_read(fd, buff, 100);
	printf("ft_read: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	//-------------------------------------
	bzero(buff, 100);
	ret = read(-1, buff, 100);
	buff[ret] = 0;
	printf("read: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	errno = 0;
	bzero(buff, 100);
	ret = ft_read(-1, buff, 100);
	printf("ft_read: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	bzero(buff, 100);
	//-------------------------------------
	errno = 0;
	ret = ft_read(1, buff, 100);
	printf("ft_read: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	//-------------------------------------
	printf("\n======MAIN TEST: WRITE======\n");
	int		i = 32;
	int		j = 0;
	while (i < 122)
	{
		buff[j] = i;
		i++;
		j++;
	}
	errno = 0;
	fd = open("wr_std", O_CREAT | O_WRONLY | 777);
	ret = write(fd, buff, 100);
	printf("write: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	errno = 0;
	fd = open("wr_my", O_WRONLY);
	ret = ft_write(fd, buff, 100);
	printf("ft_write: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	//-------------------------------------
	errno = 0;
	fd = 50;
	ret = write(fd, buff, 100);
	printf("write: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	errno = 0;
	fd = 50;
	ret = ft_write(fd, buff, 100);
	printf("ft_write: \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
	perror("errno_msg");
	close(fd);
	//-------------------------------------
	errno = 0;
	ret = ft_write(1, buff, 100);
	printf("ft_write: запись в stdout \"%s\", ret: %ld, errno: %d\n", buff, ret, errno);
}

void	main_str_test(void)
{
	char *str;

	if(!(str = malloc(100)))
		return ;
	printf("======MAIN TEST: STR======\n");
	printf("===ft_strlen===\n");
	printf("str: \"abcde\", strlen: %ld, ft_strlen: %ld\n", strlen("abcde"), ft_strlen("abcde"));
	printf("str: \"a\", strlen: %ld, ft_strlen: %ld\n", strlen("a"), ft_strlen("a"));
	printf("str: \"\", strlen: %ld, ft_strlen: %ld\n", strlen(""), ft_strlen(""));
	printf("str: \"adddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\", strlen: %ld, ft_strlen: %ld\n", strlen("adddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"), ft_strlen("adddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"));
	//printf("str: 0, strlen: %ld, ft_strlen: %ld\n", strlen((char *)0), ft_strlen((char *)0));
	printf("\n===ft_strcmp===\n");
	printf("str1: \"abcde\", str2: \"abcde\", strcmp: %d, ft_strcmp: %d\n", strcmp("abcde", "abcde"), ft_strcmp("abcde", "abcde"));
	printf("str1: \"ab0de\", str2: \"abcde\", strcmp: %d, ft_strcmp: %d\n", strcmp("ab0de", "abcde"), ft_strcmp("abbde", "abcde"));
	printf("str1: \"abcd\", str2: \"abcde\", strcmp: %d, ft_strcmp: %d\n", strcmp("abcd", "abcde"), ft_strcmp("abcd", "abcde"));
	printf("str1: \"zbcde\", str2: \"abcde\", strcmp: %d, ft_strcmp: %d\n", strcmp("zbcde", "abcde"), ft_strcmp("zbcde", "abcde"));
	printf("str1: \"\", str2: \"\", strcmp: %d, ft_strcmp: %d\n", strcmp("", ""), ft_strcmp("", ""));
	printf("str1: \"abcde\", str2: \"\", strcmp: %d, ft_strcmp: %d\n", strcmp("abcde", ""), ft_strcmp("abcde", ""));
	printf("str1: \"\", str2: \"abcde\", strcmp: %d, ft_strcmp: %d\n", strcmp("", "abcde"), ft_strcmp("", "abcde"));

	//printf("str1: 0, str2: 0, strcmp: %d, ft_strcmp: d\n", strcmp(0, 0), ft_strcmp(0, 0));
	printf("\n===ft_strdup===\n");
	printf("str: \"abcde\", strdup: \"%s\", ft_strdup: \"%s\"\n", strdup("abcde"), ft_strdup("abcde"));
	printf("str: \"\", strdup: \"%s\", ft_strdup: \"%s\"\n", strdup(""), ft_strdup(""));
	printf("str: \"1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1\", strdup: \"%s\", ft_strdup: \"%s\"\n", strdup("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1"), ft_strdup("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1"));
	//printf("str: 0, strdup: \"%s\", ft_strdup: \"%s\"\n", strdup(0), ft_strdup(0));
	printf("\n===ft_strcpy===\n");
	printf("str: \"abcde\", strcpy: \"%s\" ", strcpy(str, "abcde"));
	bzero(str, 100);
	printf("ft_strcpy: \"%s\"\n",ft_strcpy(str, "abcde"));
	printf("str: \"\", strcpy: \"%s\" ", strcpy(str, ""));
	//bzero(str, 100);
	str[0] = 'a';
	printf("ft_strcpy: \"%s\"\n",ft_strcpy(str, ""));
		printf("str: \"1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1\", strcpy: \"%s\" ", strcpy(str, "1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1"));
	bzero(str, 100);
	printf("ft_strcpy: \"%s\"\n",ft_strcpy(str, "1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1"));
}

int		main(void)
{
	main_str_test();
	main_wr_test();
	bonus_test();
	return (0);
}