#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Create an instance of the server
WebServer server(80);

// Define the LED pin
const int ledPin = 13;
bool ledState = false; // Initial state of the LED

// HTML content for the web page
const char* htmlContent = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Web Server</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; }
    h1 { color: #0F3376; padding: 2vh; }
    p { font-size: 1.5rem; }
    button { padding: 10px 24px; font-size: 1rem; }
  </style>
</head>
<body>
  <h1>ESP32 Web Server</h1>
  <p>Click the button to toggle LED:</p>
  <button onclick="toggleLED()">Toggle LED</button>
  <p id="status">LED is OFF</p>
  <script>
    function toggleLED() {
      fetch('/toggle').then(response => response.text()).then(state => {
        document.getElementById('status').innerText = 'LED is ' + state;
      });
    }
  </script>
</body>
</html>
)rawliteral";

// Function to handle the root path
void handleRoot() {
  server.send(200, "text/html", htmlContent);
}

// Function to handle the toggle path
void handleToggle() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState ? HIGH : LOW);
  server.send(200, "text/plain", ledState ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", handleRoot);

  // Route to toggle LED state
  server.on("/toggle", handleToggle);

  // Start server
  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
  server.handleClient();
}

