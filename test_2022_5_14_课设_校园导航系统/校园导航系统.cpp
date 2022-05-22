
//191302周绍林
//#include<iostream> 
//using namespace std;
//#include<stdlib.h> 
//#include<conio.h> 
//#include<malloc.h> 
//#include<string.h>
//#define MAX 1000 //定义#define 
//#define LENGTH 11 
//#define value int
//typedef struct {
//
//	char name[30]; //结点名称
//	int num; //结点编号
//}
//VEXTYPE; //数据类型别名 
//typedef struct {
//	VEXTYPE vexs[LENGTH];//结点
//	value arcs[LENGTH][LENGTH];//邻接矩阵边表
//	int vexnum, arcnum;//结点数和最大路径
//}
//MGraph; //邻接矩阵
//MGraph b;//生成图
//MGraph InitGraph() {
//	int i, j;
//	MGraph G;
//	G.vexnum = 11; // 初始结点数为 11 ，即图的顶点数
//	G.arcnum = 55; // 初始结点最大路径数为 55 ，即图的最大边数
//	for (i = 0; i < G.vexnum; i++) G.vexs[i].num = i;
//	strcpy(G.vexs[0].name, "	校门");
//	strcpy(G.vexs[1].name, " 	13公寓");
//	strcpy(G.vexs[2].name, " 	14公寓");
//	strcpy(G.vexs[3].name, "	操场");
//	strcpy(G.vexs[4].name, "	大活");
//	strcpy(G.vexs[5].name, " 	篮球场");
//	strcpy(G.vexs[6].name, " 	11号楼");
//	strcpy(G.vexs[7].name, " 	10号楼");
//	strcpy(G.vexs[8].name, " 	9号楼");
//	strcpy(G.vexs[9].name, " 	8号楼");
//	strcpy(G.vexs[10].name, " 	浴室");
//	for (i = 0; i < G.vexnum; i++)
//
//		for (j = 0; j < G.vexnum; j++)
//			G.arcs[i][j] = MAX;//将不相邻顶点设置为距离无穷大
//	G.arcs[0][1] = 100;
//	G.arcs[1][2] = 30;
//	G.arcs[1][3] = 70;
//	G.arcs[2][3] = 100;
//	G.arcs[3][4] = 70;
//	G.arcs[4][5] = 70;
//	G.arcs[5][6] = 100;
//	G.arcs[6][7] = 80;
//	G.arcs[7][8] = 70;
//	G.arcs[8][9] = 60;
//	G.arcs[5][10] = 30;
//	for (i = 0; i < G.vexnum; i++)
//		for (j = 0; j < G.vexnum; j++)
//			G.arcs[j][i] = G.arcs[i][j];
//	return G;
//}
//
//void Menu() { // 功能需求选项菜单
//	cout << "  ****** 天津科技大学泰达校区西苑 ******\n";
//	cout << "* 1--- 输出学校内各地点	           	*\n";
//	cout << "* 2--- 输出每两个直接相连地点的距离     *\n";
//	cout << "* 3--- 修改两个地点距离	         	*\n";
//	cout << "* 4--- 两地点之间最短路径	     	*\n";
//	cout << "* 0--- 退出                      	*\n";
//	cout << " ***************************************\n";
//}
//void PutOutVex(MGraph* G) { // 功能 1 输出学校内各地点
//	for (int i = 0; i < G->vexnum; i++)
//		cout << G->vexs[i].name << " " << endl;
//}
//
//void PutOutArc(MGraph* G) { // 功能 2	输出每两个直接相连地点的距离
//	for (int i = 0; i < G->vexnum; i++)
//		for (int j = 0; j < G->vexnum; j++)
//			if (G->arcs[i][j] < MAX) {
//				cout << G->vexs[i].name << "   ---->" << G->vexs[j].name << " 的距离为 " << G->arcs[i][j] << endl;
//			}
//}
//
//void Change(MGraph* G) { // 功能 3 修改：修改两个地点距离
//	int v0, v1, length;
//	cout << "\t\t\t\t\t * *              	*地点列表* 	              * *\n";
//	cout << "\t\t\t\t\t ********************************************************\n";
//	cout << "\t\t\t\t\t * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <0> 校门     <1>13公寓     <2>14公寓           * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <3> 操场     <4>大活       <5>篮球场           * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <6>11 号楼   <7>10号楼     <8>9号楼            * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <9>8 号楼    <10>浴室	                      * *\n";
//	cout << "\t\t\t\t\t * *                                                  * *\n";
//
//	cout << "\t\t\t\t\t ********************************************************\n";
//	cout << " 修改：请输入起始顶点:\n"; cin >> v0;
//	if (v0<0 || v0>G->vexnum) {
//		cout << " 此点不存在! 请重新输入顶点:"; cin >> v0;
//	}
//	cout << " 请输入结束顶点:\n"; cin >> v1;
//	if (v1<0 || v1>G->vexnum) {
//		cout << " 此点不存在! 请重新输入顶点:"; cin >> v1;
//	}
//	cout << " 输入距离:"; cin >> length;
//	G->arcs[v0][v1] = G->arcs[v1][v0] = length;
//	cout << " 修改成功\n";
//}
//
//
//void Dijkstra(MGraph* G) { // 功能 4. 求最短路径 输两地点之间最短路径 使用Dijkstra 算法求解最短路径
//	int v, w, i, min, t = 0, x, v0, v1;
//	int final[20], D[20], p[20][20];
//	cout << "\t\t\t\t\t * *               	*地点列表*              	* *\n";
//	cout << "\t\t\t\t\t *";
//	cout << "*********************************************************\n";
//	cout << "\t\t\t\t\t * *                                                   	* *\n";
//	cout << "\t\t\t\t\t * *       <0> 校门	<1>13公寓	<2>14公寓	* *";
//
//	cout << "\t\t\t\t\t                 * *                                             	* *\n";
//	cout << "\t\t\t\t\t * *       <3> 操场	<4>大活	    <5>篮球场         	* *";
//
//	cout << "\t\t\t\t\t 		 * *                                         	        * *\n";
//	cout << "\t\t\t\t\t * *       <6>11 号楼	<7>10号楼	<8>9号楼	* *";
//
//	cout << "\t\t\t\t\t 		 * *                                                    * *\n";
//	cout << "\t\t\t\t\t * *       <9>8 号楼	<10>浴室	         	* *\n";
//	cout << "\t\t\t\t\t * *                                                   	* *\n";
//	cout << "\t\t\t\t\t *";
//	cout << "*********************************************************\n";
//	cout << " 请输入起始顶点:\n"; cin >> v0;
//	if (v0<0 || v0>G->vexnum) {
//		cout << " 此点不存在! 请重新输入顶点:"; cin >> v0;
//	}
//	cout << " 请输入结束顶点:\n"; cin >> v1;
//	if (v1<0 || v1>G->vexnum) {
//		cout << " 此点不存在! 请重新输入顶点:"; cin >> v1;
//	}
//	for (v = 0; v < G->vexnum; v++) { //迪杰斯特拉算法 
//		final[v] = 0;
//		D[v] = G->arcs[v0][v];//将v0到各个终点的最短路径长度初始化
//		for (w = 0; w < G->vexnum; w++)
//			p[v][w] = 0;
//		if (D[v] < MAX) {
//			p[v][v0] = 1;
//			p[v][v] = 1;
//		}
//	}
//	D[v0] = 0; //源点到源点的距离为0 
//	final[v0] = 1;
//	for (i = 1; i < G->vexnum; i++) {
//		min = MAX;
//		for (w = 0; w < G->vexnum; w++)
//			if (!final[w])
//				if (D[w] < min) {
//					v = w;
//					min = D[w];
//				}
//		final[v] = 1;
//		for (w = 0; w < G->vexnum; w++)
//			if (!final[w] && (min + G->arcs[v][w] < D[w])) {
//				D[w] = min + G->arcs[v][w];
//				for (x = 0; x < G->vexnum; x++)
//					p[w][x] = p[v][x];
//				p[w][w] = 1;
//			}
//	}
//	cout << "从" << G->vexs[v0].name << " 到" << G->vexs[v1].name << "的最短路径长度为： " << D[v1] << endl;
//	cout << " 途经的地点： " << endl;
//	for (int j = 0; j < G->vexnum; j++) {
//		if (p[v1][j] == 1)
//			cout << G->vexs[j].name << endl;
//	}
//}
//
//int main() {
//
//	int a;
//	b = InitGraph();
//	Menu();
//	cin >> a;
//	while (a != 0) {
//		switch (a) {
//		case 1:
//			PutOutVex(&b);
//			Menu();
//			break;
//		case 2:
//			PutOutArc(&b);
//			Menu();
//			break;
//		case 3:
//			Change(&b);
//			Menu();
//			break;
//		case 4:
//			Dijkstra(&b);
//			Menu();
//			break;
//		case 0:
//			exit(1);
//			break;
//		default:
//			break;
//		}
//		cin >> a;
//	}
//}


//19101308崔学昊
//#include<iostream>
//#include<string>
//#include<stack>      //栈
//using namespace std;
//
//#define dis 9999
//#define maxsize 10
////定义结构体
//typedef struct school
//{
//    float n = maxsize;
//    string position[maxsize] = { "西院入口 ","食堂 ","15公寓","大活 ","教学楼 ","图书馆 ","8号楼","9号楼","10号楼","11号楼", };
//    int code[maxsize] = { '1','2','3','4','5','6','7','8','9','10' };
//    float edges[maxsize][maxsize] = {
//        {0,500,400,550,800,900,200,300,400,500},
//        {500,0,300,100,200,200,300,400,500,200},
//        {400,300,0,300,400,700,400,500,200,300},
//        {550,100,300,0,100,100,200,300,400,500},
//        {800,200,400,100,0,100,300,400,500,200},
//        {900,200,700,100,100,0,400,500,200,300},
//        {200,300,400,200,300,400,0,500,200,300},
//        {300,400,500,300,400,500,400,0,200,300},
//        {400,500,200,400,500,200,400,500,0,300},
//        {500,200,300,500,200,300,400,500,200,0},
//    };
//}Mgraph;
//
//string map[4][7] = {
//    {"  8号楼(7)    "," 9号楼(8)        ","      教学楼(5)     ","    10号楼(9)     "," 11号楼(10)       ","         ","         "},
//    {"         ","         ","         "," 大活(4)   ","      食堂(2)       ","         ","         "},
//    {"         ","         ","         ","         ","       15公寓(3)      ","         ","                     西院入口(1)  "},
//    {"         ","    图书馆(6)       ","         ","         ","         ","         ","         "},
//};
//
//
//
////Dijkstra
//void Dijkstra(Mgraph g, int v, int dist[], int path[])
//{
//    int set[maxsize];
//    int i, j, u;
//
//    for (i = 0; i < g.n; i++)
//    {
//        set[i] = 0;
//        dist[i] = g.edges[v][i];  //赋值距离
//        if (dist[i] < dis && i != v) { path[i] = v; }
//        else { path[i] = -1; }
//    }
//    set[v] = 1;      //用来判断后面除去起始点
//    //path[v]=-1;
//    for (i = 0; i < g.n; i++)
//    {
//        int min = dis;
//        for (j = 0; j < g.n; j++)
//        {
//            if (dist[j] < min && set[j] == 0)
//            {
//                u = j;
//                min = dist[j];
//            }
//        }
//        set[u] = 1; //最短的 u 
//
//        for (j = 0; j < g.n; j++)
//        {
//            if (set[j] == 0 && (dist[j] > g.edges[u][j] + dist[u]))
//            {
//                dist[j] = dist[u] + g.edges[u][j];                 //重新赋值距离 如果直接到达的距离比绕的距离大那么重新赋值
//                path[j] = u;
//            }
//        }
//    }
//}
//
////Floyd 运用两个二维矩阵
//void Floyd(Mgraph g, int A[][maxsize], int path[][maxsize])
//{
//    int i, j, k;
//    for (i = 0; i < g.n; i++)
//    {
//        for (j = 0; j < g.n; j++)
//        {
//            A[i][j] = g.edges[i][j];
//            if (A[i][j] < dis && i != j) { path[i][j] = i; }
//            else path[i][j] = -1;
//        }
//    }
//    for (k = 0; k < g.n; k++)
//    {
//        for (i = 0; i < g.n; i++)
//        {
//            for (j = 0; j < g.n; j++)
//            {
//                if (A[i][k] + A[k][j] < A[i][j])
//                {
//                    A[i][j] = A[i][k] + A[k][j];//最短路径
//                    path[i][j] = path[k][j];    //路程
//                }
//            }
//        }
//    }
//}
//
//
//
////1. 输出顶点信息：将校园内各景点输出。
////打印地图
//void printMap()
//{
//    cout << "*****************************************************************************" << endl;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            cout << map[i][j];
//        }
//        cout << endl;
//    }
//    cout << "*****************************************************************************" << endl;
//}
//
//
//
////打印两个位置（若两个位置之间有直接路径）的距离 Distance between two points
////2. 输出边的信息：将校园内每两个位置（若两个位置之间有直接路径）的距离输出。
//void printDBTP(Mgraph g)
//{
//    cout << endl;
//    int flag[maxsize][maxsize] = { 0 };
//    int  count = 0;
//    for (int i = 0; i < g.n; i++)
//    {
//        for (int j = 0; j < g.n; j++)
//        {
//            flag[i][j] = 1;
//            if (flag[j][i] == 0) { cout << "{" << g.position[i] << "，" << g.position[j] << "}" << "：" << g.edges[i][j] << "m    ";  count++; }
//            if (count == 3) { cout << endl; count = 0; }
//        }
//    }
//};
//
//
//
////3. 修改：修改两个位置（若两个位置之间有直接路径）的距离；
//Mgraph  f1(Mgraph g)
//{
//    cout << endl;
//    int i, j;
//    char con, con2;
//    //判断起点    
//    cout << "请输入第一个位置的代号：";
//    cin >> con;
//    for (i = 0; i < g.n; i++) { if (con == g.code[i]) { cout << "第一个位置是：" << g.position[i] << endl; break; } }
//    //判断终点
//
//    cout << "请输入第二个位置的代号：";
//    cin >> con2;
//    for (j = 0; j < g.n; j++) { if (con2 == g.code[j]) { cout << "第二个位置是：" << g.position[j] << endl; break; } }
//
//    //设置距离
//    cout << "请设置这两个地点之间的新距离：";
//    int p;
//    if (cin >> p)
//    {
//        g.edges[i][j] = p;
//        g.edges[j][i] = p;
//        printDBTP(g);
//    }
//    return g;
//}
//
//// 4.求最短路径：输出给定两点之间的最短路径的长度及途经的地点
//void f2(Mgraph g) {
//    int i = -1, j = -1, tmp;
//    cout << endl;
//    char sta, end;
//    //判断起点
//    cout << "请输入起点位置的代号：";
//    cin >> sta;
//    cin.clear();//这里清空之前cin缓冲区的数据
//    for (i = 0; i < g.n; i++) { if (sta == g.code[i]) { cout << "起点是：" << g.position[i] << endl; } }
//    //判断终点
//    cout << "请输入起点位置的代号：";
//    cin >> end;
//
//    cin.clear();//这里清空之前cin缓冲区的数据
//    for (j = 0; j < g.n; j++) { if (end == g.code[j]) { cout << "终点是：" << g.position[j] << endl; } };
//
//    int path[maxsize];
//    int dist[maxsize];
//    Dijkstra(g, i, dist, path);
//    stack<string> map; //容器栈
//    for (int j = 0; j < g.n; j++) {
//        tmp = path[j];
//        int flag = 0;
//        while (true)
//        {
//            if (flag == 0) { map.push(g.position[j]); flag = 1; }
//            if (tmp != -1) { map.push(g.position[tmp]); }
//            else { break; }
//            tmp = path[tmp];   //变为 -1 退出程序
//        }
//    }
//    cout << "路线为： ";
//    while (true)
//    {
//        cout << map.top();
//        map.pop();
//        if (!map.empty()) { cout << " => "; }
//        else { break; }
//    }
//    cout << endl;
//    cout << "最短路径长度为： " << dist[j] << "m" << endl;
//}
//// 5.求最短路径：输出任意一点与其他各点的最短路径。
//void f3(Mgraph g)
//{
//    int A[maxsize][maxsize];
//    int path[maxsize][maxsize];
//    Floyd(g, A, path);
//    int i, j, tmp;
//    stack<string> map;
//    for (i = 0; i < g.n; i++)
//    {
//        for (j = 0; j < g.n; j++)
//        {
//            tmp = path[i][j];
//            int flag = 0;
//            while (true)
//            {
//                if (i == j) { break; }
//                if (flag == 0) { map.push(g.position[j]); flag = 1; }
//                if (tmp != -1) { map.push(g.position[tmp]); }
//                else { break; }
//                tmp = path[i][tmp];  //直接-1
//            }
//            if (flag == 0) { continue; }
//            while (true)
//            {
//                cout << map.top();
//                map.pop();
//                if (!map.empty()) { cout << " => "; }
//                else { break; }
//            }
//            cout << "----【路程为】:" << A[i][j] << "m" << endl;
//        }
//        cout << endl;
//    }
//}
//
////主函数
//int main()
//{
//    Mgraph g;
//    int select;
//    while (true)
//    {
//        cout << "\n" << endl;
//        cout << "1. 输出校园内各位置" << endl;
//        cout << "2. 将校园内每两个位置的距离输出" << endl;
//        cout << "3. 修改两个位置的距离" << endl;
//        cout << "4. 输出给定两点之间的最短路径的长度及途经的地点" << endl;
//        cout << "5. 输出任意一点到其他各点的最短路径" << endl;
//        cin >> select;
//        while (cin.get() != '\n') { continue; }
//        if (select == 1) { printMap(); }
//        else if (select == 2) { printDBTP(g); }
//        else if (select == 3) { g = f1(g); }
//        else if (select == 4) { f2(g); }
//        else if (select == 5) { f3(g); }
//        else { break; }
//    }
//    return 0;
//}



//19101314方铭杰
//#include<iostream>
//#include<string>
//#include<stack>
//
//using namespace std;
//
//#define INFINITY 9999
//#define maxsize 11
//
//typedef struct
//{
//    int n = maxsize;
//    string position[maxsize] = { "东大门 ","宿舍楼 ","教学楼1","教学楼2 ","教学楼3 ","图书馆 ","食堂 ","操场 ","活动中心 ","南大门 ","广场 " };
//    char code[maxsize] = { 'a','b','c','d','e','f','g','h','i','j','k' };
//    int edges[maxsize][maxsize] = {
//        {0,100,INFINITY,INFINITY,INFINITY,400,720,300,INFINITY,INFINITY,INFINITY},//东 
//        {100,0,INFINITY,INFINITY,INFINITY,INFINITY,640,550,780,INFINITY,INFINITY},//宿 
//        {INFINITY,INFINITY,0,40,INFINITY,80,INFINITY,INFINITY,200,INFINITY,INFINITY},//1 
//        {INFINITY,INFINITY,40,0,40,140,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},//2
//        {INFINITY,INFINITY,INFINITY,40,0,160,INFINITY,INFINITY,INFINITY,INFINITY,60},//3
//        {400,INFINITY,80,140,160,0,INFINITY,INFINITY,80,350,190},//图 
//        {720,640,INFINITY,INFINITY,INFINITY,INFINITY,0,INFINITY,40,INFINITY,INFINITY},//食 
//        {300,550,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,0,INFINITY,800,INFINITY},//操 
//        {INFINITY,780,200,INFINITY,INFINITY,80,40,INFINITY,0,INFINITY,INFINITY},//活 
//        {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,350,INFINITY,800,INFINITY,0,90},//南 
//        {INFINITY,INFINITY,INFINITY,INFINITY,60,190,INFINITY,INFINITY,INFINITY,90,0},//广    
//    };
//} Mgraph;
//
//string map[10][7] = {
//    {"\t\t\t\t\t||          ","           ","           ","           ","           "," 宿舍楼(b) ","         ||"},
//    {"\t\t\t\t\t||          ","  食堂(g)  ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","活动中心(i)","           ","           ","           ","           ","东大门(a)||"},
//    {"\t\t\t\t\t||教学楼1(c)","           "," 图书馆(f) ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||教学楼2(d)","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||教学楼3(e)","           ","           ","           ","  操场(h)  ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||广场(k)   ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           "," 南大门(j) ","           ","           ","         ||"} };
//
//
//
////迪杰斯特拉 算法 
//void Dijkstra(Mgraph g, int v, int dist[], int path[])
//{
//    int set[maxsize];
//    int i, j, u;
//    for (i = 0; i < g.n; i++)
//    {
//        set[i] = 0;
//        dist[i] = g.edges[v][i];
//        if (dist[i] < INFINITY && i != v) { path[i] = v; }
//        else { path[i] = -1; }
//    }
//    set[v] = 1;
//
//    for (i = 0; i < g.n; i++)
//    {
//        int min = INFINITY;
//        for (j = 0; j < g.n; j++)
//        {
//            if (dist[j] < min && set[j] == 0)
//            {
//                u = j;
//                min = dist[j];
//            }
//        }
//        set[u] = 1;
//        for (j = 0; j < g.n; j++)
//        {
//            if (set[j] == 0 && (dist[j] > g.edges[u][j] + dist[u]))
//            {
//                dist[j] = dist[u] + g.edges[u][j];
//                path[j] = u;
//            }
//        }
//    }
//}
//
//
//
////佛洛依德 算法 
//void Floyd(Mgraph g, int A[][maxsize], int path[][maxsize])
//{
//    int i, j, k;
//    for (i = 0; i < g.n; i++)
//    {
//        for (j = 0; j < g.n; j++)
//        {
//            A[i][j] = g.edges[i][j];
//            if (A[i][j] < INFINITY && i != j) { path[i][j] = i; }
//            else path[i][j] = -1;
//        }
//    }
//    for (k = 0; k < g.n; k++)
//    {
//        for (i = 0; i < g.n; i++)
//        {
//            for (j = 0; j < g.n; j++)
//            {
//                if (A[i][k] + A[k][j] < A[i][j])
//                {
//                    A[i][j] = A[i][k] + A[k][j];
//                    path[i][j] = path[k][j];
//                }
//            }
//        }
//    }
//}
//
//
//
////1. 输出顶点信息：将校园内各景点输出。
////打印地图
//void printMap()
//{
//    cout << "\t\t\t\t\t******************************************************************************" << endl;
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            cout << map[i][j];
//        }
//        cout << endl;
//    }
//    cout << "\t\t\t\t\t******************************************************************************" << endl;
//}
//
//
//
////打印两个位置（若两个位置之间有直接路径）的距离 Distance between two points
////2. 输出边的信息：将校园内每两个位置（若两个位置之间有直接路径）的距离输出。
//void printDBTP(Mgraph g)
//{
//    cout << endl;
//    int flag[maxsize][maxsize] = { 0 };
//    int tmp = 0, count = 0;
//    for (int i = 0; i < g.n; i++)
//    {
//        for (int j = 0; j < g.n; j++)
//        {
//            if (g.edges[i][j] != INFINITY && g.edges[i][j] != 0)
//            {
//                flag[i][j] = 1;
//                tmp = 0;
//                if (flag[j][i] == 0) { cout << "\t\t<" << g.position[i] << "，" << g.position[j] << ">" << "：" << g.edges[i][j] << "m    "; tmp = 1; count++; }
//
//            }
//            if (count == 3) { cout << endl; count = 0; }
//        }
//        if (tmp == 1)
//        {
//            if (count != 0) { cout << endl; }
//            cout << endl;
//            count = 0;
//        }
//    }
//}
//
//
//
////3. 修改：修改两个位置（若两个位置之间有直接路径）的距离；
//Mgraph xiugai(Mgraph g)
//{
//    cout << endl;
//    char array[20];
//    int i, j;
//
//    while (true)
//    {
//        //判断起点
//        while (true)
//        {
//            //array[20]={NULL};
//            cout << "\t\t\t\t\t请输入第一个位置的代号：";
//            cin.get(array, 20);
//            cin.clear();//这里清空之前cin缓冲区的数据
//            while (cin.get() != '\n') { continue; }
//            if (array[1] == '\0')
//            {
//                for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t第一个位置是：" << g.position[i] << endl; break; } }
//                if (i == g.n) { cout << "\t\t\t\t\t在地图上找不到该地点！" << endl; continue; }
//                break;
//            }
//            else { cout << "\t\t\t\t\t错误格式！" << endl; continue; }
//        }
//
//        //判断终点
//        while (true)
//        {
//            //array[20]={NULL};
//            cout << "\t\t\t\t\t请输入第二个位置的代号：";
//            cin.get(array, 20);
//            cin.clear();//这里清空之前cin缓冲区的数据
//            while (cin.get() != '\n') { continue; }
//            if (array[1] == '\0')
//            {
//                for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "\t\t\t\t\t第二个位置是：" << g.position[j] << endl; break; } }
//                if (j == g.n) { cout << "\t\t\t\t\t在地图上找不到该地点！" << endl; continue; }
//                break;
//            }
//            else { cout << "\t\t\t\t\t错误的代号格式！" << endl; continue; }
//        }
//
//        if (g.edges[i][j] == INFINITY)
//        {
//            cout << "\t\t\t\t\t这两个位置没有直接距离！" << endl;
//            continue;
//        }
//
//        while (true)
//        {
//            cout << "\t\t\t\t\t请设置这两个地点之间的新距离：";
//            int p;
//            if (cin >> p)
//            {
//                cin.clear();//这里清空之前cin缓冲区的数据
//                while (cin.get() != '\n') { continue; }
//                g.edges[i][j] = p;
//                g.edges[j][i] = p;
//                break;
//            }
//            else {
//                cin.clear();//这里清空之前cin缓冲区的数据
//                while (cin.get() != '\n') { continue; }
//                cout << "\t\t\t\t\t输入的数据类型不正确！" << endl;
//            }
//        }
//        break;
//    }
//    return g;
//}
//
//
//
////4.1 求最短路径：输出给定两点之间的最短路径的长度及途经的地点
//void zuiduan(Mgraph g) {
//    int i = -1, j = -1, tmp;
//    cout << endl;
//    char array[20];
//
//    //判断起点
//    while (true)
//    {
//        //array[20]={NULL};
//        cout << "\t\t\t\t\t请输入起点位置的代号：";
//        cin.get(array, 20);
//        cin.clear();//这里清空之前cin缓冲区的数据
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t起点是：" << g.position[i] << endl; break; } }
//            if (i == g.n) { cout << "\t\t\t\t\t在地图上找不到该地点！" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t错误的代号格式！" << endl; continue; }
//    }
//
//    //判断终点
//    while (true)
//    {
//        //array[20]={NULL};
//        cout << "\t\t\t\t\t请输入终点位置的代号：";
//        cin.get(array, 20);
//        cin.clear();//这里清空之前cin缓冲区的数据
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "\t\t\t\t\t终点是：" << g.position[j] << endl; break; } }
//            if (j == g.n) { cout << "\t\t\t\t\t在地图上找不到该地点！" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t错误的代号格式！" << endl; continue; }
//    }
//
//    int path[maxsize];
//    int dist[maxsize];
//    Dijkstra(g, i, dist, path);
//    stack<string> map;
//
//    tmp = path[j];
//    int flag = 0;
//    while (true)
//    {
//        if (flag == 0) { map.push(g.position[j]); flag = 1; }
//        if (tmp != -1) { map.push(g.position[tmp]); }
//        else { break; }
//        tmp = path[tmp];
//    }
//    cout << "\t\t\t\t\t路线为： ";
//    while (true)
//    {
//        cout << map.top();
//        map.pop();
//        if (!map.empty()) { cout << " => "; }
//        else { break; }
//    }
//    cout << endl;
//    cout << "\t\t\t\t\t路程为： " << dist[j] << "m" << endl;
//}
//
//
//
////4.2 求最短路径：输出指定一点与其他各点的最短路径。
//void zhidingduan(Mgraph g)
//{
//    char array[20];
//    int i;
//    //判断起点
//    while (true)
//    {
//        cout << "\t\t\t\t\t请输入你想查询的出发点代号：";
//        cin.get(array, 20);
//        cin.clear();//这里清空之前cin缓冲区的数据
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t出发点是：" << g.position[i] << endl; break; } }
//            if (i == g.n) { cout << "\t\t\t\t\t在地图上找不到该地点！" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t错误的代号格式！" << endl; continue; }
//    }
//
//    int path[maxsize];
//    int dist[maxsize];
//    Dijkstra(g, i, dist, path);
//    int j, tmp;
//    stack<string> map;
//    for (j = 0; j < g.n; j++)
//    {
//        tmp = path[j];
//        int flag = 0;
//        while (true)
//        {
//            if (i == j) { break; }
//            if (flag == 0) { map.push(g.position[j]); flag = 1; }
//            if (tmp != -1) { map.push(g.position[tmp]); }
//            else { break; }
//            tmp = path[tmp];
//        }
//        if (flag == 0) { continue; }
//        cout << "\t\t\t\t\t";
//        while (true)
//        {
//            cout << map.top();
//            cout << "【路程为】:" << dist[tmp - 1] << "m" << endl;
//            map.pop();
//            if (!map.empty()) { cout << " => "; }
//
//            else { break; }
//
//        }
//
//        cout << "----【路程为】:" << dist[j] << "m" << endl;
//    }
//}
//
//
//
////4.3 求最短路径：输出任意一点与其他各点的最短路径。
//void renyiduan(Mgraph g)
//{
//    int A[maxsize][maxsize];
//    int path[maxsize][maxsize];
//    Floyd(g, A, path);
//    int i, j, tmp;
//    stack<string> map;
//    for (i = 0; i < g.n; i++)
//    {
//        for (j = 0; j < g.n; j++)
//        {
//            tmp = path[i][j];
//            int flag = 0;
//            while (true)
//            {
//                if (i == j) { break; }
//                if (flag == 0) { map.push(g.position[j]); flag = 1; }
//                if (tmp != -1) { map.push(g.position[tmp]); }
//                else { break; }
//                tmp = path[i][tmp];
//            }
//            if (flag == 0) { continue; }
//            cout << "\t\t\t\t\t";
//            while (true)
//            {
//                cout << map.top();
//                map.pop();
//                if (!map.empty()) { cout << " => "; }
//                else { break; }
//            }
//            cout << "----【路程为】:" << A[i][j] << "m" << endl;
//        }
//        cout << endl;
//    }
//}
//
//
//
////主函数
//int main()
//{
//    Mgraph g;
//    //printMap();
//    system("mode con cols=150 lines=200");
//    cout << "\t\t\t\t\t         *-----------------科大校园导航系统-------------------*" << endl;
//    int flag;
//    while (true)
//    {
//        cout << "\n" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>1. 输出校园内各位置                                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>2. 将校园内每两个位置（若两个位置之间有直接路径）的距离输出<<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>3. 修改两个位置（若两个位置之间有直接路径）的距离          <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>4. 输出给定两点之间的最短路径的长度及途经的地点            <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>5. 输出指定一点到其他各点的最短路径                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>6. 输出任意一点到其他各点的最短路径                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>0. 退出程序                                                <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cin >> flag;
//        cin.clear();//这里清空之前cin缓冲区的数据
//        while (cin.get() != '\n') { continue; }
//        if (flag == 1) { system("cls"); printMap(); }
//        else if (flag == 2) { system("cls"); printMap(); printDBTP(g); }
//        else if (flag == 3) { system("cls"); printMap(); g = xiugai(g); }
//        else if (flag == 4) { system("cls"); printMap(); zuiduan(g); }
//        else if (flag == 5) { system("cls"); printMap(); zhidingduan(g); }
//        else if (flag == 6) { system("cls"); printMap(); renyiduan(g); }
//        else { break; }
//    }
//    return 0;
//}
//




#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;

#define MaxVexNum 50 //最大顶点个数
#define MaxInt 32767 //代表点与点之间无直接路径
#define MaxEdgeNum 50 //最大边的条数

int pathmatirx[MaxVexNum][MaxVexNum];//记录对应点的最小路径的前驱点
int shortPath[MaxVexNum][MaxVexNum];//记录顶点间的最小路径值
int dist[MaxVexNum]; //存储最短距离
int path[MaxVexNum]; //记录途径的点前驱结点

//图的结构体
typedef struct AMGraph {
	int vexs[MaxVexNum];//顶点表
	int arcs[MaxVexNum][MaxVexNum];//邻接矩阵表
	string name[MaxVexNum]; //景点名表
	int vexnum, edgenum;//顶点数，边数
}AMGraph;

AMGraph g; //创建图变量
void createGraph(AMGraph& g) { //创建无向图
	g.vexnum = 10;
	g.edgenum = 10;
	//景点名
	g.name[0] = "第三食堂";
	g.name[1] = "15公寓";
	g.name[2] = "8号楼";
	g.name[3] = "第二食堂";
	g.name[4] = "快递点";
	g.name[5] = "逸夫楼";
	g.name[6] = "中院校门";
	g.name[7] = "西院澡堂";
	g.name[8] = "言泉楼";
	g.name[9] = "西院校门";

	//将景点名转化为下标
	for (int i = 0; i < g.vexnum; i++) {
		g.vexs[i] = i;
	}
	//初始化邻接矩阵
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = 0; j < g.vexnum; j++) {
			g.arcs[i][j] = MaxInt;
			if (i == j) g.arcs[i][j] = 0;
		}
	}
	//赋权值
	g.arcs[0][1] = g.arcs[1][0] = 1;
	g.arcs[0][7] = g.arcs[7][0] = 2;
	g.arcs[0][8] = g.arcs[8][0] = 3;
	g.arcs[1][3] = g.arcs[3][1] = 11;
	g.arcs[1][4] = g.arcs[4][1] = 13;
	g.arcs[1][8] = g.arcs[8][1] = 2;
	g.arcs[2][7] = g.arcs[7][2] = 5;
	g.arcs[2][8] = g.arcs[8][2] = 4;
	g.arcs[2][9] = g.arcs[9][2] = 3;
	g.arcs[3][4] = g.arcs[4][3] = 5;
	g.arcs[4][5] = g.arcs[5][4] = 6;
	g.arcs[5][6] = g.arcs[6][5] = 12;
	g.arcs[5][8] = g.arcs[8][5] = 20;
	g.arcs[6][9] = g.arcs[9][6] = 13;
	g.arcs[7][8] = g.arcs[8][7] = 2;
	g.arcs[7][9] = g.arcs[9][7] = 10;
	g.arcs[8][9] = g.arcs[9][8] = 8;
}
bool isNum(string str) {
	stringstream sin(str);
	double d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;
	return true;
}

//寻找景点所对应的下标
int Search(string s) {
	if (isNum(s)) {
		int n = 0;
		for (int i = 0; i < s.length(); i++) {
			n = n * 10 + s[i] - '0';
		}
		if (n >= 0 && n <= (g.vexnum - 1))
			return n;
		else {
			cout << "地图中无该景点" << endl;
			return -1;
		}
	}
	else {
		for (int i = 0; i < g.vexnum; i++) {
			if (s == g.name[i]) {
				return i;
			}
		}
		cout << "地图中无该景点" << endl;
		return -1;
	}
}

void Print_vexs() {
	//打印所有顶点信息
	cout << "   地图点为：";
	for (int i = 0; i < g.vexnum; i++) cout << "(" << i << ")" << g.name[i] << " ";
	cout << endl << endl;
}

//打印每两个位置之间的距离(若两个位置之间有直接路径)
void Print_arcs(AMGraph g) {
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = i + 1; j < g.vexnum; j++) {
			if (g.arcs[i][j] != MaxInt) {
				cout << "   " << g.name[i] << "->" << g.name[j] << "的距离为：" << g.arcs[i][j] << endl;
			}
		}
	}
	cout << endl;
}

//修改两个位置之间的距离(若两个位置之间有直接路径)
void Update_arcs() {
	string start, end;
	int distance;
	cout << "修改两个位置之间的距离(若两个位置之间有直接路径)" << endl;
	while (true) {
		cout << "起始点(地点名或标号): "; cin >> start; //输入修改起点
		cout << "终止点(地点名或标号): "; cin >> end; //输入修改终点
		if (g.arcs[Search(start)][Search(end)] != 0 && g.arcs[Search(start)][Search(end)] != MaxInt) {
			cout << "新的距离: "; cin >> distance; // 输入修改距离
			break;
		}
		else {
			cout << "这两个位置之间没有直接路径，请重新输入！" << endl;
			continue;
		}
	}
	g.arcs[Search(start)][Search(end)] = g.arcs[Search(end)][Search(start)] = distance; //修改距离
	cout << "修改后每两个位置之间的距离(若两个位置之间有之间路径)" << endl;
	Print_arcs(g); //重新打印输出边的信息
}

//Dijkstra算法，求最短路径
void Dijkstra(AMGraph g, int dist[], int path[], string begin, string end) {
	int start = Search(begin); //起点坐标
	int over = Search(end); //终点坐标
	int n = g.vexnum, v = 0;
	int set[10] = {}; //set数组用于记录该顶点是否加入n
	//第一步：初始化
	for (int i = 0; i < n; i++) {
		set[i] = 0;
		dist[i] = g.arcs[start][i];
		if (dist[i] < MaxInt) {//若距离小于MaxInt说明两点之间有路可通
			path[i] = start;//则更新路径i的前驱为start
		}
		else {
			path[i] = -1; //表示这两点之间没有边
		}
	}
	set[start] = 1;//将初始顶点并入
	path[start] = -1;//初始顶点没有前驱

	//第二步
	for (int i = 1; i < n; i++) {//共n-1个顶点
		int min = MaxInt;
		//第二步：从i=1开始依次选一个距离顶点的最近顶点
		for (int j = 0; j < n; j++) {
			if (set[j] == 0 && dist[j] < min) {
				v = j;
				min = dist[j];
			}
		}
		//将顶点并入
		set[v] = 1;
		//第三步：在将新结点并入后，其初始顶点start到各顶点的距离将会发生变化，所以需要更新dist[]数组
		for (int j = 0; j < n; j++) {
			if (set[j] == 0 && dist[v] + g.arcs[v][j] < dist[j]) {
				dist[j] = dist[v] + g.arcs[v][j];
				path[j] = v;
			}
		}
	}
	//格式化输出
	cout << "\n" << "   " << g.name[start] << "到" << g.name[over] << "的最短路径为: " << dist[over];
	cout << "\n   路径为: " << g.name[over];
	int a = path[over];
	if (over > start) {
		for (int i = over; i >= start; i--) {
			cout << "<-" << g.name[a];
			a = path[a];
			if (a == -1) break;
		}
	}
	else if (over < start) {
		for (int i = over; i <= start; i++) {
			cout << "<-" << g.name[a];
			a = path[a];
			if (a == -1) break;
		}
	}
	cout << endl << endl;
}

void Floyd(AMGraph g, int P[MaxVexNum][MaxVexNum], int D[MaxVexNum][MaxVexNum]) {
	int v, w, k;
	//初始化floyd算法的两个矩阵
	for (v = 0; v < g.vexnum; v++) {
		for (w = 0; w < g.vexnum; w++) {
			D[v][w] = g.arcs[v][w];
			P[v][w] = w;
		}
	}
	//这里是弗洛伊德算法的核心部分
	//k为中间点
	for (k = 0; k < g.vexnum; k++) {
		//v为起点
		for (v = 0; v < g.vexnum; v++) {
			//w为终点
			for (w = 0; w < g.vexnum; w++) {
				if (D[v][w] > (D[v][k] + D[k][w])) {
					D[v][w] = D[v][k] + D[k][w];//更新最小路径
					P[v][w] = P[v][k];//更新最小路径中间顶点
				}
			}
		}
	}
	cout << "输入源点: ";
	string name;
	cin >> name;
	v = Search(name);
	//求源点v到其它所有点的最小路径
	for (int w = 0; w < 10; w++) {
		if (v == w) continue;
		cout << endl << "   " << g.name[v] << "->" << g.name[w] << "的最小路径为：" << D[v][w] << endl;
		k = P[v][w];
		cout << "   path: " << g.name[v];//打印起点
		while (k != w) {
			cout << "->" << g.name[k];//打印中间点
			k = P[k][w];
		}
		cout << "->" << g.name[w] << endl;
	}
}

int main() {
	createGraph(g);
	string start, end;
	int n;
	while (true) {
		cout << endl; //界面输出
		cout << "   *****************************************************" << endl;
		cout << "   *********          校园导航系统             *********" << endl;
		cout << "   *****************************************************" << endl;
		cout << "   *********  1.顶点信息     2.边的信息        *********" << endl;
		cout << "   *********  3.修改两个位置之间的距离         *********" << endl;
		cout << "   *********  4.求最短路径(Dijkstra)           *********" << endl;
		cout << "   *********  5.任意点与其它点的最短路径(Floyd)*********" << endl;
		cout << "   *********  6.退出   请输入对应序号进行操作! *********" << endl;
		cout << "   *****************************************************" << endl;
		cout << "输入对应标号：";
		cin >> n;
		if (n > 0 && n <= 6) {
			switch (n) { //功能选择
			case 1:
				Print_vexs();
				break;
			case 2:
				Print_arcs(g);
				break;
			case 3:
				Update_arcs();
				break;
			case 4:
				cout << "起始点(地点名或标号)："; cin >> start;
				while (Search(start) == -1) {
					cout << "起始点(地点名或标号)："; cin >> start;
				}
				cout << "终止点(地点名或标号)："; cin >> end;
				while (Search(end) == -1) {
					cout << "终止点(地点名或标号)："; cin >> end;
				}
				Dijkstra(g, dist, path, start, end);
				break;
			case 5:
				Floyd(g, pathmatirx, shortPath);
				break;
			case 6:

			default:
				return 0;
			}
		}
		else {
			cout << "没有该标号对应的功能！请重新输入！" << endl;
			continue;
		}
	}
}                                      
