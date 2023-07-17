#include <stdio.h>

int idMascota[10];
char nombreMascota[10][50];
char razaMascota[10][50];
int edadMascota[10];
char nombreDueno[10][50];

int idServicio[10][5];
char nombreServicio[5][50] = {"Baño", "Corte de pelo", "Vacunación", "Desparasitación", "Revision general"};
char descripcionServicio[5][100] = {"Limpieza y aseo del pelaje", "Corte de pelo y arreglo personalizado", "Administración de vacunas", "Tratamiento antiparasitario", "Revision general de salud y peso"};
float precioServicio[5] = {10.0, 15.0, 5.0, 2.0, 20.0};

int cantidadServicios[10] = {0};
int cantidadMascotas = 0;

void ingresarMascota(int *id, char *nombre, char *raza, int *edad, char *nomdueño) {
    printf("Ingrese el ID de la mascota (Ingresar un ID que pueda recordar posteriormente, solo números): ");
    scanf("%d", id);
    printf("Ingrese el nombre de la mascota: ");
    scanf("%s", nombre);
    printf("Ingrese la raza de la mascota (Si la raza contiene más de 1 palabra, separarlas con '_'): ");
    scanf("%s", raza);
    printf("Ingrese la edad de la mascota (En años): ");
    scanf("%d", edad);
    printf("Ingrese el nombre del dueño (Si desea ingresar Nombre y Apellido, separar con '_' Ej. Nombre_Apellido): ");
    scanf("%s", nomdueño);
    printf("Mascota ingresada con éxito.\n");
    
    idMascota[cantidadMascotas] = *id;
}

void mostrarServicios() {
    printf("\n****** Servicios disponibles ******\n");
    for (int i = 0; i < 5; i++) {
        printf("* %d %s - Precio: %.2f$ - Descripción: %s\n", i + 1, nombreServicio[i], precioServicio[i], descripcionServicio[i]);
    }
}

void ingresarServicio(int *idMascota) {
    if (cantidadMascotas == 0) {
        printf("No hay mascotas registradas.\n");
        return;
    }

    int idMascotaFacturar;
    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &idMascotaFacturar);

    int mascotaEncontrada = 0;
    int indiceMascota = 0;

    for (int i = 0; i < cantidadMascotas; i++) {
        if (idMascotaFacturar == idMascota[i]) {
            mascotaEncontrada = 1;
            indiceMascota = i;
            break;
        }
    }

    if (mascotaEncontrada==0) {
        printf("No se encontró la mascota con el ID ingresado, porfavor volver a intentarlo.\n");
        return;
    }

    if (cantidadServicios[indiceMascota] >= 5) {
        printf("No se pueden agregar más servicios a esta mascota.\n");
        return;
    }

    mostrarServicios();

    int opcion;
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 5) {
        printf("Opción inválida.\n");
        return;
    }

    idServicio[indiceMascota][cantidadServicios[indiceMascota]] = opcion - 1;

    cantidadServicios[indiceMascota]++;
    printf("Servicio ingresado con éxito.\n");
}

void facturarServicios(int *idMascota) {
    if (cantidadMascotas == 0) {
        printf("No hay mascotas registradas.\n");
        return;
    }

    int idMascotaFacturar;
    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &idMascotaFacturar);

    int mascotaEncontrada = 0;
    int indice2Mascota = 0;

    for (int i = 0; i < cantidadMascotas; i++) {
        if (idMascotaFacturar == idMascota[i]) {
            mascotaEncontrada = 1;
            indice2Mascota = i;
            break;
        }
    }

    if (mascotaEncontrada == 0) {
        printf("No se encontró la mascota con el ID ingresado.\n");
        return;
    }

    float precioTotal = 0.0;

    printf("\n****** Factura ******\n");
    printf("ID de la mascota: %d\n", idMascota[indice2Mascota]);
    printf("Nombre de la mascota: %s\n", nombreMascota[indice2Mascota]);
    printf("Raza de la mascota: %s\n", razaMascota[indice2Mascota]);
    printf("Edad de la mascota: %d\n", edadMascota[indice2Mascota]);
    printf("Nombre del dueño: %s\n", nombreDueno[indice2Mascota]);

    for (int i = 0; i < cantidadServicios[indice2Mascota]; i++) {
        int servicioIndice = idServicio[indice2Mascota][i];
        precioTotal += precioServicio[servicioIndice];
    }

    printf("Precio total: %.2f dólares\n", precioTotal);
}

int main() {
    int opcion;

    do {
        printf("\n****** Menú ******\n");
        printf("1) Ingresar animal\n");
        printf("2) Servicios\n");
        printf("3) Factura \n");
        printf("0) Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                ingresarMascota(&idMascota[cantidadMascotas], nombreMascota[cantidadMascotas], razaMascota[cantidadMascotas], &edadMascota[cantidadMascotas], nombreDueno[cantidadMascotas]);
                cantidadMascotas++;
                break;
            }
            case 2:
                ingresarServicio(idMascota);
                break;
            case 3:
                facturarServicios(idMascota);
                break;
            case 0:
                printf("Gracias por preferirnos.....\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
