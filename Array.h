//
// Created by lujim on 19/9/2023.
//
#include <cstdlib>
#include <stdexcept>
#include <iostream>

#ifndef TUTOPAGINAION_ARRAY_H
#define TUTOPAGINAION_ARRAY_H


class Array {
private:
    int page_num = 0;       // número de página
    int elem_size = sizeof(int); // tamaño de cada elemento
    int page_size = 16;     // tamaño de página (bloque en bytes)
    int page[4];            // página en memoria (el tamaño de la página es page_size/elem_size)
    int file_size;          // tamaño del archivo completo (en cantida de elementos)
    int storage[1024];      // almacenamiento (simulado, en cantidad de elementos)

public:

    Array(int* file, int file_size);

    int operator[](int index);
};


#endif //TUTOPAGINAION_ARRAY_H
