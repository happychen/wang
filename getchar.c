#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a, ch;
    printf("Please input some chars:\n");
    scanf("%c", &a);
    printf("a = %c\n", a);

    while((ch = getchar()) != '\n');
    printf("input char\n");
    scanf("%c", &a);
    printf("a= %c", a);
    return 0;
}
