#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
      string re="";
      string stack="";
      vector<int>num;//to record the repeats
      for(int i=0;i<s.size();i++){
        int sum=0;
        while(s[i]>=48&&s[i]<=57){//to get the repeat
            sum=10*sum+s[i]-48;
            i++;
        }
        if((s[i]>=97&&s[i]<=122)||s[i]=='['){
            stack.push_back(s[i]);
        }
        if(sum!=0){//to add the number to the array
            num.push_back(sum);
        }
        if(s[i]==']'){//to deal with the []
            string g;
            while(stack[stack.size()-1]!='['){//to get the string in [],save in g
                g+=stack[stack.size()-1];//
                stack.erase(stack.end()-1,stack.end());
            }
            reverse(g.begin(),g.end());
            stack.erase(stack.end()-1,stack.end());//to delete the '['
            int repeat=num[num.size()-1];
            num.erase(num.end()-1,num.end());
            while(repeat!=0){//add g into the stack
                stack+=g;
                repeat--;
            }
        }
      }
      return stack;
    }  
};
int main(){
    cout<<"please enter the string:";
    string s;
    cin>>s;
    cout<<Solution().decodeString(s);
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='l'){
            sum++;
        }
    }
    cout<<sum<<endl;
}
