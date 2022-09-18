#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<cstring>
#include <sstream>
#include<queue>
#include<vector>
#include<map>
#include<fstream>
#include<unordered_map>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;
set<int>st;
unordered_map<int,int>mp;//使用的时候记得开long long
struct hp{    
    void init(){
        mp.clear();st.clear();
    }
    void ins(int k){
        mp[k]++;
        st.insert(k);
    }
    bool del(int d){
        if(mp[d]==0)return false;
        mp[d]--;
        if(mp[d]==0)st.erase(d);
        return true;
    }
}heap;