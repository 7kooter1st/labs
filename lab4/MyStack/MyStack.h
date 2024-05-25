#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен


#include <iostream>

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode* next;         // указатель на следующий узел списка
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

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack  {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top = new Node();
public:
    MyStack(void) { top = nullptr; }           // конструктор
    ~MyStack(void) {};          // освободить динамическую память
    bool empty(void) { return top == nullptr; }        // стек пустой?
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
    };      // добавить узел в вершину стека
    bool pop() {
        if (empty()) {
            return 0;
        }
        Node *tmp = top;
        top = top->next;
        delete tmp;
    };;          // удалить узел из вершины стека
    INF top_inf(void) { return top->d; };      // считать информацию из вершины стека
};

//void print(MyStack<class INF>*&, char*);

#endif
