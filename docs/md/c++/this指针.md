## 1. this指针
```cpp
//CPP
class C
{
    pubilc:
        int x;
        void func(int a);
};
void C::func(int a)
{
    x=a;
}
int main()
{
    C obj;
    obj.func(1);
    return 0;
}
```

```c
//C
struct C
{
    int x;
};
void func(struct C *this,int a)
{
    this->x=a;
}
int main()
{
    struct C obj;
    func(&obj,1);
    return 0;
}
```
* 其作用就是指向成员函数所作用的对象

* **非静态成员函数**中可以**直接**使用this来代表指向该函数作用的对象的指针

* 静态成员函数中不能使用this指针，因为静态成员函数并不具体作用于某个对象

* 用处：但函数里定义的变量名等于成员变量名时，可使用this指针对同名的成员变量进行操作
