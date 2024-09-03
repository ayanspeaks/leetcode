class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x<=y)
            return y-x;
        queue<pair<int,int>>q;
        q.push({x,0});
        map<int,int>m;
        m[x]=1;
        while(!q.empty()) {
            queue<pair<int,int>>t;
            while(!q.empty()) {
                pair<int,int>p=q.front();
                q.pop();
                int a=p.first,b=p.second;
                if(a==y)
                    return b;
                if(m[a-1]==0) {
                    t.push({a-1,b+1});
                    m[a-1]=1;
                } 
                if(m[a+1]==0) {
                    t.push({a+1,b+1});
                    m[a+1]=1;
                }
                if(a%5==0 && m[a/5]==0) {
                    t.push({a/5,b+1});
                    m[a/5]=1;
                }
                if(a%11==0 && m[a/11]==0) {
                    t.push({a/11,b+1});
                    m[a/11]=1;
                }
            }
            q=t;
        }
        return -1;

    }
};