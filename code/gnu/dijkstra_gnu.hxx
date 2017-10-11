#include <climits>
#include <ext/pb_ds/priority_queue.hpp>
#include <utility>
#include <vector>
using namespace std;
template <typename X, typename C = greater<X>>
using heap = __gnu_pbds::priority_queue<X, C>;
void dijkstra_gnu(const vector<vector<pair<int, long long>>>& g, vector<long long>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	heap<pair<long long, int>> q;
	vector<heap<pair<long long, int>>::point_iterator> pt(g.size());
	pt[start] = q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				if (pt[x.first] == nullptr)
					q.push(make_pair(d[x.first], x.first));
				else
					q.modify(pt[x.first], {d[x.first], x.first});
			}
		}
	}
}
void dijkstra_gnu(const vector<vector<pair<int, double>>>& g, vector<double>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	heap<pair<double, int>> q;
	vector<heap<pair<double, int>>::point_iterator> pt(g.size());
	pt[start] = q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				if (pt[x.first] == nullptr)
					q.push(make_pair(d[x.first], x.first));
				else
					q.modify(pt[x.first], {d[x.first], x.first});
			}
		}
	}
}