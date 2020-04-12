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
  map<ii, int> mp;
  auto make = [](int num) {
    int l = num%10;
    int h;
    while (num>0) {
      h=num;
      num/=10;
    }
    return ii(h,l);
  };

  for (int i=1; i<=N;i++) {
    ii p = make(i);
    mp[p]++;
  }

  ll ans = 0;
  for (int i=1; i<=N; i++) {
    ii p = make(i);
    ii q = ii(p.second, p.first);
    ans += mp[q];
  }
  cout << ans << endl;
  return 0;
}