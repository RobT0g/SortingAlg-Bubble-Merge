#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int main(){
    int t, *l;
    cin >> t;
    l = (int*) malloc(sizeof(int)*t);
    for(int i = 0; i < t; i++){
        cin >> l[i];
    }
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
    auto duration = duration_cast<microseconds>(end-beg);
    cout << "Elapsed time " << duration.count() << endl;
    return 0;
    for(int i = 0; i < t; i++)
        cout << l[i] << " ";

    return 0;
}

