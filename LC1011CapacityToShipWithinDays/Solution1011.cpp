#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;
class Solution {
public:
    int getMax(vector<int>& p){
        int m = 0;
        for(int num : p){
            m = max(m,num);
        }
        return m;
    }
    int getSum(vector<int>& p){
        int sum = 0;
        for(int num:p){sum+=num;}
        return sum;
    }
    bool canFinish(vector<int>& weights, int capacity, int D){
        stack<int> stk;
        stk.push(weights[0]);
        for(int i=1;i<weights.size();++i){
          if(stk.top()<=capacity && stk.top()+weights[i] > capacity){
            stk.push(weights[i]);
          }else if(stk.top()<=capacity && stk.top()+weights[i]<=capacity){
            int tmp = stk.top();
            stk.pop();
            stk.push(tmp+weights[i]);
          }
        }
        return stk.size()<=D;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = getMax(weights);
        int right = getSum(weights)+1;
        while(left<right){
          int capacity = left+(right-left)/2;
          if(canFinish(weights,capacity,days)){
            right = capacity;
          }else{
            left = capacity+1;
          }
        }
        return left;

    }
};

int main(){
  Solution solution;
  vector<int> weights1{1,2,3,4,5,6,7,8,9,10};
  int days1 = 5;
  vector<int> weights2{3,2,2,4,1,4};
  int days2 = 3;
  vector<int> weights3{1,2,3,1,1};
  int days3 = 4;

  cout<<solution.shipWithinDays(weights1,days1)<<endl;
  cout<<solution.shipWithinDays(weights2,days2)<<endl;
  cout<<solution.shipWithinDays(weights3,days3)<<endl;
}