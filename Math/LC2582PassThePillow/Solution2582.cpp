class Solution {
public:
    int passThePillow(int n, int time) {
        // 1 -> 2 -> 3 -> ... -> n -> n-1
        // 0s-> 1s-> 2s-> ... -> n-1s
        int index = time%(2*n-2);
        if(index <= (n-1)){
            return index+1;
        }
        return n-(index%(n-1));
    }
};