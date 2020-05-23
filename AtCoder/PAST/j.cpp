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

int main() {
  int n,m; cin >> n >> m;
  vi dp(n,INF);
  rep(i,m) {
    int sushi; cin >> sushi;
    sushi= -sushi;
    if (dp.back() != INF && dp.back() <= sushi) {
      cout << -1 << endl;
    } else {
      auto it = upper_bound(dp.begin(), dp.end(), sushi);
      *it = sushi;
      cout << it - dp.begin() +1 << endl;
    }
 }
  return 0;
}