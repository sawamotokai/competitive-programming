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
  vi A(N);
  rep(i,N) cin >> A[i];
  vi ord(A);
  sort(ord.begin(), ord.end(), [](int a, int b) {return a>b;});
  int left = 0, right=N-1;
  ll ans =0;
  rep(i, ord.size()) {
    bool pending = false;
    rep(j, N) {
      if (A[j] == ord[i]) {
        if ((j-left) == (right -j)) {
          ans += (j-left) * A[j];
          pending = true;
          continue;
        }
        if ((j-left) > (right-j)) {
          if (pending) right--;
          ans += (j-left)*A[j];
          left++;
        } else {
          if (pending) left++;
          ans += (right-j) * A[j];
          right--;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}