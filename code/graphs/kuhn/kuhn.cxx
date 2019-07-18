#include <iostream>
#include <vector>
using namespace std;
vector<int> pa, u, pal;
int cc;
vector<int> e;
vector<vector<int>> g;

bool dfs(int v) {
	if (u[v] == cc) return 0;
	u[v] = cc;
	for (int x : g[v]) {
		if (pa[x] == -1 || dfs(pa[x])) {
			pa[x] = v;
			if (pal[v] != -1) pa[pal[v]] = -1;
			pal[v] = x;
			return 1;
		}
	}
	return 0;
}

void kuhn() {
	bool fl = 1;
	while (fl) {
		fl = 0;
		cc++;
		for (int x : e)
			if (pal[x] == -1 && dfs(x)) fl = 1;
	}
}
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	pal.assign(n1 + 1, -1);
	pa.assign(n2 + 1, -1);
	g.resize(n1 + 1);
	u.resize(n1 + 1);
	for (int i = 1; i <= n1; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			g[i].push_back(x);
		}
		e.push_back(i);
	}
	kuhn();
	for (int i = 1; i < n1 + 1; i++) {
		cout << i << ' ' << pal[i] << '\n';
	}
	return 0;
}