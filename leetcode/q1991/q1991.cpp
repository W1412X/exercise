#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int findMiddleIndex(vector<int>& nums){
		int sum=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
		}
		if(nums.size()==1){
			return 0;
		}
		if(sum-nums[0]==0){
			return 0;
		}
		int new_sum=0;//its the new sum of the changable arrray
		for(int i=0;i<nums.size()-1;i++){
			new_sum+=nums[i];
			if(new_sum==sum-nums[i+1]-new_sum){
				return i+1;
			}
		}
		if(sum-nums[nums.size()-1]==0){
			return nums.size()-1;
		}
		return -1;
	}
};
int main(){
	int n;
	cout<<"enter the sum of the array:";
	cin>>n;
	vector<int>nums;
	int g;
	for(int i=0;i<n;i++){
		cin>>g;
		nums.push_back(g);	
	}
	Solution s;
	cout<<s.findMiddleIndex(nums);
}
