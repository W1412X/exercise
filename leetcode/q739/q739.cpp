#include<iostream>
#include<vector>
using namespace std;
struct deal{
    int val;
    int p;
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        for(int i=0;i<temperatures.size();i++){
            ans.push_back(0);
        }
        vector<struct deal>stack;
        for(int i=0;i<temperatures.size();i++){
            if(stack.size()==0){
                stack.push_back({temperatures[i],i});
                continue;
            }
            if(stack.size()>=1&&stack[stack.size()-1].val<temperatures[i]){//if the next bigger than the last one in the stack,then judge by while;
                while(stack.size()!=0&&stack[stack.size()-1].val<temperatures[i]){
                    ans[stack[stack.size()-1].p]=i-stack[stack.size()-1].p;//to record the anwser
                    stack.pop_back();//to delete the last element of stack
                }
                stack.push_back({temperatures[i],i});
            }
            else if(stack.size()!=0&&stack[stack.size()-1].val>=temperatures[i]){
                stack.push_back({temperatures[i],i});
            }
        }
        return ans;
    };
};
int main(){
    cout<<"cin the sum of the array"<<endl;
    int n;
    cin>>n;
    cout<<"cin the element of the array"<<endl;
    int g;
    vector<int>array;
    for(int i=0;i<n;i++){
        cin>>g;
        array.push_back(g);
    }
    vector<int>re=Solution().dailyTemperatures(array);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<' ';
    }
}