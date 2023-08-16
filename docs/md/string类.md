1. string类
    * string类是模板类`typedef basic_string<char> string;`
    * 使用string类要包含头文件`<string>`
    * string对象初始化
        ```c++
        string s1("Hello");
        string month="March";
        ```    
        * 错误的初始化方法：
            ![Alt text](image-7.png)    
        * 可以将字符赋值给string对象
            ```c++
            string s;
            s='n';
            ```    
    ![Alt text](image-8.png)      

2. string的赋值和连接
    * 用`=`赋值
        ```c++
        string s1("cat"),s2;
        s2=s1;
        ```
    * 用`assign`成员函数复制
        ```c++
        string s1("cat"),s3;
        s3.assign(s1);
        ```    
    * 用`assign`成员函数部分复制
        ```c++
        string s1("catpig"),s3;
        s3.assign(s1,1,3);    //s3变成“atp”
        ```    
    * 单个字符复制`s2[5]=s1[3]='a'`
    * 逐个访问string对象中的字符
        ```c++
        string s1("Hello");
        for(int i=0;i<s1.length();i++)
            cout<<s1.at(i)<<endl;
        ```    
        * 成员函数`at`会做范围检查，如果超出范围，会抛出`out_of_range`异常，而`下标运算符[]`不做范围检查
    * 用`+`运算符连接字符串
        ```c++
        string s1("good"),s2("morning!");
        s1+=s2;
        cout<<s1;
        ```
    * 用成员函数`append`连接字符串
        ```c++
        string s1("good"),s2("morning!");
        s1.append(s2);
        cout<<s1<<endl;
        s2.append(s1,3,s1.size());    //s1下标从3开始,s1.size()个字符,如果字符串内没有足够字符,则复制到字符串最后一个字符
        cout<<s2<<endl;
        ```    

3. 比较string
    * 用关系运算符比较string大小
        ![Alt text](image-9.png)    
    * 用成员函数`compare`比较string大小
        ![Alt text](image-10.png)    

4. 子串
    * 成员函数`substr`
        ```c++
        string s1("hello world"),s2;
        s2=s1.substr(4,5);    //下标4开始5个字符
        cout <<s2<<endl;
        ```    

5. 交换string
    * 成员函数`swap`
        ```c++
        string s1("hello world"),s2("really");
        s1.swap(s2);
        cout<<s1<<endl;    //really
        cout<<s2<<endl;    //hello world
        ```    

6. 寻找string中字符
    * 成员函数`find()`
        ![Alt text](image-17.png)    
        ![Alt text](image-19.png)    
    * 成员函数`rfind()`
        ![Alt text](image-18.png)    
    * 成员函数`find_first_of()`
        ![Alt text](image-20.png)    
    * 成员函数`find_last_of()`
        ![Alt text](image-21.png)    
    * 成员函数`find_first_not_of()`
        ![Alt text](image-22.png)     
    * 成员函数`find_last_not_of()`
        ![Alt text](image-23.png)    

7. 删除string中的字符
    * 成员函数`erase()`
        ![Alt text](image-24.png)    

8. 替换string中的字符
    * 成员函数`replace()`
        ![Alt text](image-25.png)    
        ![Alt text](image-26.png)    

9. 在string中插入字符
    * 成员函数`insert()`
        ![Alt text](image-27.png)    

10. 转换成C语言char *字符串
    * 成员函数`c_str()`
        ![Alt text](image-28.png)    
    * 成员函数`data()`
        ![Alt text](image-29.png)    

11. 字符串拷贝
    * 成员函数`copy()`
        ![Alt text](image-30.png)    

12. 字符串流处理
    * 除了标准流和文件输入输出外,还可以从string进行输入输出
    * 类似istream和ostream进行标准输入输出,我们用istringstream和ostringstream进行字符串上的输入输出,也称为内存输入输出
    ![Alt text](image-31.png)    

13. 字符串输入流
    ![Alt text](image-32.png)        

14. 字符串输出流
    ```c++
    ostringstream outputString;
    int a=10;
    outputString<<"this "<<a<<"ok"<<endl;
    cout<<outputString.str();    //此处输出"this 10ok"
    ```    
