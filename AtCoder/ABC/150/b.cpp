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
  int N;cin>>N;
  string s; cin>>s;
  int ans = 0;
  for (int i=0; i<N-2; i++) {
    if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
  }
  cout << ans << endl;
  return 0;
}