// 注意： 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。 

// 现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。

// 输入
// 第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a

// 紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。

// 每个病人的疾病严重程度都不一样。

// 输出
// 要求按照病人的严重程度输出住在重症病房里的病人的编号

// 注意：
// 如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）
#include<iostream>
#include<iomanip>
using namespace std;

void rank_patient(float (*arr)[2], int m);

int main(){
    int m=0;
    float a = 0.0;
    cin>>m>>a;
    float patient[50][2]={0};
    for(int i =0;i<m;i++){
        cin>>patient[i][0]>>patient[i][1];
    }
    //排序
    rank_patient(patient, m);
    //输出
    int n = 0;
    for(int i=m-1;i>=0;i--){
        if(patient[i][1]>=a){
            n=n+1;
            cout<< fixed<< setw(3)<< setfill('0')<< setprecision(0)<<patient[i][0]<<' ';
            cout<< fixed << setprecision(1)<<patient[i][1]<<endl;
            // 注意：setprecision 对浮点数默认控制的是“有效位数”，不是小数位数，除非加上 fixed。
        }
    }
    if (n==0)
    {
        cout << "None." << endl;
    }
    
    return 0;
}


void rank_patient(float (*arr)[2], int m){
    for(int i=0;i<m-1;i++){
        for(int j = i+1;j<m;j++){
            if(*(*(arr+i)+1)>*(*(arr+j)+1)){
                float temp_idx, temp_state;
                temp_idx=*(*(arr+j));
                temp_state=*(*(arr+j)+1);
    
                *(*(arr+j)+1)=*(*(arr+i)+1);
                *(*(arr+j))=*(*(arr+i));
    
                *(*(arr+i))=temp_idx;
                *(*(arr+i)+1)=temp_state;
            }
        }
    }
}
