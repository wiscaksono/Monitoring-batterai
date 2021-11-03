#include <Vcc.h>

const float VccMin   = 0.0;           // Minimum expected Vcc level, in Volts.
const float VccMax   = 5.0;           // Maximum expected Vcc level, in Volts.
const float VccCorrection = 1.0/1.0;  // Measured Vcc by multimeter divided by reported Vcc
float Vout = 0;
double Current = 0;
const double scale_factor = 0.066;
const double resConvert = 1024;
float vRef;
double zeroPoint;
double resADC;
Vcc vcc(VccCorrection);
float analog;

void setup()
{
  Serial.begin(115200);
}

float ambilanalog()
{
  delay(350);
  return analogRead(A0);
}
  
void loop()
{  
  vRef = vcc.Read_Volts();
  zeroPoint = vRef/2;
  resADC = vRef/resConvert;
  Vout = Vout + (resADC * ambilanalog());
  Current = (Vout - zeroPoint)/scale_factor;
  
  Serial.print("analog = ");
  Serial.println(analogRead(A0));
  Serial.print("Vout = ");
  Serial.print(Vout,10);
  Serial.println(" Volts");
  Serial.print("Current = ");
  Serial.print(Current,10);
  Serial.println(" Ampere \n");
  delay(1000);
  Vout=0;
}