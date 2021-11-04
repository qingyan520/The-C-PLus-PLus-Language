#"""
#任务：定义一个 Cuboid 类，该类有长、宽和高三个属性，而且类中定义了一个求表面积的函数 area 和 体积函数 volume，
#长、宽和高都是通过 input 函数获取，请编写代码实现该类。
#"""


## 请在下面的Begin-End之间按照注释中给出的提示编写正确的代码
########### Begin ##########
## 第一步：定义Cuboid类，定义长、宽和高三个属性

## 第二步：在类中定义area函数和volume函数

## 第三步：实例化类，并调用函数

########### End ##########
#class Cuboid:
#    length=0
#    weight=0
#    height=0
#    def __init__(self,length,weight,height):
#        self.length=length
#        self.weight=weight
#        self.height=height
#    def area(self):
#        return self.height*self.weight*2+self.length*self.weight*2+self.height*self.length*2
#    def volume(self):
#        return self.height*self.length*self.weight

#if __name__=='__main__':
#    length=int(input())
#    weight=int(input())
#    height=int(input())
#    a=Cuboid(length,weight,height)
#    print("表面积为%d平方米"%(a.area()))
#    print("体积为%d立方米"%(a.volume()))


#"""
#任务：给定一段代码，请修改其中部分代码，使代码可以成功运行。
#"""


## 请在下面的Begin-End之间按照注释中给出的提示编写正确的代码
########### Begin ##########
#class Kls:
#    data='a'
#    def __init__(self, data):
#        self.data = data
#    @classmethod
#    def checkind():
#        return IND == 'ON'
    
#    def do_reset(self):
#        print('输入的值为 %s' %self.data)

#IND = 'ON'
#k = Kls(input())
#k.do_reset()
########### End ##########

import math

     # 获取球的半径

class Sphere:
# 请在下面的Begin-End之间按照注释中给出的提示编写正确的代码
########## Begin ##########
# 第1步：定义构造函数
    r=0.0
    def __init__(self,r):
        self.r=(float)(r)
# 第2步：定义volumn方法求球的体积
    def volumn(self):
        return (4.0*math.pi*self.r**3/3.0 )
# 第3步：实例化类，调用volumn方法求体积，打印球的体积
R = int(input())
a=Sphere(R)
print("体积为%.16f立方米"%(a.volumn()))
########## End ##########

