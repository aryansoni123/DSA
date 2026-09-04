class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int _key, int _val, Node* _next = NULL, Node* _prev = NULL){
        key = _key;
        val = _val;
        next = _next;
        prev = _prev;
    }
};

class LRUCache {
    int cap;

    map<int, Node*> mpp;
    Node *head, *tail;


public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        cap = capacity;
    }

    void del(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        // mpp.erase(node->key);
    }

    void insertathead(Node* node){
        Node* nxt = head->next;
        head->next = node;
        node->prev = head;

        node->next = nxt;
        nxt->prev = node;
    }
    
    int get(int key) {
        if(!mpp.contains(key)) return -1;

        Node* loc = mpp[key];

        del(loc);
        insertathead(loc);

        return loc->val;
    }
    
    void put(int key, int value) {

        Node* node = new Node(key, value);

        if(mpp.contains(key)){
            Node* loc = mpp[key];
            loc->val = value;
            del(loc);
            insertathead(loc);

        }else{
            if(mpp.size()<cap){
                mpp[key] = node;
                insertathead(node);

            } else{

                Node* lru = tail->prev;
                del(lru);
                mpp.erase(lru->key);

                mpp[key] = node;
                insertathead(node);
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */