/*Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client‘s telephone number. Make use of 
Quadratic Probing technique to handle collision and compare them using number 
of comparisons required to find a set of telephone numbers*/
#include<iostream>
#define MAX 10
using namespace std;
class teledb{
    public:
        string naa[MAX];
        int na[MAX];
        string name;
        long no;
        int n;
        teledb(){
            for(int i=0;i<MAX;i++){
                naa[i]="";
                na[i]=-1;
            }
        }
        int cnt=0;
        void insert(){
            cout<<"Enter  Number of Records : ";
            cin>>n;
            for(int i=0;i<n ;i++){
            cout<<"Enter Name : ";
            cin>>name;
            int x= name.length()%MAX;
            while(naa[x]!="")
            {
                x=(x+(i*i))%MAX;
                cnt++;
            }
            cout<<"Enter Phone : ";
            cin>>no;
            naa[x]=name;
            na[x]=no;
            cout<<"Inserted at "<<x<<"with "<<cnt<<" Comparisions"<<endl;
            }
        }
        void show(){
            cout<<"Enter Name : ";
            cin>>name;
            int x= name.length()%MAX;
            if(naa[x]==name){
                cout<<"Name: "<<naa[x]<<endl;
                cout<<"Phone: "<<na[x]<<endl;
            }
            else{
                int i=0;
                while(naa[x]!=name){
                    int x=(x+(i*i))%MAX;
                    i++;
                }
            }
        }
};
int main()
{
    teledb t1;
    t1.insert();
    t1.show();
    return 0;
}