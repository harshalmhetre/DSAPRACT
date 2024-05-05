#include <iostream>
#include <string>
using namespace std;

struct Client {
    string name;
    int phoneNumber;
};

class HashTable {
private:
    Client* table[10]; 

public:
    HashTable() {
        for (int i = 0; i < 10; ++i) {
            table[i] = nullptr;
        }
    }

    int hashPhoneNumber(int phoneNumber) {
        return phoneNumber % 10;
    }

    int quadraticProbing(int index, int i) {
        return (index + i * i) % 10;
    }

    int linearProbing(int index) {
        return (index + 1) % 10;
    }

    void insert(Client* client) {
        int index = hashPhoneNumber(client->phoneNumber);
        int i = 1;
        while (table[index] != nullptr) {
            index = quadraticProbing(index, i);
            i++;
        }
        table[index] = client;
    }

    void search(int phoneNumber) {
        int index = hashPhoneNumber(phoneNumber);
        int comparisons = 1;
        int i = 1;
        while (table[index] != nullptr && table[index]->phoneNumber != phoneNumber) {
            index = quadraticProbing(index, i);
            i++;
            comparisons++;
        }
        if (table[index] != nullptr && table[index]->phoneNumber == phoneNumber) {
            cout << "Number of comparisons: " << comparisons << endl;
            cout << table[index]->name << ": " << table[index]->phoneNumber << endl;
        } else {
            cout << "Number of comparisons: " << comparisons << endl;
            cout << "Number not found" << endl;
        }
    }

    void display() {
        cout << "HashTable: " << endl;
        for (int i = 0; i < 10; ++i) {
            if (table[i] != nullptr) {
                cout << "Index " << i << ": " << table[i]->name << ": " << table[i]->phoneNumber << endl;
            } else {
                cout << "Index " << i << ": " << "Empty" << endl;
            }
        }
    }

    void getData() {
        string name;
        int phoneNumber;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
        Client* newClient = new Client{name, phoneNumber};
        insert(newClient);
    }
};

int main() {
    HashTable Table;
    
    int n;
    cout << "Enter the number of clients: ";
    cin >> n;

    cout << "Enter client details:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Client " << i + 1 << ":" << endl;
        Table.getData();
    }


    Table.display();

    int s;
    cout << "Enter phone number to search: ";
    cin >> s;

    cout << "Searching for " << s << "'s number:" << endl;
    Table.search(s);

    return 0;
}
