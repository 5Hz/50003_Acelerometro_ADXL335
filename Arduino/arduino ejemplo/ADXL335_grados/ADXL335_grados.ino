//Definimos los pines analogicos en los que estan cada uno de los ejes  
#define xPin  A4       
#define yPin  A3  
#define zPin  A2  
#define ST 2
//mínimos y máximos del acelerometro  
int minVal = 405;      
int maxVal = 609;  

//creamos tres variables double para almacenar las lecturas de cada eje  
double x;      
double y;  
double z;  
  
void setup ( ) { 
 pinMode(ST,OUTPUT);
  digitalWrite(ST,LOW); 
    //iniciamos la comunicación por serial a 9600 baudios  
    Serial.begin(9600);  
}  
  
void loop ( ) {  
    //leemos los valores de cada eje del acelerometro  
    int xRead = analogRead(xPin);     
    int yRead = analogRead(yPin);  
    int zRead = analogRead(zPin);  

    //convertimos las lecturas en valores propocionales entre -90 y 90  
    int xAng = map(xRead, minVal, maxVal, -100, 100);  
    int yAng = map(yRead, minVal, maxVal, -100, 100);  
    int zAng = map(zRead, minVal, maxVal, -100, 100);  

    //hacemos la conversión de radianes a grados  
   y = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);  
   x = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);  
   z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI); 

    //Enviamos por serial las lecturas  
    Serial.print("x: ");  
    Serial.print(x);  
    Serial.print("   y: ");  
    Serial.println(y);  
//    Serial.print("   z: ");  
//    Serial.println(z);  
  
    //esperamos un una decimia de segundo y volvemos a leer.  
    delay(200);         
} 
