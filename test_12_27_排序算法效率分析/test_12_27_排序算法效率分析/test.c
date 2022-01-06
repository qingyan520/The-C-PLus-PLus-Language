#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<errno.h>
#include<time.h>
//交换数值
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//正序打印
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//逆序打印
void Print_Reverse(int* arr, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//1.插入排序
//1.1直接插入排序
//让每次要插入的数据和前面的有序数组进行比较，让要插入的数据到适合的位置去，就像打牌一样
void InsertSort(int* arr, int n)
{
	//循环区间为[0,end-2]即可，最后一个元素下表为n-1，即区间范围为第一个元素到倒数第二个元素范围即可
	for (int i = 0; i < n - 1; i++)
	{
		//假设arr[i+1]是要插入的数据，而[0,end]是前面的有序数列，将arr[i+1]插入前面的有序数列
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			//如果前面一个数比要插入的数据大，那么就后移这个元素
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//前面元素不大于要插入元素，退出循环
			else
			{
				break;
			}
		}
		//循环退出的情况：
		//1.当end=-1时，即要插入的元素为最小元素时，end<0结束循环，此时end+1刚好为第一个元素位置，让其称为要插入的元素
		//2.如果要插入的元素比前面元素大，退出，让前面一个元素的下一个元素为要插入的元素
		arr[end + 1] = temp;
	}
}


//1.2希尔排序
////(2)希尔排序
////为了对插入排序进行优化，提出了希尔排序
////在排序之前先对数组进行预处理，使数组变得尽量有序，减少排序次数
////预处理之后在进行直接插入排序
////例：
////数组：9  1  2  5  7  4  8  6  3  5
////我们定义一个数gap，将每gap个数分为一组，例在这组中，我们使gap=3
////我们使arr[0],arr[0+gap](arr[3]),arr[0+gap+gap](arr[6]),arr[0+gap+gap+gap](arr[9])
////      9      5                  8                      5            第一组数据
////第二组：arr[1],arr[1+gap](arr[4]),arr[1+gap+gap](arr[7])
////       1       7                  6                                 第二组数据
////第三组：arr[2],arr[2+gap](arr[5]),arr[2+gap+gap](arr[8])
////        2       4                 3                                 第三组数据
////我们使三组数据进行内部排序，使其在每个小组内成为有序序列
////   5   5    8          9
////   1   7    6
////   2   4    3
////  5  1  2   5  7   4   8  6  3   9
//// 排序后我们会发现数组局部接近于有序
////然后按照同样的方法让gap=2，在使其进行排序
////最后另gap=1,我们会发现当gap==1时，不就是我们之前都写的插入排序吗，即gap>1时，进行预处理，当gap==1，时，进行插入排序
////当分为gap组后，大的数更容易被挪到后面，小的数更容易被挪到前面
////gap越大，大的数和小的数更容易被挪到对应的方向
////gap越大，越不接近有序
////gap越小，越快挪到对应位置
////gap越小，越接近有序
////gap==1时，相当于插入排序
void ShellSort(int* arr, int n)
{
	int gap=n;
	while (gap > 1)
	{
		gap =( gap / 3+ 1);
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > temp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = temp;;
		}

	}
}


//2.交换排序
//2.1直接交换排序
//每次让这个元素与后面的元素比较，选出最小的
void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

//2.2堆排序
////1.先建堆：排升序，建大堆，排降序，建小堆
////2.交换第一个数和最后一个数的位置，然后使用向下调整算法
////注意：建堆时从最后一个非叶子结点开始，即（n-1-1）/2开始使用使用向下调整算法进行建堆
////      建堆之后进行比较，交换第一个数和最后一个数的位置，然后使用向下调整算法重新选出第二大的数

//建立大堆
void AdjustDown(int* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n&&arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//1.先建立大堆
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	//2.交换第一个元素位置和最后一个元素位置，--end，然后使用向下调整算法继续调整
	int end = n - 1;
	while (end >0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}


//3.交换排序
//3.1冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

//3.2快排
//快速排序(快排)
//选取左边或者右边的值作为key值
//右边往左走找比key小的数字，左边往右走找比key大的数字，找到后交换位置
//这样到最后key会到合适的位置，而左边的数字都比key小，右边的数字都比key大
//之后将区间后分为key左边和右边，然后让在这两个区间内进行上述步骤，这样，每次下来就有一个数字到达它的指定位置，到最后所有数字都到达合适位置

//快排的两种优化方式
//1.三数取中法：防止最坏情况(有序序列)的出现
//2.小区间优化：当区间范围足够小时，我们直接插入排序，减少递归次数
//
//1.三数取中法
//快速排序时间复杂度O(N*logN),当其是有序时，为最坏情况，时间复杂度为O(N*N)
//这时可以通过优化解决
int GetMid(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if ((arr[mid] - arr[right]) * (arr[mid] - arr[left]) <= 0)
	{
		return mid;
	}
	else if ((arr[left] - arr[mid]) * (arr[left] - arr[right]) <= 0)
	{
		return left;
	}
	else
	{
		return right;
	}
}

//2.小区间优化:当区间范围小时，利用其他排序进行排序，减少排序次数

void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin, right = end;
	int mid = GetMid(arr, left, right);
	Swap(&arr[left], &arr[mid]);
	int key = begin;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[key], &arr[left]);
	
		QuickSort(arr, begin, left - 1);
		QuickSort(arr, left + 1, end);
}

//4.归并排序：分治
//将区间分为两端，假设左边有序了，右边也有序了，那么合并插入排序，整个数组就有序了
//例如：
//1  6  7  10    2  3  4  9
//1  6  7  10  |  2  3  4  9
//1  2  3  4  6  7  9  10
//取小的数据尾插到下面数组，知道一个区间结束，再把另一个区间剩下元素尾插到最后

void _MergeSort(int* arr, int left, int right, int* temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (right + left) / 2;
	_MergeSort(arr, left, mid, temp);
	_MergeSort(arr, mid + 1, right, temp);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			temp[i++] = arr[begin1++];
		}
		else
		{
			temp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = arr[begin1++];
	}
	while(begin2 <= end2)
	{
		temp[i++] = arr[begin2++];
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}


}
void MergeSort(int* arr, int n)
{
	int* temp = malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(arr, 0, n - 1, temp);
	free(temp);
}


//5.基数排序
//5.计数排序
//思想：假设有一个数组如下所示
//2  5  3  0  2  3   0  3
//另外开辟一个计数的数组count,全部初始化为0，，遍历A数组，使得count[A[i]]++;
//2  0  2  3  0  1
//0  1  2  3  4  5
//所以原来数组大小为
//0 0 2 2 3 3 5
//时间复杂度：O(N+range)
//空间复杂度：O(range)

void CountSize(int* arr, int n)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	//数组大小=最大值-最小值+1
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[arr[i]-min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[j++] = i + min;
		}
	}
}

void Save(int* arr, int n,int Speed)
{
	//打开文件
	FILE* pfOut = fopen("Sort.txt", "w+");
	if (pfOut == NULL)
	{
		printf("Save::%s\n", strerror(errno));
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i <n; i++)
	{
		fwrite(arr+i, sizeof(int), 1, pfOut);
	}

	fwrite(&Speed, sizeof(Speed), 1, pfOut);

	//关闭文件
	fclose(pfOut);
	pfOut = NULL;
}

void test()
{

	//创建测试用例，利用不同的数据对同一组数据进行排序，分析时间复杂度
	int n = 50000;
	int*arr1 =(int*)malloc(sizeof(int)*n);
	int* arr2 = (int*)malloc(sizeof(int) * n);
	int* arr3 = (int*)malloc(sizeof(int) * n);
	int* arr4 = (int*)malloc(sizeof(int) * n);
	int* arr5 = (int*)malloc(sizeof(int) * n);
	int* arr6 = (int*)malloc(sizeof(int) * n);
	int* arr7 = (int*)malloc(sizeof(int) * n);
	int* arr8 = (int*)malloc(sizeof(int) * n);
	if (arr1 ==NULL)
		return;
	if (arr2 == NULL)
		return;
	if (arr3 == NULL)
		return;
	if (arr4 == NULL)
		return;
	if (arr5 == NULL)
		return;
	if (arr6 == NULL)
		return;
	if (arr7 == NULL)
		return;
	if (arr8 == NULL)
		return;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr1[i] = rand() % n;
	}
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
		arr7[i] = arr1[i];
		arr8[i] = arr1[i];
	}

	//1.插入排序
	//1.1直接插入排序
	int a = clock();
	InsertSort(arr1, n);
	int b = clock();
	printf("直接插入排序:%dms\n", b - a);
	
	//1.2希尔排序
	int c = clock();
	ShellSort(arr2, n);
	int d = clock();
	printf("希尔排序:%dms\n", d - c);



	//2.交换排序
	//2.1冒泡排序
	int e = clock();
	BubbleSort(arr3, n);
	int f = clock();
	printf("冒泡排序:%dms\n", f - e);

	//2.2堆排
	int g = clock();
	HeapSort(arr4, n);
	int h = clock();
	printf("堆排:%dms\n", h - g);


	//3.选择排序
	//3.1直接选择排序
	int i = clock();
	SelectSort(arr5, n);
	int j = clock();
	printf("直接选择排序:%dms\n", j - i);

	//3.2快排
	int k = clock();
	QuickSort(arr6, 0, n - 1);
	int l = clock();
	printf("快排:%dms\n", l - k);


	//4.归并排序
	int m = clock();
	MergeSort(arr7, n);
	int o = clock();
	printf("归并排序:%dms\n", o - m);


	//5.基数排序
	int p = clock();
	CountSize(arr8, n);
	int q = clock();
	printf("基数排序:%dms\n", q- p);

	//保存数据
	Save(arr1, n,b-a);
	Save(arr2, n,d-c);
	Save(arr3, n,f-e);
	Save(arr4, n,h-g);
	Save(arr5, n,j-i);
	Save(arr6, n,l-k);
	Save(arr7, n,o-m);
	Save(arr8, n,q-p);


}

int main()
{
	 test();
	return 0;
}