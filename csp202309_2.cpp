#include <bits/stdc++.h>

using namespace std;
    int n,m;
  vector<double>sumop1(100005,1);
    vector<double>sumop2(100005);
int main(){

    cin>>n>>m;

 
    for(int i=1;i<=n;i++){
        int type;
        double ope;

        cin>>type>>ope;
        if(type == 1){
            sumop1[i] = sumop1[i-1] * ope;
            sumop2[i] = sumop2[i-1];
        }
        else{
            sumop1[i] = sumop1[i-1];
            sumop2[i] = sumop2[i-1] + ope;
        }
    }
    for(int i=0;i<m;i++){
        int start,end;
        double x,y;
        cin>>start>>end>>x>>y;
        double time = sumop1[end]/sumop1[start-1];
        double theta = sumop2[end]-sumop2[start-1];
        cout<<fixed<<setprecision(3)<<(x*cos(theta)-y*sin(theta))*time<<" "<<(x*sin(theta)+y*cos(theta))*time<<endl;
    }
    return 0;
}


