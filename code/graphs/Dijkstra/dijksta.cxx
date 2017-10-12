#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<long long> dijkstra(const vector<vector<pair<int, long long>>>& g, int start) {
	vector<long long> d;
	d.assign(g.size(), LLONG_MAX);
	vector<int> used(g.size());
	d[start] = 0;
	for (size_t i = 0; i < g.size(); i++) {
		int v = -1;
		for (int j = 0; j < g.size(); j++) {
			if (!used[j] && (v == -1 || d[v] > d[j])) v = j;
		}
		if (v == -1 || d[v] == LLONG_MAX) break;
		used[v] = 1;
		for (auto x : g[v]) {
			if (d[v] + x.second < d[x.first]) d[x.first] = d[v] + x.second;
		}
	}
	return d;
}
vector<double> dijkstra(const vector<vector<pair<int, double>>>& g, int start) {
	vector<double> d;
	d.assign(g.size(), LLONG_MAX);
	vector<int> used(g.size());
	d[start] = 0;
	for (size_t i = 0; i < g.size(); i++) {
		int v = -1;
		for (int j = 0; j < g.size(); j++) {
			if (!used[j] && (v == -1 || d[v] > d[j])) v = j;
		}
		if (v == -1 || d[v] >= LLONG_MAX) break;
		used[v] = 1;
		for (auto x : g[v]) {
			if (d[v] + x.second < d[x.first]) d[x.first] = d[v] + x.second;
		}
	}
	return d;
}
vector<long long> dijkstra_heap(const vector<vector<pair<int, long long>>>& g, int start) {
	vector<long long> d;
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		q.pop();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				q.push(make_pair(d[x.first], x.first));
			}
		}
	}
	return d;
}
vector<double> dijkstra_heap(const vector<vector<pair<int, double>>>& g, int start) {
	vector<double> d;
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		q.pop();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				q.push(make_pair(d[x.first], x.first));
			}
		}
	}
	return d;
}
vector<vector<pair<int, long long>>> g;
int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int ii = 0; ii < m; ii++) {
		int x, y;
		long long w;
		cin >> x >> y >> w;
		x--;
		y--;
		g[x].emplace_back(y, w);
		g[y].emplace_back(x, w);
	}
	auto d = dijkstra(g, 0);
	for (auto x : d) cout << x << ' ';
	cout << endl;
	d = dijkstra_heap(g, 0);
	for (auto x : d) cout << x << ' ';
	cout << endl;
	return 0;
}