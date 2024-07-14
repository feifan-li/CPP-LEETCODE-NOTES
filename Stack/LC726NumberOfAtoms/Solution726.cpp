class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCounts;
        deque<string> stack;
        int i = 0, n = formula.size();
        while(i < n){
            if(formula[i]=='('){
                stack.push_back("(");
                i++;
            }else if(isUppercase(formula[i])){
                if(i+1<n && isLowercase(formula[i+1])){
                    stack.push_back(formula.substr(i,2));
                    i = i + 2;
                }else{
                    stack.push_back(formula.substr(i,1));
                    i = i + 1;
                }
            }else if(isDigit(formula[i])){
                int j = i;
                while(j<n && isDigit(formula[j])){
                    j++;
                }
                stack.push_back(formula.substr(i,j-i));
                i = j;
            }else if(formula[i] == ')'){
                int multi = 1;
                int j = i + 1;
                while(j < n && isDigit(formula[j])){
                    j++;
                }
                if(j > i + 1){
                    multi = stoi(formula.substr(i+1,j-i-1));
                }
                deque<string> groupQueue;
                while(!stack.empty() && stack.back()!="("){
                    string tmp = stack.back();
                    stack.pop_back();
                    if(isDigit(tmp[0])){
                        int local_multi = multi * stoi(tmp);
                        tmp = stack.back();
                        stack.pop_back();
                        if(isLetter(tmp[0])){
                            groupQueue.push_back(tmp);
                            groupQueue.push_back(to_string(local_multi));
                        }
                    }else if(isLetter(tmp[0])){
                        groupQueue.push_back(tmp);
                        if(multi>1){
                            groupQueue.push_back(to_string(multi));
                        }
                    }
                }
                if(stack.back()=="("){
                    stack.pop_back();
                }
                while(!groupQueue.empty()){
                    stack.push_back(groupQueue.front());
                    groupQueue.pop_front();
                }
                i = j;
            }
        }  
        while(!stack.empty()){
            string tmp = stack.front();
            stack.pop_front();
            if(isLetter(tmp[0])){
                if(stack.empty() || isLetter(stack.front()[0])){
                    atomCounts[tmp] += 1;
                }else if(isDigit(stack.front()[0])){
                    atomCounts[tmp] += (stoi(stack.front()));
                    stack.pop_front();
                }
            }
        }
        string ans = "";
        for(auto it = atomCounts.begin(); it!=atomCounts.end(); ++it){
            ans.append(it->first);
            if(it->second > 1){
                ans.append(to_string(it->second));
            }
        }
        return ans;
    }
private:
    bool isUppercase(char a){
        return (a-'A')>=0 && ('Z'-a)>=0;
    }
    bool isLowercase(char a){
        return (a-'a')>=0 && ('z'-a)>=0;
    }
    bool isLetter(char a){
        return isUppercase(a) || isLowercase(a);
    }
    bool isDigit(char a){
        return (a-'0')>=0 && ('9'-a)>=0;
    }
};