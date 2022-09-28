### Web原理基础

`html5基本结构

```html
<!DOCTYPE html>
<html>
    <head>
        <title>网页标题</title>
    </head>
    <body>
        主题内容
    </body>
</html>
```

2.2.2文本格式标签

```html
1.斜体字标签<i>
2.粗体字标签<b>和<strong>
   区别：<strong>标记的内容被认为是重要的
3.上标标签<sup>和下标标签<sub>
4.修订标签<del>和<ins>,分别用于添加文本删除线和下划线
5.与格式化标签<pre>,</pre>:可以将所标记的文本内容显示时保留换行于空格的排版效果，
```

2.2.3列表标签

```html
1.有序列表标签<ol>:需要和列表项目标签<li>配合使用，<li>需要标记在每个表象的表头
    <ol>
    <li>第一项
     <li>第二项
    </ol>
    <ol>默认从1开始，可使用start重新定义起始标号:<ol start="3">(从3开始)
使用其它样式标号，使用type进行属性说明，格式为<ol type="属性值">
2.无序列表标签<ul>:该标签也需要配合<li>使用，默认显示为缩进
        <ul>
        <li>第一项
        <li>第二项
        </ul>
 无序列表标签默认编号为实心圆，也可以自定义样式:<ul type="属性值">
3.自定义列表标签<dl>:要结合<dt>和<dd>一起使用，<dt>标记在每个词条的开头,<dd>标记在每个定义部分的开头
    
```

2.2.4图像标签

```html
<img>用于网页插入图片:含有src和alt属性，src代表图像存储路径，alt用于当图像无法找到时，用文字进行代替
<img="图像.jpg",alt="风景图片",heigth="200",width="100">
heigth:设置图片高度
width:设置图片宽度

```

2.2.6表格标签

```
1.表盒标签<table>
2.表格行标签<tr>
3.表格格标签<>
```

2.2.7框架标签

```
网页内部定义子窗口，可能对网页性能有负面影响
iframe
<iframe src="iframe/new.html"></iframe>
```

2.2.8容器标签

```
<div>标签：将网页页面分割成不同的独立部分，浏览器会自动在<div></div>所标记的区域前后自动放置一个换行符，每个标签可有一个独立的id号

<span>标签：作为文本的容器，没有特定的含义和样式，只有与css一起使用才能指定文本设置样式属性，该标签是一个内敛元素，内联元素不会自动在前后防止换行符，
```





2.3HTML5新增的常用标签

2.3.1HTML5新增文档结构标签

1.页眉标签<header>

页眉标签，用于定义整个网页文档或者其中一节的标题

2.导航标签<nav>

用于定义导航菜单栏

3.节标签<section>:用于定义段落

4.<article>:定义正文内容，每个article可以包含自己的页眉页脚

5.<aside>:侧栏标签：定义侧边栏

6.



2.3.2HTML5新增格式标签

<mark>:突出显示指定区域的文本内容,例如:

<mark>mark标签</mark>

<progress>:进度标签，用于显示任务的进度状态，可加上value和max,value代表进度，max代表进度最大值

<progress value="80">

<meter>:显示标量测量结果，通常用于显示磁盘使用率，投票计数

```
value:显示实际数值

min:规定范围内最小值

low:规定范围内的较低值

high:用于规定范围内的较高值

optimum:用于规定范围内的最佳值


```

2.4HTML新增API







3.CSS基础

3.1.1内联样式表

语法格式

<元素名 style =“属性名称：属性值”>

如果有多个属性，需要同时添加

例如：

```css
<h1 style="clor:blue;background-clor:yellow">标题</h1>
```

![image-20220315105018696](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220315105018696.png)

3.1.2内部样式表

常用于<head></head>>,

![image-20220315105648540](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220315105648540.png)

![image-20220315105734686](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220315105734686.png)

3.1.3外部样式表

玩不样式表独立为css文件，后缀名为.css

引用独立css文件语法如下

```
<link rel="stylesheet"href="样式文件URL">
例如：
<link rel="stylesheet"href="css/test.css">
```

3.1.4样式表层叠优先级

![image-20220315111845604](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220315111845604.png)

3.2CSS选择器

3.2.1元素选择器

用于匹配THML文档中某一个元素类型

```
例如：将匹配所有的段落元素<p>,并将其背景色声明为灰色
p{backgtound:gray}
```

3.2.2ID选择器

使用指定id名称匹配元素

```
#id名称{属性名称1:属性值1...}
```

```
<p id="test">这是一个段落</p>
```

```css
#test{color:red}
```



3.2.3类选择器

```
.class 名称{属性值1:属性值1...}
```

```
.red{color:ret}
<h1 class="red">这时标题<h1>
<p class="red">这时段落</>
```



3.4.6颜色

```
1.RGB色彩模式

2.常用颜色表示方式
使用RGB颜色方式
RGB的十六进制表示法
直接使用英文单词名称


```



3.5.1 CSS背景

![image-20220329104015683](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220329104015683.png)

![image-20220329104120533](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220329104120533.png)



