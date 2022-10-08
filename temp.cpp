#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];

    int n;
    scanf("%d", &n);
    while (n--)
    {

        int cnt = 0;
        scanf("%s", s);
        if (strlen(s) > 10)
        {
            int m = strlen(s) - 2;
            if (m < 10)
            {
                s[1] = m;
                s[2] = s[strlen(s)];
                s[3] = '\0';
            }
            else
            {
                s[1] = m / 10;
                s[2] = m % 10;
                s[3] = s[strlen(s)];
                s[4] = '\0';
            }
            printf("%s", s);
        }
        else
        {
            printf("%s\n", s);
        }
    }
}