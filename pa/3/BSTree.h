#ifndef BSTREE_H
    #define BSTREE_H

    #include <iostream>

    struct Node {
        int value;
        Node* left;
        Node* right;
        int search_time; //see the problem description

        // Node constructor
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
            : value(val), left(l), right(r), search_time(0) {}
    };

    struct BSTree {
        public:
            // default constructor
            BSTree() : size(0), root(nullptr) {}
            // copy constructor
            BSTree(const BSTree& other);
            // move constructor
            BSTree(BSTree&& other);
            // copy assignment
            BSTree& operator=(const BSTree& other);
            // move assignment
            BSTree& operator=(BSTree&& other);
            // destructor
            ~BSTree();

            // getters
            const Node* get_root() const { return root; }
            const int get_size() const { return size; }
            
            Node* insert(int val);
            Node* search(int val);
            void update_search_times();
            float get_average_search_time();
            void inorder(std::ostream& out);
            void print_level_by_level(std::ostream& out);

        private:
            int size;
            Node* root;
            // helper functions
            int get_total_search_time(Node* node);
            // you can add recursive helper functions to help you
            // this one is implemented for you:
            void copy_helper(Node*& newNode, const Node* sourceNode);
            // you may need these recursive functions (optional):
            // void delete_helper(Node*& node);
            // Node* insert_helper(Node*& node, int val, int cost);
            // Node* search_helper(Node* node, int val);
            // void update_helper(Node* node, int cost);
            // void inorder_helper(Node* node, ostream& out);
    };

    // print a node
    std::ostream& operator<<(std::ostream& out, Node& node);

    // print a BSTree
    std::ostream& operator<<(std::ostream& out, BSTree& tree);

    // read in a BSTree data from a file (see read_from_file)
    std::istream& operator>>(std::istream& in, BSTree& tree);


#endif