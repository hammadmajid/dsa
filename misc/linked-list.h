#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
    } *head, *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {
    }

    // checks if the head is null
    bool is_empty() {
        return head == nullptr;
    }

    // returns the total count of elements in the list
    unsigned size() {
        if (is_empty()) {
            return 0;
        }
        unsigned count = 1;
        Node* tmp = head;

        while (tmp->next != nullptr) {
            count += 1;
            tmp = tmp->next;
        }

        return count;
    }

    // returns the element at the given index
    T at(const unsigned index) {
        if (is_empty()) {
            std::cerr << "Error: cannot index a empty list\n";
            std::exit(1);
        }
        unsigned count = 0;
        Node* tmp = head;

        while (tmp->next != nullptr) {
            if (index == count) {
                return tmp->data;
            }
            tmp = tmp->next;
            count += 1;
        }

        std::cerr << "Error: index out of bounds\n";
        std::exit(1);
    }

    // insert element at the front
    void insert_at_head(const T& data) {
        if (is_empty()) {
            head = new Node;

            head->data = data;
            head->next = tail;
        }
        else {
            Node* tmp = new Node;
            tmp->data = data;
        }
    }

    // inserts element at the given index
    void insert_at_index(T data, unsigned index) {
        Node* tmp = new Node;
        tmp->data = data;
    }

    // inserts element at the end
    void insert_at_tail(const T& data) {
        if (is_empty()) {
            return insert_at_head(data);
        }
        Node* new_node = new Node;

        new_node->data = data;

        // get the last node
        Node* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }

        last_node->next = new_node;
    }

    // remove elements from the front
    void delete_head() {
    }

    // removes element at the given index
    void delete_at_index(unsigned index) {
    }

    //
    // // remove element from the end
    void delete_tail() {
    }
};

#endif
