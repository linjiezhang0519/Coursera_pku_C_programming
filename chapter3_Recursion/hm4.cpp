// 编程题＃4：扩号匹配问题
// 来源: POJ 
// (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。

// 写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

// 输入
// 输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100

// 注意：cin.getline(str,100)最多只能输入99个字符！

// 输出
// 对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
#include<iostream>
using namespace std;
#include <cstring>
int  match(char str[], int idx, bool match_mark[]);

int main(){
    char str[101];
    while (cin.getline(str,101))
    {
        bool match_mark[101] = {0};
        //进行匹配
        int n = match(str, 0, match_mark);
        while (n != -1)
        {
            n = match(str, n+1, match_mark);
        }
        
        cout<<str<<endl;
        for(int i = 0; str[i] != '\0';i++){
            char out = ' ';
            if(!match_mark[i]){
                switch (str[i])
                {
                case '(':
                    out = '$';
                    break;
                case ')':
                    out = '?';
                    break;
                }
            }
            cout<<out;
            }   
        cout<<endl;
    }
    return 0;
    
}

int  match(char str[], int idx, bool *match_mark){
    if(str[idx]=='\0'){
        return -1;
    }else{
        if(str[idx]=='('){
            //这里的n代表与之匹配的右括号的序号（如果有的话，如果没有，会一直遍历到str[idx] = '\0'为止。
            int n = match(str, idx+1, match_mark);
            if(str[n]==')'){
                match_mark[idx] = true;
                match_mark[n] = true;
                return match(str, n+1, match_mark);
                //如果这一层匹配成功了，要返回match(str, n+1, match_mark)让程序回到上一层的匹配任务上，当然，上一层可能存在的)号在n后面。
            }else{
                return n;
                //如果这一层没匹配成功（str[n]不是)符号），那么返回最后的n值。
            }
        }else if(str[idx] ==')'){
            return idx;
        }else{
            //如果没有遇到()符号，就向前移动一个字符
            return match(str, idx+1, match_mark);
        }
    }
}


