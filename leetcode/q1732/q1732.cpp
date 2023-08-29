#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int dif=0;
        int max=0;
        for(int i=0;i<gain.size();i++){
            dif+=gain[i];
            if(dif>=max){
                max=dif;
            }
            else{
                max=max;
            }
        }
        return max;
    }
};
int main(){
    cout<<"enter the numbers of array 'gain'"<<endl;
    int n;
    cin>>n;
    cout<<"enter the array"<<endl;
    vector<int>gain;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        gain.push_back(g);
    }
    cout<<Solution().largestAltitude(gain);
}