// 编程题＃3：发票统计
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一个小型的报账系统，它有如下功能：

// （1）统计每个人所报发票的总钱数

// （2）统计每类发票的总钱数

// 将此系统简化为如下：假设发票类别共有A、B、C三种; 一共有三个人，ID分别为1、2、3。

// 输入
// 系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

// 输出
// 输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。

#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    float cal_id[3][2]= {};

    float Asum = 0.0;
    float Bsum = 0.0;
    float Csum = 0.0;

    for(int i = 0; i<3; i++){
        // 一共输入三行
        int id= 0, n = 0;
        float idsum = 0.0;
        cin>> id>>n;
        for(int j = 0; j<n; j++){
            // 对于每一对输入
            char type;
            float amount;
            cin>>type>>amount;
            switch (type)
            {
            case 'A':
                Asum+=amount;
                break;
            case 'B':
                Bsum+=amount;
                break;
            case 'C':
                Csum+=amount;
                break;
            default:
                break;
            }
            idsum += amount;
        }
        cal_id[id-1][0] = id;
        cal_id[id-1][1] = idsum;
    }
    // 输出
    for(int i = 0; i<3;i++){
        cout<<fixed<<setprecision(0)<<cal_id[i][0]<<" "<<fixed<<setprecision(2)<<cal_id[i][1]<<endl;
    }
    cout<<'A'<<" "<<fixed<<setprecision(2)<<Asum<<endl;
    cout<<'B'<<" "<<fixed<<setprecision(2)<<Bsum<<endl;
    cout<<'C'<<" "<<fixed<<setprecision(2)<<Csum<<endl;

    return 0;
}