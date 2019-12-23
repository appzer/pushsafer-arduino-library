#include <ESP8266WiFi.h>
/*#include <WiFiClientSecure.h>*/
#include <WiFiClient.h>
#include <Pushsafer.h>

// Initialize Wifi connection to the router
char ssid[] = "ssid";     // your network SSID (name)
char password[] = "password"; // your network key

// Pushsafer private or alias key
#define PushsaferKey "XXXXXXXXXXXXX"

/*WiFiClientSecure client;*/
WiFiClient client;
Pushsafer pushsafer(PushsaferKey, client);

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pushsafer.debug = true;

  // Take a look at the Pushsafer.com API at
  // https://www.pushsafer.com/en/pushapi
  
  struct PushSaferInput input;
  input.message = "This is a test message";
  input.title = "Hello!";
  input.sound = "8";
  input.vibration = "1";
  input.icon = "1";
  input.iconcolor = "#FFCCCC";
  input.priority = "1";
  input.device = "a";
  input.url = "https://www.pushsafer.com";
  input.urlTitle = "Open Pushsafer.com";
  input.picture = "";
  input.picture2 = "";
  input.picture3 = "";
  input.time2live = "";
  input.retry = "";
  input.expire = "";
  input.answer = "";

  Serial.println(pushsafer.sendEvent(input));
  Serial.println("Sent");
  
  // client.stop();
}

void loop() {
}
