
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;

// 用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。

// 给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。

// 编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。

// 本题规定：n不超过100，并且不考虑点的坐标为负数的情况。

// 输入
// 输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。

// 输出
// 按x轴坐标最小到大的顺序输出所有极大点。

// 输出格式为:(x1,y1),(x2,y2),...(xk,yk)

// 注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
#include<iostream>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    int coordinate[102][2]={0};
    int ordered_coord[102][2]={0};
    for(int i=0;i<n;i++){
        cin>>coordinate[i][0]>>coordinate[i][1];
    }
    //按照x-y排序
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(coordinate[j][0]>coordinate[i][0]){
                int tempx = coordinate[i][0];
                int tempy = coordinate[i][1];

                coordinate[i][0] = coordinate[j][0];
                coordinate[i][1] = coordinate[j][1];
                
                coordinate[j][0] = tempx;
                coordinate[j][1] = tempy;
            }else if (coordinate[j][0]==coordinate[i][0] && coordinate[j][1]>coordinate[i][1])
            {
                int tempx = coordinate[i][0];
                int tempy = coordinate[i][1];

                coordinate[i][0] = coordinate[j][0];
                coordinate[i][1] = coordinate[j][1];
                
                coordinate[j][0] = tempx;
                coordinate[j][1] = tempy;
            }
            
        }
    }
    //比较y
    int outcount = 0;
    for(int i=n-1;i>=0;i--){
        int count = 0;
        for (int j = 0; j<i;j++)
        {
            if(coordinate[i][1]<coordinate[j][1]) count++;
            else if (coordinate[i][1]==coordinate[j][1])
            {
                if(coordinate[i][0]<coordinate[j][0]) count++;
            }
            
        }
        if(count==0){
            outcount++;
            if(outcount==1){
                cout<<'('<<coordinate[i][0]<<','<<coordinate[i][1]<<')';
            }else if (outcount>1)
            {
                cout<<",("<<coordinate[i][0]<<','<<coordinate[i][1]<<')';
            }
        }
    }
    return 0;
}
