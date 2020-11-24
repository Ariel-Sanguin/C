#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void VariablesContinuas(int );
void VariablesDiscretas(int);
int main(){

    int datos;
    int Tipo_datos;

    printf("\nIndique la cantidad de datos a ingresar: ");
    scanf("%d", &datos);

    printf("Indique que tipo de datos se tratan ingresando su numero correspondiente: \n0-Discretos\n1-Continuos\n3-Salir\n");
    scanf("%d",&Tipo_datos);

    if(Tipo_datos==3) return 0;
    if(Tipo_datos){
            printf("\nSelecciono variables continuas");
            VariablesContinuas(datos);}
    if(!Tipo_datos) {
            printf("Selecciono variables discretas");
            VariablesDiscretas(datos);}

    return 0;

}

void VariablesContinuas(int N){
    float datos[N];
    int i, j,CM=0, frecuencia[11]={}, frecuenciaAcum[11]={0};
    float menor, mayor, rango, long_clase, aux, media, sumatoria=0, moda;
    float mediana, varianza, sumavar=0;

    for(i=0; i<N; i++){
        printf("\n%d-Ingrese el dato: ", i+1);
        scanf("%f",&datos[i]);
    }

    for(i=0; i<N;i++){//ordenamiento
        for(j=0;j<N-1-i; j++){
            if(datos[j]> datos[j+1]){
                aux= datos[j];
                datos[j]= datos[j+1];
                datos[j+1]= aux;
            }
        }
    }

    menor= datos[0];
    mayor= datos[N-1];
    printf("\nel mayor es %0.2f y el menor es %0.2f", mayor, menor);
    rango = mayor - menor;
    printf("el rango es %f", rango);
    long_clase= rango/10;

    float lim_inf[11], lim_sup[11], MarcaClase[11];
    float Frelativa[11], FrelAcum[11];
    lim_inf[0]= datos[0];
    lim_sup[0]= datos[0] + long_clase;
    MarcaClase[0]= (lim_inf[0] + lim_sup[0])/2;
    for(i=1; i<11; i++){
        lim_inf[i]= lim_sup[i-1];
        lim_sup[i]= lim_inf[i] + long_clase;
        MarcaClase[i]= (lim_inf[i]+lim_sup[i])/2;
    }

    for(i=0; i<N; i++){
        for(j=0; j<11; j++){
            if(datos[i]>=lim_inf[j] && datos[i]<lim_sup[j]){
                frecuencia[j]= frecuencia[j]+1;
            }
        }
    }
    frecuenciaAcum[0]= frecuencia[0];
    for(i=1; i<11; i++){
        frecuenciaAcum[i]= frecuenciaAcum[i-1]+ frecuencia[i];
    }
    for(i=0;i<11;i++){
        sumatoria= sumatoria + (MarcaClase[i]*frecuencia[i]);
    }
    media= sumatoria/N;

    for(i=1; i<11;i++){//Busco pos de la clase modal
        if(frecuencia[i]>frecuencia[CM]) CM=i;
    }
    printf("\n\nClase Modal: %0.2f %0.2f", lim_inf[CM], lim_sup[CM]);
    printf("\n\nClase PreModal: %0.2f %0.2f", lim_inf[CM-1], lim_sup[CM-1]);
    printf("\n\nClase PosModal: %0.2f %0.2f", lim_inf[CM+1], lim_sup[CM+1]);

    float AB, CD;
    AB= frecuencia[CM]- frecuencia[CM-1];
    CD= frecuencia[CM]- frecuencia[CM+1];
    moda=((lim_sup[CM]*(AB/CD))+ lim_inf[CM])/(1+(AB/CD));

    float Icme=lim_inf[CM], Nme= N, Fpreme= frecuencia[CM-1], Fme= frecuencia[CM];//Para no hacer casteo

    mediana= lim_inf[CM]+ long_clase *(((Nme/2)-Fpreme)/Fme);

    for(i=0;i<11;i++){
        sumavar= sumavar + pow(MarcaClase[i]-media, 2)*frecuencia[i];
    }
    varianza= sumavar/(N-1);

    printf("\nLimInf     LimSup     Xi        fi       Fi    fri   Fri");
    for(i=0;i<11;i++){
        printf("\n%0.2f       %0.2f       %0.2f       %d       %d    %d/%d   %d/%d",
                lim_inf[i],lim_sup[i],MarcaClase[i], frecuencia[i], frecuenciaAcum[i], frecuencia[i], N, frecuenciaAcum[i],N);
    }
    printf("\nMedia: %0.2f", media);
    printf("\nModa: %0.2f", moda);
    printf("\nMediana: %0.2f",mediana);
    printf("\nVarianza: %0.2f", varianza);
    printf("\nDesvio estandar: %0.2f", sqrt(varianza));
}

void VariablesDiscretas(int N){
    int datos[N], i=0, j=0, aux, rango, contar, moda, PM=0, par=0, mediana;
    int DifDatos=0;
    float media, suma=0, varianza, sumaVar=0;

    for(i=0;i<N; i++){
        printf("\n%d-Ingrese dato: ",i+1);
        scanf("%d",&datos[i]);
    }
    for(i=0;i<N;i++){
        for(j=0;j<N-1-i;j++){
            if(datos[j]>datos[j+1]){
                aux= datos[j];
                datos[j]= datos[j+1];
                datos[j+1]= aux;
            }
        }
    }
    rango= datos[N-1]- datos[0];
    for(i=0;i<N;i++){
        suma= suma + datos[i];
    }
    media= suma/N;
    int x=0, z;
    while(x<N){//Busco la cantidad de datos diferentes para saber el largo del vector frecuencia
        z=x;
        while(datos[x]==datos[z]){
            z++;
        }
        DifDatos++;
        x=z;
    }
    int datosTabla[DifDatos], frecuencia[DifDatos], FrecuenciaAcum[DifDatos];
    i=0;//Tuve q volver a inicializar
    j=0;
    x=0;
    while(i<N){
        j=i;
        while(datos[i]== datos[j]){
            j++;
        }
        datosTabla[x]= datos[i];
        x++;
        i=j;
    }
    for(i=0; i<DifDatos;i++){
        j=0;
        contar=0;
        while(j<N){
            if(datos[j]==datosTabla[i]){
                contar++;
            }
            j++;
        }
        frecuencia[i]= contar;
    }
    FrecuenciaAcum[0]= frecuencia[0];
    for(i=1; i<DifDatos; i++){
        FrecuenciaAcum[i]= FrecuenciaAcum[i-1]+ frecuencia[i];
    }
    for(i=0;i<DifDatos;i++){
        if(frecuencia[i]>frecuencia[PM]) PM=i;
    }
    moda= datosTabla[PM];
    int CantModas=0;
    for(i=0;i<DifDatos;i++){
        if(frecuencia[i]==frecuencia[PM]) CantModas++;
    }
    if(N%2==0) par=1;

    if(par){
        mediana= (datos[(N-1)/2] + datos[(N-1)/2+1])/2;
    }
    else{
        mediana= datos[(N+1)/2];
    }

    for(i=0;i<DifDatos;i++){
        sumaVar= sumaVar + pow(datosTabla[i]-media, 2)*frecuencia[i];
    }
    varianza= sumaVar/(N-1);
    printf("\nX  fi   Fi     fir    Fir");
    for(i=0;i<DifDatos;i++){
        printf("\n%d  %d    %d     %d/%d    %d/%d", datosTabla[i], frecuencia[i],FrecuenciaAcum[i], frecuencia[i],N
               , FrecuenciaAcum[i], N);

    }
    printf("\nMediana: %d", mediana);
    printf("\nMedia:%0.2f", media);
    printf("\nVarianza: %0.2f", varianza);
    printf("\nDesvio estandar: %0.2f", sqrt(varianza));
    if(CantModas>1){
        printf("\nLa muestra es multimodal");
    }
    else{
        printf("\nLa muestra es unimodal");
        printf("\nModa: %d", moda);}
}
