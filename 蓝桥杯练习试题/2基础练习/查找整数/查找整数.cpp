#include <iostream>
using namespace std;
const int MAXN = 10001;
int n, a, ans;
int s[MAXN];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cin >> a;
    ans = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == a)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}