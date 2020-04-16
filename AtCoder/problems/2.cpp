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
  int N; cin >> N;
  double D = sqrt( 1+8*N);
  bool ok = D - (double) floor(D) == 0.0;
  if (!ok) {
    cout << "No" << endl; return 0;
  } else {
    cout << "Yes" << endl;
  }
  int numSet = (D-1)/2 +1;
  cout << numSet << endl;
  vector<vector<int >> sets;
  sets.push_back(vi(1,1));
  sets.push_back(vi(1,1));
  int curSet = 1;
  int leftMost = 1;
  for (int i=2; i<=N; i++) {
    if (leftMost == curSet) { 
      sets.push_back(vi(1, i));
      curSet++;
      sets[0].push_back(i);
      leftMost=1;
      continue;
    }
    sets[leftMost++].push_back(i);
    sets[curSet].push_back(i);
  }
  rep(i, sets.size()){
    cout << sets[i].size() << ' ';
    rep(j, sets[i].size()) cout << sets[i][j] << ' ';
    cout << endl;
  }
  return 0;
}