#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string>a;
        string g="";
        for(int i=0;i<s.size();i++){
            if(s[i]==32&&(i==0||i==s.size()-1)){
                continue;
            }
            else if(s[i]==32){
                if(g==""){
                    continue;
                }
                a.push_back(g);
                g.clear();
            }
            else{
                g+=s[i];
            }
        }
        if(g!=""){
            a.push_back(g);
        }
        string re="";
        for(int i=a.size()-1;i>=1;i--){
            re+=a[i];
            re+=" ";
        }
        re+=a[0];
        return re;
    }
};
int main(){
    string s;
    cout<<"cin the string:"<<endl;
    getline(cin,s);
    cout<<Solution().reverseWords(s);
}