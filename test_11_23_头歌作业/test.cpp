#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include"ListOp.h"
using namespace std;
int A[1000];
int main() {
    List* p = new ArrayList;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        p->insert(p->getSize(), A[i]);
    }
    cout << *p << endl;
    for (int i = 0; i < 3 && p->getSize() != 0; ++i) {
        p->remove(0);
    }
    cout << *p << endl;
    for (int i = 0; i < p->getSize(); i += 2) {
        p->modify(i, p->at(i) * 10);
    }
    cout << *p << endl;
    delete p;
    p = new LinkedList;
    for (int i = 0; i < n; ++i) {
        p->insert(p->getSize(), A[i]);
    }
    cout << *p << endl;
    for (int i = 0; i < 3 && p->getSize() != 0; ++i) {
        p->remove(0);
    }
    cout << *p << endl;
    for (int i = 0; i < p->getSize(); i += 2) {
        p->modify(i, p->at(i) * 10);
    }
    cout << *p << endl;
    delete p;
    return 0;
}