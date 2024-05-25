#include "MyStack.h"


//void print(MyStack<class INF>*& stack, char* del) {
//    std::cout << stack->top_inf() << " " << del;
//    if (stack->next_elem() != nullptr)
//        print(stack->next_elem(), del);
//    else
//        std::cout << ";\n";
//}


//template<class INF>
//void MyStack<INF>::push(INF value){
//    Node* newNode = new Node(value);
//    if (top == nullptr) {
//        top = newNode;
//    }
//    else {
//        top->set_elem(newNode);
//        newNode->set_elem(nullptr);
//        top = newNode;
//    }
//};

//template<class INF>
//bool MyStack<INF>::pop(void) {
//    if (empty()) {
//        return 0;
//    }
//    ListNode* tmp = top;    
//    top = top->GetNext();
//    tmp->~ListNode();
//};

