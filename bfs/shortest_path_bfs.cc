#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

std::map<int, vector<int>> g_link;
std::map<int, int> my_stack; //store current arrived nodes & score

int n_planet, target_me;

bool min_score(map<int,int>::iterator x1, map<int,int>::iterator x2) {
  return x1->second < x2->second;
}
int bfs(){
  //args: 
  //current_node: 
  //cout<<"Now in node: "<<i<<", "<<a[i]<<" , sum= "<<sum<<endl;
  int answer = std::numeric_limits<int>::max();
  my_stack.insert(pair<int, int>(0, 0));
  map<int, int>  *ptmap, *ptmap_next, *ptmap_tmp;

  std::map<int, int> my_stack_next; //store current arrived nodes & score

  ptmap = &my_stack;
  ptmap_next = &my_stack_next;
  
  while(true) {
    for(map<int, int>::iterator it = ptmap->begin(); it != ptmap->end(); it++) {
      int current_node = it->first;
      int current_score = it->second;
      for(vector<int>::iterator itnext = g_link[current_node].begin(); itnext != g_link[current_node].end(); itnext++) {
        //if next node is last of sequence, keep small score
        //expansion to next child nodes
        int next_score = current_score + 1;
        if(*itnext == n_planet - 1) {
          if(answer > next_score)
            answer = next_score;
          continue;
        }
        map<int, int>::iterator ifound = ptmap_next->find(*itnext);
        if(ifound != ptmap_next->end()) {
          //alreay reached by another path, check score and only keep small
          if(ifound->second > next_score)
            ifound->second = next_score;
        }
        else {
          //first time reach the node
          ptmap_next->insert(pair<int, int>(*itnext, next_score));
        }
      }
    }
    if(ptmap_next->empty())
      break;
    //exchange stack
    ptmap_tmp = ptmap;
    ptmap = ptmap_next;
    ptmap_next = ptmap_tmp;
    //clean next stack
    ptmap_next->clear();
  }  
  //
  //map<int, int>::iterator answer = std::min(ptmap->begin(), ptmap->end(), min_score);

  return answer;
}
void solve(){
  //initial state & value
  target_me = bfs(); 
  //cout<<"minimal time: "<<target_me;
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
