## 1. KNN原理

1. 假设有一个带有标签的样本数据集(训练样本集),其中包含每条数据与所属分类的对应关系
2. 输入没有标签的新数据后,将新数据的每个特征与样本集中数据对应的特征进行比较
    1. 计算新数据与样本数据集中每条数据的距离
    2. 对求得的所有距离进行排序(从小到大,越小越相似)
    3. 取前K个数据中出现次数最多的分类标签作为新数据的分类

* KNN通俗理解:给定一个训练数据集,对新的输入实例,在训练数据集中找到与该实例最相近的K个实例,这K个实例的多数属于某个类,就把该输入实例分为这个类

* KNN算法特点:
    * 优点:精度高,对异常值不敏感,无数据输入假定
    * 缺点:计算复杂度高,空间复杂度高
    * 适用数据范围:数值型和标称型

## 2. KNN项目案例

* 二分

```Python
import numpy as np
from matplotlib import pyplot as plt
from matplotlib.colors import ListedColormap
from numpy import array
from sklearn import neighbors


n_neighbors=3
X = array([[3, 104], [2, 100], [1, 81], [101, 10], [99, 5], [98, 2],[18,90]])#属性
y = array([1, 1, 1, 0, 0, 0,2])#标签
h = 0.2#分割线步长


cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA'])#背景色
cmap_bold = ListedColormap(['#FF0000', '#00FF00'])#点色


for weights in ['uniform', 'distance']:
    clf = neighbors.KNeighborsClassifier(n_neighbors, weights=weights)#创建KNeighborsClassifier分类器对象
    clf.fit(X, y)#拟合分类器模型
    x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1#获取X的最小值-1和最大值+1
    y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1#获取y的最小值-1和最大值+1
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h),np.arange(y_min, y_max, h))#生成网格点坐标矩阵xx和yy
    Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])#通过np.c_[]函数将xx.ravel()和yy.ravel()展平后的坐标合并为一个二维数组作为输入,得到预测值Z
    Z = Z.reshape(xx.shape)#将X的形状重新调整为与xx相同
    plt.figure()#创建新窗口
    plt.pcolormesh(xx, yy, Z, cmap=cmap_light)#将网格点和对应的预测类别Z以彩色区域的形式绘制出来,使用cmap_light指定颜色映射
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold)#将原始样本数据X的两个特征绘制为散点图,根据y着色,使用camp_bold指定颜色映射
    plt.xlim(xx.min(), xx.max())#设置x轴范围
    plt.ylim(yy.min(), yy.max())#设置y轴范围
    plt.title("3-Class classification (k = %i, weights = '%s')"%(n_neighbors, weights))#设置图形标题

plt.show()#显示窗口
```

