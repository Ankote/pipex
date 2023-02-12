#include "pipex.h"

int main()
{
    int id;
    int i;
    id = fork();
    int n;

    if (!id)
        n = 1;
    else
    {
        wait(0);
        n = 10;
    }
        
    i = n - 1;
    while (++i < n + 5)
        printf("%d ", i);
    if (id == -1)
     printf ("\n");
    return 0;
}
