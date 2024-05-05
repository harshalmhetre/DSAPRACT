#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


void addstudent(){
    
    string name , add,b ,rn ;


    ofstream f("db.txt",ios::app);

    cout<<"\nEnter roll no.";
    cin>>rn;
    cout<<"\nEnter name";
    cin>>name;
    cout<<"\nEnter Division";
    cin>>b;
    cout<<"\nEnter Address";
    cin>>add;

    f<<"\n"<<left<<setw(20)<<rn<<setw(20)<<name<<setw(20)<<b<<setw(20)<<add;

    f.close();
    cout<<"Data added successfully\n";
}
void deletestudent(){
    ifstream f("db.txt");
    string line ,rn ,filedata;
   
    cout<<"\nEnter the roll no. to delete";
    cin>>rn;
    
    while(getline(f,line)){
        if(line.find(rn) == string::npos ){
            filedata+=line;
            filedata+="\n";
            
        }
    }
    f.close();
    
    ofstream f1("db.txt",ios::out);
        f1<<filedata;
        f1.close();
}

void searchstudent(){
    ifstream f("db.txt");
    string line ,rn;
   
    cout<<"\nEnter the roll no. to search";
    cin>>rn;
    bool found=false;
    while(getline(f,line)){
        if(line.find(rn) != string::npos ){
            cout<<line<<endl;
            found=true;
        }
    }
    f.close();
    if(!found){
        cout<<"\nStudent does't exist.";
    }
    
}
void printstudent(){
    ifstream f("db.txt",ios::in);
    string line ; 
    cout<<"student data:\n";
    while(getline(f,line)){
        cout<<line<<"\n";

    }
    
    f.close();
}

int main(){

    ofstream f("db.txt",ios::out);
    f<<left<<setw(20)<<"Roll no."<<setw(20)<<"Name"<<setw(20)<<"Division"<<setw(20)<<"Address";

    f.close();

    int ch;

    while(ch!=-1){
        cout<<"Enter your choice\n1.Add Student\n2.Delete Student\n3.Search Student\n4.Print Student\n5.Exit";
        cin>>ch;
        switch(ch){
            case 1:
            addstudent();
            break;
            case 2:
            deletestudent();
            break;
            case 3:
            searchstudent();
            break;
            case 4:
            printstudent();
            break;
            case 5:
            break;
            default:
            cout<<"give valid input";
        
        }
    }
}