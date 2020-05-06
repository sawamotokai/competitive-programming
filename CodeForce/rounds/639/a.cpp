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

vector<ll> mem(100000, INF);
ll f(int h)
{
  if (h == 1)
    mem[h] = 2;
  if (mem[h] == INF)
  {
    mem[h] = 3 * h - 1 + f(h - 1);
  }
  return mem[h];
}

int main() {
  int t; cin >> t;
  rep(i, 100000) {
    f(i);
  }
  rep(_, t) {
    int n; cin >> n;
    int ans = 0;
    for (int i=min(n, 100000-1); i>0; i--) {
      if (mem[i] > n) continue;
      ans++;
      n -= mem[i];
    }     

    cout << ans << endl;
  }
  return 0;
}