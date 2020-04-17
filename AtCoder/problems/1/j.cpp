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
  vi h(N);
  rep(i,N) cin>>h[i];
  vi peaks;
  if (N==1) {
    cout << 1 << endl; return 0;
  }
  if (h[0]>h[1]) peaks.push_back(0);
  if (h[N-1]> h[N-2]) peaks.push_back(N-1);
  for (int i=1; i<N-1; i++) {
    if (h[i-1]<h[i] && h[i] > h[i+1]) peaks.push_back(i);
  }
  int ans = 0;
  // printf("%d peaks exists\n", peaks.size());
  for (int peak: peaks) {
    // printf("%d peak", h[peak]);
    int size = 1;
    int left=0, right=0;
    bool toL=true, toR=true;
    while (toL || toR)
    {
      if (peak-left-1>=0 && h[peak-left]>h[peak-left-1]) {
      // printf("toLeft %d\n", h[peak-left]);
      size++; left++;
      } else toL = false;
      if (peak+right+1<N && h[peak+right] > h[peak+right+1]) {
      // printf("toRight %d\n", h[peak+right]);
        size++; right++;
      } else toR = false;
    }
    ans = max(ans, size);
  }
  cout << ans << endl;
  return 0;
} 