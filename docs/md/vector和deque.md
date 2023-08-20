# vector示例
```c++
template<class T>
void PrintVector(T s,T e)
{
    for(;s!=e;++s)
        cout<<*s<<" ";
    cout<<endl;
}
int main()
{
    int a[5]={1,2,3,4,5};
    vector<int> v(a,a+5);    //将数组a的内容放入v
    cout<<"1) "<<v.end()-v.begin()<<endl;    //两个随机迭代器相减，输出：“1) 5”
    cout<<"2) ";
    PrintVector(v.begin(),v.end());    //“2) 1 2 3 4 5 ”
    v.insert(v.begin()+2,13);    //在begin()+2位置插入13
    cout<<"3) ";
    PrintVector(v.begin(),v.end());    //“1 2 13 3 4 5 ”
    v.erease(v.begin()+2);    //在begin()+2位置删除
    cout<<"4) ";
    PrintVector(v.begin(),v.end());    //“1 2 3 4 5 ”
    vector<int> v2(4,100);    //有4个元素，都是100
    v2.insert(v2.begin(),v.begin()+1,v.begin()+3);    //将v的一段插入v2开头
    cout<<"5) v2: ";
    PrintVector(v2.begin(),v2.end());    //“v2: 2 3 100 100 100 100”
    v.erase(v.begin()+1,v.begin()+3);    //删除v上的一个区间
    cout<<"6) ";
    PrintVector(v.begin(),v.end());    //“1 4 5 ”
}
```    
# 用vector实现二维数组
```c++
int main()
{
    vector<vector<int>> v(3);    //v有3个元素，每个元素都是vector<int>容器
    for(int i=0;i<v.size();++i)
        for(int j=0;j<4;++j)
            v[i].push_back(j);
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v[i].size();++j)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
输出结果：
0 1 2 3 
0 1 2 3 
0 1 2 3 
*/
```    
# deque
* 所有适用于vector的操作都适用于deque
* deque还有push_front（将元素插入到前面）和pop_front（删除最前面的元素）操作，复杂度是O(1)
