#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;


struct Node 
{
    int data;  
    Node* next;
};

class LinkList 
{
private:
    Node* head; 
public:
    // 1. 构造函数：初始化链表（创建头节点）
    LinkList();
    // 2. 析构函数：销毁链表（释放所有内存，防止泄漏）
    ~LinkList();

    void addTail(int val);  // 尾插法：在链表末尾添加节点
    void addHead(int val);  // 头插法：在链表头部添加节点
    bool delNode(int val);  // 删除指定值的节点
    Node* findNode(int val);// 查找指定值的节点
    void showList();        // 遍历打印链表
    void clearList();       // 清空链表（保留头节点）
};

void LinkList::addTail(int val) 
{
    // 1. 创建新节点
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    // 2. 找尾节点（用临时指针p遍历，不修改头指针）
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    // 3. 尾节点连接新节点
    p->next = newNode;
}

// 删除指定值的节点，成功返回true，失败返回false
bool LinkList::delNode(int val)
{
    Node* p = head; 
    while (p->next != NULL && p->next->data != val)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        cout << "未找到值为" << val << "的节点" << endl;
        return false;
    }
    Node* temp = p->next;
    p->next = temp->next;
    // 3. 释放内存（关键！防止内存泄漏）
    delete temp;
    return true;
}

// 清空链表（保留头节点）
void LinkList::clearList() 
{
    Node* p = head->next;
    while (p != NULL)
    {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    head->next = NULL;
}

// 析构函数：销毁整个链表
LinkList::~LinkList() 
{
    clearList();  // 清空有效节点
    delete head;   // 释放头节点
    cout << "链表已销毁，内存释放成功！" << endl;
}