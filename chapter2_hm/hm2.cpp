// ; 描述
// ; 我国有4大淡水湖。

// ; A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。

// ; B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。

// ; C说：洪泽湖最小，洞庭湖第三。

// ; D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。


// ; 已知这4个湖的大小均不相等，4个人每人仅答对一个，

// ; 请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。

#include<iostream>
using namespace std;

int check(int gus[],int answer[]){
    int count = 0;
    for(int i = 0; i<4; i++){
        if(gus[i]== answer[i]){
            count++;
        }
    }
    return count;
}

bool check_diff(int a, int b, int c, int d){
    int arr[4] = {a, b, c, d};
    bool all_diff=false;
    int same = 0;
    for(int i = 0;i<3;i++){
        for(int j = i+1;j<4;j++){
            if(arr[i] == arr[j]) same++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if(arr[i] == 0) same++;
    }
    if (same == 0)   all_diff = true;
    return all_diff;
}



int main(){
    int gusA[4] = {3,1,0,4};
    int gusB[4] = {2,4,3,1};
    int gusC[4] = {0,3,0,4};
    int gusD[4] = {1,3,4,2};
    int countA = 0;
    int countB = 0;
    int countC= 0;
    int countD = 0;

    for(int i = 0; i<4; i++){
        for(int j = 0; j <4; j++){
            for(int k = 0; k<4; k++){
                for(int t = 0; t<4; t++){
                    // 生成所有可能的答案组合
                    int answer[4] = {gusA[i],gusB[j],gusC[k],gusD[t]};
                    countA = check(gusA, answer);
                    countB = check(gusB, answer);
                    countC = check(gusC, answer);
                    countD = check(gusD, answer);
                    
                    bool count_all = countA == 1 && countB==1 && countC ==1 && countD==1; 
                    bool diff = check_diff(gusA[i],gusB[j],gusC[k],gusD[t]);
                    if(count_all && diff){
                        for(int m = 0;m<4; m++){
                            cout<<answer[m]<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
   
    
