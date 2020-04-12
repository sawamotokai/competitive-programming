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
  int N,M; cin>>N>>M;
  vb accepted(N, false);
  vi wa(N);
  int good = 0;
  int wrong=0;
  rep(i, M) {
    int p; cin >> p; p--;
    string s; cin >> s;
    if (s=="AC") {
      if (!accepted[p]) {
        good++; accepted[p]=true;
        wrong+=wa[p];
      }
    } else {
      wa[p]++;
    }
  }
  printf("%d %d\n", good, wrong);
  return 0;
}