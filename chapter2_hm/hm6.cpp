// 编程题＃6：流感传染
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

// 输入
// 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

// 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

// 接下来的一行是一个整数m，m不超过100.

// 输出
// 输出第m天，得流感的人数
#include<iostream>
using namespace std;

int mar(int idx,int row){
    if(idx>row){
        idx = row;
    }else if (idx<0)
    {
        idx = 0;
    }
    return idx;
}


int main(){
    int row = 0;
    int day = 0;
    cin>>row;
    int room[100][100] = {};
    int preday[100][100] ={};

    for(int i = 0;i<row;i++){
        for(int j = 0; j<row; j++){
            char person;
            cin>> person;
            if(person=='.'){
                room[i][j] = 1;
            }else if (person=='#')
            {
                room[i][j] = 0;
            }else if (person=='@')
            {
                room[i][j] = 8;
            }
            preday[i][j] = room[i][j];
        }
    }
    cin>>day;
    

    // 开始传染过程
    for(int d = 1;d<day;d++){
        for(int i = 0; i< row; i++){
            for(int j=0;j<row;j++){
                int value = 0;
                // 注意数组越界问题，如果数组越界，如value+=preday[row+1][row],那么value会变成一个非常大的数（int精度上界）
                if (preday[i][j]==1){
                    if(i>0) value+=preday[i-1][j];
                    if(i<row-1) value+=preday[i+1][j];
                    if(j>0) value+=preday[i][j-1];
                    if(j<row-1) value += preday[i][j+1];

                    if(value>7) room[i][j]=8;
                }
            }
        }

        // 更新昨日状态，在接下来的循环中根据昨日状态判定传染
        for(int i = 0; i<row;i++){
            for (int j = 0; j < row;j++){
            preday[i][j] = room[i][j];
        }     
    }
        
    }

    int total = 0;
    for(int i = 0; i<row;i++){
        for(int j = 0; j<row;j++){
            if(room[i][j]==8){
                total++;
            }
        }
    }
    cout<<total<<endl;
return 0;
}
