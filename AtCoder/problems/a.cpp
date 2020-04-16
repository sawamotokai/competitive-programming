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
  vvi F(N);
  rep(i, N) {
    vi temp(10);
    rep(j,10) {
      cin >> temp[j];
    }
    F[i]=temp;
  }
  vvi P(N);
  rep(i,N) {
    vi temp(11);
    rep(j,11) {
      cin >> temp[j];
    }
    P[i] = temp;
  }
  ll ans = -1e9;
  rep(i, 10) {
    ll profit = 0;
    rep (j, N) {
      if (F[j][i]) profit += P[j][1];
    }
    ans = max(ans, profit);
  }

  for (int i=1; i<(1<<10); i++ ) {
    ll profit = 0;
    int days = __builtin_popcount(i);
    for (int j=0; j<N; j++) {
      int cnt =0;
      for (int k=0; k<10; k++){
        if ((i>>k)&1 && F[j][k]) cnt++;
      }
      profit+=P[j][cnt];
    }
    ans = max(ans, profit);
  }
  cout << ans << endl;
  return 0;
}