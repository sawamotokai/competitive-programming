#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++

// AGC44 A

ll n, a, b, c, d;
unordered_map<ll, ll> mp;
void helper(ll num, ll cost) {
  if (mp.find(num) != mp.end()) return;
  if (num == n) {
    cout << cost << endl;
    return;
  }
  if (mp.find(num) == mp.end()) mp[num] = cost;
  else mp[num] = min(mp[num], cost);
  helper(num*2, cost + a);
  helper(num*3, cost + b);
  helper(num*5, cost + c);
  helper(num+1, cost + d);
  helper(num-1, cost + d);
}

void solve() {
  mp.clear();
  cin >> n >> a >> b >> c >> d;
  mp[0] = 0;
  helper(0, 0);
}

int main() {
  int t; cin >> t;
  rep(_, t) solve();
  return 0;
}