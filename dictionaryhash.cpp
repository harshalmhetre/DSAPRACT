#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    string value;
    Node* next;
    
    Node(int key, const string& value) : key(key), value(value), next(nullptr) {}
};

class Dictionary {
private:
    Node* table[10];

    
    int hashFunction(int key) {
        return key % 10;
    }

public:
    Dictionary() {
        for (int i = 0; i < 10; ++i)
            table[i] = nullptr;
    }

    
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
           
            table[index] = newNode;
        } else {
            
            Node* current = table[index];
            while (current->next != nullptr) {
                if (current->key == key) {
                    
                    current->value = value;
                    delete newNode; 
                    return;
                }
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    string find(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return "Key not found";
    }

    
    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (current) {
            if (prev)
                prev->next = current->next;
            else
                table[index] = current->next;
            delete current;
            cout << "Key " << key << " deleted successfully." << endl;
        } else {
            cout << "Key not found." << endl;
        }
    }

    
    void display() {
        for (int i = 0; i < 10; ++i) {
            cout << "[" << i << "]: ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary dict;

    
    dict.insert(1, "Value1");
    dict.insert(11, "Value11");
    dict.insert(21, "Value21");
    dict.insert(2, "Value2");
    dict.insert(12, "Value12");

    
    dict.display();
    
    
    dict.remove(2);

    
    cout << "\nAfter deletion:\n";
    dict.display();

    return 0;
}
