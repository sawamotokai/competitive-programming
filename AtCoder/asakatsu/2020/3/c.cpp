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
  int R,G,B,N; cin>>R>>G>>B>>N;
  int cnt=0;
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=N; j++) {
      int left = N - R*i - G*j;
      if (left<0) continue;
      double q = left/(double)B;
      if (floor(q) == q) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}