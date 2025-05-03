/*Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client‘s telephone number. Make use of Linear 
Probing technique to handle collision and compare them using number of 
comparisons required to find a set of telephone numbers*/

//let the hash fn be number of letters in the name
#include<iostream>
#include<string>
#define MAX 10
using namespace std;
class teledb{
    public:
        teledb(){
            for(int i=0;i<MAX;i++){
                na[i] = "";
                ta[i] = -1;
            }
        }
        string na[MAX];
        long ta[MAX];
        int n;
        long tele;
        string name;
        void insert(){
            cout<<"Enter  Number of Records : ";
            cin>>n;
            for(int i=0;i<n ;i++){
            cout<<"Enter Name : ";
            cin>>name;  
            int x = name.length() %MAX;
            int cnt=0;
            while(na[x]!="")
            {
                x=(x+1)%MAX;
                cnt++;
            }
            na[x]=name;
            cout<<"Enter Number : ";
            cin>>tele;
            ta[x]=tele;
            cout<<"Record Inserted at "<<x<<"with "<<cnt<<"comparisions"<<endl;
            }
        }
        void show()
        {
            cout<<"Enter Name : ";
            cin>>name;
            int x = name.length()%MAX;
            while(na[x]!=""){
                if(na[x]==name){
                    cout<<"Name : "<<na[x]<<"Phone : "<<ta[x];
                    break;
                }
                else{
                x=(x+1)%MAX;}
            }
        }
};
int main(){
    teledb t1;
    t1.insert();
    t1.show();
    return 0;
}