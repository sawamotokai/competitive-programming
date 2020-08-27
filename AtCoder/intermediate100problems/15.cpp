#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
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
int x[10],y[10];
double sum = 0;
vi way;
int used[10];

double getDist(int i, int j) {
  ll sq = (x[i] - x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
  double ret = sqrt(sq);
  return ret;
}

void dfs(int d=0) {
  if (d==N) {
    assert(way.size() == N);
    for (int i=0; i<N-1;i++) sum += getDist(way[i], way[i+1]);
    return;
  }
  rep(i,N) {
    if (used[i]) continue;
    way.pb(i);
    used[i] = true;
    dfs(d+1);
    way.pop_back();
    used[i] = false;
  }
}

int main() {
  cin >> N;
  rep(i,N) cin >> x[i] >> y[i];
  dfs();
  ll ways = 1;
  rep(i,N) ways *= i+1; 
  printf("%.10f\n", sum/ways);
  return 0;
}