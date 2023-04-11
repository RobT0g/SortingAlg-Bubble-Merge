#include <iostream>
using namespace std;



int main(int argc, char **argv){
    bool save = false, display = false;
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
        if(argv[i][0] == '-' && argv[i][1] == 's')
            save = true;
        if(argv[i][0] == '-' && argv[i][1] == 'd')
            display = true;
    }
    cout << "save: " << save << " display " << display << endl;

    return 0;
}