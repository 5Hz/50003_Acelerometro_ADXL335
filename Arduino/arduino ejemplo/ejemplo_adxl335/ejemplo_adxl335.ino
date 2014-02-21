/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por: autorcillo                                               **
** Basado en el código de: autorcillo original                   **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el acelerómetro ADXL335                          **
**                                                               **
*******************************************************************
Conexiones:
UNO   ADXL335

3.3V  VCC
GND   GND
A2    ZOUT
A3    YOUT
A4    XOUT
*/


/*
descripcion del codigo
*/

//-----------------------------------------------------------definiciones
#define ST 10

//--------------------------------------------------definiciones de pines
const int analogInPinX = A4;  // Pin de entrada analógica conectado al Eje X 
const int analogInPinY = A3;  // Pin de entrada analógica conectado al Eje Y
const int analogInPinZ = A2;  // Pin de entrada analógica conectado al Eje Z



//----------------------------------------------------------configuracion
void setup()
{
  pinMode(ST,OUTPUT);
  digitalWrite(ST,LOW);
  Serial.begin(9600);
  Serial.println("Programa de ejemplo para el sensor ADXL335");
  Serial.println("x - y - z");
}

//#########################################################ciclo principal
void loop()
{
  Serial.print(analogRead(analogInPinX));
  Serial.print(" - ");
  Serial.print(analogRead(analogInPinY));
  Serial.print(" - ");
  Serial.println(analogRead(analogInPinZ));
  delay(250);
}
//##################################################fin del ciclo principal



