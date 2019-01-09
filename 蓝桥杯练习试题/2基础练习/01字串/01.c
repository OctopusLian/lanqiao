#include <stdio.h>
int main()
{
    int i, j, k, l, m;
    for (i = 0; i <= 1; ++i)
        for (j = 0; j <= 1; ++j)
            for (k = 0; k <= 1; ++k)
                for (l = 0; l <= 1; ++l)
                    for (m = 0; m <= 1; ++m)
                        printf("%d%d%d%d%d\n", i, j, k, l, m);
    return 0;
}