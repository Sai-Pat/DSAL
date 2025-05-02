#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
using namespace std;
class Student{

    public:
        int rn;
        string div,name;
        string add;
        void insert( )
        {
            cout<<"Enter Roll No."<<endl;
            cin>>rn;
            cin.ignore();
            cout<<"Enter Name "<<endl;
            getline(cin,name);
            cout<<"Enter Division "<<endl;
            getline(cin,div);
            cout<<"Enter Address "<<endl;

            ofstream o("xyz.txt",ios::app);
            o<<rn<<","<<name<<","<<div<<","<<add<<endl;
            o.close();
        }
        void delet()
        {
            cout<<"Enter Roll no.";
            cin>>rn;
            fstream o("xyz.txt", ios::in);
            fstream i("abc.txt",ios::out);
            string l;
            bool f=false;
            while(getline(o,l)){
               if(l.substr(0,l.find(","))!= to_string(rn)){
                    i<<l<<endl;
               } 
               else{
                    f = true;    
               }
            }
            o.close();
            i.close();
            if(!f)
            {
                cout<<"nahi sapdla" ;
            }
            else{
                cout<<"zhal delete ;)";
                remove("xyz.txt");
                rename("abc.txt","xyz.txt");
            }
            
        }
        void display()
        {
            cout<<"------------------------------------";
            fstream o("xyz.txt",ios::in);
                string l;
                while(getline(o,l)){
                    cout<<l<<endl;
                }
        }
        

};

int main()
{   
    int ch;
    cout<<"What Operation You Would Like to Perform : "<<endl;
    cout<<"1.Insert Data "<<endl;
    cout<<"2.Delete Data "<<endl;
    cout<<"3.Display Data "<<endl;
    cin>>ch;
    Student s;
    if(ch==1){
        s.insert();
    }
    else if(ch==2){
        s.delet();
    }
    else{
        s.display();
    }
    return 0;
}