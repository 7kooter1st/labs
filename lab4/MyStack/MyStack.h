#ifndef MyStack_h           // ������ �� ��������� ����������
#define MyStack_h           // ������ ���������


#include <iostream>

// ��������� ����� ListNode (���� ������������ ������)
template<class INF, class FRIEND>
class ListNode              // ���� ������
{
private:
    INF d;                  // �������������� ����� ����
    ListNode* next;         // ��������� �� ��������� ���� ������
    ListNode() {
        d = INF();
        next = nullptr;
    };
    ListNode(INF inf, ListNode* next_) {
        d = inf;
        next = next_;
    }
public:  
    friend FRIEND;
    void set_elem(ListNode* value) { next = value; };
    ListNode GetNext() { return next; };
};

// ��������� ����� MyStack �� ������ ������������ ������.
template<class INF>
class MyStack  {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top = new Node();
public:
    MyStack(void) { top = nullptr; }           // �����������
    ~MyStack(void) {};          // ���������� ������������ ������
    bool empty(void) { return top == nullptr; }        // ���� ������?
    void push(INF value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        //if (top == nullptr) {
        //    top = newNode;
        //}
        //else {
        //    top->set_elem(newNode);
        //    newNode->set_elem(nullptr);
        //    top = newNode;
        //}
    };      // �������� ���� � ������� �����
    bool pop() {
        if (empty()) {
            return 0;
        }
        Node *tmp = top;
        top = top->next;
        delete tmp;
    };;          // ������� ���� �� ������� �����
    INF top_inf(void) { return top->d; };      // ������� ���������� �� ������� �����
};

//void print(MyStack<class INF>*&, char*);

#endif
