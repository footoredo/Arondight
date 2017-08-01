#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "a"
const int N = 204;
const int M = 21;

int ans[N][M][M][M][M];

pair<int,int> to_go[N][M][M];

int to_ride[N];
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k); 
  if (k<m) m = k;
  for (int i=0; i<n; i++){
      int a;
      scanf("%d",&a);
      to_ride[i]+=a;
  }
  for (int i=0; i<n; i++){
      int a;
      scanf("%d",&a);
      to_ride[i]+=a;
  }
  for (int i = 0; i < n; i++)
      for (int a = 0; a <= k; a++)
          for (int j = 0; j <= a; j++){
              int k1 = a;
              int m1 = j;
              int k3 = k;
              int m3 = m;
              int z = i;
              for (; z < n; z++){
                  if ( k1 == 0 || m1 == 0 || k3==0 || m3 ==0)
                     break;
                  if (to_ride[z] > 0) m3--;
                  if (to_ride[z] > 1) m1--;
                  k1--;
                  k3--;
              }
              if (m3 > k3) m3 = k3;
              to_go[i][j][a].first = z;
              to_go[i][j][a].second = m3;             
          }
  for (int i = 0; i <= n; i++)
      for (int m1 = 0; m1 <= m; m1++)
          for (int k1 = 0; k1 <= k; k1++)
              for (int m2 = 0; m2 <= m; m2++)
                  for (int k2 = 0; k2 <= k; k2++)
                      ans[i][m1][k1][m2][k2] = 2*n;
  ans[0][0][0][0][0] = 0;
  int nk1,nk2,nm1,nm2;
  int answer;
  for (int i = 0; i < n; i++)
      for (int m1 = 0; m1 <= m; m1++)
          for (int k1 = m1; k1 <= k; k1++)
              for (int m2 = m1; m2 <= m; m2++)
                 for (int k2 = max(k1,m2); k2 <= k; k2++)

                  {
                      answer = ans[i][m1][k1][m2][k2];
                      if (answer == 2*n) {
                         continue;
                      }
                       
                      
                      if ( to_ride[i] == 0 ) {
                           nk1 = k1 > 0 ? k1 - 1 : 0;
                           nk2 = k2 > 0 ? k2 - 1 : 0;
                           nm1 = m1 == k1 ? nk1 : m1;
                           nm2 = m2 == k2 ? nk2 : m2;
                           ans[i+1][nm1][nk1][nm2][nk2] = min(ans[i+1][nm1][nk1][nm2][nk2], answer);
                           continue;
                      }
                      
                      
                      if (m1 == 0) {
                         ans[i][m2][k2][m][k] = min(ans[i][m2][k2][m][k], answer+1);
                         if (m2 == 0 || to_ride[i] == 2) continue;
                         ans[i+1][0][0][m2 - 1][k2 - 1] = min(ans[i+1][0][0][m2-1][k2-1], answer);
                         continue;
                      }
                      
                      pair<int,int> z3 = to_go[i][m1][k1];
                     
                      nk1 = k2 - z3.first + i;
                      nm1 = min(m2,nk1);
                      nm2 = z3.second;
                      nk2 = k - z3.first + i;
                      ans[z3.first][nm1][nk1][nm2][nk2] = min (ans[z3.first][nm1][nk1][nm2][nk2], answer+1);
                      
                      
                      if (to_ride[i] == 1) {
                         nm2 = min(m2, k2-1);
                         ans[i+1][m1-1][k1-1][nm2][k2-1] = min(ans[i+1][m1-1][k1-1][nm2][k2-1], answer);
                         if (m1 != m2)
                            ans[i+1][min(m1,k1-1)][k1-1][m2-1][k2-1] = min(ans[i+1][min(m1,k1-1)][k1-1][m2-1][k2-1], answer);
                         continue;
                      }
                      ans[i+1][m1-1][k1-1][m2-1][k2-1] = min(ans[i+1][m1-1][k1-1][m2-1][k2-1], answer); 
                       
                  }
  answer = 2*n;
  for (int m1=0; m1<=m; m1++)
      for (int k1=0;k1<=k;k1++)
          for (int m2=0; m2<=m;m2++)
              for (int k2=0;k2<=k;k2++)
                  answer = min(answer, ans[n][m1][k1][m2][k2]);
  cout << answer << "\n";

  

  return 0;
}
