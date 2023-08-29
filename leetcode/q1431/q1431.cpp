#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<bool>kidsWithCandies(vector<int>&candies,int extraCandies){
		int max=-14120621;
		vector<bool>result(candies.size());
		for(int i=0;i<candies.size();i++){
			if(candies[i]>max){
				max=candies[i];
			}
		}
		for(int i=0;i<candies.size();i++){
			if(candies[i]==max){
				result[i]=1;
			}
			else if(candies[i]+extraCandies>=max){
				result[i]=1;
			}
			else{
				result[i]=0;
			}
		}
		return result;
	}
};
int main(){
	vector<int>candies;
	cout<<"enter the sum of the candies"<<endl;
	int n;
	cin>>n;
	int g;
	for(int i=0;i<n;i++){
		cin>>g;
		candies.push_back(g);
	}
	cout<<"enter the extracandies' sum"<<endl;
	int extra;
	cin>>extra;
	vector<bool>re=Solution().kidsWithCandies(candies,extra);
	for(int i=0;i<re.size();i++){
		cout<<re[i]?"ture ":"false ";
	}
}
