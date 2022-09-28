Opencv数字图像处理

```cpp
实验一：数字图像的读取与显示
掌握Imread,Imwrite,ImShow使用
```

1.图像的读取

```cpp
#include<opencv2/opencv.hpp>
void help(char*argv[])
{
    std::cout<<argv[0]<<" "<<"路径"<<endl;
}
int main(int argc,char*argv[])
{
    if(argc!=2)
    {
        help(argc);
        return 0;
    }
    
    //读入图像文件
    cv::Mat img=cv::imread(argv[0],-1);
    
    if(img.empty())
        return -1;
    //显示图像
    //创建窗口，并且为窗口命名为argv[1],数学设置为WINDOW_NORMAL
    cv::namedWindow(argv[1],cv::WINDOW_NORMAL);
    
    //显示图像img到名字为argv[1]的窗口中
    cv::imshow(argv[1],img);
    //等待键盘输入，不然图像就会一闪而过
    cv::waitKey(0);
    //销毁窗口argv[1];
    cv::destoryWindow(argv[1]);
    
    //cv::destroyAllWindows();//销毁所有窗口
    
    //将图像写入到文件中
    cv::imwrite("d:\\test\\test.jpg",img);
    
    
    return 0;
}
```

imread()

```c++
cv::Mat cv::imread(const string&filename,int flags=IMREAD_COLOR);
filename:图像路径
flags:读取图像形式的标志，默认为1标识彩色图像，为0标识灰度图像，为-1表示原图像

输出：返回给一个Mat类变量，出错时，返回一个空矩阵，因此可以通过判断data的属性是否为空或者empty()是否为真来判断是否成功读取图像，如果读取失败，data的属性值为0，empty函数返回值为1

能够读取的图像格式：bmp文件个dib文件都可以读取，可以读取jpg,hpeg,PNG,TIFF文件，按照图像文件内容进行读取，与后缀名无关
```

图像窗口函数nameWindow

```cpp
void cv::nameWindow(const string &winname,int flags=WINDOW_AUTOSIZE);

winname:窗口名称，用作窗口默认标识符
flags：窗口属性设置标志，默认不能调整窗口大小，可以WINDOW_NORMAL自由调整大小
```

图像显示函数imshow()

```cpp
void cv::imshow(const string&winname,InputArray mat)；
winname:要显示图像窗口的名字，用字符串形式赋值
mat:要显示的图像矩阵
```

存储如下到文件的函数imwrite

```cpp
bool imwite(const string&filename,InputArray img,const std::vector<int>&params=std::vector<int>());

```

