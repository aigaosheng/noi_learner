#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 21;
int a[MAX_N];
int n_arr, target_me;

bool dfs(int i, int sum){
  // leaf node, note n_arr not (n_arr-1)
  //cout<<"Now in node: "<<i<<", "<<a[i]<<" , sum= "<<sum<<endl;
  if(i==n_arr) {
    cout<<"Now in leaf: "<<i<<", sum= "<<sum<<endl; 
    return sum == target_me;
  }
  // not take a[i]
  cout<<"move no ****"<<i<<", no, sum= "<<sum<<endl;
  if(dfs(i+1, sum)) {
    cout<<"Now in node: "<<i<<", no, sum= "<<sum<<endl; 
    return true;
  }
  // take a[i]
  cout<<"move yes **** "<<i<<", yes, sum= "<<sum+a[i]<<endl;
  if(dfs(i+1, sum+a[i])) {
    cout<<"Now in node: "<<i<<", yes, sum= "<<sum+a[i]<<endl; 
    return true;
  }
  cout<<"return ****"<<endl;

  return false;
}
void solve(){
  if(dfs(0, 0)) printf("YES");
  else printf("NO");
}

int main(int argc, char** argv) {
  //int n_arr, target_me;
  
  //input size of array
  cout<<"Input size of array, and target value: "<<endl;
  cin>>n_arr>>target_me;
  //
  for(int target_me = 0; target_me < n_arr; target_me++) {
    cin>>a[target_me];
  }
  //
  solve();
}
