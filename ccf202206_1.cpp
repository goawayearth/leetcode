#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


int main(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    double min = ((double)sum) /((double)n);
    double din=0;
    for(int i=0;i<n;i++){
        double tem = (double)nums[i]-min;
        tem = pow(tem,2);
        din+=tem;
    }
    double D = pow((din / n),0.5);
    for(int i=0;i<n;i++){
        double tem1 = (double)nums[i]-min;
        double tem2 = tem1 / D;
        cout<<tem2<<endl;

    }

    return 0;
}