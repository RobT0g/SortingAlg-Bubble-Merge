#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void swap(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int run(int t, int *l){
    auto beg = high_resolution_clock::now();
    for(int i = 0; i < t; i++){
        bool c = false;
        for(int j = t-1; j > 0; j--){
            if(l[j] < l[j-1]){
                swap(&l[j], &l[j-1]);
                c = true;
            }
        }
        if(!c)
            break;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-beg);
    return duration.count();
}

int *copy(int t, int *l){
    int *n = (int*) malloc(sizeof(int)*t);
    for(int i = 0; i < t; i++)
        n[i] = l[i];
    return n;
}

int main(){
    ofstream fil;
    fil.open("example.txt");
    int size, *lista, *result;
    cin >> size;
    lista = (int*) malloc(sizeof(int)*size);
    result = (int*) malloc(sizeof(int)*40);
    for(int i = 0; i < size; i++){
        cin >> lista[i];
    }
    for(int i = 0; i < 60; i++){
        int t = run(size, copy(size, lista));
        if(i > 19)
            result[i-20] = t;
        cout << "Elapsed time for the " << i+1 <<"th run: " << t << endl;
    }
}

