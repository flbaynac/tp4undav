#include <iostream>
#include <string>
#include <cstdlib>
#include "fileMan.h"

#define TOPE_VECTOR 10

struct promotores {
    char nombre[30];
    float porcComision;
};

struct telefonos {
    char desc[20];
    int precio;
};

struct venta {
    char nombrePromotor[30];
    char descTelefono[20];
    int cantVendida, diaVenta;
};

bool cargarPromotores();
bool cargarTelefonos();
bool cargarVentas();
bool generarVentasValidasInvalidas();

int main() {

    if (cargarPromotores() && cargarTelefonos() && cargarVentas() && generarVentasValidasInvalidas())
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

bool cargarPromotores() {

    char nombres[TOPE_VECTOR][10] = { {"Juan"},{"Heriberto"},{"Carlos"},{"Maria"},{"Juana"},{"Diana"},{"Leonor"},{"Marcos"},{"Natalia"},{"Nicolas"}};
    promotores vectorPromotores[TOPE_VECTOR];

    for (int i = 0; i < sizeof(vectorPromotores)/sizeof(vectorPromotores[0]); i++) {
        strncpy_s(vectorPromotores[i].nombre, nombres[i], sizeof(vectorPromotores[0].nombre));
        vectorPromotores[i].porcComision = rand() % 100;
    }
    
    return saveVecToFile(vectorPromotores, sizeof(vectorPromotores), "promotores.dat");
}

bool cargarTelefonos() {
    
    char modelos[TOPE_VECTOR][10] = { {"Nokia1"},{"Moto1"},{"Alcatel1"},{"Uauei1"},{"Nokia2"},{"Nokia3"},{"Samsung7"},{"Moto2"},{"Moto3"},{"Alcatel2"} };
    telefonos vectorTelefonos[TOPE_VECTOR];

    for (int i = 0; i < sizeof(vectorTelefonos) / sizeof(vectorTelefonos[0]); i++) {
        strncpy_s(vectorTelefonos[i].desc, modelos[i], sizeof(vectorTelefonos[0].desc));
        vectorTelefonos[i].precio = rand() % 100;
    }

    return saveVecToFile(vectorTelefonos, sizeof(vectorTelefonos), "telefonos.dat");
}

bool cargarVentas() {

    char nombresVendedores[TOPE_VECTOR][10] = { {"Juan"},{"Heriberto"},{"Juana"},{"12236"},{"Juana"},{"Diana"},{"Alberto"},{"Marcos"},{"Natalia"},{"Nicolas"} };
    char descTelefonos[TOPE_VECTOR][10] = { {"Nokia1"},{"12222"},{"Alcatel1"},{"####"},{"Nokia2"},{"Nokia3"},{"Zamsung7"},{"Moto22"},{"Moto3"},{"Alcatel2"} };
    venta vecVentas[TOPE_VECTOR];

    for (int i = 0; i < sizeof(vecVentas) / sizeof(vecVentas[0]); i++) {
        strncpy_s(vecVentas[i].descTelefono, descTelefonos[i], sizeof(vecVentas[0].descTelefono));
        strncpy_s(vecVentas[i].nombrePromotor, nombresVendedores[i], sizeof(vecVentas[0].nombrePromotor));
        vecVentas[i].cantVendida = rand() % 30;
        vecVentas[i].diaVenta = rand() % 31;
    }
    
    return saveVecToFile(vecVentas, sizeof(vecVentas), "ingresoVentas.dat");
}

bool generarVentasValidasInvalidas() {
    
    bool exit_success = false;
    venta vecVentas[TOPE_VECTOR];
    venta vecVentasValidas[TOPE_VECTOR];
    venta vecVentasInvalidas[TOPE_VECTOR];
    int cantidad_validas = 0, cantidad_invalidas = 0;
    telefonos vecTelefonos[TOPE_VECTOR];
    promotores vecPromotores[TOPE_VECTOR];
    if (readVecFromFile(vecVentas, sizeof(vecVentas), "ingresoVentas.dat")) {
        if ((readVecFromFile(vecTelefonos, sizeof(vecTelefonos), "telefonos.dat")) && readVecFromFile(vecPromotores, sizeof(vecPromotores), "promotores.dat")) {
            for (int i = 0; i < sizeof(vecVentas) / sizeof(vecVentas[0]); i++) {
                bool telefono_es_valido = false;
                bool promotor_es_valido = false;
                for (int j = 0; j < sizeof(vecTelefonos) / sizeof(vecTelefonos[0]); j++) {
                    std::cout << "vecVentas[" << i << "].descTelefono: " << vecVentas[i].descTelefono << std::endl;
                    std::cout << "vecTelefonos[" << j << "].desc: " << vecTelefonos[j].desc << std::endl;
                    if (strcmp(vecVentas[i].descTelefono, vecTelefonos[j].desc) == 0)
                        telefono_es_valido = true;
                }
                for (int j = 0; j < sizeof(vecPromotores) / sizeof(vecPromotores[0]); j++) {
                    if (strcmp(vecVentas[i].nombrePromotor, vecPromotores[j].nombre) == 0)
                        promotor_es_valido = true;
                }
                if (telefono_es_valido && promotor_es_valido) {
                    vecVentasValidas[cantidad_validas] = vecVentas[i];
                    cantidad_validas =+ 1;
                }
                else {
                    vecVentasInvalidas[cantidad_invalidas] = vecVentas[i];
                    cantidad_invalidas = +1;
                }
            }
            if (saveVecToFile(vecVentasValidas, cantidad_validas * sizeof(venta), "ventasValidas.dat") && saveVecToFile(vecVentasInvalidas, cantidad_invalidas * sizeof(venta), "ventasErroneas.dat"))
                exit_success = true;
        }
    }
    return exit_success;
}
