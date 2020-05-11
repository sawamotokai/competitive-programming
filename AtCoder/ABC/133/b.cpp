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
  int n, d; cin >> n >> d;
  vvi points(n, vi(d, 0));
  rep(i,n) {
    vi temp(d);
    rep(j,d) {
      cin >> temp[j];
    }
    points[i] = temp;
  }
  auto getDist = [] (vi p1, vi p2) {
    double sum = 0;
    rep(i, p1.size()) {
      sum += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return sum;
  };
  int ans =0;
  rep(i, n) {
    for (int j=i+1; j<n; j++) {
      double dist = getDist(points[i], points[j]);
      if (floor(sqrt(dist)) == sqrt(dist)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}