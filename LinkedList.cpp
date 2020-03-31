#include <iostream>
using namespace std;

struct list_node {
    int value;
    list_node *next;
    list_node(int v, list_node *nxt = nullptr) {
        value = v;
        next = nxt;
    };
};

class List {
private:
    list_node *head;
    int number;
public:
    List();
    ~List();
    bool is_empty() const;
    int size() const;
    void push_front(int val);
    void pop_front();
    void clear();
    // removes first occurence of `val` in the list
    // returns true if removal occured
    bool remove(int val);
    list_node *get_head();

    //ADDITIONAL:
    void print_list();
    bool findElement(int val, list_node *&current, list_node *&previous) const;
};

List::List() {
    cout << "constructor" << endl;
    head = nullptr;
    number = 0;
}

List::~List() {
    this->clear();
    cout << "destructor" << endl;
}

bool List::is_empty() const {
    return head != nullptr;
}

int List::size() const {
    return number;
}

void List::push_front(int val) {
    auto ptr = new list_node(val);
    if (ptr == nullptr) {
        cerr << "List::push_front: Allocation memory failure!" << endl;
        return;
    }
    ptr->value = val;
    ptr->next = head;
    head = ptr;
    number++;
}

void List::pop_front() {
    if (!is_empty()) {
        cerr << "List::pop_front: Unable to pop from empty list" << endl;
        return;
    }
    list_node *current = head->next;
    list_node *previous = head;

    number--;
    head = current;
    delete previous;
};

void List::clear() {
    list_node *etr = head;
    while (etr) { // remove all elements from *this
        etr = etr->next;
        delete head;
        head = etr;
    }
    number = 0;
}

bool List::remove(int val) {
    bool result = false;
    list_node *curr = nullptr;
    list_node *prev = nullptr;
    result = findElement(val, curr, prev);
    if (result) {
        if (prev == nullptr)
            head = curr->next;
        else
            prev->next = curr->next;
        delete curr;
        number--;
    } else {
        cerr << "List::remove: Item not found" << endl;
    }
    return result;
}

list_node *List::get_head() {
    return head;
}

void List::print_list() {
    list_node *check = head;
    while (check != nullptr) {
        cout << check->value << endl;
        check = check->next;
    }
}

bool List::findElement(int val, list_node *&current, list_node *&previous) const{
    current = head;
    previous = nullptr;
    while (current) {
        if (current->value == val)
            return true;
        previous = current;
        current = current->next;
    }
    return false;
}
int test() {

    List xnnn;
    xnnn.push_front(1);
    xnnn.pop_front();
    for (int i=0; i < 3; i++){
        xnnn.push_front(i);
    }
    xnnn.remove(2);
    xnnn.clear();
    xnnn.pop_front(); //case when there is nothing to pop
    xnnn.push_front(234);
    return 0;
}