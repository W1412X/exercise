#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int presum=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int p=-1;
        for(int i=0;i<nums.size();i++){
            if(sum-presum-nums[i]==presum){
                p=i;
                return p;
            }
            presum+=nums[i];
        }
        return -1;
    }
};
int main(){
    int n;
    cout<<"enter the sum of the array:"<<endl;
    cin>>n;
    int g;
    vector<int>nums;
    cout<<"enter the element of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>g;
        nums.push_back(g);
    }
    cout<<Solution().pivotIndex(nums);
}