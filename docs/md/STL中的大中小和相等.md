# STL中“大”“小”的概念
* 关联容器内部的元素是从小到大排序的
* 有些算法要求其操作的区间是从小到大排序的，称为“有序区间算法”
* 有些算法会对区间进行从小到大排序，称为“排序算法”
* 还有一些其它算法会使用到“大”“小”的概念
![Alt text](image-44.png)    
# STL中“相等”的概念
* 有时，“x和y相等”等价于“x==y为真”
* 有时“x和y相等”等价于“x小于y和y小于x同时为假”
```c++
class A
{
        int v;
    public:
        A(int n):v(n){}
        bool operator<(const A& a2)const
        {
            cout<<v<<"<"<<a2.v<<"?"<<endl;
            return false;
        }
        bool operator ==(const A& a2)const
        {
            cout<<v<<"=="<<a2.v<<"?"<<endl;
            return v==a2.v;
        }
};
int main()
{
    A a[]={A(1),A(2),A(3),A(4),A(5)};
    cout<<binary_search(,a+4,A(9)); 
    return 0;
}
/*
输出结果：
3<9?
2<9?
1<9?
9<1?
1
*/
```    
