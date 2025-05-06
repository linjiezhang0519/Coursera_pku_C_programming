// 两个整数 a 和 b 运算后得到结果 c。表示为：a ? b = c，其中，？可能是加法 +，减法 -，乘法 *，整除 / 或 取余 %。请根据输入的 a,b,c 的值，确定运算符。如果某种运算成立，则输出相应的运算符，如果任何运算都不成立，则输出 error. 

// 例如： 

// 输入： 

// 3,4,5 

// 输出： 

// error 

// 若输入： 

// 3,4,3 

// 则输出： 

// %

#include<iostream>
using namespace std;

int main(){
    int a, b, c = 0;
    char comma;
    cin>>a>>comma>>b>>comma>>c;

    if(a+b==c){
        cout<<'+'<<endl;
    }else if (a-b==c)
    {
        cout<<'-'<<endl;
    }else if (a*b==c)
    {
        cout<<'*'<<endl;
    }else if (a/b==c)
    {
        cout<<'/'<<endl;
    }else if (a%b==c)
    {
        cout<<'%'<<endl;
    }else cout<<"error"<<endl;
    
    return 0;
    
    
}