#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int sum=0;
	for(int i=0;i<flowerbed.size()-1;i++){
		if(flowerbed[i]==0){
			if(i==0&&i+1<flowerbed.size()){
				if(flowerbed[i]==0){
					flowerbed[i]=1;
					sum++;
				}
			}
			else if(flowerbed[i-1]==0&&flowerbed[i+1]==0){
				sum++;
				flowerbed[i]=1;
			}
		}
	}
	if(flowerbed[flowerbed.size()]==0&&flowerbed.size()-1>=0&&flowerbed[flowerbed.size()-1]==0){
		sum++;
	}
	return sum>=n;
    }
};
int main(){
	vector<int>flowerbed;
	int num;
	int n;
	cout<<"cin the num:"<<endl;
	cin>>num;
	cout<<"cin the array:"<<endl;
	int g;
	for(int i=0;i<num;i++){
		cin>>g;
		flowerbed.push_back(g);
	}
	cout<<"cin the other flowers:"<<endl;
	cin>>n;
	if(Solution().canPlaceFlowers(flowerbed,n)){
		cout<<"ture"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}	
}
