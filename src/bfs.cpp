#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
ofstream outfile;
struct state{
    int z[9];
};
int const maxstate=100000;
state st[maxstate],goal;
int dist[maxstate];
int bfs(){
    int front=1,rear=2;
    while(front<rear){
        state& t=st[front];
        if(memcmp(t.z,goal.z,sizeof(t.z)))return front;
        //用t计算每一个需要的参数
        for(){//枚举每一种下一个的状态
        //计算确定下一个状态所需要的参数
        if(){//下一个参数满足条件
            state& s=st[rear];
            //对s赋值
            dist[rear]=dist[front]+1;
            if(try_ins(rear))rear++;
        }
        }
        front++;
    }
}
int main(){
    init_st();
    cout<<dist[bfs()];
}