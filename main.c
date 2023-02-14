#include <unistd.h>
#include <string.h>

// int	main(int argc, char const *argv[])
// {
// 	int i;
//     int j;
//     int test;

//     i = 0;
//     int k;
//     k = 0; 
//     if (argc != 3)
//     {
//          write (1, "\n", 1);
//         return (0);
//     }
        
//     while (argv[1][i])
//     {
//         j = 0;
//         test = 0;
//         while(j < i)
//         {
//             if (argv[1][i] == argv[1][j])
//                 test = 1;
//             j ++;
//         }
//         if (test == 0)
//             write (1, &argv[1][i] , 1);
//         i ++;
//     }

//     while (argv[2][k])
//     {
//         i = 0;
//         test = 0;
//         while (argv[1][i])
//         {
//             if (argv[1][i] == argv[2][k])
//                     test = 1;
//             i ++;
//         }
//         i = 0;
//         while(i < k)
//         {
//             if (argv[2][k] == argv[2][i])
//                 test = 1;
//             i ++;
//         }
//     if (test == 0)
//         write (1, &argv[2][k], 1);
//     k ++;
//     }                                   
//     write (1, "\n", 1);
// 	return (0);
// }

void ft_putchar(int c)
{
    write (1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr <= 9)
         ft_putchar((nbr % 10) + 48);
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar((nbr % 10) + 48);
    }
}
int	main(int argc, char const *argv[])
{
    char str[]= "123456789abcdef";
    
}