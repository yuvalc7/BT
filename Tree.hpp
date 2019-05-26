namespace ariel{
    class Node{

        public:
        Node(int a);
        int getData();
        Node*left;
        Node*right;
        Node*parent;
        int val;
        };

    class Tree{

        public:
        Tree(){
        root = nullptr;
        _size = 0;
        }
        ~Tree(){}
        Tree& insert(int val);
        bool remove(int val);
        int size();
        int parent(int val);
        int right(int val);
        int left(int val);
        void print();
        int root();
        bool contains(int val);

        private:
        void print(Node *n);
        void insert(Node *n , int v);
        Node* find(Node *n, int v);
        Node *root;
        int _size;

    };
}
