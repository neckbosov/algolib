#include <climits>
#include <ext/pb_ds/priority_queue.hpp>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
template <typename X, typename C = greater<X>>
using heap = __gnu_pbds::priority_queue<X, C>;
vector<long long> dijkstra_gnu(const vector<vector<pair<int, long long>>>& g, int start) {
	vector<long long> d;
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	heap<pair<long long, int>> q;
	vector<heap<pair<long long, int>>::point_iterator> pt(g.size());
	pt[start] = q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		q.pop();
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				if (pt[x.first] == nullptr)
					pt[x.first] = q.push(make_pair(d[x.first], x.first));
				else
					q.modify(pt[x.first], {d[x.first], x.first});
			}
		}
	}
	return d;
}
vector<double> dijkstra_gnu(const vector<vector<pair<int, double>>>& g, int start) {
	vector<double> d;
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	heap<pair<double, int>> q;
	vector<heap<pair<double, int>>::point_iterator> pt(g.size());
	pt[start] = q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		cout << q.size() << endl;
		q.pop();
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				if (pt[x.first] == nullptr)
					pt[x.first] = q.push(make_pair(d[x.first], x.first));
				else
					q.modify(pt[x.first], {d[x.first], x.first});
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
	auto d = dijkstra_gnu(g, 0);
	for (auto x : d) cout << x << ' ';
	cout << endl;
	return 0;
}