#include <stdio.h>
#define MAXN 10001
int n, a, ans;
int s[MAXN];
int main()
{
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    scanf("%d", &a);
    ans = -1;
    for (i = 0; i < n; ++i)
    {
        if (s[i] == a)
        {
            ans = i + 1;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}