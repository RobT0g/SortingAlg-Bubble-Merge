#include <iostream>
using namespace std;

int binary(int *l, int e, int f, int t){
    //list, element, from, to
    if(f == t){
        if(l[f] < e)
            return f+1;
        return f;
    }
    int h = (f+t)/2;
    cout << "h: " << h << " ";
    if (l[h] < e){
        if(h == t)
            return h;
        cout << h+1  << " - " << t << endl;
        return binary(l, e, h+1, t);
    }
    if(h == f)
        return h;
    cout << f << " - " << h-1 << endl;
    return binary(l, e, f, h-1);
}

int main(){
    int *l = (int*) malloc(sizeof(int)*50);
    for(int i = 0; i < 50; i++){
        l[i] = i*2;
        cout << l[i] << " ";
    }
    cout << endl << binary(l, 3, 0, 49);

    return 0;
}