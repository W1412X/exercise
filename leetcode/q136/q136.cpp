#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int re=0;
        for(int i=0;i<nums.size();i++){
            re=nums[i]^re;
        }
        return re;
    }
};
int main(){
    cout<<"cin the sum of the array:"<<endl;
    int n;
    cin>>n;
    cout<<"cin the elements of the array:";
    int g;
    vector<int>array;
    for(int i=0;i<n;i++){
        cin>>g;
        array.push_back(g);
    }
    cout<<Solution().singleNumber(array);
}