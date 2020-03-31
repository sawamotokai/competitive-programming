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


void solve() {
  int a,b,c,d; cin >>a>>b>>c>>d;
  int x,y,x1,y1,x2,y2;
  cin >>x>>y>>x1>>y1>>x2>>y2;
  int xMove = b-a, yMove = d-c;
  int xPos = x+xMove; 
  int yPos = y+yMove;
  bool ok = false;
  if (x1<=xPos && xPos <= x2 && y1<=yPos && yPos <= y2) ok = true;
  if (x1==x2 && (a!=0 ||b!=0)) ok = false;
  if (y1==y2 && (c!=0 ||d!=0)) ok = false;
  puts(ok?"YES":"NO");

}

int main() {
  int t; cin >>t;
  rep(i,t) solve();
  return 0;
}