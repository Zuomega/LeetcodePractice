/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/jy291/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class MyLinkedList {
public:
    MyLinkedList() {

    }
    
    int get(int index) {
        if(index >= this->listsize)
        {
            return -1;
        }else{
            node* tmpnode = head;
            while(index > 0)
            {
                tmpnode = tmpnode->next;
                index--;
            }
            return tmpnode->value;
        }
    }
    
    void addAtHead(int val) {
        if(this->listsize == 0)
        {
            node* headnode = new node(val);
            head = headnode;
            this->listsize++;
        }else{
            node* headnode = new node(val);
            headnode->next = head;
            head = headnode;
            this-> listsize++;
        }
       
    }
    
    void addAtTail(int val) {
        if(this->listsize == 0)
        {
            node* tailnode = new node(val);

            head = tailnode;
            this->listsize++;
        }else{
            node* tailnode = new node(val);

            int tmplength = this->listsize - 1;
            node * tailnodeptr = head;
            while(tmplength > 0)
            {
                tailnodeptr = tailnodeptr->next;
                tmplength--;
            }

            tailnodeptr->next = tailnode;
            this->listsize++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0)
        {
            addAtHead(val);
        }else if(index == listsize){
            addAtTail(val);
        }else if (index > listsize ){
            return;
        }else{
            node* newnode = new node(val);

            node * tmpnode = head;
            node * tmpnodeprev;
            while(index > 0){
                tmpnodeprev = tmpnode;
                tmpnode = tmpnode->next;
                index--;
            }
            tmpnodeprev->next = newnode;
            newnode->next = tmpnode;

            this->listsize++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (this->listsize > 1)
        {
            if(index == 0)
            {
                node* todelete = head;
                head = head->next;
                delete todelete;
                this->listsize--; 
            }else if(index < this->listsize )
            {
                node* tmpnode = head;
                node* tmpnodeprev;
                while(index > 0)
                {
                    tmpnodeprev = tmpnode;
                    tmpnode = tmpnode->next;
                    index--;
                }
                node* todelete =  tmpnode;
                tmpnodeprev->next = tmpnode->next;
                delete todelete;
                this->listsize--;
            }
        }else if (this->listsize == 1 && index == 0)
        {
            delete head;
            this->listsize = 0;
        }
    }
    struct node{
        int value;
        node * next;
        node(int x):value(x),next(nullptr){};
    };
    private:
    int listsize = 0;
    node* head;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */