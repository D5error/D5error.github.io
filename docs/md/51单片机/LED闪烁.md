# 软件延时
* main函数会自身循环
* 常用延时方法：
    * 软件延时：
    ```c51
    unsigned int i;
    i=65535;
    while(i);
    ```
    * 定时器延时
    待定
# I/O口与一个字节的对应关系
* 如果把一个字节的数据赋值给一组I/O口，其中数据的最低位对应此组I/O口的最低位，数据的最高位对应此组的I/O口的最高位
# 例子
* 流水灯
```c51
#include<reg52.h>
#include<intrins.h>
void delay()
{
	unsigned i=65535;
	while(i--);
}
void main()
{
	P1=0xfe;
	while(1)
	{
		P1=_crol_(P1,1);
		delay();
	}
}
```    
