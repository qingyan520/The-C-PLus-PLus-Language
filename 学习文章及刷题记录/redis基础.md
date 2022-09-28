redis基础

Redis:远程字典服务

Redis是内存数据库



可以存储：

string是一个安全的二进制字符串

双端队列(链表):有序(有序插入)

无序集合：对顺序不关注，里面的值都是唯一的

有序集合(zset):对顺序是关注的，里面的值是唯一的，根据member来确定唯一，更具score来确定有序

```
set key val#设置key
get key    #获取key的value
INCR key   #执行原子+1操作
INCR incrby key 100 #key+100操作
decr key#减一
decrby key 100 #key减100

SETNEX key value  #set Not exist  key不存在时存在成功


```

string:字符数组，改字符串

```
object encodeing hello
"embstr"
set hello 11111111111111111111111111111111111111111111111111111111111111111111111111111111111111
obkect encoding hello:"row"

#动态字符串，能够节约内存

setbit xkdx 9 1  #为位图
getbit xkdx 9    
getbit xkdx 8
bincount xkdx    #统计位图中1的个数
```

string的应用

```
#key如何设置
1.有意义的字段 role有多行
2.role:10001 redis客户端工具     role:1001:recharge
```



分布式锁

```
#加锁  解锁 redis实现的是非公平锁

setnx lock 1# 不存在才能设置

```



3