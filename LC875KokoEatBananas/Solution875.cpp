#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int getMax(vector<int>& piles){
        int m = 0;
        for(int num : piles){
            m = max(m,num);
        }
        return m;
    }
    bool canFinish(vector<int>& piles, int speed, int h){
      int hours = 0;
      for(int num:piles){
        hours += ceil((double)num/speed);
      }
      return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = getMax(piles)+1;
        while(left<right){
          int speed = left+(right-left)/2;
          if(canFinish(piles,speed,h)){
            right = speed;
          }else{
            left = speed+1;
          }
        }
        return left;
    }
};

int main(){
  Solution solution;
  vector<int> piles1{3,6,7,11};
  int h1 = 8;
  vector<int> piles2{30,11,23,4,20};
  int h2 = 5;
  vector<int> piles3{30,11,23,4,20};
  int h3 = 6;

  cout << solution.minEatingSpeed(piles1,h1)<<endl;
  cout << solution.minEatingSpeed(piles2,h2)<<endl;
  cout << solution.minEatingSpeed(piles3,h3)<<endl;

}