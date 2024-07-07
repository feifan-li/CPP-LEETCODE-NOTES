#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
              for(int j = i*i;j<n;j=j+i){isPrime[j] = false;}
            }
        }

        int cnt = 0;
        for(int i=2;i<n;++i){
          if(isPrime[i]){++cnt;}
        }

        return cnt;
    }
};

int main(){
  Solution s;
  cout << s.countPrimes(0) <<endl;
  cout << s.countPrimes(1) <<endl;
  cout << s.countPrimes(10) <<endl;
  cout << s.countPrimes(100) <<endl;

  return 0;
}