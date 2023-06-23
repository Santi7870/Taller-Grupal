#include <stdio.h>
#include <math.h>
int main (int argc, char *argv[]) {

    float puntos[3][2]={{0,0},{0,3},{3,0}};

    float perimetro=calcularPerimetro(puntos);
    float area = calcularArea(puntos);



    printf("El perimetro del triangulo es: %f", perimetro);
    printf("El area del triangulo es: %f", area);
    return 0;


}

float calcularDistancia(float x1, float y1, float x2, float y2 ){
    float dist= sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return dist;
}

float calcularPerimetro(float puntos[3][2]){
    float a = calcularDistancia(puntos[0][0],puntos[0][1],puntos [1][0],puntos[1][1]);
    float b = calcularDistancia(puntos[0][0],puntos[0][1],puntos [2][0],puntos[2][1]);
    float c = calcularDistancia(puntos[2][0],puntos[2][1],puntos [1][0],puntos[1][1]);
    float per=a+b+c;
    return per;
}

float calcularArea(float puntos[3][2]){
    float a = calcularDistancia(puntos[0][0],puntos[0][1],puntos [1][0],puntos[1][1]);
    float b = calcularDistancia(puntos[0][0],puntos[0][1],puntos [2][0],puntos[2][1]);
    float c = calcularDistancia(puntos[2][0],puntos[2][1],puntos [1][0],puntos[1][1]);
    float s=(a+b+c)/2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
