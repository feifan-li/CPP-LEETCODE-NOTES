#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty() || t.empty() || size(s)==0 || size(t)==0) return true;
        unordered_set<char> setT;
        unordered_map<char,char> map;
        for(int i=0;i<s.length();++i){
          char a = s.at(i);
          char b = t.at(i);
          if(!map.count(a)){
            if(setT.count(b)) return false;
            else{
              map[a] = b;
              setT.insert(b);
              continue;
            }
          }else{
            if(map[a]==b) continue;
            else return false;
          }
        }
        return true;
    }
};

int main(){
  Solution solution;
  string s1 = "paper";
  string t1 = "title";
  string s2 = "foo";
  string t2 = "bar";
  string s3 = "egg";
  string t3 = "add";
  cout<<solution.isIsomorphic(s1,t1)<<endl;//1
  cout<<solution.isIsomorphic(s2,t2)<<endl;//0
  cout<<solution.isIsomorphic(s3,t3)<<endl;//1

  return 0;
}