#ifndef SOCIALNETWORK_LINKEDLIST_H
#define SOCIALNETWORK_LINKEDLIST_H

template <class T>
class LinkedList {
private:
    class Node {
    public:
        T value;
        Node *prev, *next;
        Node(T val = T{}, Node* p = nullptr, Node* n = nullptr) : value {val}, prev {p}, next {n} {
        }
    };

    Node *head, *tail;
    int Size = 0;

public:

    class iterator {
    private:
        Node *current;
        iterator (Node* p) : current {p} {}
    public:
        T & operator* () {
          return current->value;
        }
        iterator operator++ () {
          this->current = this->current->next;
          return *this;
        }
        iterator operator++ (int) {
          iterator ret = *this;
          ++(*this);
          return ret;
        }
        bool operator== (iterator it) {
          return current == it.current;
        }
        bool operator!= (iterator it) {
          return current != it.current;
        }
        friend class LinkedList<T>;

    };
    LinkedList() {
      head = new Node();
      tail = new Node();
      head->next = tail;
      tail->prev = head;
    }


    ~LinkedList() {
      clear();
      delete head;
      delete tail;
    }

    iterator begin() {
      return {head->next};
    }

    iterator end() {
      return {tail};
    }

    void clear() {
      for (iterator it = begin(); it!=end(); it++) {
        erase(it);
      }
      this->Size = 0;
    }

    iterator insert(T value, iterator it) {
      Node *newNode = new Node(value, it.current->prev, it.current);
      it.current->prev = it.current->prev->next = newNode;
      ++Size;
      return it;
    }

    iterator insert(T value) {
      return insert(value, end());
    }

    iterator erase(iterator it) {
      it.current->prev->next = it.current->next;
      it.current->next->prev = it.current->prev;
      it.current = it.current->next;
      --Size;
      return it;
    }
    int size() {
      return this->Size;
    }
};


#endif //SOCIALNETWORK_LINKEDLIST_H
