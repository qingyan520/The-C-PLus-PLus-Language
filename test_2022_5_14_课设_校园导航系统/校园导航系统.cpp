
//191302������
//#include<iostream> 
//using namespace std;
//#include<stdlib.h> 
//#include<conio.h> 
//#include<malloc.h> 
//#include<string.h>
//#define MAX 1000 //����#define 
//#define LENGTH 11 
//#define value int
//typedef struct {
//
//	char name[30]; //�������
//	int num; //�����
//}
//VEXTYPE; //�������ͱ��� 
//typedef struct {
//	VEXTYPE vexs[LENGTH];//���
//	value arcs[LENGTH][LENGTH];//�ڽӾ���߱�
//	int vexnum, arcnum;//����������·��
//}
//MGraph; //�ڽӾ���
//MGraph b;//����ͼ
//MGraph InitGraph() {
//	int i, j;
//	MGraph G;
//	G.vexnum = 11; // ��ʼ�����Ϊ 11 ����ͼ�Ķ�����
//	G.arcnum = 55; // ��ʼ������·����Ϊ 55 ����ͼ��������
//	for (i = 0; i < G.vexnum; i++) G.vexs[i].num = i;
//	strcpy(G.vexs[0].name, "	У��");
//	strcpy(G.vexs[1].name, " 	13��Ԣ");
//	strcpy(G.vexs[2].name, " 	14��Ԣ");
//	strcpy(G.vexs[3].name, "	�ٳ�");
//	strcpy(G.vexs[4].name, "	���");
//	strcpy(G.vexs[5].name, " 	����");
//	strcpy(G.vexs[6].name, " 	11��¥");
//	strcpy(G.vexs[7].name, " 	10��¥");
//	strcpy(G.vexs[8].name, " 	9��¥");
//	strcpy(G.vexs[9].name, " 	8��¥");
//	strcpy(G.vexs[10].name, " 	ԡ��");
//	for (i = 0; i < G.vexnum; i++)
//
//		for (j = 0; j < G.vexnum; j++)
//			G.arcs[i][j] = MAX;//�������ڶ�������Ϊ���������
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
//void Menu() { // ��������ѡ��˵�
//	cout << "  ****** ���Ƽ���ѧ̩��У����Է ******\n";
//	cout << "* 1--- ���ѧУ�ڸ��ص�	           	*\n";
//	cout << "* 2--- ���ÿ����ֱ�������ص�ľ���     *\n";
//	cout << "* 3--- �޸������ص����	         	*\n";
//	cout << "* 4--- ���ص�֮�����·��	     	*\n";
//	cout << "* 0--- �˳�                      	*\n";
//	cout << " ***************************************\n";
//}
//void PutOutVex(MGraph* G) { // ���� 1 ���ѧУ�ڸ��ص�
//	for (int i = 0; i < G->vexnum; i++)
//		cout << G->vexs[i].name << " " << endl;
//}
//
//void PutOutArc(MGraph* G) { // ���� 2	���ÿ����ֱ�������ص�ľ���
//	for (int i = 0; i < G->vexnum; i++)
//		for (int j = 0; j < G->vexnum; j++)
//			if (G->arcs[i][j] < MAX) {
//				cout << G->vexs[i].name << "   ---->" << G->vexs[j].name << " �ľ���Ϊ " << G->arcs[i][j] << endl;
//			}
//}
//
//void Change(MGraph* G) { // ���� 3 �޸ģ��޸������ص����
//	int v0, v1, length;
//	cout << "\t\t\t\t\t * *              	*�ص��б�* 	              * *\n";
//	cout << "\t\t\t\t\t ********************************************************\n";
//	cout << "\t\t\t\t\t * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <0> У��     <1>13��Ԣ     <2>14��Ԣ           * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <3> �ٳ�     <4>���       <5>����           * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <6>11 ��¥   <7>10��¥     <8>9��¥            * *";
//	cout << "\t\t\t\t\t                 * *                                                  * *\n";
//	cout << "\t\t\t\t\t * *   <9>8 ��¥    <10>ԡ��	                      * *\n";
//	cout << "\t\t\t\t\t * *                                                  * *\n";
//
//	cout << "\t\t\t\t\t ********************************************************\n";
//	cout << " �޸ģ���������ʼ����:\n"; cin >> v0;
//	if (v0<0 || v0>G->vexnum) {
//		cout << " �˵㲻����! ���������붥��:"; cin >> v0;
//	}
//	cout << " �������������:\n"; cin >> v1;
//	if (v1<0 || v1>G->vexnum) {
//		cout << " �˵㲻����! ���������붥��:"; cin >> v1;
//	}
//	cout << " �������:"; cin >> length;
//	G->arcs[v0][v1] = G->arcs[v1][v0] = length;
//	cout << " �޸ĳɹ�\n";
//}
//
//
//void Dijkstra(MGraph* G) { // ���� 4. �����·�� �����ص�֮�����·�� ʹ��Dijkstra �㷨������·��
//	int v, w, i, min, t = 0, x, v0, v1;
//	int final[20], D[20], p[20][20];
//	cout << "\t\t\t\t\t * *               	*�ص��б�*              	* *\n";
//	cout << "\t\t\t\t\t *";
//	cout << "*********************************************************\n";
//	cout << "\t\t\t\t\t * *                                                   	* *\n";
//	cout << "\t\t\t\t\t * *       <0> У��	<1>13��Ԣ	<2>14��Ԣ	* *";
//
//	cout << "\t\t\t\t\t                 * *                                             	* *\n";
//	cout << "\t\t\t\t\t * *       <3> �ٳ�	<4>���	    <5>����         	* *";
//
//	cout << "\t\t\t\t\t 		 * *                                         	        * *\n";
//	cout << "\t\t\t\t\t * *       <6>11 ��¥	<7>10��¥	<8>9��¥	* *";
//
//	cout << "\t\t\t\t\t 		 * *                                                    * *\n";
//	cout << "\t\t\t\t\t * *       <9>8 ��¥	<10>ԡ��	         	* *\n";
//	cout << "\t\t\t\t\t * *                                                   	* *\n";
//	cout << "\t\t\t\t\t *";
//	cout << "*********************************************************\n";
//	cout << " ��������ʼ����:\n"; cin >> v0;
//	if (v0<0 || v0>G->vexnum) {
//		cout << " �˵㲻����! ���������붥��:"; cin >> v0;
//	}
//	cout << " �������������:\n"; cin >> v1;
//	if (v1<0 || v1>G->vexnum) {
//		cout << " �˵㲻����! ���������붥��:"; cin >> v1;
//	}
//	for (v = 0; v < G->vexnum; v++) { //�Ͻ�˹�����㷨 
//		final[v] = 0;
//		D[v] = G->arcs[v0][v];//��v0�������յ�����·�����ȳ�ʼ��
//		for (w = 0; w < G->vexnum; w++)
//			p[v][w] = 0;
//		if (D[v] < MAX) {
//			p[v][v0] = 1;
//			p[v][v] = 1;
//		}
//	}
//	D[v0] = 0; //Դ�㵽Դ��ľ���Ϊ0 
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
//	cout << "��" << G->vexs[v0].name << " ��" << G->vexs[v1].name << "�����·������Ϊ�� " << D[v1] << endl;
//	cout << " ;���ĵص㣺 " << endl;
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


//19101308��ѧ�
//#include<iostream>
//#include<string>
//#include<stack>      //ջ
//using namespace std;
//
//#define dis 9999
//#define maxsize 10
////����ṹ��
//typedef struct school
//{
//    float n = maxsize;
//    string position[maxsize] = { "��Ժ��� ","ʳ�� ","15��Ԣ","��� ","��ѧ¥ ","ͼ��� ","8��¥","9��¥","10��¥","11��¥", };
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
//    {"  8��¥(7)    "," 9��¥(8)        ","      ��ѧ¥(5)     ","    10��¥(9)     "," 11��¥(10)       ","         ","         "},
//    {"         ","         ","         "," ���(4)   ","      ʳ��(2)       ","         ","         "},
//    {"         ","         ","         ","         ","       15��Ԣ(3)      ","         ","                     ��Ժ���(1)  "},
//    {"         ","    ͼ���(6)       ","         ","         ","         ","         ","         "},
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
//        dist[i] = g.edges[v][i];  //��ֵ����
//        if (dist[i] < dis && i != v) { path[i] = v; }
//        else { path[i] = -1; }
//    }
//    set[v] = 1;      //�����жϺ����ȥ��ʼ��
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
//        set[u] = 1; //��̵� u 
//
//        for (j = 0; j < g.n; j++)
//        {
//            if (set[j] == 0 && (dist[j] > g.edges[u][j] + dist[u]))
//            {
//                dist[j] = dist[u] + g.edges[u][j];                 //���¸�ֵ���� ���ֱ�ӵ���ľ�����Ƶľ������ô���¸�ֵ
//                path[j] = u;
//            }
//        }
//    }
//}
//
////Floyd ����������ά����
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
//                    A[i][j] = A[i][k] + A[k][j];//���·��
//                    path[i][j] = path[k][j];    //·��
//                }
//            }
//        }
//    }
//}
//
//
//
////1. ���������Ϣ����У԰�ڸ����������
////��ӡ��ͼ
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
////��ӡ����λ�ã�������λ��֮����ֱ��·�����ľ��� Distance between two points
////2. ����ߵ���Ϣ����У԰��ÿ����λ�ã�������λ��֮����ֱ��·�����ľ��������
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
//            if (flag[j][i] == 0) { cout << "{" << g.position[i] << "��" << g.position[j] << "}" << "��" << g.edges[i][j] << "m    ";  count++; }
//            if (count == 3) { cout << endl; count = 0; }
//        }
//    }
//};
//
//
//
////3. �޸ģ��޸�����λ�ã�������λ��֮����ֱ��·�����ľ��룻
//Mgraph  f1(Mgraph g)
//{
//    cout << endl;
//    int i, j;
//    char con, con2;
//    //�ж����    
//    cout << "�������һ��λ�õĴ��ţ�";
//    cin >> con;
//    for (i = 0; i < g.n; i++) { if (con == g.code[i]) { cout << "��һ��λ���ǣ�" << g.position[i] << endl; break; } }
//    //�ж��յ�
//
//    cout << "������ڶ���λ�õĴ��ţ�";
//    cin >> con2;
//    for (j = 0; j < g.n; j++) { if (con2 == g.code[j]) { cout << "�ڶ���λ���ǣ�" << g.position[j] << endl; break; } }
//
//    //���þ���
//    cout << "�������������ص�֮����¾��룺";
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
//// 4.�����·���������������֮������·���ĳ��ȼ�;���ĵص�
//void f2(Mgraph g) {
//    int i = -1, j = -1, tmp;
//    cout << endl;
//    char sta, end;
//    //�ж����
//    cout << "���������λ�õĴ��ţ�";
//    cin >> sta;
//    cin.clear();//�������֮ǰcin������������
//    for (i = 0; i < g.n; i++) { if (sta == g.code[i]) { cout << "����ǣ�" << g.position[i] << endl; } }
//    //�ж��յ�
//    cout << "���������λ�õĴ��ţ�";
//    cin >> end;
//
//    cin.clear();//�������֮ǰcin������������
//    for (j = 0; j < g.n; j++) { if (end == g.code[j]) { cout << "�յ��ǣ�" << g.position[j] << endl; } };
//
//    int path[maxsize];
//    int dist[maxsize];
//    Dijkstra(g, i, dist, path);
//    stack<string> map; //����ջ
//    for (int j = 0; j < g.n; j++) {
//        tmp = path[j];
//        int flag = 0;
//        while (true)
//        {
//            if (flag == 0) { map.push(g.position[j]); flag = 1; }
//            if (tmp != -1) { map.push(g.position[tmp]); }
//            else { break; }
//            tmp = path[tmp];   //��Ϊ -1 �˳�����
//        }
//    }
//    cout << "·��Ϊ�� ";
//    while (true)
//    {
//        cout << map.top();
//        map.pop();
//        if (!map.empty()) { cout << " => "; }
//        else { break; }
//    }
//    cout << endl;
//    cout << "���·������Ϊ�� " << dist[j] << "m" << endl;
//}
//// 5.�����·�����������һ����������������·����
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
//                tmp = path[i][tmp];  //ֱ��-1
//            }
//            if (flag == 0) { continue; }
//            while (true)
//            {
//                cout << map.top();
//                map.pop();
//                if (!map.empty()) { cout << " => "; }
//                else { break; }
//            }
//            cout << "----��·��Ϊ��:" << A[i][j] << "m" << endl;
//        }
//        cout << endl;
//    }
//}
//
////������
//int main()
//{
//    Mgraph g;
//    int select;
//    while (true)
//    {
//        cout << "\n" << endl;
//        cout << "1. ���У԰�ڸ�λ��" << endl;
//        cout << "2. ��У԰��ÿ����λ�õľ������" << endl;
//        cout << "3. �޸�����λ�õľ���" << endl;
//        cout << "4. �����������֮������·���ĳ��ȼ�;���ĵص�" << endl;
//        cout << "5. �������һ�㵽������������·��" << endl;
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



//19101314������
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
//    string position[maxsize] = { "������ ","����¥ ","��ѧ¥1","��ѧ¥2 ","��ѧ¥3 ","ͼ��� ","ʳ�� ","�ٳ� ","����� ","�ϴ��� ","�㳡 " };
//    char code[maxsize] = { 'a','b','c','d','e','f','g','h','i','j','k' };
//    int edges[maxsize][maxsize] = {
//        {0,100,INFINITY,INFINITY,INFINITY,400,720,300,INFINITY,INFINITY,INFINITY},//�� 
//        {100,0,INFINITY,INFINITY,INFINITY,INFINITY,640,550,780,INFINITY,INFINITY},//�� 
//        {INFINITY,INFINITY,0,40,INFINITY,80,INFINITY,INFINITY,200,INFINITY,INFINITY},//1 
//        {INFINITY,INFINITY,40,0,40,140,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},//2
//        {INFINITY,INFINITY,INFINITY,40,0,160,INFINITY,INFINITY,INFINITY,INFINITY,60},//3
//        {400,INFINITY,80,140,160,0,INFINITY,INFINITY,80,350,190},//ͼ 
//        {720,640,INFINITY,INFINITY,INFINITY,INFINITY,0,INFINITY,40,INFINITY,INFINITY},//ʳ 
//        {300,550,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,0,INFINITY,800,INFINITY},//�� 
//        {INFINITY,780,200,INFINITY,INFINITY,80,40,INFINITY,0,INFINITY,INFINITY},//�� 
//        {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,350,INFINITY,800,INFINITY,0,90},//�� 
//        {INFINITY,INFINITY,INFINITY,INFINITY,60,190,INFINITY,INFINITY,INFINITY,90,0},//��    
//    };
//} Mgraph;
//
//string map[10][7] = {
//    {"\t\t\t\t\t||          ","           ","           ","           ","           "," ����¥(b) ","         ||"},
//    {"\t\t\t\t\t||          ","  ʳ��(g)  ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","�����(i)","           ","           ","           ","           ","������(a)||"},
//    {"\t\t\t\t\t||��ѧ¥1(c)","           "," ͼ���(f) ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||��ѧ¥2(d)","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||��ѧ¥3(e)","           ","           ","           ","  �ٳ�(h)  ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||�㳡(k)   ","           ","           ","           ","           ","           ","         ||"},
//    {"\t\t\t\t\t||          ","           ","           "," �ϴ���(j) ","           ","           ","         ||"} };
//
//
//
////�Ͻ�˹���� �㷨 
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
////�������� �㷨 
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
////1. ���������Ϣ����У԰�ڸ����������
////��ӡ��ͼ
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
////��ӡ����λ�ã�������λ��֮����ֱ��·�����ľ��� Distance between two points
////2. ����ߵ���Ϣ����У԰��ÿ����λ�ã�������λ��֮����ֱ��·�����ľ��������
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
//                if (flag[j][i] == 0) { cout << "\t\t<" << g.position[i] << "��" << g.position[j] << ">" << "��" << g.edges[i][j] << "m    "; tmp = 1; count++; }
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
////3. �޸ģ��޸�����λ�ã�������λ��֮����ֱ��·�����ľ��룻
//Mgraph xiugai(Mgraph g)
//{
//    cout << endl;
//    char array[20];
//    int i, j;
//
//    while (true)
//    {
//        //�ж����
//        while (true)
//        {
//            //array[20]={NULL};
//            cout << "\t\t\t\t\t�������һ��λ�õĴ��ţ�";
//            cin.get(array, 20);
//            cin.clear();//�������֮ǰcin������������
//            while (cin.get() != '\n') { continue; }
//            if (array[1] == '\0')
//            {
//                for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t��һ��λ���ǣ�" << g.position[i] << endl; break; } }
//                if (i == g.n) { cout << "\t\t\t\t\t�ڵ�ͼ���Ҳ����õص㣡" << endl; continue; }
//                break;
//            }
//            else { cout << "\t\t\t\t\t�����ʽ��" << endl; continue; }
//        }
//
//        //�ж��յ�
//        while (true)
//        {
//            //array[20]={NULL};
//            cout << "\t\t\t\t\t������ڶ���λ�õĴ��ţ�";
//            cin.get(array, 20);
//            cin.clear();//�������֮ǰcin������������
//            while (cin.get() != '\n') { continue; }
//            if (array[1] == '\0')
//            {
//                for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "\t\t\t\t\t�ڶ���λ���ǣ�" << g.position[j] << endl; break; } }
//                if (j == g.n) { cout << "\t\t\t\t\t�ڵ�ͼ���Ҳ����õص㣡" << endl; continue; }
//                break;
//            }
//            else { cout << "\t\t\t\t\t����Ĵ��Ÿ�ʽ��" << endl; continue; }
//        }
//
//        if (g.edges[i][j] == INFINITY)
//        {
//            cout << "\t\t\t\t\t������λ��û��ֱ�Ӿ��룡" << endl;
//            continue;
//        }
//
//        while (true)
//        {
//            cout << "\t\t\t\t\t�������������ص�֮����¾��룺";
//            int p;
//            if (cin >> p)
//            {
//                cin.clear();//�������֮ǰcin������������
//                while (cin.get() != '\n') { continue; }
//                g.edges[i][j] = p;
//                g.edges[j][i] = p;
//                break;
//            }
//            else {
//                cin.clear();//�������֮ǰcin������������
//                while (cin.get() != '\n') { continue; }
//                cout << "\t\t\t\t\t������������Ͳ���ȷ��" << endl;
//            }
//        }
//        break;
//    }
//    return g;
//}
//
//
//
////4.1 �����·���������������֮������·���ĳ��ȼ�;���ĵص�
//void zuiduan(Mgraph g) {
//    int i = -1, j = -1, tmp;
//    cout << endl;
//    char array[20];
//
//    //�ж����
//    while (true)
//    {
//        //array[20]={NULL};
//        cout << "\t\t\t\t\t���������λ�õĴ��ţ�";
//        cin.get(array, 20);
//        cin.clear();//�������֮ǰcin������������
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t����ǣ�" << g.position[i] << endl; break; } }
//            if (i == g.n) { cout << "\t\t\t\t\t�ڵ�ͼ���Ҳ����õص㣡" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t����Ĵ��Ÿ�ʽ��" << endl; continue; }
//    }
//
//    //�ж��յ�
//    while (true)
//    {
//        //array[20]={NULL};
//        cout << "\t\t\t\t\t�������յ�λ�õĴ��ţ�";
//        cin.get(array, 20);
//        cin.clear();//�������֮ǰcin������������
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "\t\t\t\t\t�յ��ǣ�" << g.position[j] << endl; break; } }
//            if (j == g.n) { cout << "\t\t\t\t\t�ڵ�ͼ���Ҳ����õص㣡" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t����Ĵ��Ÿ�ʽ��" << endl; continue; }
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
//    cout << "\t\t\t\t\t·��Ϊ�� ";
//    while (true)
//    {
//        cout << map.top();
//        map.pop();
//        if (!map.empty()) { cout << " => "; }
//        else { break; }
//    }
//    cout << endl;
//    cout << "\t\t\t\t\t·��Ϊ�� " << dist[j] << "m" << endl;
//}
//
//
//
////4.2 �����·�������ָ��һ����������������·����
//void zhidingduan(Mgraph g)
//{
//    char array[20];
//    int i;
//    //�ж����
//    while (true)
//    {
//        cout << "\t\t\t\t\t�����������ѯ�ĳ�������ţ�";
//        cin.get(array, 20);
//        cin.clear();//�������֮ǰcin������������
//        while (cin.get() != '\n') { continue; }
//        if (array[1] == '\0')
//        {
//            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "\t\t\t\t\t�������ǣ�" << g.position[i] << endl; break; } }
//            if (i == g.n) { cout << "\t\t\t\t\t�ڵ�ͼ���Ҳ����õص㣡" << endl; continue; }
//            break;
//        }
//        else { cout << "\t\t\t\t\t����Ĵ��Ÿ�ʽ��" << endl; continue; }
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
//            cout << "��·��Ϊ��:" << dist[tmp - 1] << "m" << endl;
//            map.pop();
//            if (!map.empty()) { cout << " => "; }
//
//            else { break; }
//
//        }
//
//        cout << "----��·��Ϊ��:" << dist[j] << "m" << endl;
//    }
//}
//
//
//
////4.3 �����·�����������һ����������������·����
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
//            cout << "----��·��Ϊ��:" << A[i][j] << "m" << endl;
//        }
//        cout << endl;
//    }
//}
//
//
//
////������
//int main()
//{
//    Mgraph g;
//    //printMap();
//    system("mode con cols=150 lines=200");
//    cout << "\t\t\t\t\t         *-----------------�ƴ�У԰����ϵͳ-------------------*" << endl;
//    int flag;
//    while (true)
//    {
//        cout << "\n" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>1. ���У԰�ڸ�λ��                                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>2. ��У԰��ÿ����λ�ã�������λ��֮����ֱ��·�����ľ������<<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>3. �޸�����λ�ã�������λ��֮����ֱ��·�����ľ���          <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>4. �����������֮������·���ĳ��ȼ�;���ĵص�            <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>5. ���ָ��һ�㵽������������·��                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>6. �������һ�㵽������������·��                        <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cout << "\t\t\t\t\t    >>0. �˳�����                                                <<" << endl;
//        cout << "\t\t\t\t\t    >>-----------------------------------------------------------<<" << endl;
//        cin >> flag;
//        cin.clear();//�������֮ǰcin������������
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

#define MaxVexNum 50 //��󶥵����
#define MaxInt 32767 //��������֮����ֱ��·��
#define MaxEdgeNum 50 //���ߵ�����

int pathmatirx[MaxVexNum][MaxVexNum];//��¼��Ӧ�����С·����ǰ����
int shortPath[MaxVexNum][MaxVexNum];//��¼��������С·��ֵ
int dist[MaxVexNum]; //�洢��̾���
int path[MaxVexNum]; //��¼;���ĵ�ǰ�����

//ͼ�Ľṹ��
typedef struct AMGraph {
	int vexs[MaxVexNum];//�����
	int arcs[MaxVexNum][MaxVexNum];//�ڽӾ����
	string name[MaxVexNum]; //��������
	int vexnum, edgenum;//������������
}AMGraph;

AMGraph g; //����ͼ����
void createGraph(AMGraph& g) { //��������ͼ
	g.vexnum = 10;
	g.edgenum = 10;
	//������
	g.name[0] = "����ʳ��";
	g.name[1] = "15��Ԣ";
	g.name[2] = "8��¥";
	g.name[3] = "�ڶ�ʳ��";
	g.name[4] = "��ݵ�";
	g.name[5] = "�ݷ�¥";
	g.name[6] = "��ԺУ��";
	g.name[7] = "��Ժ����";
	g.name[8] = "��Ȫ¥";
	g.name[9] = "��ԺУ��";

	//��������ת��Ϊ�±�
	for (int i = 0; i < g.vexnum; i++) {
		g.vexs[i] = i;
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = 0; j < g.vexnum; j++) {
			g.arcs[i][j] = MaxInt;
			if (i == j) g.arcs[i][j] = 0;
		}
	}
	//��Ȩֵ
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

//Ѱ�Ҿ�������Ӧ���±�
int Search(string s) {
	if (isNum(s)) {
		int n = 0;
		for (int i = 0; i < s.length(); i++) {
			n = n * 10 + s[i] - '0';
		}
		if (n >= 0 && n <= (g.vexnum - 1))
			return n;
		else {
			cout << "��ͼ���޸þ���" << endl;
			return -1;
		}
	}
	else {
		for (int i = 0; i < g.vexnum; i++) {
			if (s == g.name[i]) {
				return i;
			}
		}
		cout << "��ͼ���޸þ���" << endl;
		return -1;
	}
}

void Print_vexs() {
	//��ӡ���ж�����Ϣ
	cout << "   ��ͼ��Ϊ��";
	for (int i = 0; i < g.vexnum; i++) cout << "(" << i << ")" << g.name[i] << " ";
	cout << endl << endl;
}

//��ӡÿ����λ��֮��ľ���(������λ��֮����ֱ��·��)
void Print_arcs(AMGraph g) {
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = i + 1; j < g.vexnum; j++) {
			if (g.arcs[i][j] != MaxInt) {
				cout << "   " << g.name[i] << "->" << g.name[j] << "�ľ���Ϊ��" << g.arcs[i][j] << endl;
			}
		}
	}
	cout << endl;
}

//�޸�����λ��֮��ľ���(������λ��֮����ֱ��·��)
void Update_arcs() {
	string start, end;
	int distance;
	cout << "�޸�����λ��֮��ľ���(������λ��֮����ֱ��·��)" << endl;
	while (true) {
		cout << "��ʼ��(�ص�������): "; cin >> start; //�����޸����
		cout << "��ֹ��(�ص�������): "; cin >> end; //�����޸��յ�
		if (g.arcs[Search(start)][Search(end)] != 0 && g.arcs[Search(start)][Search(end)] != MaxInt) {
			cout << "�µľ���: "; cin >> distance; // �����޸ľ���
			break;
		}
		else {
			cout << "������λ��֮��û��ֱ��·�������������룡" << endl;
			continue;
		}
	}
	g.arcs[Search(start)][Search(end)] = g.arcs[Search(end)][Search(start)] = distance; //�޸ľ���
	cout << "�޸ĺ�ÿ����λ��֮��ľ���(������λ��֮����֮��·��)" << endl;
	Print_arcs(g); //���´�ӡ����ߵ���Ϣ
}

//Dijkstra�㷨�������·��
void Dijkstra(AMGraph g, int dist[], int path[], string begin, string end) {
	int start = Search(begin); //�������
	int over = Search(end); //�յ�����
	int n = g.vexnum, v = 0;
	int set[10] = {}; //set�������ڼ�¼�ö����Ƿ����n
	//��һ������ʼ��
	for (int i = 0; i < n; i++) {
		set[i] = 0;
		dist[i] = g.arcs[start][i];
		if (dist[i] < MaxInt) {//������С��MaxInt˵������֮����·��ͨ
			path[i] = start;//�����·��i��ǰ��Ϊstart
		}
		else {
			path[i] = -1; //��ʾ������֮��û�б�
		}
	}
	set[start] = 1;//����ʼ���㲢��
	path[start] = -1;//��ʼ����û��ǰ��

	//�ڶ���
	for (int i = 1; i < n; i++) {//��n-1������
		int min = MaxInt;
		//�ڶ�������i=1��ʼ����ѡһ�����붥����������
		for (int j = 0; j < n; j++) {
			if (set[j] == 0 && dist[j] < min) {
				v = j;
				min = dist[j];
			}
		}
		//�����㲢��
		set[v] = 1;
		//���������ڽ��½�㲢������ʼ����start��������ľ��뽫�ᷢ���仯��������Ҫ����dist[]����
		for (int j = 0; j < n; j++) {
			if (set[j] == 0 && dist[v] + g.arcs[v][j] < dist[j]) {
				dist[j] = dist[v] + g.arcs[v][j];
				path[j] = v;
			}
		}
	}
	//��ʽ�����
	cout << "\n" << "   " << g.name[start] << "��" << g.name[over] << "�����·��Ϊ: " << dist[over];
	cout << "\n   ·��Ϊ: " << g.name[over];
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
	//��ʼ��floyd�㷨����������
	for (v = 0; v < g.vexnum; v++) {
		for (w = 0; w < g.vexnum; w++) {
			D[v][w] = g.arcs[v][w];
			P[v][w] = w;
		}
	}
	//�����Ǹ��������㷨�ĺ��Ĳ���
	//kΪ�м��
	for (k = 0; k < g.vexnum; k++) {
		//vΪ���
		for (v = 0; v < g.vexnum; v++) {
			//wΪ�յ�
			for (w = 0; w < g.vexnum; w++) {
				if (D[v][w] > (D[v][k] + D[k][w])) {
					D[v][w] = D[v][k] + D[k][w];//������С·��
					P[v][w] = P[v][k];//������С·���м䶥��
				}
			}
		}
	}
	cout << "����Դ��: ";
	string name;
	cin >> name;
	v = Search(name);
	//��Դ��v���������е����С·��
	for (int w = 0; w < 10; w++) {
		if (v == w) continue;
		cout << endl << "   " << g.name[v] << "->" << g.name[w] << "����С·��Ϊ��" << D[v][w] << endl;
		k = P[v][w];
		cout << "   path: " << g.name[v];//��ӡ���
		while (k != w) {
			cout << "->" << g.name[k];//��ӡ�м��
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
		cout << endl; //�������
		cout << "   *****************************************************" << endl;
		cout << "   *********          У԰����ϵͳ             *********" << endl;
		cout << "   *****************************************************" << endl;
		cout << "   *********  1.������Ϣ     2.�ߵ���Ϣ        *********" << endl;
		cout << "   *********  3.�޸�����λ��֮��ľ���         *********" << endl;
		cout << "   *********  4.�����·��(Dijkstra)           *********" << endl;
		cout << "   *********  5.�����������������·��(Floyd)*********" << endl;
		cout << "   *********  6.�˳�   �������Ӧ��Ž��в���! *********" << endl;
		cout << "   *****************************************************" << endl;
		cout << "�����Ӧ��ţ�";
		cin >> n;
		if (n > 0 && n <= 6) {
			switch (n) { //����ѡ��
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
				cout << "��ʼ��(�ص�������)��"; cin >> start;
				while (Search(start) == -1) {
					cout << "��ʼ��(�ص�������)��"; cin >> start;
				}
				cout << "��ֹ��(�ص�������)��"; cin >> end;
				while (Search(end) == -1) {
					cout << "��ֹ��(�ص�������)��"; cin >> end;
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
			cout << "û�иñ�Ŷ�Ӧ�Ĺ��ܣ����������룡" << endl;
			continue;
		}
	}
}                                      
