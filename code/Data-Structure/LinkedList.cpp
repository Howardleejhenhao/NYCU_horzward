struct Node{
    Node *next = nullptr, *prev = nullptr;
    int data;
    Node(int x=0): data(x) {}
};

struct LinkedList{
    Node *head, *tail;
    int n = 0;
    LinkedList(){
        // 初始化頭尾偽指標
        head = new Node;
        tail = new Node;
        head -> prev = tail -> next = nullptr;
        head -> next = tail;
        tail -> prev = head;
    }
    Node *insert(Node *node, int data){ 
        // insert data after node a <-> c  ==>  a <-> b <-> c
        Node *a = node;
        Node *b = new Node(data);
        Node *c = node -> next;
        a -> next = c -> prev = b;
        b -> prev = a;
        b -> next = c;
        n++;
        return b;
    }
    Node* del(Node *node){
        // 刪除 node 並且回傳前一個指標 a <-> b <-> c  ==>  a <-> c
        Node *a = node -> prev;
        Node *b = node;
        Node *c = node -> next;

        a -> next = c;
        c -> prev = a;
        n--;

        return a;
    }
    Node *front(){
        return head -> next;
    }
    Node *back(){
        return tail -> prev;
    }
    unsigned size(){
        return n;
    }
}lst;
