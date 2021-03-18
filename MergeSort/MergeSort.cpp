
//COSTO DI ESECUZIONE O(nlogn)

#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

void stampaArray(int A[],int n);
void Merge(int A[],int first, int mid, int last);
void MergeSort(int A[],int first, int last);



int main(int argc, char **argv)
{

int myArray[MAX]= {4,5,3,1,2,6,7,10,9,8};
int arr_size = sizeof(myArray) / sizeof(myArray[0]);

cout<<"Array NON ordinato"<<endl;
stampaArray(myArray,MAX);

MergeSort(myArray,0,arr_size-1);

cout<<"Array ordinato"<<endl;
stampaArray(myArray,MAX);

return 0;

}

void stampaArray(int A[],int n){
	for(int i=0; i<n; i++){
		cout<<"["<<A[i]<<"]"<<" ";
	}
    cout<<endl;
}


void Merge(int A[],int first, int mid, int last){
    
    int n1 = mid - first+1;
    int n2 = last - mid;

    //creao array di appoggio
    int L[n1];
    int R[n2];

    //copio valori nei 2 sottoArray
    for(int a=0; a<n1; a++){
        L[a]=A[first+a];
    }
    for(int b=0;b<n2;b++){
        R[b]=A[mid+1+b];
    }

    int i=0;
    int j= 0;
    int k=first;

    // Ordinamento array A confrontando valori dei 2 sottovettori
    while(i < n1 && j < n2){
        if(L[i]<R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
        k++;

    }
    //inserimento valori rimasti
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }

}

void MergeSort(int A[],int first, int last){
    if(last<=first){
        //array vuoto , iterrompi la ricorsione!
        return;
    }
    int m = first+(last-first)/2;
    //DA SEGMENTATION FAULT !! int m = first+last/2;
    MergeSort(A,first,m);
    MergeSort(A,m+1,last);
    Merge(A,first,m,last);
        
}

