#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

std::map<int, vector<int>> g_link;
int n_planet, target_me;


bool dfs(int current_node, int score){
  //args: 
  //current_node: 
  //cout<<"Now in node: "<<i<<", "<<a[i]<<" , sum= "<<sum<<endl;
  if(current_node == n_planet - 1) {
    cout<<"Arrive in the last planet: "<<current_node<<", current time = "<<score<<endl; 
    if(score < target_me) {
      target_me = score; 
    }
    return true;
  }
  //move to next child
  //cout<<"move no ****"<<i<<", no, sum= "<<sum<<endl;
  for(vector<int>::iterator it = g_link[current_node].begin(); it != g_link[current_node].end(); it++) {
    //cout<<"Now in node: "<<*it<<", score = "<<score<<endl; 
    if(dfs(*it, score + 1)) {
      cout<<"Now in node: "<<*it<<", score = "<<score + 1<<endl; 
      //return true;
    }
  }

  return false;
}
void solve(){
  if(dfs(0, 0)) 
    cout<<"minimal time: "<<target_me;
  else 
    cout<<"All path searched for answe"<<endl;
}

int main(int argc, char** argv) {
  //int n_arr, target_me;
  
  //input size of array
  int n_hole;
  cout<<"Input planet number, hole number, planet link "<<endl;
  cin>>n_planet>>n_hole;
  //add sequence link
  for(int k = 0; k < n_planet - 1; k++) {
    vector<int> tmp;
    tmp.push_back(k+1);
    g_link.insert(pair<int, vector<int>>(k, tmp));
  }

  //
  for(int k = 0; k < n_hole; k++) {
    int n1, n2;
    cin>>n1>>n2;
    //push to g_link to store graph structure
    map<int, vector<int>>::iterator ifound = g_link.find(n1);
    if(ifound != g_link.end()) {
      ifound->second.push_back(n2);
    }
    else {
      cout<<"Warning: error"<<endl;
      //g_link[n1].push_back(n2);
    }
  }
  //debug, print graph
  for(map<int, vector<int>>::iterator it = g_link.begin(); it != g_link.end(); it++) {
    cout<<"node: "<<it->first<<" ";
    for(vector<int>::iterator itv = it->second.begin(); itv != it->second.end(); itv++) {
      cout<<*itv<<" ";
    }
    cout<<endl;
  }
  //
  target_me = std::numeric_limits<int>::max();
  solve();
  cout<< "minimal time: "<< target_me<<endl;
  return 0;
}
