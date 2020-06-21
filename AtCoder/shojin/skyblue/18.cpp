#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

vi to[1000005];

int main() {
  int n; cin >> n;
  vector<queue<int>> a(n);
  rep(i,n) rep(j,n-1) {
    int foo; cin >> foo;
    foo--;
    a[i].push(foo);
  }
  set<ii> q;
  auto check = [&](int fi) {
    if (a[fi].size() == 0) return;
    int se = a[fi].front();
    if (a[se].size() == 0) return;
    if (a[se].front() == fi) {
      ii p(fi, se);
      if (p.first > p.second) swap(p.first, p.second);
      q.insert(p);
    } 
  };
  rep(i,n) {
    check(i);
  }
  int day = 0;
  while (q.size()) {
    day++;
    set<ii> next;
    swap(q, next);
    for (auto it=next.begin(); it != next.end(); it++) {
      ii p = *it;
      int fi = p.first, se = p.second;
      a[fi].pop();
      a[se].pop();
      check(fi);
      check(se);
    }
 }
 rep(i,n) {
   if (a[i].size()) {
     cout << -1 << endl; return 0;
   }
 }
  cout << day << endl;
  return 0;

}