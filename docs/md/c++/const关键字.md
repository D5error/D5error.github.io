# 1. const
* 定义常量
    ```cpp
    const int MAX=23;
    const string NAME="D5rrr";
    ```

* 定义常量指针
    * 不可通过常量指针修改其指向的内容
    
    * 不可把常量指针赋值给非常量指针,反之可以

    ```c
    int n,m;
    const int *p=&n;
    p=&m;    //常量指针的指向可以变化
    ```

* 定义常引用

    * 不能通过常引用修改其引用的变量

```c
int n;
const int &p=n;
```