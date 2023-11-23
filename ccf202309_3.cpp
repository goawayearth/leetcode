/*************************************************************************
        > File Name: ccf202309_3.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月19日 星期日 12时54分16秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

// 多项式每一项的结构体
struct item{
    ll coefficient;//系数
    map<int,int>mp;//乘积的每一项
    item(ll coe ,map<int,int>mp):coefficient(coe),mp(mp) {}
};

struct formula{
    vector<item> vec;//所有的乘积项都用+号连接
    formula(vector<item>vec):vec(vec) {}
};//多项式结构体

ll convert(string str){//将字符串转化成数字
    ll num = 0;
    for(int i=(str[0]=='-')?1:0;i<str.length();i++){
        num*=10;
        num+=str[i]-'0';
    }
    return (str[0]=='-') ? -1*num:num;
}
 item item_mul(item A,item B){
     ll coefficient_c=A.coefficient * B.coefficient;
     map<int,int>mp_c;
     map<int,int>::iterator it;
     for(it = A.mp.begin();it!=A.mp.end();it++){
         mp_c[it->first] = A.mp[it->first]+B.mp[it->first];
         B.mp.erase(it->first);
     }
     for(it=B.mp.begin();it!=B.mp.end();it++){
         mp_c[it->first] = B.mp[it->first];
     }
     return item(coefficient_c,mp_c);
 }

formula formula_mul(formula A,formula B){
    vector<item>vec;
    for(int i=0;i<A.vec.size();i++){
        for(int j=0;j<B.vec.size();j++){
            vec.push_back(item_mul(A.vec[i],B.vec[j]));
        }
    }
    return formula(vec);
}

//多项式加法
formula formula_add(formula A,formula B){
    for(int i=0;i<B.vec.size();i++){
        A.vec.push_back(B.vec[i]);
    }
    return A;
}

//多项式减法
formula formula_sub(formula A, formula B){
    for(int i=0;i<A.vec.size();i++){
        A.vec[i].coefficient*=-1;
    }
    return formula_add(B,A);
}

//求导数
ll function(formula A,int goal){
    ll sum = 0,mul;
    for(int i=0;i<A.vec.size();i++){
        item now=A.vec[i];
        mul = 1;
        if(now.mp.find(goal) != now.mp.end()){
            //含有未知数采取求道，不然没有价值
            mul=(now.coefficient * now.mp[goal]) % mod;
            now.mp[goal]--;
            for(map<int,int>::iterator it = now.mp.begin();it!=now.mp.end();it++){
                for(int k=0;k<it->second;k++){
                    mul=(mul*val[it->first]) % mod;
                }
            }
            sum = (sum + mul) % mod;
        }
    }
    return sum;
}

int main(){
    int n,m;
    cin>>n>>m;
    getchar();
    string str,temp;
    getline(cin,str);
    while(sin>>temp){
        if(temp=="+" || temp=="-" || temp=="*"){//运算符
			formula A=st.top(); st.pop();//从栈中依次弹出两个formula
			formula B=st.top(); st.pop();
			if(temp=="*"){
				st.push(formula_mul(B,A));
			}else if(temp=="+"){
				st.push(formula_add(B,A));
			}else{
				st.push(formula_sub(A,B));//A B的顺序很重要
			}
		}else{
			map<int,int>mp;//下标 指数
			vector<item>vec;
			if(temp[0]=='x'){//自变量
				mp[convert(temp.substr(1,temp.length()-1))]=1;
				vec.push_back(item(1,mp));//把乘积项包装成多项式
			}else{//常数
				vec.push_back(item(convert(temp),mp));//把乘积项包装成多项式
			}
			st.push(formula(vec));
		}
	}
	for(int i=0;i<m;i++){
		ll value;
		for(int j=0;j<n+1;j++){
			cin>>value;
			val.push_back(value);
		}
		ll ans=function(st.top(),val[0]);
		cout<<((ans<0)?ans+mod:ans)<<endl;//当计算整数n对M的模时，若n为负数,需要注意将结果调整至区间[0,M)内
		val.clear();
	}

	return 0;
}
