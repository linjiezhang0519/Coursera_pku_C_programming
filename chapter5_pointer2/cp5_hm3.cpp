// 给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：

// 每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。

#include<iostream>
#include <cstring>
using namespace std;

int main(){
    int num = 0;
    int length=0;
    bool space = false;
    cin>>num;
    char word[num];
    for(int i = 0;i<num;i++){
        cin>>word;
        length+=strlen(word);
        if(length<80){
            space = true;
        }else{
            length = strlen(word);
            cout<<endl;
            space = false;
        }
        if(i==0){
            space = false;      
        }
        //控制空格的输出，为了不让行尾有字符，将空格看成“下一个单词之前的空格"，而不是“这一个单词之后的空格".
        if(space){
            cout<<" ";
            length++;
        }
        cout<<word;  
    }
    return 0;
}