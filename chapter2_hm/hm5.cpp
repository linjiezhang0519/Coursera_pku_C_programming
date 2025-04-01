#include<iostream>
using namespace std;

int main(){
    int num = 0;
    cin>>num;
    int id_array[100]={};
    float v_array[100]={};
    for (int i =0; i<num; i++){
        int id = 0;
        float start_num = 0, end_num = 0;
        cin>>id>>start_num>>end_num;
        id_array[i] = id;
        v_array[i] = end_num/start_num;
    }
    
    // 由小到大排序
    for(int j = 0; j<num; j++){
        for(int i = j; i<num; i++){
            if(v_array[j]>v_array[i]){
                float p = v_array[j];
                v_array[j] = v_array[i];
                v_array[i] = p;

                // id也需要照样排序
                int id_p = id_array[j];
                id_array[j] = id_array[i];
                id_array[i] = id_p;
            }
        }
    }

    // 确定阈值，相邻两个数相减
    float diff[100]= {};
    for(int i = 0; i<num-1;i++){
        diff[i] = v_array[i+1]-v_array[i];
    }

    // 找出diff最大值，其序号+1就是第一个A的idx
    float max_diff = diff[0];
    int max_idx = 0; 
    for(int i = 1; i<num-1; i++){
        if(diff[i]>max_diff){
            max_diff = diff[i];
            max_idx = i;
        }
    }

    int numA = num-(max_idx+1);
    int numB = max_idx+1;

    // 输出
    cout<<numA<<endl;
    for(int i = max_idx+1; i<num;i++){
        cout<<id_array[i]<<endl;
    }
    cout<<numB<<endl;
    for(int i = 0; i<max_idx+1; i++){
        cout<<id_array[i]<<endl;
    }
    return 0;
}