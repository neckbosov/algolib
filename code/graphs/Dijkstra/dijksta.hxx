#include <climits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
void dijkstra(const vector<vector<pair<int, long long>>>& g, vector<long long>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	vector<int> used(g.size());
	d[start] = 0;
	for (size_t i = 0; i < g.size(); i++) {
		int v = -1;
		for (int j = 0; j < g.size(); j++) {
			if (!used[v] && (v == -1 && d[v] > d[j])) v = j;
		}
		if (v == -1 || d[v] == LLONG_MAX) break;
		used[v] = 1;
		for (auto x : g[v]) {
			if (d[v] + x.second < d[x.first]) d[x.first] = d[v] + x.second;
		}
	}
}
void dijkstra(const vector<vector<pair<int, double>>>& g, vector<double>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	vector<int> used(g.size());
	d[start] = 0;
	for (size_t i = 0; i < g.size(); i++) {
		int v = -1;
		for (int j = 0; j < g.size(); j++) {
			if (!used[v] && (v == -1 && d[v] > d[j])) v = j;
		}
		if (v == -1 || d[v] >= LLONG_MAX) break;
		used[v] = 1;
		for (auto x : g[v]) {
			if (d[v] + x.second < d[x.first]) d[x.first] = d[v] + x.second;
		}
	}
}
void dijkstra_heap(const vector<vector<pair<int, long long>>>& g, vector<long long>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				q.push(make_pair(d[x.first], x.first));
			}
		}
	}
}
void dijkstra_heap(const vector<vector<pair<int, double>>>& g, vector<double>& d, int start) {
	d.assign(g.size(), LLONG_MAX);
	d[start] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	q.push({d[start], start});
	while (!q.empty()) {
		auto v = q.top();
		if (v.first != d[v.second]) continue;
		for (auto x : g[v.second]) {
			if (d[v.second] + x.second < d[x.first]) {
				d[x.first] = d[v.second] + x.second;
				q.push(make_pair(d[x.first], x.first));
			}
		}
	}
}