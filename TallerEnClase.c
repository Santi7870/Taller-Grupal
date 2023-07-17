#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularArea(float a, float b, float c, float d, float e, float f);
float calcularVolumen(float areaBase, float altura);
float calcularVolumen2(float areaBase, float distancia_baricentro_p4);

int main() {
    float puntos[4][3] = {{0, 0, 0}, {0, 0, 3}, {3, 0, 0}, {1, 7, 1}};
    float a, b, c, d, e, f;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    printf("El perimetro de la piramide es: %.2f\n", perimetro);

    float areaBase = calcularArea(a, b, c, d, e, f);
    printf("El área de la pirámide es: %.2f\n", areaBase);

    float baricentrox = (puntos[0][0] + puntos[1][0] + puntos[2][0]) / 3;
    float baricentroy = (puntos[0][1] + puntos[1][1] + puntos[2][1]) / 3;
    float baricentroz = (puntos[0][2] + puntos[1][2] + puntos[2][2]) / 3;

    float distanciabaricentro = calcularDistancia(baricentrox, baricentroy, baricentroz, puntos[3][0], puntos[3][1], puntos[3][2]);

    float altura = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], baricentrox, baricentroy, baricentroz);

    float volumen = calcularVolumen(areaBase, distanciabaricentro);
    printf("El volumen de la pirámide es: %.2f\n", volumen);

    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f) {
    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

    *d = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    float per = *a + *b + *c + *d + *e + *f;
    return per;
}

float calcularArea(float a, float b, float c, float d, float e, float f) {
    float s = (a + b + c) / 2;
    float areaBase = sqrt(s * (s - a) * (s - b) * (s - c));
    float areaTriangulo1 = 0.5 * a * d;
    float areaTriangulo2 = 0.5 * b * e;
    float areaTriangulo3 = 0.5 * c * f;
    return areaBase + areaTriangulo1 + areaTriangulo2 + areaTriangulo3;
}


float calcularVolumen(float areaBase, float distanciabaricentro) {
    return (areaBase * distanciabaricentro) / 3;
}
