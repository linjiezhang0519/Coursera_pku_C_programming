// 描述
// 当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，
// 事情就会变得非常简单。 

// 假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。

// 输入
// 第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。

// 接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。

// 输出
// 输出从起点到出口最少需要走的步数。(你不能起出迷宫外)

#include<iostream>
using namespace std;

void searchT(char *position);

int main(){
    int n,m=0;
    cin>>n>>m;
    char maze[102][102];
    
    //输入
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            cin>>maze[i][j];
        }  
    }
    // 在最外围添加一圈
    for (int i = 0; i < 102; i++){
        maze[0][i]='#';
        maze[n+1][i]='#';
        maze[i][0]='#';
        maze[i][m+1]='#';
    }

    // 复制一份地图
    char maze_copy[102][102];
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            maze_copy[i][j]=maze[i][j];
        }  
    }

    //找到初始入口
    int start_x,start_y=0;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(maze[i][j]=='S'){
                maze[i][j]='@';
            } 
        }  
    }
    bool flag = true;
    int step_count =0; 

    while (flag){
        bool step_out = false;
        //根据maze状态在maze_copy做标记
        for (int i = 1; (i < n+1); i++){
            for (int j = 1; (j < m+1); j++){
                if(maze[i][j]=='@'){
                    char *p = *(maze_copy+i)+j;
                    searchT(p+1);
                    searchT(p-1);
                    searchT(p-102);
                    searchT(p+102);
                }
            }
        }
        for (int i = 1; (i < n+1)&flag; i++){
            for (int j = 1; (j < m+1)&flag; j++){
                if(maze_copy[i][j]=='*'){
                    maze[i][j]='@';
                    step_out = true;
                }else if (maze_copy[i][j]=='$')
                {
                    flag = false;
                    step_out = true;
                }
                
            }
        }
        if(step_out){
            step_count++;
        }
        //将maze的状态更新给maze_copy
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                maze_copy[i][j]=maze[i][j];
            }
        }

    }
    
    cout<<step_count<<endl;
    return 0;

}

void searchT(char *position){
    if(*position=='.'){
        *position='*';
    }else if (*position=='T')
    {
        *position='$';
    }
    
}


