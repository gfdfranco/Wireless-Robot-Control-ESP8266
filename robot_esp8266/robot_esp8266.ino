//Gerardo Franco Delgado
#include <ESP8266WiFi.h>

const char* ssid = "ESP8266_Robot";
const char* password = "password123";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT); // Motor driver connected to GPIO16 (D0)
  pinMode(D1, OUTPUT); // Motor driver connected to GPIO5 (D1)
  pinMode(D2, OUTPUT); // Motor driver connected to GPIO4 (D2)
  pinMode(D3, OUTPUT); // Motor driver connected to GPIO0 (D3)

  WiFi.softAP(ssid, password); // Set up the Access Point
  Serial.println("Access Point Started");
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients
  if (!client) {
    return;
  }

  while(!client.available()){
    delay(1);
  }

  String request = client.readStringUntil('\r'); // Read the first line of the request
  client.flush(); // Clear the incoming buffer
  request.trim();

  Serial.print("Received command: ");
  Serial.println(request);

  String command = parseCommand(request);
  handleCommand(command); // Handle the incoming command

  // HTML content with control buttons
  // HTML content with control buttons and enhanced CSS for better mobile visibility
  String htmlResponse = "<!DOCTYPE HTML><html>";
  htmlResponse += "<head><title>ESP8266 Robot Control</title>";
  htmlResponse += "<style>";
  htmlResponse += "body { font-family: Arial, sans-serif; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; }";
  htmlResponse += "h1 { font-size: 40px; margin: 20px; }";
  htmlResponse += "button { background-color: #4CAF50; color: white; border: none; padding: 20px 40px; text-align: center; text-decoration: none; display: inline-block; font-size: 30px; margin: 10px; cursor: pointer; border-radius: 10px; }";
  htmlResponse += "button:hover { background-color: #45a049; }";
  htmlResponse += "</style></head><body>";
  htmlResponse += "<h1>Robot Control Panel</h1>";
  htmlResponse += "<button onclick=\"location.href='/forward'\">Forward</button>";
  htmlResponse += "<button onclick=\"location.href='/reverse'\">Reverse</button>";
  htmlResponse += "<button onclick=\"location.href='/left'\">Left</button>";
  htmlResponse += "<button onclick=\"location.href='/right'\">Right</button>";
  htmlResponse += "<button onclick=\"location.href='/stop'\">Stop</button>";
  htmlResponse += "</body></html>";

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println(htmlResponse); // Send the HTML page with buttons
  client.stop();

}

String parseCommand(String request) {
  int firstSpaceIndex = request.indexOf(' ');
  int secondSpaceIndex = request.indexOf(' ', firstSpaceIndex + 1);
  if (firstSpaceIndex != -1 && secondSpaceIndex != -1) {
    return request.substring(firstSpaceIndex + 1, secondSpaceIndex);
  }
  return "";
}

void handleCommand(String command) {
  Serial.print("Executing command: ");
  Serial.println(command);

  if (command == "/forward") {
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
  } else if (command == "/reverse") {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
  } else if (command == "/right") {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
  } else if (command == "/left") {
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
  } else if (command == "/stop") {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
  }
}
