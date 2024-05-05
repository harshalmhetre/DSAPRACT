#include <iostream>
#include <string>
using namespace std;

struct node {
    int key;
    string value;
    bool filled; // Flag to indicate if the slot is filled or not

    node() : filled(false) {}
};

class Dictionary {
private:
    node table[10];

    int hash(int key) {
        return key % 10;
    }

    
    int linearProbe(int index) {
        return (index + 1) % 10;
    }

public:
    Dictionary() {
        for (int i = 0; i < 10; ++i) {
            table[i] = node();
        }
    }

    
    void insert(int key, const string& value) {
        int index = hash(key);

    
        while (table[index].filled) {
            index = linearProbe(index);
        }

        
        table[index].key = key;
        table[index].value = value;
        table[index].filled = true;

        cout << "Inserted key: " << key << ", value: " << value << endl;
    }

    
    string find(int key) {
        int index = hash(key);


        while (table[index].filled && table[index].key != key) {
            index = linearProbe(index);
        }

        if (table[index].filled && table[index].key == key) {
            return table[index].value;
        } else {
            return "Key not found";
        }
    }


    void remove(int key) {
        int index = hash(key);

        while (table[index].filled && table[index].key != key) {
            index = linearProbe(index);
        }

        if (table[index].filled && table[index].key == key) {
            table[index].filled = false;
            cout << "Key " << key << " deleted successfully." << endl;
        } else {
            cout << "Key not found." << endl;
        }
    }

    void display(){
        for (int i = 0; i < 10; ++i) {
            cout << "[" << i << "]: ";
            node current = table[i];
                if(current.filled){
                cout << "(" << current.key << ", " << current.value << ") ";
                }
                else{
                    cout << "(No key ,NO value  ) ";
                }
                
            
            cout << endl;
        }
    }
};

int main() {
    Dictionary dict;

    dict.insert(5, "Value5");
    dict.insert(15, "Value15");
    dict.insert(25, "Value25");
    dict.insert(6, "Value6");

    dict.display();

    cout << "Value for key 5: " << dict.find(5) << endl;
    cout << "Value for key 15: " << dict.find(15) << endl;
    

    dict.remove(15);

    cout << "Value for key 15 after deletion: " << dict.find(15) << endl;

    dict.display();

    return 0;
}
