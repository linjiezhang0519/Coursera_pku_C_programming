#include<iostream>
using namespace std;

// 输入

// 输入的第一行上有两个整数，依次为row和col。

// 余下有row行，每行包含col个整数，构成一个二维整数数组。

// （注：输入的row和col保证0 < row < 100, 0 < col < 100）

int main(){
    int row,col;
    cin>>row>>col;
    int a[100][100]={0};
    //输入
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>a[i][j];
        }
    }
    //对角线上方元素(列对角线)
    for (int i = 0; i < col; i++){
		for (int j = 0, k = i; j < row && k >= 0; j++, k--){
			cout << a[j][k] << endl;
		}
	}
    
    //对角线下方元素
    for(int i=1;i<row;i++){
        for(int j=i,k=col-1;j<row && k>=0;j++,k--){
            cout<<a[j][k]<<endl;
        }
    }
    return 0;
}

    
