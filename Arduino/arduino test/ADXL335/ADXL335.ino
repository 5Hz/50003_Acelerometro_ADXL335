#define ST 10

const int analogInPinX = A4;  // Analog input pin that the potentiometer is attached to
const int analogInPinY = A3;  // Analog input pin that the potentiometer is attached to
const int analogInPinZ = A2;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int opcion = 0;
int barras;

int entrada;
void setup(){
//  analogReference(EXTERNAL);
  pinMode(ST,OUTPUT);
  digitalWrite(ST,LOW);
  Serial.begin(9600);

//  do{
//  }while(Serial.available()==0);
//  if(Serial.available()>0){
    menu();
//  }
}

void loop(){
  if (opcion == 1)  // indica que se seleccionó una opción válida
    leer_sensor_x();
    if (opcion == 2)  // indica que se seleccionó una opción válida
    leer_sensor_y();
    if (opcion == 3)  // indica que se seleccionó una opción válida
    leer_sensor_z();
   
   if ((opcion == 4) || (opcion == 5)|| (opcion == 0))
    menu();
  if (Serial.available()){
    entrada=Serial.read();
    if(entrada=='*'){
      menu();
    }
    
  }
}


void menu(){
  int entradaMenu;
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL ADXL335");
  Serial.println("");
  Serial.println("            YA ESTAS LISTO??");
Serial.println("");
    Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("MENU PRINCIPAL");
  Serial.println("1- X");
  Serial.println("2- Y");
  Serial.println("3- Z");
  Serial.println("4- ACTIVAR SELFTEST");
  Serial.println("5- DESACTIVAR SELFTEST (MODO NORMAL)");
  
 
  do{
  }while(Serial.available()==0);
      entradaMenu=Serial.read();
    switch(entradaMenu){
   
    case '4':
      digitalWrite(ST,HIGH);
       Serial.println("");
      Serial.println("SELF TEST Activado");
      delay(1000);
      opcion = 4;
      break;
      
    case '5':
       digitalWrite(ST,LOW);
      Serial.println("");
      Serial.println("MODO NORMAL DE OPERACION");
      Serial.println(".............");
      delay(1000);
      opcion = 5;
      break;
      
        case '1':
      Serial.println("");
      Serial.println("X");
      Serial.println(".............");
      delay(1000);
      opcion = 1;
      break;
      
      
        case '2':
 
      Serial.println("");
      Serial.println("Y");
      Serial.println(".............");
      delay(1000);
      opcion = 2;
      break;
      
      
        case '3':
     Serial.println("");
      Serial.println("Z");
      Serial.println(".............");
      delay(1000);
      opcion = 3;
      break;
      
      
    default:
      Serial.println("Opcion no valida");
      opcion = 0;
      break;
    }
    
    if ((opcion == 1) || (opcion == 2) || (opcion == 3))
    Serial.println("Hola soy la TERMINAL DE 5Hz (teclea * para ir al menu) cuando termines ");
    delay(1000);

}

  
  
void leer_sensor_x() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinX);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}

void leer_sensor_y() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinY);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}

void leer_sensor_z() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinZ);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}
