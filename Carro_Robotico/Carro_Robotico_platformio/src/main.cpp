#include <Arduino.h>
#include <WiFi.h>

// Pines de los motores
int motor1Pin1 = 25;
int motor1Pin2 = 26;
int motor2Pin1 = 27;
int motor2Pin2 = 33;
int port = 8144;
WiFiServer server(port);

// Credenciales de WiFi
const char *ssid = "rasJaveriana";
const char *passwd = "rasjaveriana2023";

void setup() {
  Serial.begin(9600);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Configurar conexión WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConectado a WiFi");
  Serial.println(WiFi.localIP());

  // Iniciar el servidor WiFi
  server.begin();
}

void moverAdelante() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moverAtras() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void detenerMotores() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void loop() {
  WiFiClient client = server.available();
  String read_ros = "";

  if (client) {
    Serial.println("Cliente conectado");
    while (client.connected()) {
      while (client.available() > 0) {
        char data = client.read();
        if (data == '\n') break;
        read_ros += data;
      }
      
      if (read_ros.length() > 0) {
        Serial.print("Comando recibido: ");
        Serial.println(read_ros);

        // Convierte el comando recibido a un número entero
        int command = read_ros.toInt();

        // Realizar acciones según el comando recibido
        switch (command) {
          case 1:
            moverAdelante();
            break;
          case 2:
            moverAtras();
            break;
          default:
            detenerMotores();
            break;
        }

        // Limpia el comando después de procesarlo
        read_ros = "";
      }
    }
    client.stop();
    Serial.println("Cliente desconectado");
  }
}