#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}//you should be aware of the order of a and b;
//the second parameter should be judged whether its zero(here is 'b')
int main(){
	cout<<"the greatest common divisor"<<endl;
	cout<<"enter two numbers:";
	int a,b;
	cin>>a;cin>>b;
	cout<<gcd(a,b);
}
