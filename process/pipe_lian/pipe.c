/*读端没关闭，持有读端不读，持有写端写*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) 
    {
        perror("pipe");
        exit(1);
    }
    if ((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0) 
    {
//        close(fd[0]);
        close(fd[1]);
        int i = 0;
        while(++i)
        {
            printf("111111\n");
            write(fd[1], "hello world\n", 12);
            printf("i = %d\n", i);
        }

//        n = read(fd[0], line, MAXLINE);
//        write(STDOUT_FILENO, line, n);
        
        wait(NULL);
    }
    else
    {
        
//        close(fd[0]);
        close(fd[1]);
        while(1);
//        n = read (fd[0], line, MAXLINE);
//        write(STDOUT_FILENO, line, n);

//        n = read (fd[0], line, MAXLINE);
//        write(STDOUT_FILENO, line, n);
//        printf("%d\n", n);
    }
    return 0;
}
