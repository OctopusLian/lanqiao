#include <stdio.h>
#define N 10
int num[N][N];
int tag[N][N] = {0};
int m, n;
int r = 100;
int find(int i, int j, int t, int ntag[][N])
{ 
    int count = 0;
    if (i < 0 || i >= n || j < 0 || j >= m || ntag[i][j] == 1)
        return 0; 
    ntag[i][j] = 1;
    if (tag[i][j] != t)
        return 0;
    count++;
    count += find(i - 1, j, t, ntag);
    count += find(i + 1, j, t, ntag);
    count += find(i, j - 1, t, ntag);
    count += find(i, j + 1, t, ntag);
    return count;
}
 
int isbad()
{
    int i, j, k = 0,ge2;
    int t = tag[0][0];
    int ntag1[N][N] = {0};
    int ntag2[N][N] = {0};  
    int ge1 = find(0, 0, t, ntag1);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (tag[i][j] != t)
            {
                k = 1;
                break;
            }
        }
        if (k == 1)
            break; 
    }
    
    if (i == n && j == m)
        return 0;
     ge2 = find(i, j, tag[i][j], ntag2);

    return ge1 + ge2 != m * n;
}
int bad(int i, int j)
{
   int b;
	if (i < 0 || i >= n || j < 0 || j >= m || tag[i][j] == 1)
        return 1;
        
    tag[i][j] = 1; 
    b = isbad();  
    tag[i][j] = 0;  
    return b;
}

void go(int i, int j, int k, int count)
{
    
    if (bad(i, j) || count < num[i][j])
        return;
    k++;
   
    if (count == num[i][j])
    {
        if (r > k)
            r = k;
        return; 
    }
    
  
    tag[i][j] = 1;
    count -= num[i][j];
    go(i - 1, j, k, count); 
    go(i + 1, j, k, count);
    go(i, j - 1, k, count); 
    go(i, j + 1, k, count);
    tag[i][j] = 0;
}

int main()
{
    
    int i, j;
    int half = 0;
	scanf("%d %d", &m, &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf("%d", &num[i][j]);
 
            half += num[i][j];
        }
    
 
    if (half % 2 == 0 && half >= num[0][0] * 2)
    {
       
        half /= 2;
        go(0, 0, 0, half);
    }
    
    if (r == 100)
        r = 0;
    
    printf("%d", r);

    return 0;
}