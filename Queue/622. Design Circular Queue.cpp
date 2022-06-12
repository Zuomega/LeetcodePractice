/*
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/kzlb5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        this->start = -1;
        this->end = -1;
        this->len = k;
        for (int i = 0; i < this->len;i++)
        {
            queue.push_back(-1);
        }
    }
    
    bool enQueue(int value) {
        int tmpend = end;
        if (end == this->len - 1)
        {
            end = 0;
        }else{
            end++;
        }
        if (end == start)
        {
            end = tmpend;
            return false;
        }else{
            if (tmpend == -1)
            {
                start = 0;
            }
            queue[end] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if (start == -1)
        {
            return false;
        }
        if (start == end)
        {
            start = -1;
            end = -1;
            return true;
        }
        if (start == this->len - 1)
        {
            start = 0;
        }else{
            start++;
        }
        return true;
    }
    
    int Front() {
        if (start == -1)
        {
            return -1;
        }else{
            return queue[start];
        }
    }
    
    int Rear() {
        if (start == -1)
        {
            return -1;
        }else{
            return queue[end];
        }
    }
    
    bool isEmpty() {
        if (start == -1)
        {
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        int tmpend = end;
        if (tmpend == this->len - 1)
        {
            tmpend = 0;
        }else{
            tmpend++;
        }
        if (tmpend == start)
        {
            return true;
        }else{
            return false;
        }
    }
private:
    vector<int> queue;
    int start;
    int end;
    int len;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */