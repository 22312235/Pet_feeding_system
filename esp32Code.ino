#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESP32Servo.h>

// ==============================
// CONFIG
// ==============================
const char* WIFI_SSID = "CIU-NET_WIFI";   // Open WiFi (uni wifi)

const String SUPABASE_URL      = "https://nkalwrqyuixhirwpmfce.supabase.co";
const String SUPABASE_API_URL  = SUPABASE_URL + "/rest/v1/FeedingRequests";
const String SUPABASE_ANON_KEY = "sb_publishable_D-iIqd8nx2QdVWGGemTKTg_7oAEt_ru";

Servo myservo;

// Relay pin
#define RELAY_PIN 14    


// ==============================
// SETUP
// ==============================
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // relay OFF

  Serial.println("\nConnecting WiFi...");
  WiFi.begin(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    delay(400);
    Serial.print(".");
  }

  Serial.println("\nConnected.");
}


// ==============================
// LOOP
// ==============================
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  checkForTask();
  delay(3000);
}


// ==============================
void reconnectWiFi() {
  Serial.println("WiFi re-connecting...");
  WiFi.disconnect();
  WiFi.begin(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nWiFi reconnected.");
}


// ==============================
void checkForTask() {
  HTTPClient http;
  String url = SUPABASE_API_URL + "?status=eq.pending&select=*&order=id.desc&limit=1";

  http.begin(url);
  http.addHeader("apikey", SUPABASE_ANON_KEY);
  http.addHeader("Authorization", "Bearer " + SUPABASE_ANON_KEY);

  int code = http.GET();
  if (code != 200) {
    Serial.print("GET error: ");
    Serial.println(code);
    http.end();
    return;
  }

  String res = http.getString();
  http.end();

  Serial.println("GET: " + res);

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, res);

  if (doc.size() == 0) {
    Serial.println("No pending tasks.");
    return;
  }

  int id = doc[0]["id"];
  int amount = doc[0]["amount"];

  Serial.println("Task Detected! Amount: " + String(amount));

  runFeeding(amount);

  markFeeded(id);
}


// ==============================
void runFeeding(int amount) {
  Serial.println("Feeding...");

  // turn relay ON
  digitalWrite(RELAY_PIN, HIGH);
  delay(200);  

  myservo.attach(15);

  // forward
  myservo.write(90);
  delay(2000);

  // backward
  myservo.write(0);
  delay(2000);

  myservo.detach();

  digitalWrite(RELAY_PIN, LOW);

  Serial.println("Feeding done.");
}


// ==============================
void markFeeded(int id) {
  HTTPClient http;
  String url = SUPABASE_API_URL + "?id=eq." + String(id);

  http.begin(url);
  http.addHeader("apikey", SUPABASE_ANON_KEY);
  http.addHeader("Authorization", "Bearer " + SUPABASE_ANON_KEY);
  http.addHeader("Content-Type", "application/json");

  String body = "{\"status\":\"feeded\"}";

  int code = http.PATCH(body);
  Serial.println("PATCH code: " + String(code));

  http.end();
}
