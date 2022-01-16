> ​                                                         20101320   史金伟  python作业

> 代码如下：

```python
def func(stu_list):
    
    d={}
    #创建列表
    b=[]
    #将stu_list中的每一个字符串以"_"分割形成新的列表存储到b中
    for str in stu_list:
        str=str.split("_")
        b.append(str)
        
    #创建临时字典，将key值相同的元素构成键值对存储到字典中
    temp={}
    for i in range(0,len(b)):
        #key值已经存在于字典中了，那么就向其value中添加列表
        if(b[i][0]in temp):
            temp[b[i][0]]+=[b[i][1]]
        #key目前还没有添加到字典中，添加key和value到字典中
        else:
            temp[b[i][0]]=[b[i][1]]
            
    #将字典按照len(value)进行排序
    d=dict(sorted(temp.items(),key=lambda x:-len(x[1])))
    return d
if __name__=="__main__":
    
    #stu_list：手动创建字符串模拟从文件中读取到的内容
    stu_list=["A1_12","A4_23","A4_03","A1_05","A3_12","A2_07","A1_07","A3_01","A1_04","A4_11"]
    
    #执行函数得到最终结果
    result=func(stu_list)
    #打印字典
    for k,v in result.items():
        print(k,"->",v)
```

> 演示效果：



















> 流程图：

![image-20211017210319414](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211017210319414.png)
