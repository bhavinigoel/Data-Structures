#include<iostream>
using namespace std;

class heap{
    int arr[100];
    int size;

    public:

    heap(){
        arr[0]=-1;
        size =0;
        
    }

    void insert(int val){
        size =size + 1;
        int index =size ;
        arr[index]=val;

        while(index > 1){

            int parent = index/2;
            if( arr[index]>arr[parent ]){

               swap( arr[parent], arr[index]);
                index =parent;

            }
            else{
            return;}


    }
    }
    void print(){
        for(int i=1; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};
int main(){
    heap h;
     h.insert(5);
     h.insert(8);
     h.insert(90);
     h.insert(78);
     h.insert(56);
     h.insert(72);
     h.insert(17);
     h.print();

    

}