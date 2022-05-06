/*
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xhqwd3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#define LENGTH 100
class MyHashMap {
public:
    struct node{
        int key;
        int value;
        node* next = nullptr;
        node(int key, int value):key(key), value(value){};
    };
    node* a[LENGTH] = {};
    MyHashMap() {
       
    }
    
    void put(int key, int value) {
        int hashkey = hash(key);
        
        if (a[hashkey] == nullptr)
        {
            node* newnode = new node(key, value);
            a[hashkey] = newnode;
        }else{
            node* nodeptr = a[hashkey];
            while( nodeptr->next != nullptr)
            {
                if (nodeptr->key == key)
                {
                    nodeptr->value = value;
                    return;
                }
                nodeptr = nodeptr->next;
            }
            
            if (nodeptr->key == key)
            {
                nodeptr->value = value;
                return;
            }
            node* newnode = new node(key, value);
            nodeptr->next = newnode;
        }
    }
    
    int get(int key) {
        int hashkey = hash(key);
        if (a[hashkey] == nullptr)
        {
            return -1;
        }else{
            node* nodeptr = a[hashkey];
            while( nodeptr != nullptr)
            {
                if (nodeptr->key == key)
                {
                    return nodeptr->value;
                }
                nodeptr = nodeptr->next;
            }
            return -1;
        }
    }
    
    void remove(int key) {
        int hashkey = hash(key);
        if (a[hashkey] == nullptr)
        {
            return;
        }else{
            node* nodeptr = a[hashkey];
            if (nodeptr->key == key)
            {
                a[hashkey] = nodeptr->next;
                delete nodeptr;
                return;
            }
            node* prevptr = nodeptr;
            nodeptr = nodeptr->next;
            while( nodeptr != nullptr)
            {
                if (nodeptr->key == key)
                {
                    prevptr->next = nodeptr->next;
                    delete nodeptr;
                    return;
                }
                prevptr = nodeptr;
                nodeptr = nodeptr->next;
                
            }
            return;
        }
    }

    int hash(int value)
    {
        return value% LENGTH;
    }

    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */