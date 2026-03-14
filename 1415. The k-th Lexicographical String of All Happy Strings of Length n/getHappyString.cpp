class Solution {
private:
    int count=0;
    string result="";
    void dfs(int n, int k, string current){
        if(result!="") return;
        if(current.length()==n){
            count++;
            if(count==k){
                result=current;
            }
            return;
        }
        for(char c:{'a','b','c'}){
            if(current.empty()||current.back()!=c){
                dfs(n,k,current+c);
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        dfs(n,k,"");
        return result;
    }
};