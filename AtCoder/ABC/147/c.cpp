#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int N; cin>>N;
  vector<vector<ii> > testimonies(N);
  rep(i,N) {
    int a; cin >> a;
    vector<ii> temp(a);
    rep(j, a) {
      int x, y;
      cin >>x>>y;
      x--;
      temp[j] = ii(x,y);
    }
    testimonies[i] = temp;
  }

  int ans = 0;
  for (int i=0; i< (1<<N); i++) {
    vi isHonest(N, 1);
    [&] {
      for (int j=0; j<N; ++j) {
        if ((i>>j)&1) isHonest[j]=1;
        else isHonest[j] = 0;
      }
      for (int j=0; j<N; ++j) {
        if (!isHonest[j]) continue;
        for (int k=0; k<testimonies[j].size(); k++) {
          int x = testimonies[j][k].first;
          if (isHonest[x] != testimonies[j][k].second) return;
        }
      }
      ans = max(ans, __builtin_popcount(i));
    }();
  }
  cout << ans << endl;
  return 0;
}