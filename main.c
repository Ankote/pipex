#include "pipex.h"

int main()
{
    int fd[2];
    int id;

    if (pipe(fd) == -1)
        printf("can't opening the pipe\n");
    id = fork();
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf ("put x  :  ");
        scanf("%d", &x);
       // write (fd[1], &x,  4);
        close (fd[1]);
    }
    else{
        close (fd[1]);
        int y;
        read(fd[0], &y, 4);
        close(fd[0]);
        printf("output  : %d\n", y);
    }
    return 0;



    
}
