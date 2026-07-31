class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->next=nullptr;
            this->prev=nullptr;
        }
    };
    unordered_map<int,Node*> mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* newNode){
        Node* temp=head->next;
        temp->prev=newNode;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
    }
    void deleteNode(Node* delNode){
        Node* prev=delNode->prev;
        Node* next=delNode->next;
        prev->next=next;
        next->prev=prev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* res=mp[key];
            int ans=res->val;
            deleteNode(res);
            mp.erase(key);
            addNode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */