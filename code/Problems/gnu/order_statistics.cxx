#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
using namespace std;
template <typename X, typename Y = __gnu_pbds::null_type, typename C = less<X>>
using ordered_map = __gnu_pbds::tree<X, Y, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
int main() {
	ordered_map<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.insert(x);
	}
	// finding by order
	int q1;
	cin >> q1;
	for (int i = 0; i < q1; i++) {
		int k;
		cin >> k;
		assert(k < n && k >= 0);
		cout << *q.find_by_order(k) << '\n';
	}
	// order of key
	int q2;
	cin >> q2;
	for (int i = 0; i < q2; i++) {
		int k;
		cin >> k;
		cout << q.order_of_key(k) << '\n';
	}
	return 0;
}