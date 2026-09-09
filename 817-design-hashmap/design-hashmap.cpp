class MyHashMap {
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            this->next=nullptr;
        }
    };
    Node** table;
    int size=1000;
    int hash(int key){
        return key%size;
    }
public:
    MyHashMap() {
        table=new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=nullptr;
        }
    }
    
    void put(int key, int value) {
        int index=hash(key);
        Node* curr=table[index];
        while(curr!=nullptr){
            if(curr->key==key){
                curr->value=value;
                return;
            }
            curr=curr->next;
        }
        Node* newNode=new Node(key,value);
        newNode->next=table[index];
        table[index]=newNode;
    }
    
    int get(int key) {
        int index=hash(key);
        Node* curr=table[index];
        while(curr!=nullptr){
            if(curr->key==key){
                return curr->value;
            }
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index=hash(key);
        Node* curr=table[index];
        Node* prev=nullptr;
        while(curr!=nullptr){
            if(curr->key==key){
                if(prev==nullptr){
                    table[index]=curr->next;
                }
                else{
                    prev->next=curr->next;
                }
                delete curr;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */