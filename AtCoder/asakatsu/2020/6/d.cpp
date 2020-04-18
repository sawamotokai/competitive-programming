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
  ll N,K,M,R;
  cin >>N>>K>>M>>R;
  ll sum = 0;
  vector<ll> score(N-1);
  rep(i,N-1) {
    cin >> score[i];
  };
  sort(score.begin(), score.end(), [](ll a, ll b) { return a>b;});
  ll topK = 0;
  if (K<N) {
      rep (i,K) topK+=score[i];
      if(topK >= R*K) {
        cout << 0 << endl; return 0;
      } else {
        topK -= score[K-1];
      }
  } else {
    rep(i,K-1) topK+=score[i];
  }
 ll want = R*K-topK;
  if (want > M) want = -1;
  printf("%lld\n", want);

  return 0;
}