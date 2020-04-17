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
  vector<vector<int>> tree;

int rec(int b) {
  int mx=0;
  int mn=INF;
  if (tree[b].size()==0) return 1;
  for (int s: tree[b]) {
    int m = rec(s);
    mx=max(mx,m);
    mn=min(mn,m);
  }
  return mx+mn+1;
}

int main() {
  int N; cin>>N;
  tree.resize(N+1, vector<int>());
  rep(i,N-1) {
    int e = i+2;
    int b; cin>>b;
    tree[b].push_back(e);
  }
  cout << rec(1) << endl;
  return 0;
}