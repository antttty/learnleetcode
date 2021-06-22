#include <string>
#include <vector>
#include <set>

using namespace std;

    set<string> strset;
    void dfs(int index, string &s, vector<string> &ret){
        if (index == s.length()){
            if (strset.find(s) != strset.end())
                return;
            strset.insert(s);
            ret.push_back(s);
            return ;
        }

        for (int i = index; i < s.length(); i++){
                swap(s[i], s[index]);
                dfs(index+1, s, ret);
                swap(s[i], s[index]);
        }
    }
    vector<string> permutation(string s) {
        vector<string>  ret;
        dfs(0, s, ret);
        return ret;
    }

    int main(){
        string  s="aab";
        vector<string> ret = permutation(s);
        return 0;
    }