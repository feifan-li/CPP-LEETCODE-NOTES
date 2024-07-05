#include<iostream>
#include<vector>
using namespace std;
// Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
// (a*b)%k = (a%k)(b%k)%k
class Solution {
public:
    int BASE = 1337;
    int myPow(int a,int k){
        if(k==0) return 1;
        a %= BASE;

        if(k%2==1){return (a*myPow(a,k-1))%BASE;}
        else{
            int sub = myPow(a,k/2);
            return (sub*sub)%BASE;
        }
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = myPow(a,last);
        int part2 = myPow(superPow(a,b),10);

        return (part1*part2)%BASE;
    }
};
int main(){

  int a1 = 2;
  vector<int> b1{4,3,3,8,5,3};
  int a2 = 3;
  vector<int> b2{2,0};

  Solution solution;
  cout<<solution.superPow(a1,b1)<<endl;
  cout<<solution.superPow(a2,b2)<<endl;


  return 0;
}