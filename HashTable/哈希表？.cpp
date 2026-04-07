#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



// 链表节点结构
struct Node 
{
    int key;    // 键（唯一标识）
    int value;  // 值
    Node* next; // 指向下一个节点的指针（解决冲突）


    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable 
{
private:
    Node** table;   // 指针数组：每个元素是链表头节点
    int capacity;   

    int hashFunction(int key) 
    {
        return key % capacity;
    }

public:
    HashTable(int cap = 7)
    {
        capacity = cap;
        table = new Node * [capacity];
        for (int i = 0; i < capacity; i++) 
        {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) 
    {
        int index = hashFunction(key);//下标

		Node* newNode = new Node(key, value);   
        //这个时候newNode是一个新的节点，也就是头节点

        newNode->next = table[index];
		table[index] = newNode;    
        //table[index成为这个链表的头节点

        std::cout << "插入成功：key = " << key << ", 下标 = " << index << std::endl;
    }

    bool search(int key, int& outValue) 
    {
        int index = hashFunction(key);

        Node* cur = table[index];
        while (cur != nullptr) 
        {
            if (cur->key == key) 
            {
                outValue = cur->value;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void remove(int key) 
    {
        int index = hashFunction(key);
        Node* cur = table[index];
        Node* prev = nullptr;

        while (cur != nullptr && cur->key != key) 
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr) 
        {
            std::cout << "删除失败：key " << key << " 不存在\n";
            return;
        }

        if (prev == nullptr) 
        {
            table[index] = cur->next;
        }
        else 
        {
            prev->next = cur->next;
        }
        delete cur;
        std::cout << "删除成功：key = " << key << std::endl;
    }


    void print() {
        std::cout << "\n===== 哈希表内容 =====" << std::endl;
        for (int i = 0; i < capacity; i++) 
        {
            std::cout << "下标 " << i << "：";
            Node* cur = table[i];
            while (cur != nullptr) 
            {                std::cout << "(" << cur->key << "," << cur->value << ") → ";
                cur = cur->next;
            }
            std::cout << "nullptr\n";
        }
    }

    // 析构函数：释放内存
    ~HashTable()
    {
        for (int i = 0; i < capacity; i++) 
        {
            Node* cur = table[i];
            while (cur != nullptr) 
            {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
        delete[] table;
    }
};


int main()
{

    HashTable ht(7);

    // 插入数据
    ht.insert(101, 90);
    ht.insert(102, 85);
    ht.insert(103, 92);
    ht.insert(104, 88);
    ht.insert(105, 95);
    // 故意制造哈希冲突：108%7=3，和101下标一样
    ht.insert(108, 99);

    ht.print();

    // 查找
    int val;
    if (ht.search(108, val)) 
    {
        std::cout << "\n查找 108 的成绩：" << val << std::endl;
    }

    // 删除
    ht.remove(101);
    ht.print();

    return 0;
}