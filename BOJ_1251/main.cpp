#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s;
	cin >> s;

	const auto n = static_cast<int>(s.length());

	vector<string> ss{};
	ss.reserve(n * n * n);
	for (auto i = 1; i < n; ++i) {
		for (auto j = 1; j < n; ++j) {
			if (1 <= n - i - j) {
				auto s1 = s.substr(0, i);
				auto s2 = s.substr(i, j);
				auto s3 = s.substr(i + j, n - i - j);

				reverse(s1.begin(), s1.end());
				reverse(s2.begin(), s2.end());
				reverse(s3.begin(), s3.end());

				ss.push_back(s1 + s2 + s3);
			}
		}
	}

	cout << *min_element(ss.begin(), ss.end());

	return 0;
}