#"""
#任务：定义一个四边形父类 Quadrilateral，给定了一个长方形子类 Rectangle，
#在父类中定义一个 area 方法用于求四边形的面积。
#"""
        
## 请在下面的Begin-End之间按照注释中给出的提示编写正确的代码
########### Begin ##########
## 定义四边形父类Quadrilateral，并在类中定义一个area方法用于求长方形面积

 
########### End ##########
## 长方形子类
#class Rectangle(Quadrilateral):
#	def func(self):
#    	print("这是长方形")

#    def  __init__(self):

        
#length = int(input())     # 获取四边形的长
#wigh = int(input())     # 获取四边形的宽
## 实例化长方形类
#r = Rectangle(length,wigh)
########### Begin ##########
## 调用area方法求长方形面积


########### End ##########



class TerrestrialAnimal:
	def activy(self):
    	print("可以在陆地上运动")
    def breath(self):
    	print("使用肺呼吸")
    def eat(self):
    	print("可以吃东西")
        
class AquaticAnimal:
	def activy(self):
    	print("可以在水中游泳")
    def breath(self):
    	print("使用鳃呼吸")

        
        
# 请在下面的Begin-End之间按照注释中给出的提示编写正确的代码
########## Begin ##########
# 第1步：定义 Frog 类，继承 TerrestrialAnimal 和 AquaticAnimal 方法

# 第2步：重写 breath 方法

########## End ##########
f = Frog()
f.breath()