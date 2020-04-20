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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int N,C,K; cin>>N>>C>>K;
  vi T(N);
  rep(i,N) cin >> T[i];
  sort(T.begin(), T.end());
  int firstPassenger = T[0];
  int cnt = 0;
  int bus=0;
  rep(i,N) {
    int t = T[i];
    if (cnt < C && t-firstPassenger <= K) {
      cnt++;
    } else {
      bus++; cnt = 1;
      firstPassenger = t;
    }
  }
  if (cnt) bus++;
  cout << bus << endl;
  return 0;
}