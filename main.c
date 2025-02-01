#include "main.h"
#include "printf.c"

int	main()
{
    int count;

    //Test the code for task 1,2
    count = _printf("Hello %s\n","Ahmed");
    printf("%d\n",count);
    count = _printf("Your grade is %c\n",'B');
    printf("%d\n",count);
    count = _printf("%d %i\n",10,10);
    printf("%d\n",count);

    //Test the code for Task 4
    count = _printf("%b\n",98);
    printf("%d\n",count);


    return 0;
}
