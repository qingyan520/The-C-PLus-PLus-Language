//����λ��Ϊ0�Ŀ�ʼ���
#include<iostream>
using namespace std;
int main()
{
	int arr[10][10] = {
		{5650,4542,3554,473,946,4114,3871,9073,90,4329},
		{2758,7449,6113,5659,5245,7432,3051,4434,6704,3594},
		{9937,1173,6866,3397,4759,7557,3070,2287,1453,9899},
		{1486,5722,3135,1170,4014,5510,5120,729,2880,9019},
		{2049,698,4582,4346,4427,646,9742,7340,1230,7683},
		{5693,7015,6887,7381,4172,4341,2909,2027,7355,5649},
		{6701,6645,1671,5978,2704,9926,295,3125,3878,6785},
		{2066,4247,4800,1578,6652,4616,1113,6205,3264,2915},
		{3966,5291,2904,1285,2193,1428,2265,8730,9436,7074},
		{689,5510,8243,6114,337,4096,8199,7313,3685,211}
	};

	double ret=1;
	//ͳ��ÿλ����ĩβ2��5�������Ѽ�0������
	int count1 = 0;//5
	int count2 = 0;//2
	int count3 = 0;//0
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] % 10 == 2)
			{

				count2++;
				continue;
			 }
			if (arr[i][j] % 10 == 5)
			{
				count1++;
				continue;
			}
			if (arr[i][j] % 10 == 0)
			{
				while (arr[i][j] % 10 == 0)
				{
					count3++;
					arr[i][j] /= 10;
				}
			}
		}
	}

	cout << min(count1, count2) + count3 << endl;
	
}