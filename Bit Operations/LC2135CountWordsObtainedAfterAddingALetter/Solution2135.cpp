class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int targetCount = 0;
        unordered_set<int> startWordsToInts;
        int start_min_size = 100, start_max_size = 0;
        for(string start: startWords){
            start_min_size = start.size()<start_min_size?start.size():start_min_size;
            start_max_size = start.size()>start_max_size?start.size():start_max_size;
            startWordsToInts.insert(stringToInt(start));
        }
        //O(m) until now
        for(string target: targetWords){
            if(target.size()<start_min_size+1 || target.size()>start_max_size+1){
                continue;
            }
            int tInt = stringToInt(target);
            //tInt and sInt can only have 1 bit's difference
            for(int offset=0; offset<26; ++offset){
                if((tInt&(1<<offset))>0){
                    int temp = tInt - (1<<offset);
                    if(startWordsToInts.count(temp)){
                        targetCount ++;
                        //then we now this 'target' can be converted
                        break;
                    }
                }
            }
        }
        //O(m+k*n) until now
        return targetCount;
    }
private:
    int stringToInt(string s){
        int a = 0;
        for(int i=0;i<s.size();++i){
            a |= (1<<(s.at(i)-'a'));
        }
        return a;
    }
};