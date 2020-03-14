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
typedef long long ll;
const ll INF = 1e18L + 1;

int main() {
  int H,W;
  cin >> H >> W;
  ll ans = 0;
  if (H!=1&&W!=1){
    ans += ceil((double)H / 2) * ceil((double)W / 2);
  ans += floor((double)H / 2) * floor((double)W / 2);
  }else
    ans = 1;

  cout << ans << endl;
  return 0;
}