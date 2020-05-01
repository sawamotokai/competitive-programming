#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
const int INF = 1e9 + 1;

int n, x, y;
vvi g;
int main()
{
 cin >> n >> x >> y; x--;y--;
  vi ans(n);
  rep(sv, n) {
    vi dist(n, INF);
    queue<int> q;
    auto push = [&] (int v, int d) {
      if (dist[v] != INF) return ;
      dist[v] = d;
      q.push(v);
    };
    push(sv, 0);
    while (q.size()) {
      int v = q.front(); q.pop();
      int d=dist[v];
      if (v) push(v-1, d+1);
      if (v+1<n) push(v+1, d+1);
      if (v==x) push(y, d+1);
      if (v==y) push(x, d+1);
    }
    rep(i, n) ans[dist[i]]++;
  }
  for (int i=1; i<n ;i++) {
    cout << ans[i]/2 << endl;
  }
  return 0;
}