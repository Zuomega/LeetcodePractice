/*
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xh377h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#define capacity  6000
class MyHashSet {
public:
    int bucket[capacity];
    MyHashSet() {
        for (int i = 0; i < capacity; i++)
        {
            bucket[i] = -1;
        }
    }
    
    void add(int key) {
        int hashkey = hash(key);
        if (bucket[hashkey] == -1)
        {
            bucket[hashkey] = key;
        }else{
            int newhashkey = hashkey ;
            while(bucket[newhashkey] > -1 && bucket[newhashkey] != key)
            {
                newhashkey++;
                if(newhashkey >= capacity) newhashkey = 0;
                if(newhashkey == hashkey) return;
            }
            bucket[newhashkey] = key;
        }
    }
    
    void remove(int key) {
        int hashkey = hash(key);
        if (bucket[hashkey] == key)
        {
            bucket[hashkey] = -1;
        }else{
            int newhashkey = hashkey;
            while(bucket[newhashkey] != key)
            {
                newhashkey++;
                if(newhashkey >= capacity) newhashkey = 0;
                if(newhashkey == hashkey) return;
            }
            bucket[newhashkey] = -1;
        }
    }
    
    bool contains(int key) {
        int hashkey = hash(key);
        if (bucket[hashkey] == key)
        {
            return true;
        }else{
            int newhashkey = hashkey;
            while(bucket[newhashkey] != key )
            {
                newhashkey++;
                if(newhashkey >= capacity)
                {
                    newhashkey = 0;
                } 
                if(newhashkey == hashkey)
                {
                    return false;
                } 
            }           
                
            return true;
        }
    }

    int hash(int in){
        return in % capacity;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */