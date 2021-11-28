//BST解决迷宫问题
//测试用例：
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
0 0 3 2
*/
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//int startx, starty;
//int endx, endy;
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//int v[100][100]{ 0 };
//struct pos
//{
//	int x;
//	int y;
//	int step;
//};
//int BST(vector<vector<int>>& map)
//{
//	pos start{ startx,starty,0 };
//	queue<pos>q;
//	q.push(start);
//	v[startx][starty] = 1;
//	while (!q.empty())
//	{
//		pos front = q.front();
//		pos next;
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			next.x = front.x + dir[i][0];
//			next.y = front.y + dir[i][1];
//			next.step = front.step + 1;
//			if (next.x == endx && next.y == endy)
//			{
//				return next.step;
//			}
//
//			if (next.x >= 0 && next.x < map.size() && next.y >= 0 && next.y < map[0].size() && map[next.x][next.y] == 1 && v[next.x][next.y] == 0)
//			{
//				q.push(next);
//				v[next.x][next.y] = 1;
//			}
//		}
//	}
//	return 0;
//
//}
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>>map(m, vector<int>(n, 0));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	cin >> startx >> starty >> endx >> endy;
//
//	cout << BST(map) << endl;
//	return 0;
//}



//DST解决迷宫问题
//测试用例：
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
0 0 3 2
*/
#include<iostream>
#include<vector>
using namespace std;
int startx, starty;
int endx, endy;
int v[100][100]{ 0 };
int min_step = INT_MAX;
vector<vector<int>>map;

int dir[4][2]{ {0,1},{1,0},{0,-1},{-1,0} };
void DFS(int x,int y,int step)
{
	if (x == endx && y == endy)
	{
		if (step < min_step)
		{
			min_step = step;
		}
		return;
	}
	////右
	//if (y + 1 < map[0].size() && v[x][y + 1] == 0 && map[x][y + 1] == 1)
	//{
	//	v[x][y + 1] = 1;
	//	DFS(x, y + 1, step + 1);
	//	v[x][y + 1] = 0;
	//}

	////下
	//if (x + 1 < map.size() && v[x + 1][y] == 0 && map[x + 1][y] == 1)
	//{
	//	v[x + 1][y] = 1;
	//	DFS(x + 1, y, step + 1);
	//	v[x + 1][y] = 0;
	//}

	////左
	//if (y - 1 >= 0 && v[x][y - 1] == 0 && map[x][y - 1] == 1)
	//{
	//	v[x][y - 1] = 1;
	//	DFS(x, y - 1, step + 1);
	//	v[x][y - 1] = 0;
	//}
	////上
	//if (x - 1 >= 0 && v[x - 1][y] == 0 && map[x-1][y] == 1)
	//{
	//	v[x - 1][y] = 1;
	//	DFS(x - 1, y, step + 1);
	//	v[x - 1][y] = 0;
	//}

	for (int i = 0; i < 4; i++)
	{
		int _x =x+ dir[i][0];
		int _y =y+ dir[i][1];
		if (_x >= 0 && _x < map.size() && _y >= 0 && _y <map[0].size() && map[_x][_y] == 1 && v[_x][_y] == 0)
		{
			v[_x][_y] = 1;
			DFS(x + dir[i][0], y + dir[i][1], step+1);
			v[_x][_y] = 1;
		}
	}


}
int main()
{
	int m, n;
	cin >> m >> n;
	map.resize(m);
	for (int i = 0; i < m; i++)
	{
		map[i].resize(m, 0);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> startx >> starty >> endx >> endy;
	DFS(startx, starty, 0);
	cout << min_step << endl;
}