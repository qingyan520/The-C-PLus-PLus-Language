json和xml文件基础语法



xml基础语法和规范

```xml
<!--注释-->

<!--固定开头-->
<?xml virsion="1.0" encoding="UTF-8"?>
<!--树状结构的标签-->
<!--根标签--只有一个自己起名-->
<!--标签一般都是成对出现-->
<!--不成对--><lisi/>
<!--标签区分大小写-->
<hello>
    <!--根标签里面就是子标签-->
    <child>
        <!--没有子标签，标签必须有值-->
        <!--标签可以设置属性值 report:属性，属性需要使用""包含-->
        <name report="yes">张三</name>
        <age yeufen="1">12</age>
        <sex>男</sex>
    </child>
    
    <!--子标签-->
    <child>
        <name>李四</name>
        <age>13</age>
        <sex>男</sex>
    </child>
</hello>
```

![image-20220322162612394](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220322162612394.png)

以上图为例设计一个xml文件格式

```xml
<China>
    <City name="北京">
        <area></area>
        <population></population>
        <GDP></GDP>
    </City>
    <City name="东京">
	    <area></area>
        <population></population>
        <GDP></GDP>
    </City>
</China>
```

minxml开源软件库

用的时候包含头文件

```
#include<mxml.h>

编译时需要包含动态库 mxml
即 -lxml
/usr/local/lib
```

minxml的使用

```
生成一个xml文件
	创建一个新的xml文件
	mxml_node_t*mxmlNewXml(const char*version);
	返回新创建的xml文件节点
	默认的文件编码为uft-8
	
	删除节点的内存
	void mxmlDelete(mxml_node*node);
	
	添加一个新的节点
	mxml_node_t*mxmlNdeElment(
	mxml_node_t*parent,//父节点
	const char*name//新节点的标签名
	)
	
	设置结点的属性名和属性值
	void mxmlElementSetAttr(
		mxml_node_t*node,//被设置属性的节点
		const char*name,//结点的属性值
		const char*value;//属性值
	)
	
	创建节点的文本内容
	mxml_node_t*mxmlNewText(
		mxml_node_t*parent,//节点地址
		int whitespace,//是否有空白 0
		const char*string//文本内容
	)
	
	保存节点到xml文件
	int mxmlSaveFile(
		mxml_node_t*node,//根节点
		FILE*fp,//文件指针
		mxml_save_cb_t cb //默认MXML_NO_CALLBACK
	)
```

示例

```cpp
#include<mxml.h>
#include<iostream>
#include<cstdio>
int main()
{
    //文件头
    mxml_node_t*root=mxmlNewXML("1.0");
    
    //跟标签
    mxml_node_t*china=mxmlNewElement(root,"China");
    
    //子标签
    mxml_node_t*city=mxmlNewElement(china,"city");
    
    mxml_node_t*info=mxmlElement(city,"name");
    
    //标签赋值
    mxmlNewText(info,0,"北京");
    mxmlElementSetAttr(info,"isbig","Yes");
    //面积
    info=mxmlNewElement(city,"area");
    mxmlNewText(info,0,"16410平方公里")
    info=mxmlNewElement(city,"Population");
    mxmlNewText(info,0,"2000万");
    info=mxmlNewElement(city,"GDP");
    mxmlNewText(info,0,"24547亿");
    
    //打开文件
    FILE*fp=fopen("china.xml","w");
    mxmlSaveFile(root,fp,MXML_NO_CALLBACK);
    fclose(fp);
    mxmlDelete(root);
    return 0;
}
```

```
gcc create.c -lmxml -o ctreate
```

解析xml文件

```
解析xml文件

```





JSON文件的使用

1.json的格式

```json
json数组：中括号表示[整型，字符串，布尔类型，json数组，json对象]
例:
[123,132,true,false,[12,23,"hello"]]

json对象:{}中是一些键值对
{
	"name":"张山",
	"name2":"李四"
}
key值：必须是字符串,不可以重复
value值：json对象，json数组，布尔，整型，字符串...

json数组+json对象
{
	"name":"张山",
	"name2":"李四"
	"张三":{
		"别名":"老王",
		"性别"："男",
		"年龄":34,
		"孩子":["小红","小绿","小黑"]
	}
}
```

JSON文件操作

```
拷贝cJSON.c,cJSON.h到项目目录下即可
编译时加 -lm
```

```cpp
	- 生成json文件
		○ 创建一个json对象
		cJSON *cJSON_CreateObject(void);
		○ 往json对象中添加数据成员
		void cJSON_AddItemToObject(
			cJSON *object,              //  json对象
			const char *string,         //  key值
			cJSON *item                  //  value值（int，string，array，obj）
		);
		○ 创建一个整型值
		cJSON *cJSON_CreateNumber(double num);
		○ 创建一个字符串
		cJSON *cJSON_CreateString(const char *string);
		○ 创建一个json数组
		cJSON *cJSON_CreateArray(void); -- 空数组
		○ 创建默认有count个整形值的json数组
		cJSON *cJSON_CreateIntArray(const int *numbers,int count);
			§ int arry[] = {8,3,4,5,6};
			§ cJSON_CreateIntArray(arry, 5);
		○ 往json数组中添加数据成员
		void cJSON_AddItemToArray(cJSON *array, cJSON *item);
		○ 释放jSON结构指针
		void cJSON_Delete(cJSON *c)
		○ 将JSON结构转化为字符串
		char *cJSON_Print(cJSON *item);
			§ 返回值需要使用free释放
			§ FILE* fp = fopen();
			§ fwrite();
			§ fclose();

```

代码示例

```cpp
#include"cJSON.h"
int main()
{
    //创建对象
    cJSON*obj=cJSON_CreateObject();
    //创建子对象
    cJSON*sunobj=cJSON_CreateObject();
    
    cISON_AddItemToObject(subobj,"factoty","cJSON_CreateString("一汽大众")");
    cISON_AddItemToObject(subobj,"last","cJSON_CreateNumber(31));
    cISON_AddItemToObject(subobj,"price","cJSON_CreateNumber(82)); 
    //创建json数组
     cJSON*arr=cJSON_CreateArray();
     //向json数组添加数据
     cJSON_AddItemToArray(arr,cJSON_CreateNumber(21));
     cJSON_AddItemToArray(arr,cJSON_CreateNumber(22));
     cJSON_AddItemToArray(arr,cJSON_CreateString("Hello world"));
    
      cJSON_AddItemToObject(sunboj,"other",arr);
    //添加键值对
    cJSON_AddItemToObject(obj,"奔驰",subObj);
    char*data=cJSON_Print(obj);
    FILE*fp=fopen("car.json","w");
    fwrite(data,sizeof(char),strlen(data+1),fp);
    close(fp);
}
```

解释json文件

```cpp
		将字符串解析为JSON结构
		cJSON *cJSON_Parse(const char *value);
		 返回值需要使用cJSON_Delete释放
		○ 根据键值查找json节点
		cJSON *cJSON_GetObjectItem(
			cJSON *object,           // 当前json对象
			const char *string       //  key值
		);
		○ 获取json数组中元素的个数
		int cJSON_GetArraySize(cJSON *array);
		○ 根据数组下标找到对应的数组元素
		cJSON *cJSON_GetArrayItem(cJSON *array, int index);
		○ 判断是否有可以值对应的键值对
		int cJSON_HasObjectItem(cJSON *object, const char *string)

```

