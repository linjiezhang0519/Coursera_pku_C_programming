// 已知一个整数数组x[],其中的元素彼此都不相同。找出给定的数组中是否有一个元素满足x[i]=i的关系，数组下标从0开始。

// 举例而言，如果x[]={-2,-1,7,3,0,8},则x[3] = 3,因此3就是答案。
#include<iostream>
using namespace std;


int main(){
    int num = 0;
    // bool flag = true;
    cin>> num;
    int arr[num];
    for(int i = 0; i<num; i++){
        cin>>arr[i];
    }
    bool flag = true;
    for(int j = 0; j<num; j++){
        if(arr[j] == j){
            cout<< j;
            flag = false;
            break;
        }
    }
    if(flag)   cout<<'N';
    return 0;
}
