/*Assume we have two input and two output tapes to perform the sorting. The 
internal memory can hold and sort m records at a time. Write a program in java 
for external sorting. Find out time complexity. */

public class nineteen{
    public static void conquer(int arr[], int si,int mid, int ei){
        int mer[] = new int[ei-si+1];
        int a= si;
        int b = mid+1;
        int c = 0;
        while(a<=mid && b<=ei)
        {
            if(arr[a]<=arr[b])
            {
                mer[c++]=arr[a++];
            }
            else{
                mer[c++]=arr[b++];
            }
        }
        while(a<=mid){
            mer[c++]=arr[a++];
        }
        while(b<=ei){
            mer[c++]=arr[b++];
        }
        for(int i=0,j=si;i<mer.length;i++,j++){
            arr[j]=mer[i];
        }
    }
    public static void divide(int arr[], int si, int ei){
        if(si>=ei){
            return;
        }
        int mid = (si+ei)/2;
        divide(arr,si,mid);
        divide(arr,mid+1,ei);
        conquer(arr,si,mid,ei);


    }
    public static void main(String[] args){
        int arr[] ={9,5,10,11,2,7};
        int n= arr.length;  
        divide(arr,0,n-1);
        for(int i=0;i<n;i++){
            System.out.println(arr[i]+" ");
        }
    }   
}