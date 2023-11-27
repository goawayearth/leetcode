#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    double i;
    double ans = 0;
    cin>>n>>i;

    for(int j=0;j<n+1;j++){
        int temp = 0;
        cin>>temp;
        
        ans += temp * pow((1+i),-j);
    }

    cout<<ans<<endl;

    return 0;
}