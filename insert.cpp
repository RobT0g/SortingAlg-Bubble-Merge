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

int binary(int *l, int e, int f, int t){
    //list, element, from, to
    if(f == t){
        if(l[f] < e)
            return f+1;
        return f;
    }
    int h = (f+t)/2;
    if (l[h] < e){
        if(h == t)
            return h;
        return binary(l, e, h+1, t);
    }
    if(h == f)
        return h;
    return binary(l, e, f, h-1);
}

void insert(int *l, int e, int pos, int c){
    //list, element, position, currentSize
    for(int i = c; i > pos; i--){
        l[i] = l[i-1];
    }
    l[pos] = e;
}

int run(int *l, int t){
    auto beg = high_resolution_clock::now();
    int *sorted = (int*) malloc(sizeof(int)*t);
    sorted[0] = l[0];
    for(int i = 1; i < t; i++){
        insert(sorted, l[i], binary(sorted, l[i], 0, i-1), i);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-beg);
    //testList(sorted, t);
    //showList(sorted, t);
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
    string name = "Outputs/" + to_string(size/1000) + "-insert.txt";
    fil.open(name);
    for(int i = 0; i < 60; i++){
        int t = run(copy(lista, size), size);
        if(i > 19){
            fil << t;
            if(i != 59)
                fil << endl;
        }
        cout << "Elapsed time for the " << i+1 <<"th run: " << t << endl;
        break;
    }
}