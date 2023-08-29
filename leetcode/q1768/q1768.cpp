#include<iostream>
using namespace std;
class Solution{
public:
	string mergeAlternately(string word1,string word2){
		int len1=word1.size();
		int len2=word2.size();
		int i=0;
		string return_string;
		for(i=0;i<(len1<len2?len1:len2);i++){
			return_string+=word1[i];
			return_string+=word2[i];
		}
		bool is=len1<len2;
		for(i;i<(len1<len2?len2:len1);i++){
			if(is){
				return_string+=word2[i];
			}
			else{
				return_string+=word1[i];
			}
		}
		return return_string;
	}
};
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	Solution s;
	cout<<s.mergeAlternately(s1,s2);
	return 0;
}
