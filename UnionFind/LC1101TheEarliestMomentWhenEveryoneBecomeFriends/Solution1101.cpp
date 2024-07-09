class Solution {
public:
    class UnionFind {
    private:
        int count;
        vector<int> parent;
        vector<int> size;
    public:
        UnionFind(int n):count(n), parent(n), size(n,1){
            for(int i=0;i<n;++i){
                parent[i] = i;
            }
        }
    private:
        int find(int x){
            while(x!=parent[x]){
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }
    public:
        bool connected(int x, int y){
            return parent[x]==parent[y];
        }
        void union_operation(int x, int y){
            int rootx = find(x);
            int rooty = find(y);
            if(rootx == rooty){
                return;
            }
            if(size[rootx] <= size[rooty]){
                parent[rootx] = rooty;
                size[rooty] += size[rootx];
            }else{
                parent[rooty] = rootx;
                size[rootx] += size[rooty];
            }
            count--;
        }
        int getCount(){
            return count;
        }
    };
    struct{
        bool operator()(const vector<int>& v1, const vector<int>& v2){
            return v1[0]<v2[0];
        }
    } sort_on_time;
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf = UnionFind(n);
        sort(logs.begin(), logs.end(), sort_on_time);
        for(vector<int>& log:logs){
            uf.union_operation(log[1],log[2]);
            if(uf.getCount()==1){
                return log[0];
            }
        }
        return -1;
    }
};