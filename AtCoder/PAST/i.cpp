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
  int N,Q; cin>>N>>Q;
  vector<vector<ll>> a(N, vector<ll>(N));
  rep(i,N) rep(j,N) a[i][j] = N*i + j;
  
  rep(_,Q) {
    int q; cin >> q;
    if (q==1) {
      int A, B; cin >> A>>B;
      A--; B--;
      swap(a[A], a[B]);
    } else if (q==2) {
      int A, B;
      cin >> A >> B;
      A--; B--;
      rep(i,N) swap(a[i][A], a[i][B]);
    } else if (q==3) {
      rep(i,N) {
        rep(j,i+1) {
          swap(a[i][j], a[j][i]);
        } 
      }
    } else if (q==4)
    {
       int A, B;
      cin >> A >> B;
      A--; B--;
      cout << a[A][B] << endl; 
    }
  }
  return 0;
}