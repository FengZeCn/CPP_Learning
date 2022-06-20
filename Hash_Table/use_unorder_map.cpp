/*
 * @Author: your name
 * @Date: 2022-06-20 10:26:59
 * @LastEditTime: 2022-06-20 11:00:13
 * @LastEditors: LegionR9000P
 * @Description: In User Settings Edit
 * @FilePath: \CPP_Learning\Hash_Table\use_unorder_map.cpp
 */
#include <iostream>
#include <unordered_map>
using namespace std;
class Usemap
{
    public:
        Usemap(unordered_map<int,int>& Mymap)
            :Umap(Mymap)
            {}
        void map_printf();
    private:
        unordered_map<int,int> Umap;
};
void Usemap::map_printf()
{
    int i = 0;
    for(auto Iter=Umap.begin();Iter!= Umap.end(); ++Iter)
    {   
        cout<<"i="<<i<<"  ";     
        cout<<"键"<<Iter->first;
        cout<<"值"<<Iter->second;
        cout<<endl;
        i++;
    }
};

int main(){
    unordered_map<int,int> Myhashmap;
    for(int i = 0;i<100;i++)
    {
        Myhashmap.emplace(i,100-i);
    }
    cout<<"Myhashmap size:"<<Myhashmap.size();
    Usemap Myusemap(Myhashmap);
    Myusemap.map_printf();
    return 0;
    


}
