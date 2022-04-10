struct DoublyNode{
        int val;
        DoublyNode* prev, * next;
        DoublyNode(int val):val(val), prev(nullptr), next(nullptr){}
};


class MyLinkedList {
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size)
        {
            return -1;
        }
        DoublyNode* tmpnode = head;
        while(index != 0)
        {
            tmpnode = tmpnode->next;
            index--;
        }
        return tmpnode->val;
    }
    
    void addAtHead(int val) {
        DoublyNode* newnode = new DoublyNode(val);
        if (size == 0)
        {
            head = newnode;
            tail = head;
            size++;
            return;
        }else{
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            size++;
        }
       
    }
    
    void addAtTail(int val) {
        DoublyNode* newnode = new DoublyNode(val);
        if (size == 0)
        {
            head = newnode;
            tail = head;
            size++;
            return;
        }else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index > size)
        {
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
            return;
        }else if(index == 0){
            addAtHead(val);
            return;
        }else{
            DoublyNode* tmpnode = head;
            while(index != 0)
            {
                tmpnode = tmpnode->next;
                index--;
            }
            DoublyNode* newnode = new DoublyNode(val);
            tmpnode->prev->next = newnode;
            newnode->prev = tmpnode->prev;
            tmpnode->prev = newnode;
            newnode->next = tmpnode;
            size++;
        }
        

    }
    
    void deleteAtIndex(int index) {
        if (index >= size)
        {
            return;
        }
        DoublyNode* tmpnode = head;
        int counter = index;
          while(counter != 0)
        {
            tmpnode = tmpnode->next;
            counter--;
        }
        
        if (index == 0)
        {
            if(size == 1)
            {
                head = nullptr;
                tail = nullptr;
            }else{
                tmpnode->next->prev = tmpnode->prev;
                head = tmpnode->next;
            }
            delete tmpnode;
            size--;
            return;
        }
        if (index == size - 1)
        {
            if(size == 1)
            {
                head = nullptr;
                tail = nullptr;
            }else{
                tmpnode->prev->next = tmpnode->next;
                tail = tmpnode->prev;
            }
            delete tmpnode;
            size--;
            return;
        }
        tmpnode->prev->next = tmpnode->next;
        tmpnode->next->prev = tmpnode->prev;
        delete tmpnode;
        size--;
    }

    DoublyNode* head;
    DoublyNode* tail;
    int size = 0;
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