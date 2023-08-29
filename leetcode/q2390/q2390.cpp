#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string re="";
        stack<char>vol;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                vol.pop();
            }
            else{
                vol.push(s[i]);
            }
        }
        for(int i=0;i<vol.size();i++){
            re.push_back('\0');
        }
        for(int i=vol.size()-1;i>=0;i--){
            re[i]=vol.top();
            vol.pop();
        }
        return re;
    }
};
int main(){
    string s;
    cout<<"enter the string:"<<endl;
    cin>>s;
    cout<<Solution().removeStars(s);
}