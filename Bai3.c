#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ask(int y)
{
    printf("? %d\n", y);
    fflush(stdout);
    char r[4];
    scanf("%3s", r);
    if (strcmp(r, "YES") == 0) return 1;
    else if (strcmp(r, "NO") == 0) return 0;
    else exit(1);
}

int main(void)
{
    long long max = 1e9;
    long long min = 1;

    while (min < max)
    {
        long long mid = (min + max) / 2;
        int ans = ask(mid);
        if (ans) min = mid + 1;
        else max = mid;
    }
    printf("! %lld\n", min);
    return 0;
}