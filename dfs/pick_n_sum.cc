#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 21;
int a[MAX_N];
int n, k;

bool dfs(int i, int sum){
  // leaf node, note n not (n-1)
  if(i==n) return sum == k;
  // not take a[i]
  if(dfs(i+1, sum)) return true;
  // take a[i]
  if(dfs(i+1, sum+a[i])) return true;
  return false;
}
void solve(){
  if(dfs(0, 0)) printf("YES");
  else printf("NO");
}

int main(int argc, char** argv) {
  int n_arr, target_me;
  
  //input size of array
  cout>>"Input size of array, and target value: ">>endl;
  cin>>n_arr>>target_me;
  //
  for(int k = 0; k < n_arr; k++) {
    cin>>a[k];
  }
  //
  solve()
}
