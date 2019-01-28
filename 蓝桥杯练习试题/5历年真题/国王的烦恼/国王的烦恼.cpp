#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 10000 + 10;
const int MAX_M = 100000 + 10;

struct Edge {
	int a, b, t;
	bool operator < (const Edge& e) const  {
		return t > e.t;
	}
}e[MAX_M];

int n, m;
int p[MAX_N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void solve() {
    for (int i = 1; i < MAX_N; ++ i) p[i] = i;
	sort(e, e + m);
	int t = -1;
	int ans = 0;
	for (int i = 0; i < m; ++ i) {
        int x = find(e[i].a);
        int y = find(e[i].b);
        if (x != y){
            p[x] = y;
            if (t != e[i].t) {
                ++ ans;
                t = e[i].t;
            }
        }
	}
	printf("%d\n", ans);
}

int main() {
	int a, b, t;
	while(~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < m; ++ i) {
			scanf("%d%d%d", &a, &b, &t);
			e[i].a = a; e[i].b = b; e[i].t = t;
		}
		solve();
	}
	return 0;
}
