#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Library{

    public:
        int bookId;
        string bookName;
        string authorName;
        
        Library(string bookName,string authorName,int bookId){
            this->bookName=bookName;
            this->authorName=authorName;
            this->bookId=bookId;
        }

        void display(){
            cout<<"-------------------------"<<endl;
            cout<<"Book id is: "<<bookId<<endl;
            cout<<"Book name is: "<<bookName<<endl;
            cout<<"Book author is: "<<authorName<<endl;
            cout<<"-------------------------"<<endl;
        }
};

int main()
{
    vector <Library> l1;
    int choice;
    
    do{

        cout<<"-----------------------------------"<<endl;
        cout<<"Welcome to Library Management System"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Enter 1 for add book"<<endl;
        cout<<"Enter 2 for display book"<<endl;
        cout<<"Enter 3 for search book"<<endl;
        cout<<"Enter 4 for delete book"<<endl;
        cout<<"Enter 5 for update book"<<endl;
        cout<<"Enter 6 for exit"<<endl;

        cin>>choice;
    
        if(choice==1){
            int id;
            bool exist=false;

            cout<<"Enter your id: "<<endl;
            cin>>id;
            string bookName;
            string authorName;

            for (const Library &s: l1)
            {
                if(s.bookId==id){
                    exist=true;
                }
            }

            if(exist){
                cout<<"Book Already Exists"<<endl;
                continue;
            }else{
                cout<<"Enter your book name: "<<endl;
                cin>>ws;
                getline(cin,bookName);
                cout<<"Enter your author name: "<<endl;
                cin>>ws;
                getline(cin,authorName);
                l1.push_back(Library(bookName,authorName,id));
            }
        }

        else if(choice==2){
            
            if(l1.empty()){
                cout<<"No Book found"<<endl;
            }
            for (Library &s:l1)
            {
                s.display();
            }
            
        }
        else if(choice==3){
            bool found=false;
            int id;
            cout<<"Enter your id: "<<endl;
            cin>>id;

            for (Library &s : l1)
            {
                if(s.bookId==id){
                    found=true;
                }
            }
            if(found){
                cout<<"Book found"<<endl;
            }else{
                cout<<"Book does not exits"<<endl;
            }
        }
        else if(choice==4){
            bool found=false;
            int id;
            cout<<"Enter your book id: "<<endl;
            cin>>id;

            for (auto it = l1.begin(); it !=l1.end(); ++it)
            {
                if(it->bookId==id){
                    l1.erase(it);
                    found=true;
                }
            }
            if(found){
                cout<<"Deleted book successfully!!!"<<endl;
            }else{
                cout<<"Book does not exits"<<endl;
            }
            
        }
        else if(choice==5){
            int id;
            bool exist=false;

            cout<<"Enter your book id: "<<endl;
            cin>>id;
            string bookName;
            string authorName;

            for (auto it = l1.begin(); it !=l1.end(); ++it)
            {
                if(it->bookId==id){
                    cout<<"Enter your book name: "<<endl;
                    cin>>ws;
                    getline(cin,bookName);
                    cout<<"Enter your author name: "<<endl;
                    cin>>ws;
                    getline(cin,authorName);
                    exist=true;
                }
            }
            if(exist){
                l1.push_back(Library(bookName,authorName,id));
                cout<<"Book updated successfully!!!"<<endl;
            }else{
                cout<<"Book does not exits"<<endl;
            }
        }
    }while(choice!=6);
    
    return 0;
}