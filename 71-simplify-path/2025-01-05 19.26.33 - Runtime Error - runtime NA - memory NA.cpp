class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ds;
        int i=0;
        while(i<path.size()){
            while(path[i]=='/'){
                i++;
            }

            string current;
            while(path[i]!='/' && path[i]!='\0'){
                current.push_back(path[i]);
                i++;
            }

            ds.push(current);
            if(ds.top()=="." && !ds.empty()) ds.pop();
            if(ds.top()==".."){
                if (!ds.empty()) ds.pop();
                if (!ds.empty()) ds.pop();
            }
        }

        string ans;
        while(!ds.empty()){
            string x=ds.top();
            ans="/"+x+ans;
            ds.pop();
        }
        if(ans.back()=='/') ans.pop_back();
        return ans.empty() ? "/" : ans;
    }
};
