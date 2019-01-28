#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long LL;
#define clr(x, y) memset(x, y, sizeof(x))
#define sf scanf
#define pf printf
const double pi = 4.0 * atan(1.0);
const double eps = 1e-8;
const int INF = 1 << 29;
const int maxn = 1005;

int N, M, roadNum, vis[maxn], mark[maxn];
vector<int> edge[maxn];

void init() {
    for (int i = 1; i <= N; i++) {
	    edge[i].clear();
	}
	roadNum = 0;
	clr(vis, 0), clr(mark, 0);
}

void dfs(int u, int tar) {
    vis[u] = 1;
	if (u == tar) {
	    roadNum++;
		for (int i = 1; i <= N; i++) {
		    if (vis[i]) mark[i]++;
		}
		return ;
	}
	for (int i = 0; i < edge[u].size(); i++) {
	    int v = edge[u][i];
		if (vis[v]) continue;
		dfs(v, tar);
		vis[v] = false;
	}
}

int solve() {
    init();       
	for (int i = 1; i <= M; i++) {
	    int u, v; sf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int start, end;
	sf("%d%d",&start,&end);
	dfs(start, end);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
	    if (mark[i] == roadNum && i != start && i != end) {
		    ans++;
		}
	}
	return roadNum == 0 ? -1 : ans;
}

int main() {
	while (~sf("%d%d",&N,&M)) {
	    pf("%d\n", solve());
	}
    return 0;
}
