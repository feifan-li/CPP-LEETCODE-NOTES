#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2418 {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //height -> name
        unordered_map<int, string> heightToName;
        // vector<string> ans;
        for(int i=0;i<heights.size();++i){
            heightToName[heights[i]] = names[i];
        }
        //sort height
        sort(heights.begin(), heights.end(), [](int a, int b){
            return a>b; 
        });
        for(int i=0;i<heights.size();++i){
            // ans.push_back(heightToName[heights[i]]);
            names[i] = heightToName[heights[i]];
        }
        return names;
    }
};

int main(int argc, char** argv){
  Solution2418 s;
  vector<string> names = {"Feifan", "Samuel", "Mark", "Jack", "Spencer", "Hongmeng"};
  vector<int> heights = {177,180,176,175,178,88};
  vector<string> res = s.sortPeople(names, heights);
  for(auto x : res){
    cout << x << endl;
  }
  return 0;
}