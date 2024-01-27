#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "controlAmpero-setup";
const char *password = NULL;

AsyncWebServer server(80);

void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}

String homePage()
{
    return " \
    ";
}

void webAppInit(void)
{
    // Setting the ESP as an access point
    Serial.print("Setting AP (Access Point)…");

    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    WiFi.softAP(ssid, password);

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String html = "<html><body>";
        html += "<form method='post' action='/submit'>";
        html += "Name: <input type='text' name='name'><br>";
        html += "Message: <textarea name='message'></textarea><br>";
        html += "<input type='submit' value='Submit'>";
        html += "</form>";
        html += "</body></html>";
        request->send(200, "text/html", html); });

    // Route for form submission
    server.on("/submit", HTTP_POST, [](AsyncWebServerRequest *request) {
        String name;
        String message;

        if(request->hasParam("name", true)) {
            name = request->getParam("name", true)->value();
        }
        if(request->hasParam("message", true)) {
            message = request->getParam("message", true)->value();
        }

        String response = "Name: " + name + "<br>Message: " + message;
        request->send(200, "text/html", response); 
    });

    // Route for listing patches as JSON
    server.on("/patches", HTTP_GET, [](AsyncWebServerRequest *request)
                {
        String json;
        DynamicJsonDocument doc(1024);

        // Populate JSON array with patch names
        JsonArray array = doc.to<JsonArray>();
        for (const char* patch : patches) {
        array.add(patch);
        }

        // Serialize JSON to string
        serializeJson(doc, json);
        
        request->send(200, "application/json", json); 
    });

    // Start server
    server.begin();
}
