// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。 

// 例 ab&dcAab&c9defgb 

// 这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为 

// D+d:2 

// (假定在字符串中，次数第2多的字母总存在)

// 输入
// 一个字符串

// 输出
// 大写字母+小写字母:个数

#include<iostream>
using namespace std;

int main(){
    char input[5000];
    cin.getline(input,5000);
    // 转换为大写字母
    int length = 0;
    for(int i=0;input[i]!='\0';i++){
        input[i] = toupper(input[i]);
        length++;
    }
    int position_cout[26][5000] = {0};
    int count_num[26] = {0};

    //字母计数、记录位置
    for(int k = 0;k<length;k++){
        int alpha_int = input[k]+0;
        if(alpha_int<=90 && alpha_int>=65){
            position_cout[alpha_int-65][k]++;
            count_num[alpha_int-65]++;
        }
    }
    
    //记录每个字母首次出现的位置0-5000;
    int position[26]={-1};
    for(int j = 0;j<26;j++){
        int i = 0;
        while (position_cout[j][i]<=0 && i<5000)
        {
            i++;
        }
        position[j] = i; 
    }

    //找出最大的计数,并让其=0
    int max = count_num[0];
    for(int j = 0;j<26;j++){
        if(count_num[j]> max) max = count_num[j];
    }
    for(int j = 0;j<26;j++){
        if(count_num[j]==max) count_num[j]=0;
    }
    
    //找出第二大的数字
    int second = 0;
    for(int j=0;j<26;j++){
        if(count_num[j]>second) second=count_num[j];
    }
    
    //比较位置
    int temp = 5000; //记录出现位置
    int order = 0; //记录字母表位置
    for(int j=0;j<26;j++){
        if(count_num[j]==second && position[j]<temp){
            temp = position[j];
            order = j;
        }
    }

    //输出
    char top = 'A'+order;
    char lower = 'a'+order;
    cout<<top<<'+'<<lower<<':'<<count_num[order]<<endl;

    return 0;
}