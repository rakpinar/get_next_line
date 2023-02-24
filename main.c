
// #include <stdio.h>
// #include <fcntl.h>

// int main() //dosya olusturyor icine bir sey yaziyor dosyanin icindeki ilk satirlari okuyor
// {
// 	int fd = open("a.txt", O_CREAT | O_RDWR, 0777);
// 	int fd1 = open("b.txt", O_CREAT | O_RDWR, 0777);

// 	write(fd, "iiiiiii\noooooo\npppppppp", 23);
// 	write(fd1, "1111111\n222222\n33333333", 23);

// 	close(fd);
// 	close(fd1);

// 	fd = open("a.txt", O_RDWR, 0777);
// 	fd1 = open("b.txt", O_RDWR, 0777);

// 	printf("%d\n%d\n", fd, fd1);
	
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));

// 	close(fd);
// 	close(fd1);
	
// }


// int main() //get_next_line.c dosyasinin ilk satirini okuyor
// {
// 	int fd1 = open("deneme.txt", O_RDONLY, 0777);
// 	int fd2 = open("deneme2.txt", O_RDONLY, 0777);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// }

// int main() //dosyanin tum satirlarini yazdiran kod
// {
// 	int fd1 = open("aksu.txt", O_RDONLY, 0777);
// 	int fd2 = open("deneme.txt", O_RDONLY, 0777);


// 	char 	*a = get_next_line(fd1);
// 	free(a);

// 	while(a)
// 	{
// 		printf("%s", a);
// 		a = get_next_line(fd1);
// 		free(a);
// 	}


// 	char	*b = get_next_line(fd2);
// 	free(b);

// 	while(b)
// 	{
// 		printf("%s", b);
// 		b = get_next_line(fd2);
// 		free(b);
// 	}
// }

// int main() //dosyanin icinden istenilen bir satiri yazdiran kod
// {
// 	int fd1 = open("get_next_line.c", O_RDONLY, 0777);
// 	char	*a = get_next_line(fd1);
// 	free(a);

// 	int count = 1;
// 	while(a)
// 	{
// 		if(count == 26)
// 			printf("%s", a);
// 	count++;
// 	a = get_next_line(fd1);
// 	free(a);
// 	}
// }

// int main() //dosyanin icinde istenilen kismi yazdiran kod
// {
// 	int fd1 = open("get_next_line.c", O_RDWR, 0777);

// 	char	*a = get_next_line(fd1);
// 	free(a);
// 	int count = 1;
// 	while(a)
// 	{
// 		if(count >= 20 && count < 30)
// 		{
// 			printf("%s", a);	
// 		}
// 		a = get_next_line(fd1);
// 		count++;
// 	}
// 		free(a);
// }