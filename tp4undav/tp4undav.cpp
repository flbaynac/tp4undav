#include <iostream>
#include <string>
#include <cstdlib>
#include "fileMan.h"

struct promotores {
    char nombre[30];
    float porcComision;
};

struct telefonos {
    char desc[20];
    int precio;
};

bool cargarPromotores();
bool cargarTelefonos();

int main() {

    int returnStatus = EXIT_FAILURE;
    if (cargarPromotores() && cargarTelefonos())
        return EXIT_SUCCESS;
    return returnStatus;
}

bool cargarPromotores() {

    char nombres[10][10] = { {"Juan"},{"Heriberto"},{"Carlos"},{"Maria"},{"Juana"},{"Diana"},{"Leonor"},{"Marcos"},{"Natalia"},{"Nicolas"}};
    promotores vectorPromotores[10];

    for (int i = 0; i < sizeof(vectorPromotores)/sizeof(vectorPromotores[0]); i++) {
        strncpy_s(vectorPromotores[i].nombre, nombres[i], sizeof(vectorPromotores[0].nombre));
        vectorPromotores[i].porcComision = rand() % 100;
    }
    
    return saveVecToFile(vectorPromotores, sizeof(vectorPromotores), "promotores.dat");
}

bool cargarTelefonos() {
    
    char modelos[10][10] = { {"Nokia1"},{"Moto1"},{"Alcatel1"},{"Uauei1"},{"Nokia2"},{"Nokia3"},{"Samsung7"},{"Moto2"},{"Moto3"},{"Alcatel2"} };
    telefonos vectorTelefonos[10];

    for (int i = 0; i < sizeof(vectorTelefonos) / sizeof(vectorTelefonos[0]); i++) {
        strncpy_s(vectorTelefonos[i].desc, modelos[i], sizeof(vectorTelefonos[0].desc));
        vectorTelefonos[i].precio = rand() % 100;
    }

    return saveVecToFile(vectorTelefonos, sizeof(vectorTelefonos), "telefonos.dat");
}
