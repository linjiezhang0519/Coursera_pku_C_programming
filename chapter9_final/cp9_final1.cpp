// 描述
// 输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。 

// 例如，输入： 

// 43833 3 

// 满足条件，输出YES 

// 如果输入 

// 39331 3 

// 尽管有3个3，但不能被19整除，也不满足条件，应输出NO

// 输入
// m 和 k 的值，空格间隔

// 输出
// 满足条件时输出 YES，不满足时输出 NO
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int m,k;
    cin>>m>>k;
    bool division = false;
    int count_three = 0;
    division = (m%19 ==0);
    
    int m_arr[5]={0};
    int count = 0;
    while (m>0)
    {
        m_arr[count]= m%10;
        m = m/10;
        count++;
    }

    for(int i = 0;i<5;i++){
        if(m_arr[i]==3){
            count_three++;
        }
    }
    if(count_three==k&&(division)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;

    return 0;

}
