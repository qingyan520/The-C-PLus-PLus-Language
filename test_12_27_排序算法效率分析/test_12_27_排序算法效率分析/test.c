#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<errno.h>
#include<time.h>
//������ֵ
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//�����ӡ
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//�����ӡ
void Print_Reverse(int* arr, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//1.��������
//1.1ֱ�Ӳ�������
//��ÿ��Ҫ��������ݺ�ǰ�������������бȽϣ���Ҫ��������ݵ��ʺϵ�λ��ȥ���������һ��
void InsertSort(int* arr, int n)
{
	//ѭ������Ϊ[0,end-2]���ɣ����һ��Ԫ���±�Ϊn-1�������䷶ΧΪ��һ��Ԫ�ص������ڶ���Ԫ�ط�Χ����
	for (int i = 0; i < n - 1; i++)
	{
		//����arr[i+1]��Ҫ��������ݣ���[0,end]��ǰ����������У���arr[i+1]����ǰ�����������
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			//���ǰ��һ������Ҫ��������ݴ���ô�ͺ������Ԫ��
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//ǰ��Ԫ�ز�����Ҫ����Ԫ�أ��˳�ѭ��
			else
			{
				break;
			}
		}
		//ѭ���˳��������
		//1.��end=-1ʱ����Ҫ�����Ԫ��Ϊ��СԪ��ʱ��end<0����ѭ������ʱend+1�պ�Ϊ��һ��Ԫ��λ�ã������ΪҪ�����Ԫ��
		//2.���Ҫ�����Ԫ�ر�ǰ��Ԫ�ش��˳�����ǰ��һ��Ԫ�ص���һ��Ԫ��ΪҪ�����Ԫ��
		arr[end + 1] = temp;
	}
}


//1.2ϣ������
////(2)ϣ������
////Ϊ�˶Բ�����������Ż��������ϣ������
////������֮ǰ�ȶ��������Ԥ����ʹ�����þ������򣬼����������
////Ԥ����֮���ڽ���ֱ�Ӳ�������
////����
////���飺9  1  2  5  7  4  8  6  3  5
////���Ƕ���һ����gap����ÿgap������Ϊһ�飬���������У�����ʹgap=3
////����ʹarr[0],arr[0+gap](arr[3]),arr[0+gap+gap](arr[6]),arr[0+gap+gap+gap](arr[9])
////      9      5                  8                      5            ��һ������
////�ڶ��飺arr[1],arr[1+gap](arr[4]),arr[1+gap+gap](arr[7])
////       1       7                  6                                 �ڶ�������
////�����飺arr[2],arr[2+gap](arr[5]),arr[2+gap+gap](arr[8])
////        2       4                 3                                 ����������
////����ʹ�������ݽ����ڲ�����ʹ����ÿ��С���ڳ�Ϊ��������
////   5   5    8          9
////   1   7    6
////   2   4    3
////  5  1  2   5  7   4   8  6  3   9
//// ��������ǻᷢ������ֲ��ӽ�������
////Ȼ����ͬ���ķ�����gap=2����ʹ���������
////�����gap=1,���ǻᷢ�ֵ�gap==1ʱ������������֮ǰ��д�Ĳ��������𣬼�gap>1ʱ������Ԥ������gap==1��ʱ�����в�������
////����Ϊgap��󣬴���������ױ�Ų�����棬С���������ױ�Ų��ǰ��
////gapԽ�󣬴������С���������ױ�Ų����Ӧ�ķ���
////gapԽ��Խ���ӽ�����
////gapԽС��Խ��Ų����Ӧλ��
////gapԽС��Խ�ӽ�����
////gap==1ʱ���൱�ڲ�������
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


//2.��������
//2.1ֱ�ӽ�������
//ÿ�������Ԫ��������Ԫ�رȽϣ�ѡ����С��
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

//2.2������
////1.�Ƚ��ѣ������򣬽���ѣ��Ž��򣬽�С��
////2.������һ���������һ������λ�ã�Ȼ��ʹ�����µ����㷨
////ע�⣺����ʱ�����һ����Ҷ�ӽ�㿪ʼ������n-1-1��/2��ʼʹ��ʹ�����µ����㷨���н���
////      ����֮����бȽϣ�������һ���������һ������λ�ã�Ȼ��ʹ�����µ����㷨����ѡ���ڶ������

//�������
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
	//1.�Ƚ������
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	//2.������һ��Ԫ��λ�ú����һ��Ԫ��λ�ã�--end��Ȼ��ʹ�����µ����㷨��������
	int end = n - 1;
	while (end >0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}


//3.��������
//3.1ð������
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

//3.2����
//��������(����)
//ѡȡ��߻����ұߵ�ֵ��Ϊkeyֵ
//�ұ��������ұ�keyС�����֣�����������ұ�key������֣��ҵ��󽻻�λ��
//���������key�ᵽ���ʵ�λ�ã�����ߵ����ֶ���keyС���ұߵ����ֶ���key��
//֮��������Ϊkey��ߺ��ұߣ�Ȼ�����������������ڽ����������裬������ÿ����������һ�����ֵ�������ָ��λ�ã�������������ֶ��������λ��

//���ŵ������Ż���ʽ
//1.����ȡ�з�����ֹ����(��������)�ĳ���
//2.С�����Ż��������䷶Χ�㹻Сʱ������ֱ�Ӳ������򣬼��ٵݹ����
//
//1.����ȡ�з�
//��������ʱ�临�Ӷ�O(N*logN),����������ʱ��Ϊ������ʱ�临�Ӷ�ΪO(N*N)
//��ʱ����ͨ���Ż����
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

//2.С�����Ż�:�����䷶ΧСʱ��������������������򣬼����������

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

//4.�鲢���򣺷���
//�������Ϊ���ˣ�������������ˣ��ұ�Ҳ�����ˣ���ô�ϲ������������������������
//���磺
//1  6  7  10    2  3  4  9
//1  6  7  10  |  2  3  4  9
//1  2  3  4  6  7  9  10
//ȡС������β�嵽�������飬֪��һ������������ٰ���һ������ʣ��Ԫ��β�嵽���

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


//5.��������
//5.��������
//˼�룺������һ������������ʾ
//2  5  3  0  2  3   0  3
//���⿪��һ������������count,ȫ����ʼ��Ϊ0��������A���飬ʹ��count[A[i]]++;
//2  0  2  3  0  1
//0  1  2  3  4  5
//����ԭ�������СΪ
//0 0 2 2 3 3 5
//ʱ�临�Ӷȣ�O(N+range)
//�ռ临�Ӷȣ�O(range)

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
	//�����С=���ֵ-��Сֵ+1
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
	//���ļ�
	FILE* pfOut = fopen("Sort.txt", "w+");
	if (pfOut == NULL)
	{
		printf("Save::%s\n", strerror(errno));
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i <n; i++)
	{
		fwrite(arr+i, sizeof(int), 1, pfOut);
	}

	fwrite(&Speed, sizeof(Speed), 1, pfOut);

	//�ر��ļ�
	fclose(pfOut);
	pfOut = NULL;
}

void test()
{

	//�����������������ò�ͬ�����ݶ�ͬһ�����ݽ������򣬷���ʱ�临�Ӷ�
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

	//1.��������
	//1.1ֱ�Ӳ�������
	int a = clock();
	InsertSort(arr1, n);
	int b = clock();
	printf("ֱ�Ӳ�������:%dms\n", b - a);
	
	//1.2ϣ������
	int c = clock();
	ShellSort(arr2, n);
	int d = clock();
	printf("ϣ������:%dms\n", d - c);



	//2.��������
	//2.1ð������
	int e = clock();
	BubbleSort(arr3, n);
	int f = clock();
	printf("ð������:%dms\n", f - e);

	//2.2����
	int g = clock();
	HeapSort(arr4, n);
	int h = clock();
	printf("����:%dms\n", h - g);


	//3.ѡ������
	//3.1ֱ��ѡ������
	int i = clock();
	SelectSort(arr5, n);
	int j = clock();
	printf("ֱ��ѡ������:%dms\n", j - i);

	//3.2����
	int k = clock();
	QuickSort(arr6, 0, n - 1);
	int l = clock();
	printf("����:%dms\n", l - k);


	//4.�鲢����
	int m = clock();
	MergeSort(arr7, n);
	int o = clock();
	printf("�鲢����:%dms\n", o - m);


	//5.��������
	int p = clock();
	CountSize(arr8, n);
	int q = clock();
	printf("��������:%dms\n", q- p);

	//��������
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