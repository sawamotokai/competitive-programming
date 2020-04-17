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
  int N; cin>>N;
  vi L(N);
  rep(i,N) cin>>L[i];
  sort(L.begin(), L.end());
  int ans=0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      int a = L[i], b=L[j];
      auto c = lower_bound(L.begin()+j, L.end(), a+b);
      ans += c-L.begin()-j-1;
    }
  }
  cout << ans << endl;
  return 0;
} 