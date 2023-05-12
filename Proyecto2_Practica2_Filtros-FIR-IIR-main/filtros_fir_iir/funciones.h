

/* Inicio de variables para emular un onda seno */
int m = 0;  /* Número muestras */
int n = 0; /* Número de la muestra (actual) */
int entrada_generador=0;


/*----------Senos para filtros FIR  -------------*/
int sine_FIR_20Hz[]={
    2000,  2062,  2125,  2187,  2248,  2309,  2368,  2425,  2481,  2535,  2587,  2637,  2684,  2728,  2770,  2809,  2844,  2876,  2904,  2929,  2951,  2968,  2982,  2992,  2998,  3000,  2998,  2992,  2982,  2968,  2951,  2929,  2904,  2876,  2844,  2809,  2770,  2728,  2684,  2637,  2587,  2535,  2481,  2425,  2368,  2309,  2248,  2187,  2125,  2062,  2000,  1937,  1874,  1812,  1751,  1690,  1631,  1574,  1518,  1464,  1412,  1362,  1315,  1271,  1229,  1190,  1155,  1123,  1095,  1070,  1048,  1031,  1017,  1007,  1001,  1000,  1001,  1007,  1017,  1031,  1048,  1070,  1095,  1123,  1155,  1190,  1229,  1271,  1315,  1362,  1412,  1464,  1518,  1574,  1631,  1690,  1751,  1812,  1874,  1937
    };
/*-------------------  -  -------------------*/

int sine_FIR_10Hz[]={
    4095,  4962,  5658,  6044,  6044,  5658,  4962,  4095,  3227,  2531,  2145,  2145,  2531,  3227
};   // FIR: frecuencia de 10 Hz 
/*-------------------  -  -------------------*/

int sine_FIR_25Hz[]={
    4095,  5896,  5658,  3649,  2145
};   // FIR: frecuencia de 25 Hz 

/*---------Senos para los filtros IIR---------*/
int sine_IIR_1Hz[]={
    511,523,536,548,560,572,584,596,607,618,628,638,647,656,665,672,679,686,691,696, 
    701,704,707,709,710,711,710,709,707,704,701,696,691,686,679,672,665,656,647,638,
    628,618,607,596,584,572,560,548,536,523,511,498,485,473,461,449,437,425,414,403,
    393,383,374,365,356,349,342,335,330,325,320,317,314,312,311,311,311,312,314,317,
    320,325,330,335,342,349,356,365,374,383,393,403,414,425,437,449,461,473,485,498,
};   // FIR: frecuencia de 1 Hz
/*-------------------  -  -------------------*/

int sine_IIR_10Hz[]={
    511,628,701,701,628,511,393,320,320,393
};   // FIR: frecuencia de 10 Hz 
/*-------------------  -  -------------------*/

int sine_IIR_25Hz[]={
    511, 711, 511, 311
};   // FIR: frecuencia de 25 Hz 
/*-------------------  -  -------------------*/

  

/*****************************  COEFICIENTES FILTROS FIR  *****************************/

/*ORDEN: 7*/

const int BL = 8;
const int B[8] = {
      1,   11,   41,   75,   75,   41,   11,    1
};

/*-------------------------------------------------------------------------*/

/*ORDEN : 11*/
/*
const int BL = 12;
const int B[12] = {
      0,    1,    5,   19,   42,   63,   63,   42,   19,    5,    1,    0
};
*/
/*-------------------------------------------------------------------------*/
/*ORDEN: 17*/
 /*
const int BL = 18;
const int B[18] = {
      0,    0,    1,    1,   -3,  -11,    0,   46,   94,   94,   46,    0,
    -11,   -3,    1,    1,    0,    0
};
*/
/*-------------------------------------------------------------------------*/

/*ORDEN: 30*/
/*
const int BL = 32;
const int B[32] = {
      0,    0,    0,    0,    0,   -1,    1,    2,   -3,   -4,    6,    9,
    -13,  -21,   37,  115,  115,   37,  -21,  -13,    9,    6,   -4,   -3,
      2,    1,   -1,    0,    0,    0,    0,    0
};
*/

/*-------------------------------------------------------------------------*/  

/* Inicio de variables volatiles para pasar datos entre funciones */
volatile int x[BL];
volatile int k = 0;
volatile int k1 = 0;


/*****************************  FILTROS IIR  *****************************/


const int order = 3;  

/*FILTRO PASA-BAJOS*/
/*
//SECTION 1//
const float Gi = 0.0779563405; //Ganancia

const float Bi[order] = { // Numeradores
            1,2,1
};

const float Ai[order] = { // Denominadores
            1,-1.3209134308,0.63273879
};
  
//SECTION 2//
const float Gj = 0.0618851952997; //Ganancia

const float Bj[order] = { // Numeradores
            1,2,1
};

const float Aj[order] = { // Denominadores
            1,-1.04859957636,0.29614035
};

*/
/*FILTRO PASA-ALTAS*/
/*
//SECCION 1//
const float Gi = 0.73573334845; //Ganancia

const float Bi[order] = { // Numeradores
            1,-2,1
};

const float Ai[order] = { // Denominadores 
            1,-1.3127774425,0.63015595
};
  
//SECCION 2//
const float Gj = 0.5832121525; //Ganancia

const float Bj[order] = { // Numeradores
            1,-2,1
};

const float Aj[order] = { // Denominadores
            1,-1.0406321253,0.292216484
};
 */

/*Filtro rechaza banda*/

//SECCION 1//
const float Gi = 0.99115358977; //Ganancia

const float Bi[3] = { // Numeradores
            1,-0.00000000000000001224743499,1
};

const float Ai[3] = { // Denominadores
            1,0.1761594,0.98238545077
};
  
//SECTION 2  //
const float Gj = 0.99115358977; //ganancia

const float Bj[3] = { // Numeradores
            1,-0.00000000000000001224743499,1
};

const float Aj[3] = { // Denominadores 
            1,-0.1761594,0.98238545077
};

/* variables volatiles*/
volatile float y1;
volatile float x_i;
volatile float v[3];
volatile float w[3];


/* Variables especificas */
int walk = 0;
int cont = 0;
uint32_t ts1,ts2;
unsigned int index=0;

/* Definiciones del ejemplo */
/* Ientradas */

#define MEDIRTIEMPOS 0

#define RUIDO 1
#define PASO 2
#define IMPULSO 3
#define SENO_FIR_20Hz 4
#define SENO_FIR_10Hz 5
#define SENO_FIR_25Hz 6
#define SENO_FIR_30Hz 7
#define SENO_FIR_50Hz 8
#define SENO_IIR_1Hz 9
#define SENO_IIR_10Hz 10
#define SENO_IIR_25Hz 11
#define SENO_IIR_60Hz 12
#define entrada_generador 13


/* salidas */
#define FIR1 1
#define FIR2 2
#define FIR3 3
#define FIR4 4
#define IIR1 5

long filtrarFIR1(int in){
    
int i = 1;
x[k] = (int)in;
long y = 0;

for (i=1; i<=BL; i++){ 
    y += (long)(B[i-1]) * (long)(x[(i + k) % BL]);
} /* for */
 
k = (k+1) % BL;
return y>>8; 

} /* filtrarFIR1 */


/*** FIR 2  ***/

long filtrarFIR2(int in){
 
int i = 0;
x[k] = in;
long y = 0;
int inx = k;

for(i = 0; i < BL; ++i){
    y += (long)x[inx] * (long) B[i];
    inx = inx != 0 ? inx-1 : BL-1;
} /* for */

k++;
k = (k>=BL) ? 0:k;
return y>>8; 

} /* filtrarFIR2 */


/*** FIR 3 ***/

long filtrarFIR3(int in){
int i = 0;
x[k] = in;
int inx = k;
int *apuntadorcoef = &B[0];
volatile int *apuntadorarrc = &x[inx];
long y = 0;

for(i = 0; i < BL; ++i) {
    y += (long)(*apuntadorarrc) * (long)(*apuntadorcoef); 
    apuntadorcoef++;
    if(inx != 0){
        apuntadorarrc--;
        inx--;
    } else {
        apuntadorarrc=&x[BL-1];
        inx=BL-1;
    }
} /* for */

k++;
k = (k>=BL) ? 0:k;
return y>>8;

} /* filtrarFIR3 */

/*** FIR 4 ***/

long filtrarFIR4(int in){
int i = 0; 
x[k] = in;
long y = 0;  
int inx = k; 
int half = ((BL - 1)/2);   
int count = inx + 1;
char odd;
  
odd = (BL&(1<<0)) ? 1:0;
  
if (count>=BL){
    count = 0; 
} /* if */
    
if (odd) {
/*---------------------------  ODD COEFFICIENTS  -----------------------------*/
    for (i = 0; i < half ; ++i){
        y += (long)(B[i])*((long)(x[inx]) + (long)(x[count])); 
        inx = inx != 0 ? inx-1 : BL-1;
        count++;
        count = (count >= BL) ? 0:count; 
    } /* for */
    y += ((long)(B[half]))*((long)(x[count]));  
} else {
/*---------------------------  EVEN COEFFICIENTS  ----------------------------*/
    for (i = 0; i < BL/2; ++i){
        y += (long)(B[i])*((long)(x[inx]) + (long)(x[count])); 
        inx = inx != 0 ? inx-1 : BL-1;    
        count++;
        count = (count >= BL) ? 0:count; 
    } /* for */ 
} /* if */
        
k++;
k = (k>=BL) ? 0:k;
   
 return y>>8;

} /* filtrarFIR4 */

/***IIR 1***/

float filtrarIIR1(int in){

x_i = (float)in;
long y = 0;
  
/*-------------------------------  SECTION 1  --------------------------------*/
x_i = x_i*Gi;
v[0] = x_i*Ai[0]-Ai[1]*v[1]-Ai[2]*v[2];
y1 = Bi[0]*v[0]+Bi[1]*v[1]+Bi[2]*v[2];
v[2] = v[1];
v[1] = v[0];

/*-------------------------------  SECTION 2  --------------------------------*/
y1 = y1*Gj;
w[0] = y1*Aj[0]-Aj[1]*w[1]-Aj[2]*w[2];
y = Bj[0]*w[0]+Bj[1]*w[1]+Bj[2]*w[2];
w[2] = w[1];
w[1] = w[0];

return y; 

} /* filtrarIIR1 */
