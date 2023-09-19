
#include "Array.h"

using namespace std;

int main() {
    cout << "Bytes de un int: " << sizeof(int) << endl;

    int arreglo[] =
            {3,5,8,2,6,3,6,86,
             43,24,73,99,24,225,
             23,77,55,11,456,23, 66};

    int largo = (sizeof(arreglo)/ sizeof(*arreglo));

    Array array = Array(arreglo, largo);

    for (int i = 0; i < largo; ++i) {
        cout << "Elemento " << i << ": " << endl << array[i] << endl;
    }
}