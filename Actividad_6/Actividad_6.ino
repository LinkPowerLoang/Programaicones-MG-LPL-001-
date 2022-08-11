#include <WiFi.h>
#include <Wire.h> //Conexión de dispositivos I2C

// Replace with your network credentials
const char *ssid = "Familia_G-Ch";
const char *password = "FamiliK.13";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

int state = 0; // 0 para apagado, 1 para encendido
int state2 = 0;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

#include <TB6612_ESP32.h>

// MOTOR2
# define  BIN1  25
# define  BIN2  26
# define  PWMB  14

const int offsetB = 1;

Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, 0, 5000, 8, 2);

#include <EasyBuzzer.h>

int BUZZER_PIN = 27 ;

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  EasyBuzzer.setPin(BUZZER_PIN); //Initialize buzzer
}

void loop()
{
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /motor/on") >= 0)
            {
              state = 1;
              Serial.println("motor ON");
              motorencendido();
            }
            else if (header.indexOf("GET /motor/off") >= 0)
            {
              state = 0;
              Serial.println("motor OFF");
              motorapagado();
            }

             // turns the GPIOs on and off
            if (header.indexOf("GET /buzzer/on") >= 0)
            {
              state2 = 1;
              Serial.println("buzzer ON");
              buzzerencendido();
            }
            else if (header.indexOf("GET /buzzer/off") >= 0)
            {
              state2 = 0;
              Serial.println("buzzer OFF");
              buzzerapagado();
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences //motor
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #00FFC9; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button_2 {background-color: #000000;}</style></head>");
            //buzzer
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button_3 { background-color: #00FFC9; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button_4 {background-color: #000000;}</style></head>");


            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");

            // Display current state, and ON/OFF buttons for GPIO 26
            // If the output26State is off, it displays the ON button
            if (state == 1)
            {
              client.println("<p>Motor Encendidos</p>");
              client.println("<p><a href=\"/motor/off\"><button class=\"button button_2\">OFF</button></a></p>");
            }
            else
            {
              client.println("<p>Motor Apagados</p>");
              client.println("<p><a href=\"/motor/on\"><button class=\"button\">ON</button></a></p>");
            }

            if (state2 == 1)
            {
              client.println("<p>Buzzer Encendidos</p>");
              client.println("<p><a href=\"/buzzer/off\"><button class=\"button_3 button_4\">OFF</button></a></p>");
            }
            else
            {
              client.println("<p>Buzzer Apagados</p>");
              client.println("<p><a href=\"/buzzer/on\"><button class=\"button_3\">ON</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

  void motorencendido()
  {  
    forward(motor2,motor2, 100);
    delay(1000);
  } 
  void motorapagado()
  {
    brake(motor2,motor2);
    delay(1000);
  }

  void buzzerencendido()
  {
    EasyBuzzer.beep(500); 
    delay(500);
  }
  void buzzerapagado()
  {
    EasyBuzzer.beep(0); 
    delay(500); 
  }
