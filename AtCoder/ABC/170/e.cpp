#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
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

int main() {
  int n,q; cin >> n >> q;
  vi a(n), b(n);
  vector<multiset<int>> s(200005);
  multiset<int> maxs;

  
  auto getMax = [&] (int i) {
    if (s[i].size() == 0) return -1;
    return *(s[i].rbegin());
  };
  auto delMax = [&](int i) {
    int x = getMax(i);
    if (x==-1) return;
    maxs.erase(maxs.find(x));
  };
  auto addMax = [&](int i) {
    int x = getMax(i);
    if (x == -1) return;
    maxs.insert(x);
  };
  auto add = [&](int i, int x) {
    delMax(i);
    s[i].insert(x);
    addMax(i);
  };
  auto del = [&](int i, int x) {
    delMax(i);
    s[i].erase(s[i].find(x));
    addMax(i);
  };
  rep(i,n) {
    cin >> a[i] >> b[i];
    add(b[i], a[i]);
  }
  rep(_,q)  {
    int c,d; cin >> c >> d;
    c--;
    del(b[c], a[c]);
    b[c] = d;
    add(d, a[c]);
    int ans = *(maxs.begin());
    printf("%d\n", ans);
  }
  return 0;
}