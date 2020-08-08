#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int N;
vi to[100005];
int main() {
  cin >> N;
  rep(i,N-1) {
  int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  minq q;
  q.push(0);
  vi ans;
  vi visited(N);
  visited[0] = 1;
  while(q.size()) {
    int v = q.top(); q.pop();
    ans.push_back(v);
    for (int u: to[v]) {
      if (visited[u]) continue;
      q.push(u);
      visited[u] = 1;
    }
  }
  assert(ans.size() == N);
  rep(i,N) printf("%d%c", ans[i]+1, i==N-1?'\n':' ');
  return 0;
}