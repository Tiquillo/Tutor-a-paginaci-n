//
// Created by lujim on 19/9/2023.
//


#include "Array.h"

Array::Array(int *file, int file_size) {
    this->file_size = file_size;                // copiando el tamaño del arreglo

    for (int i = 0; i < this->file_size; ++i) {
        storage[i] = file[i];                   // guarda el arreglo en almacenamiento
    }

    for (int i = 0; i < 4; ++i) {           // guarda la primer página en memoria
        page[i] = storage[i];               // al instanciar Array (la clase).
    }                                       // Este paso es opcional, pero en caso
                                            // de que no se configure, se debe establecer
                                            // page_num = -1 o algún valor menor a 0.
}


int Array::operator[](int index) {

    // Verifica que el índice esté dentro del rango
    if (index > file_size -1) throw std::out_of_range("Index out of range.");

    if (page_num != index * elem_size / page_size) { // Si el índice invoca un elemento
                                                    // que no está en la página actual

        std::cout << "Cambiando pagina " << page_num;

        page_num = index * elem_size / page_size;   // Cambia a la página donde sí está

        std::cout << " a " << page_num << "." << std::endl;

        for (int i = 0; i < elem_size; ++i) {

            // Y copia los datos desde el alamacenamiento hacia la página

            page[i] = storage[page_size / elem_size * page_num + i];

        }
    }
    // retorna el elemento del arreglo
    // (el módulo es en caso de que el índice sea mayor al tamaño de la página)
    return page[index % elem_size];
}
