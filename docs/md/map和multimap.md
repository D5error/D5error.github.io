# multimap
```c++
template<class Key,class T,class Pred=less<Key>,class A=allocator<T>>
class multimap
{
    ......
    typedef pair<const Key,T> value_type;
    ......
};    //Key代表关键字的类型
```    
* multimap中的元素由<关键字,值>组成，每个元素是一个pair对象，关键字就是first成员变量，其类型是Key
* multimap中允许多个元素的关键字相同。元素按照first成员变量从小到大排列，缺省情况下用less<Key>定义关键字的“小于”关系
# map
```c++
template<class Key,class T,class Pred=less<Key>,class A=allocator<T>>
class map
{
    ......
    typedef pair<const Key,T> value_type;
    ......
};
```    
* map中的元素都是pair模板类的对象。关键字（first成员变量）各不相同。元素按照关键字从小到大排列，缺省情况下用less<Key>，即“<”定义“小于”
# map的[]成员函数
* 若pairs为map模板类的对象`pairs[Key]`，返回对关键字等于Key的元素的值（second成员变量）的引用。若没有关键字为Key的元素，则会往pairs里插入一个关键字为Key的元素，其值用无参构造函数初始化，并返回其值的引用
