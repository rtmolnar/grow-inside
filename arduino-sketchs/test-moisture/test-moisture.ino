#include <ESP8266WiFi.h>

int sense_Pin = 0; // sensor input at Analog pin A0
int value = 0;
const char* ssid = "........";
const char* password = "........";

void connectToWiFi(void)
{
    client.stop();
    Serial.println("Connecting to WiFi...");
    Serial.println();  
    delay(1000);
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
 
    Serial.println("");
    Serial.println("WiFi connectado com sucesso!");  
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
 
    delay(1000);
}

float readMoisture(void)
{
    int ValorADC;
    float UmidadePercentual;
 
     ValorADC = analogRead(0);   //978 -> 3,3V
     Serial.print("[Leitura ADC] ");
     Serial.println(ValorADC);
     UmidadePercentual = 100 * ((1024-(float)ValorADC) / 1024);
     Serial.print("[Umidade Percentual] ");
     Serial.print(UmidadePercentual);
     Serial.println("%");
 
     return UmidadePercentual;
}

void setup() {
   Serial.begin(9600);
   void FazConexaoWiFi(void);
   delay(2000);
}

void loop() {

   Serial.print("MOISTURE LEVEL : ");
   value= readMoisture();
   Serial.println(value);



   delay(1000);
}
