#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
class Solution{
	public:
		string gcdOfString(string str1,string str2){
			string s="";
			if(str1+str2!=str2+str1){
				return s;
			}
			else{
			int len=gcd(str1.size(),str2.size());
			for(int i=0;i<len;i++){
				s+=str1[i];
			}
			return s;}
		}
};
int main(){
	string s1,s2;
	cout<<"enter the two strings:";
	cin>>s1;
	cin>>s2;
	Solution s;
	cout<<s.gcdOfString(s1,s2);
}
