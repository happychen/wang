#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int status;
    pid_t pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(1);
    }
    if (pid > 0) 
    {
        kill(pid, SIGINT);
        wait(&status);
        if (WIFEXITED(status)) 
            printf("the return status is %d\n", WEXITSTATUS(status));

        else if(WIFSIGNALED(status))
            printf("the return status is %d\n", WTERMSIG(status));
    }
   
    if(pid == 0)
        sleep(3);
    return 0;
}
