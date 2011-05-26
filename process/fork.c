#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    char *message;
    int n;
    pid = fork();

    if (pid < 0) 
    {
        perror("fork failed:");
        exit(1);
    }

    if (pid == 0) //child
    {
        message = "This is the child\n";
        n = 6;
    }
    else        //parent
    {
        message = "This is the parent\n";
        n = 3;
    }

    for (; n > 0; n--) 
    {
        printf(message);
        sleep(1);
    }

    return 0;
}
