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

void merge(int *l, int f, int h, int t){
    //cout << f << " - " << h << " - " << t << endl;
    int ind1 = f, ind2 = h+1, ind = 0;
    int *ar = new int[t-f+1];
    while(ind1 <= h && ind2 <= t){
        if(l[ind1] < l[ind2])
            ar[ind++] = l[ind1++]; 
        else
            ar[ind++] = l[ind2++]; 
    }
    while(ind1 <= h)
        ar[ind++] = l[ind1++]; 
    while(ind2 <= t)
        ar[ind++] = l[ind2++]; 
    for(int i = 0; i <= t-f; i++){
        l[i+f] = ar[i];
    }
    delete ar;
}

void div(int *l, int f, int t){
    //cout << f << " - " << t << endl;
    if(f >= t)
        return;
    int h = (f+t)/2;
    div(l, f, h);
    div(l, h+1, t);
    merge(l, f, h, t);
}

int run(int *l, int t){
    auto beg = high_resolution_clock::now();
    div(l, 0, t-1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-beg);
    testList(l, t);
    //showList(l, t);
    delete l;
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
    string name = "Outputs/" + to_string(size/1000) + "-merge.txt";
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
