#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>bits(n+1);
        int highbit=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){//if i is aa power of 2
                highbit=i;
            }
            bits[i]=bits[i-highbit]+1;
        }
        return bits;
    }
};
int main(){
    cout<<"cin a number"<<endl;
    int n;
    cin>>n;
    vector<int>re=Solution().countBits(n);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<' ';
    }
}