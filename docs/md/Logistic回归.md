## 1. Logistic回归

* Logistic回归概述:Logistic回归或者叫逻辑回归,虽然名字有回归,但它是用来分类的,主要思想是:根据现有数据对分类边界线建立回归公式,以此进行分类

* 重要概念:
    * Sigmoid函数:
        * 回归概念:假设现在有一些数据点,我们用一条直线对这些点进行拟合(这条线称为最佳拟合直线),这个拟合的过程就叫做回归,进而可以得到对这些点的拟合直线方程
        * 二值型输出分类函数:我们想要的函数应该是:能接受所有的输入然后预测出类别.例如,在两个类的情况下,上述函数的输出为1或0,具有这种性质的函数是海维塞得阶跃函数或者直接称为单位阶跃函数.该函数的问题在于,该函数的跳跃点从0瞬间跳跃得到1,这个跳跃的过程有时很难处理.幸好,另一个函数也有类似特质(可以输出0或1的性质),且数学上更容易处理,这就是Sigmoid函数
        * Sigmoid函数的具体计算公式:![Logistic回归1](https://note.youdao.com/yws/api/personal/file/WEBd3fe43ab24cab6b606ab46b22d82ee3f?method=download&shareKey=4fc60862b74641c1078fee8818d12d71)
        * 下图给出了Sigmoid函数在不同坐标尺度下的两条曲线图.当x=0时Sigmoid函数值为0.5.随着x的增大,对应的Sigmoid值将逼近于1;随着x  的减小,Sigmoid值将逼近于0.如果横坐标尺度足够大,Sigmoid函数看起来很像一个阶跃函数![Logistic回归2](https://note.youdao.com/yws/api/personal/file/WEB152d54ea74f584c380a13a1f02aa61d7?method=download&shareKey=553b41a7dd6a5225a765a9776b3229fd)
        * 因此,为了实现Logistic回归分类器,我们可以在每个特征上都乘以一个回归系数,然后把所有结果值相加,将这个总和代入Sigmoid函数中,进而得到一个范围在0~1之间的数值.任何大于0.5的数据被分为1类,小于0.5的数据被分为0类.所以,Logistic回归也是一种概率统计,比如这里Sigmoid函数得出的值为0.5,可以理解为给定数据和参数,数据被分入1类的概率为0.5.
        * 互动链接:[Sigmoid函数在线使用](https://www.desmos.com/calculator/bgontvxotm?lang=zh-CN)
    * 基于最优化方法的回归系数确定:Sigmoid函数的输入记为z,由下面公式得到z=w0x0+w1x1+w2x2+...+wnxn,如果采用向量的写法,上述公式可写作w^(T)x,它表示将这两个数值向量对应元素相乘然后全部加起来得到z值.其中的向量x是分类器的输入数据,向量w也就是我们要找到的最佳参数(系数),从而使得分类器尽可能地准确.为了寻找最佳系数,需要用到最优化理论的一些知识.我们这里使用的是梯度上升法
    * 梯度上升法:
        * 梯度:`向量=值+方向 梯度=向量 梯度=梯度值+梯度方向`
        * 梯度上升法的思想:要找到某函数的最大值,最好的方法j是沿着该函数的梯度方向探寻.如果梯度符号记为 ▽,则函数f(x,y)的梯度由下式表示
![Logistic回归3](https://note.youdao.com/yws/api/personal/file/WEB1ef9d75d833cba16e1503d893e197cef?method=download&shareKey=3e98470e316567410b6bdcc3efd2a6f3)
        * 这个梯度意味着要沿x的方向移动 `∂f(x,y)/∂x` ,沿y的方向移动 `∂f(x,y)/∂y` .其中,函数f(x,y)必须要在待定义的点上有定义并且可微
![Logistic回归4](https://note.youdao.com/yws/api/personal/file/WEB4d0200f7219990ba903132c601d858c8?method=download&shareKey=de645f2bb9f5bbcaf7c91c46bedb6728)
        * 局部最优现象:
![Logistic回归5](https://note.youdao.com/yws/api/personal/file/WEB5939441a8e4c3a959c29f7cf457dfec4?method=download&shareKey=aa4e0798b1e75009f6e6e2cb282f71f4)

* Logistic回归工作原理:

```
每个回归系数初始化为1
重复R次:
    计算整个数据集的梯度
    使用步长 x 梯度 更新回归系数的向量
返回回归系数
```

* Logistic回归算法特点:
    * 优点:计算代价不高,易于理解和实现
    * 缺点:容易欠拟合,分类精度可能不高
    * 使用数据类型:数值型和标称型

## 2. 项目案例

```

```
