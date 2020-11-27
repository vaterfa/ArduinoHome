#include <ESP8266WiFi.h>
#include <Servo.h>

Servo motor;

const char* ssid     = "ssid";          //ESP'nin bağlanacağı WiFi adı.
const char* password = "pass";          //WiFi şifresi.

WiFiServer server(80);

String baslik;

String role2Durum="off";
String role1Durum="off";
String servoDurum="0";

#define role1 4
#define role2 0
#define servo 5
#define mesafeSensor 2
#define gazSensor A0

unsigned long anlikSure = millis();
unsigned long oncekiSure = 0;
const long asimSuresi = 2000;

void setup() {
  Serial.begin(115200);

  motor.attach(servo);

  pinMode(role2, OUTPUT);
  pinMode(role1, OUTPUT);

  Serial.print(ssid);
  Serial.println(" ağına bağlanılıyor.");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Ağa bağlanıldı.");
  Serial.println("IP adresi : ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient alici = server.available();

  if (alici) {                             
    Serial.println("Yeni bağlantı.");
    String currentLine = "";
    anlikSure = millis();
    oncekiSure = anlikSure;
    while (alici.connected() && anlikSure - oncekiSure <= asimSuresi) {
      anlikSure = millis();         
      if (alici.available()) {
        char c = alici.read();
        Serial.write(c);
        baslik += c;
        if (c == '\n') {
          
          if (currentLine.length() == 0) {            
            
            alici.println("HTTP/1.1 200 OK");
            alici.println("İçerik Türü : metin/html");
            alici.println();
       
            if (baslik.indexOf("GET /0/on") >= 0) {
              Serial.println("GPIO 0 aktif");
              role2Durum = "aktif";
              digitalWrite(role2, HIGH);
            } 
            else if (baslik.indexOf("GET /0/off") >= 0) {
              Serial.println("GPIO 0 pasif");
              role2Durum = "pasif";
              digitalWrite(role2, LOW);
            } 
            else if (baslik.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 aktif");
              role1Durum = "aktif";
              digitalWrite(role1, HIGH);
            } 
            else if (baslik.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 pasif");
              role1Durum = "pasif";
              digitalWrite(role1, LOW);
            }
            else if (baslik.indexOf("GET /5/0") >= 0) {
              Serial.println("Servo 0 derece");
              servoDurum = "0";
              motor.write(0);
            }        
            else if (baslik.indexOf("GET /5/90") >= 0) {
              Serial.println("Servo 90 derece");
              servoDurum = "90";
              motor.write(90);
            }  
            alici.println("<!DOCTYPE html><html>");
            alici.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            alici.println("<link rel=\"icon\" href=\"data:,\">");

            alici.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            alici.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            alici.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            alici.println(".button2 {background-color: #77878A;}</style></head>");
            
            alici.println("<body><h1>ESP8266 Ev Sistemi</h1>");              
                        
            alici.println("<p>GPIO 4 " + role1Durum + " durumda</p>");
            
            if (role1Durum=="pasif") {
              alici.println("<p><a href=\"/4/on\"><button class=\"button\">ACIK</button></a></p>");
            } else {
              alici.println("<p><a href=\"/4/off\"><button class=\"button button2\">KAPALI</button></a></p>");
            }
            
            alici.println("<p>GPIO 0 " + role2Durum + " durumda</p>");
     
            if (role2Durum=="pasif") {
              alici.println("<p><a href=\"/0/on\"><button class=\"button\">ACIK</button></a></p>");
            } else {
              alici.println("<p><a href=\"/0/off\"><button class=\"button button2\">KAPALI</button></a></p>");
            } 
            
            alici.println("<p>Servo " + servoDurum + " derecede</p>");
           
            if (servoDurum=="0") {
              alici.println("<p><a href=\"/5/90\"><button class=\"button\">0 DERECE</button></a></p>");
            } 
            else if(servoDurum=="90"){
              alici.println("<p><a href=\"/5/0\"><button class=\"button\">90 DERECE</button></a></p>");
            }
                   
            
            alici.println("</body></html>");            
            
            alici.println();

           break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    baslik = "";

    alici.stop();
    Serial.println("Bağlantı kesildi.");
    Serial.println("");
  }
}
