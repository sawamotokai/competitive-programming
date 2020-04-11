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

int A[100010];
int main() {
  int H, N; cin>>H>>N;
  ll sum = 0;
  rep(i,N) {
    int a; cin>>a; sum+=a;
  }
  puts(H<= sum? "Yes":
  "No");
  

  return 0;
}