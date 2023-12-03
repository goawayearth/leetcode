/*************************************************************************
        > File Name: ccf201903_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月03日 星期日 09时23分25秒
 ************************************************************************/
/* CCF201903-1 小中大 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n;
    int max,min;
    double mid;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    max = nums[0]>=nums[n-1]?nums[0]:nums[n-1];
    min = nums[0]<=nums[n-1]?nums[0]:nums[n-1];

    if(n%2==0){
        int tem = nums[n/2]+nums[n/2-1];
        if(tem%2==0){
            mid =((double) tem)/2;
            cout<<max<<" "<<mid<<" "<<min<<endl;
        }
        else{
             mid =( (double)tem)/2;
            mid = round(mid*10)/10;
           // printf("%d %.1lf %d",max,mid,min);
           cout<<max<<" "<<fixed<<setprecision(1)<<mid<<" "<<min<<endl;
        }
    }
    else{
        mid = nums[n/2];
        cout<<max<<" "<<mid<<" "<<min<<endl;

    }

}
    
