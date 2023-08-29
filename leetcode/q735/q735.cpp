#include<iostream>
#include<vector>
using namespace std;
int fbs(int a){
    return a>0?a:-1*a;
}
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int now=asteroids[0];
        vector<int>re;
        re.push_back(now);
        for(int i=1;i<asteroids.size();i++){
            bool is=0;
            bool is2=0;
            while(re.size()>0&&re[re.size()-1]>0&&asteroids[i]<0){
                is =0;
                is2=0;
                if(fbs(asteroids[i])>fbs(re[re.size()-1])){//go left
                    re.erase(re.end()-1,re.end());
                    if(re.size()==0){
                        re.push_back(asteroids[i]);
                        is2=1;
                    }
                    continue;
                }
                else if(fbs(re[(re.size())-1])==fbs(asteroids[i])){//both disappear
                    re.erase(re.end()-1,re.end());
                    is=1;
                    break;
                }
                else{//go right
                    break;
                }
            }
            if(is2){
                continue;
            }
            if(is){
                continue;
            }
            if(re.size()>0&&fbs(re[re.size()-1]+asteroids[i])>=fbs(asteroids[i])&&fbs(re[re.size()-1]+asteroids[i])>=fbs(re[re.size()-1])){
                re.push_back(asteroids[i]);
            }
            else if(re.size()>0&&re[re.size()-1]<0&&asteroids[i]>0){
                re.push_back(asteroids[i]);
            }
            else if(re.size()==0){
                re.push_back(asteroids[i]);
            }
        }
        return re;
    }
};
int main(){
    int n;
    cout<<"cin the sum of the array:"<<endl;
    cin>>n;
    cout<<"cin the element of the array:"<<endl;
    vector<int>asteroids;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        asteroids.push_back(g);
    }
    vector<int>re=Solution().asteroidCollision(asteroids);
    cout<<"the anwser"<<endl;
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<' ';
    }
}