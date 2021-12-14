#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct promotores {
    char nombre[30];
    float porcComision;
};


bool cargarPromotores();

int main()
{
    if(cargarPromotores())
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

bool cargarPromotores() {

    promotores unPromotor;
    std::vector <promotores> vectorPromotores;

    strncpy_s(unPromotor.nombre, "Juan", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 23.5;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Heriberto", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 29.7;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Carlos", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 83.5;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Maria", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 37.7;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Juana", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 55.5;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Diana", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 73.1;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Leonor", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 23.5;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Marcos", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 11.5;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Natalia", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 19.9;
    vectorPromotores.push_back(unPromotor);

    strncpy_s(unPromotor.nombre, "Nicolas", sizeof(unPromotor.nombre));
    unPromotor.porcComision = 23.5;
    vectorPromotores.push_back(unPromotor);

    const auto vector_size = size(vectorPromotores);
    std::ofstream miArchivo("promotores.dat", std::ios::binary);
    miArchivo.write(reinterpret_cast<const char*>(&vector_size), sizeof(vector_size));
    miArchivo.write(reinterpret_cast<const char*>(data(vectorPromotores)), sizeof(decltype(vectorPromotores)::value_type) * vector_size);
    miArchivo.close();
    
    std::vector <promotores> vectorLeerPromotores;
    size_t vectorLeer_size;
    std::ifstream miArchivoLeer("promotores.dat", std::ios::binary);
    miArchivoLeer.read(reinterpret_cast<char*>(&vectorLeer_size), sizeof(vectorLeer_size));
    vectorLeerPromotores.resize(vectorLeer_size);
    miArchivoLeer.read(reinterpret_cast<char*>(data(vectorLeerPromotores)), sizeof(decltype(vectorLeerPromotores)::value_type) * vectorLeer_size);
    miArchivo.close();

    for (const promotores& element : vectorLeerPromotores) {
        std::cout << element.nombre << std::endl;
        std::cout << element.porcComision << std::endl;
    }

    if(vectorLeerPromotores.size() > 0)
        return true;
    return false;

}
