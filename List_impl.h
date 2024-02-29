using namespace CS303;

template <typename Item_Type>
CS303::List<Item_Type>::List() {
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

template <typename Item_Type>
void CS303::List<Item_Type>::push_front(Item_Type value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
    num_items++;
}

template <typename Item_Type>
void CS303::List<Item_Type>::push_back(Item_Type value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;
    if (tail != nullptr) {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr) {
        head = tail;
    }
    num_items++;
}

template <typename Item_Type>
void CS303::List<Item_Type>::pop_front() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <typename Item_Type>
void CS303::List<Item_Type>::pop_back() {
    if (tail != nullptr) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        num_items--;
    }
}

template <typename Item_Type>
int& CS303::List<Item_Type>::front() {
    return head->data;
}

template <typename Item_Type>
int& CS303::List<Item_Type>::back() {
    return tail->data;
}

template <typename Item_Type>
bool CS303::List<Item_Type>::empty() {
    return num_items == 0;
}

template <typename Item_Type>
void CS303::List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else if (index < num_items) {
        Node* temp = head;
        for (std::size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* new_node = new Node;
        new_node->data = item;
        new_node->next = temp->next;
        temp->next = new_node;
        num_items++;
    }

}

template <typename Item_Type>
bool CS303::List<Item_Type>::remove(std::size_t index) {
    if (index == 0) {
        pop_front();
        return true;
    } else if (index == num_items - 1) {
        pop_back();
        return true;
    } else if (index < num_items - 1) {
        Node* temp = head;
        for (std::size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
        num_items--;
        return true;
    }
    return false;
}

template <typename Item_Type>
size_t CS303::List<Item_Type>::find(const Item_Type& item) {
    Node* temp = head;
    for (std::size_t i = 0; i < num_items; i++) {
        if (temp->data == item) {
            return i;
        }
        temp = temp->next;
    }
    return num_items;
}

template <typename Item_Type>
CS303::List<Item_Type>::~List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename Item_Type>
void CS303::List<Item_Type>::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}