// 编程题＃1：计算矩阵边缘元素之和
// 来源: POJ
//  (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

// 输入
// 第一行为整数k，表示有k组数据。

// 每组数据有多行组成，表示一个矩阵：

// 第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。

// 接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。

// 输出

// 输出对应矩阵的边缘元素和，一个一行。
#include<iostream>
using namespace std;
int func(int row, int col, int *a);

int main(){
    int num = 0;
    cin>>num;
    int out[100] ={0};

    for(int i = 0;i<num;i++){
        int row,col;
        cin>>row>>col;
        int a[row][col];
        //输入矩阵
        for(int j=0;j<row;j++){
            for (int k=0;k<col;k++){
                cin>>a[j][k];
            }
        }
        //得到输出值
        out[i] = func(row,col, a[0]);
    }
    for(int i = 0;i<num;i++){
        cout<<out[i]<<endl;
    }
    return 0;
}

int func(int row, int col, int *a){
    int out = 0;
    //计算第一行
    for(int i=0;i<col;i++){
        out += *(a);
        //*a是一个值
        a=a+1;
    }
    // 计算结束后，a应该移到a[1],也就是第二行的第一个元素;

    if(row>2){
        for(int i=1;i<row-1;i++){
            out += *(a);
            out += *(a+col-1);
            a= a+col;
        }
    }
    // 计算结束后，a应该移到a[row-1]的第一个元素,也就是最后一行。

    //计算最后一行
    if(row>1){
        for(int i=0;i<col;i++){
            out += *(a);
            a++;
        }
    }
    return out;
}