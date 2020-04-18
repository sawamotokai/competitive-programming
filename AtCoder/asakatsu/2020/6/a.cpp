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

struct show {
  int start, end, channel;
  bool operator < (const show &rhs) {
    if (start==rhs.start) {
      return end < rhs.end;
    }
    return start < rhs.start;
  }
   bool operator > (const show &rhs) {
    if (start==rhs.start) {
      return end > rhs.end;
    }
    return start > rhs.start;
  }
};

vector<priority_queue<show, vector<show>>> shows;

int main() {
  int N,C; cin>>N>>C;
  shows.resize(N);
  rep(i,N) {
    int s,t,c;
    cin>>s>>t>>c; c--;
    shows[c].push(show{s,t, c});
  }
  auto allEmpty = [&] {
    rep(i,C) if(shows[i].size()) return false;
    return true;
  };
  auto smallest = [&] {
    show ret; int ch;
    rep(i, C) {
      if(shows[i].size()) {
        ch = i;
         ret=shows[i].top();
      }
    }
    rep(i,C) {
      if (shows[i].top() < ret) {
        ret = shows[i].top(); ch=i;
      }
    }
    shows[ch].pop();
    return ret;
  };
  int ans=1;
  show next = smallest();
  
  priority_queue<show, vector<show>, [](show a, show b) {return a.end < b.end}> recording;
  recording.push(next);

  while (!allEmpty()) {
     show next = smallest(); 
     int lastShowEndsAt = recording.top().end;
     if (next.start == lastShowEndsAt) {
       if (recording.top().channel == next.channel) {

       }
       else {
         ans++;
       }
     } else if (next.start < lastShowEndsAt) {
       ans++;
     } else {
     recording.pop();
     }
     recording.push(next);
  }
  cout << ans << endl;
  return 0;
}