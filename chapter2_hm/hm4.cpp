// 描述
// 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

// 读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

// 输入
// 输入仅一行，格式为yyyy-mm-dd的日期。

// 输出
// 输出也仅一行，格式为yyyy-mm-dd的日期


#include<iostream>
#include<string>
#include <sstream>   
#include <iomanip>   
using namespace std;

bool ifleap(int year){
    // 判断是否是闰年
    bool leap = false;
    if(year%4==0 && year %100!= 0||year%400==0){
        leap = true;
    }
    return leap;
}

int main(){
    int mon_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = false;
    // 输入
    int year = 0;
    int month, day;
    char comma;
    cin>>year>>comma>>month>>comma>>day;
    
    // 日-月-年
    day++;
    leap = ifleap(year);
    if(leap){
        mon_day[1]++; 
    }
    if(day>mon_day[month-1]){
        month++;
        if(month >12){
            month = 1;
            year++;
        }
        day = 1;
    }

//  设置输出格式
    cout<<year<<'-'<<setfill('0')<<setw(2)<<month<<'-'<<setfill('0')<<setw(2)<<day<<endl;

return 0;
}
