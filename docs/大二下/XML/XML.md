# XML
> 手机下载了一个小组件，觉得太丑打算自己修改，经过一通了解后发现需要修改的部分使用了XML语言，便决定简单了解一下。

## XML简介 
XML 指可扩展标记语言（EXtensible Markup Language）

XML 是一种很像HTML的标记语言

XML 的设计宗旨是传输数据，而不是显示数据

XML 标签**没有**被**预定义**。您需要自行定义标签

## XML树结构
XML 文档形成了一种树结构，它从"根部"开始，然后扩展到"枝叶"

### 示例

```XML
<?xml version="1.0" encoding="UTF-8"?>
<note>
    <to>Tove</to>
    <from>Jani</from>
    <heading>Reminder</heading>
    <body>Don't forget me this weekend!</body>
</note>
```

第一行是 XML 声明。它定义 XML 的版本（1.0）和所使用的编码（UTF-8 : 万国码, 可显示各种语言）

第二行描述文档的**根元素**（像在说："本文档是一个便签"）

接下来 4 行描述根的 4 个**子元素**（to, from, heading 以及 body）

最后一行定义**根元素的结尾**

### XML 文档形成一种树结构
XML 文档必须包含根元素。该元素是所有其他元素的父元素

XML 文档中的元素形成了一棵文档树。这棵树从根部开始，并扩展到树的最底端

所有的元素都可以有子元素：
```XML
<root>
    <child>
        <subchild>.....</subchild>
    </child>
</root>
```

父、子以及同胞等术语用于描述元素之间的关系。父元素拥有子元素。相同层级上的子元素成为同胞（兄弟或姐妹）。

所有的元素都可以有文本内容和属性（类似 HTML 中）


## XML语法

### XML声明
XML 声明文件的可选部分，如果存在需要放在文档的第一行，如下所示：

```XML
<?xml version="1.0" encoding="utf-8"?>
```

### XML文档必须有根元素
XML 必须包含根元素，它是所有其他元素的父元素，比如以下实例中 root 就是根元素：

```XML
<root>
  <child>
    <subchild>.....</subchild>
  </child>
</root>
```

### 属性
元素可以包含属性，属性提供有关元素的附加信息。

属性位于开始标签中，例如：

```XML
<person age="30" gender="male">John Doe</person>
```

### XML单标签
所有的 XML 元素一般都有一个关闭标签，但也允许单标签的使用的。

单标签是指在一个标签中同时包含了开始和结束标签，形式类似于HTML中的空元素标签。

在XML中，你可以使用以下两种方式表示单标签：

```XML
<exampleTag />
```

```XML
<exampleTag></exampleTag>
```

### XML标签对大小写敏感
XML 标签对大小写敏感。标签 <Letter> 与标签 <letter> 是不同的。

必须使用相同的大小写来编写打开标签和关闭标签：

```XML
<Message>这是错误的</message>
<message>这是正确的</message>
```

### XML必须正确嵌套
在 HTML 中，常会看到没有正确嵌套的元素：
```HTML
<b><i>This text is bold and italic</b></i>
```

在 XML 中，所有元素都必须彼此正确地嵌套：

```XML
<b><i>This text is bold and italic</i></b>
```


### XML 属性值必须加引号
与 HTML 类似，XML 元素也可拥有属性（名称/值的对）

在 XML 中，XML 的属性值必须加引号

```XML
<note date="12/11/2007">
    <to>Tove</to>
    <from>Jani</from>
</note>
```

### 实体引用
在 XML 中，一些字符拥有特殊的意义。

如果您把字符 "<" 放在 XML 元素中，会发生错误，这是因为解析器会把它当作新元素的开始。

这样会产生 XML 错误：

```XML
<message>if salary < 1000 then</message>
```

为了避免这个错误，请用实体引用来代替 "<" 字符：

```XML
<message>if salary &lt; 1000 then</message>
```

在 XML 中，有 5 个预定义的实体引用：

|实体引用|符号|含义
|-      |-      |-|
|&lt;	|<	    |less than          
|&gt;	|>      |	greater than     
|&amp;	|&      |	ampersand
|&apos;	|'      |	apostrophe
|&quot;	|"      |	quotation mark

### XML 中的注释
在 XML 中编写注释的语法与 HTML 的语法很相似

```XML
<!-- This is a comment -->
```

### 在 XML 中，空格会被保留
HTML 会把多个连续的空格字符裁减（合并）为一个：

HTML:|	`Hello           Tove`
|-|-|
输出结果:|	`Hello Tove`

在 XML 中，文档中的空格不会被删减：
```XML
<bookstore>
    <book>
        <title>xx       xxx</title>
        <author>John Doe</author>
        <price>29.99</price>
    </book>
</bookstore>
```

title 内容读取显示如下：

```XML
xx       xxx
```

## XML元素

### 什么是XML元素？
XML 元素指的是从（且包括）开始标签直到（且包括）结束标签的部分。

一个元素可以包含：

* 其他元素

* 文本

* 属性

* 或混合以上所有...

### XML命名规则
XML 元素必须遵循以下命名规则：

* 名称可以包含字母、数字以及其他的字符

* 名称不能以数字或者标点符号开始

* 名称不能以字母 xml（或者 XML、Xml 等等）开始

* 名称不能包含空格

可使用任何名称，没有保留的字词


## XML属性
XML元素具有属性，类似 HTML。

属性（Attribute）提供有关元素的额外信息。

### XML属性
在 HTML 中，属性提供有关元素的额外信息：

```HTML
<img src="computer.gif">
<a href="demo.html">
```

属性通常提供不属于数据组成部分的信息。在下面的实例中，文件类型与数据无关，但是对需要处理这个元素的软件来说却很重要：

```XML
<file type="gif">computer.gif</file>
```

### XML属性必须加引号
属性值必须被引号包围，不过单引号和双引号均可使用。比如一个人的性别，person 元素可以这样写：

```XML
<person sex="female">
```

或者这样也可以：
```XML
<person sex='female'>
```

### XML元素与属性
请看这些实例：

```XML
<person sex="female">
    <firstname>Anna</firstname>
    <lastname>Smith</lastname>
</person>
```

```XML
<person>
    <sex>female</sex>
    <firstname>Anna</firstname>
    <lastname>Smith</lastname>
</person>
```
在第一个实例中，sex 是一个属性。在第二个实例中，sex 是一个元素。这两个实例都提供相同的信息。

没有什么规矩可以告诉我们什么时候该使用属性，而什么时候该使用元素。
