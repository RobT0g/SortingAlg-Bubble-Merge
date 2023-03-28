#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

void showList(int *l, int t){
    for(int i = 0; i < t; i++)
        cout << l[i] << " ";
    cout << endl;
}

void testList(int *l, int t){
    bool sorted = true;
    for(int i = 0; i < t-1; i++){
        if(l[i] > l[i+1]){
            sorted = false;
            break;
        }
    }
    if(sorted)
        cout << "List sorted successfully" << endl;
    else
        cout << "Failed to sort the list" << endl;
}

int *copy(int *l, int t){
    int *n = (int*) malloc(sizeof(int)*t);
    for(int i = 0; i < t; i++)
        n[i] = l[i];
    return n;
}

void swap(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int run(int *l, int t){
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
    //testList(l, t);
    //showList(l, t);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-beg);
    return duration.count();
}

int main(){
    ofstream fil;
    int size, *lista;
    cin >> size;
    lista = (int*) malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        cin >> lista[i];
    }
    string name = "Outputs/" + to_string(size/1000) + "-bubble.txt";
    fil.open(name);
    for(int i = 0; i < 60; i++){
        int t = run(copy(lista, size), size);
        if(i > 19){
            fil << t;
            if(i != 59)
                fil << endl;
        }
        cout << "Elapsed time for the " << i+1 <<"th run: " << t << endl;
    }
}
