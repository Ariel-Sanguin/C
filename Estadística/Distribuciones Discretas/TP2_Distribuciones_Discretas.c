#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double  Combinatoria(int, int);
void Binomial(float, int, int);
void Hipergeometrica(int, int, int, int);
void Geometrica (float, int);
void BinomialNegativa(int, float, int);
int main(){
    int opcion, n, k, total, x;
    float p;

    printf("\nSeleccione la distribucion deseada: \n0-Salir\n1-Binomial\n2-Binomial negativa\n3-Geometrica\n4-Hipergeometrica\n");
    scanf("%d", &opcion);
    if(!opcion) return 0;
    if(opcion==1){
        printf("\nIndique los valores de probabilidad de exito (p): ");
        scanf("%f",&p);
        printf("\nIndique el tamano de la muestra/Cantidad de intentos: ");
        scanf("%d",&n);
        printf("\nCantidad de exitos buscados: ");
        scanf("%d",&k);
        Binomial(p, n, k);
    }
    if(opcion==2){
        printf("\nIndique la cantidad de exitos buscados: ");
        scanf("%d",&k);
        printf("\nIndique la probabilidad: ");
        scanf("%f",&p);
        printf("\nIngrese la cantidad pruebas para lograr los exitos: ");
        scanf("%d", &n);
        BinomialNegativa(k, p, n);
    }
    if(opcion==3){
        printf("\nIngrese la probabilidad de exito p: " );
        scanf("%f",&p);
        printf("\nIngrese la cantidad de pruebas hasta lograr un exito: ");
        scanf("%d",&k);
        Geometrica(p, k);
    }
    if(opcion==4){
        printf("\nIngrese el tamano de la poblacion: ");
        scanf("%d",&total);
        printf("\nIngrese el numero de exitos en la poblacion: ");
        scanf("%d", &k);
        printf("\nIngrese el tamano de la muestra: ");
        scanf("%d",&n);
        printf("\nIngrese la cantidad exitos buscada en la muestra: ");
        scanf("%d", &x);
        Hipergeometrica(total, k, n, x);
    }
    return 0;
}

void Binomial(float p, int n, int k){
    double esperanza, varianza, prob[n+1],resultado ;
    float q;
    int i;
    esperanza= n*p;
    q= 1-p;
    varianza= n*p*q;
    for(i=0;i<=n;i++){
       resultado=Combinatoria(n,i)*pow(p,i)*pow(q,n-i);
       prob[i]= resultado;
    }

    printf("\nEsperanza: %0.2f", esperanza);
    printf("\nVarianza: %0.2f", varianza);
    printf("\nDesvio Estandar: %0.2f", sqrt(varianza));
    printf("\nProbabilidad buscada (x=%d): %0.3f",k, prob[k]);
    printf("\nX     Probabilidad");
    for(i=0;i<=n;i++){
    printf("\n%d      %0.3f",i, prob[i]);}

}
void BinomialNegativa(int k, float p, int n){
    float q;
    double probabilidad;
    q= 1-p;
    probabilidad= Combinatoria(n-1, k-1)*pow(p,k)*pow(q, n-k);
    printf("\nProbabilidad (X=%d)= %0.3f", k, probabilidad);
}

void Geometrica(float p, int k){
    float q, probabilidad;

    q= 1-p;
    probabilidad= pow(q,k-1)*p;
    printf("\nLa probabilidad de tener q hacer %d pruebas hasta tener un exito es: %f", k, probabilidad);
}

void Hipergeometrica(int total, int k,int  n,int  x){
    double termino1, termino2, termino3,  prob[n+1];
    int i;

    for(i=0; i<=n;i++){
        termino1= Combinatoria(k, i);
        termino2= Combinatoria(total-k, n-i);
        termino3= Combinatoria(total, n);
        prob[i]= termino1 * termino2 / termino3;
    }
    printf("\nProbabilidad Buscada (X=%d) : %0.3f",x, prob[x]);

    printf("\nX     Probabilidad");
    for(i=0;i<=n;i++){
    printf("\n%d      %0.3f",i, prob[i]);}

}
 double  Combinatoria(int n, int k){
    double combi, i, fact1, fact2, fact3;
    if(n>=k){
        fact1=1;
        for(i=1;i<=n;i++){
        fact1= fact1*i;}
        fact2=1;
        for(i=1;i<=k;i++){
        fact2= fact2*i;}
        fact3=1;
        for(i=1;i<=n-k;i++){
        fact3= fact3*i;}
        combi= fact1/(fact2*fact3);
        return combi;
     }

    }
