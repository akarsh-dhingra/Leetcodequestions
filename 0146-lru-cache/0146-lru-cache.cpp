class LRUCache {
public:
    class Node {
        public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node (int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    Node *head=new Node (-1,-1);
    Node *tail=new Node (-1,-1);

    int cap;

    unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void add(Node *newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode){
    Node *delNext=delNode->next;
    Node *delPrev=delNode->prev;
    delNext->prev=delPrev;
    delPrev->next=delNext;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node *resNode=m[key];
            m.erase(key);
            deleteNode(resNode);
            add(resNode);
            m[key]=head->next;
            return resNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        add(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */