/*************************************************************************
        > File Name: csp202309_2.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月18日 星期六 10时24分20秒
 ************************************************************************/
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

typedef struct Node{
    int type;
    double ope;
}Node;

typedef struct Point{
    int start;
    int end;
    double x;
    double y;
}Point;


int main(){
    int n,m;
    //输入m,n
    cin>>n>>m;
    vector<Node> operat(n);
    vector<Point> points(m);
    for(int i=0;i<n;i++){
        scanf("%d %lf",&operat[i].type,&operat[i].ope);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %lf %lf",&points[i].start,&points[i].end,&points[i].x,&points[i].y);
    }
    for(int i=0;i<m;i++){
        for(int j=points[i].start-1;j<=points[i].end-1;j++){
            int type = operat[j].type;
            double ope = operat[j].ope;
            if(type == 1){
                points[i].x = ope * points[i].x;
                points[i].y = ope * points[i].y;
            }
            else if(type == 2){
                double x = points[i].x;
                double y = points[i].y;
                points[i].x = cos(ope) * x - sin(ope) * y;
                points[i].y = sin(ope) * x + cos(ope) * y;
            }
        }
    }
    for(int i=0;i<m;i++){
        printf("%f %f\n",points[i].x,points[i].y);
    }
}

