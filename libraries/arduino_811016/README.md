# AsyncWebServer_Ethernet

[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncWebServer_Ethernet.svg?)](https://www.ardu-badge.com/AsyncWebServer_Ethernet)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncWebServer_Ethernet.svg)](https://github.com/khoih-prog/AsyncWebServer_Ethernet/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncWebServer_Ethernet.svg)](http://github.com/khoih-prog/AsyncWebServer_Ethernet/issues)

---
---

## Table of contents

* [Table of contents](#table-of-contents)
* [Why do we need this AsyncWebServer_Ethernet library](#why-do-we-need-this-AsyncWebServer_Ethernet-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Important things to remember](#important-things-to-remember)
* [Principles of operation](#principles-of-operation)
  * [The Async Web server](#the-async-web-server)
  * [Request Life Cycle](#request-life-cycle)
  * [Rewrites and how do they work](#rewrites-and-how-do-they-work)
  * [Handlers and how do they work](#handlers-and-how-do-they-work)
  * [Responses and how do they work](#responses-and-how-do-they-work)
  * [Template processing](#template-processing)
* [Request Variables](#request-variables)
  * [Common Variables](#common-variables)
  * [Headers](#headers)
  * [GET, POST and FILE parameters](#get-post-and-file-parameters)
  * [JSON body handling with ArduinoJson](#json-body-handling-with-arduinojson)
* [Responses](#responses)
  * [Redirect to another URL](#redirect-to-another-url)
  * [Basic response with HTTP Code](#basic-response-with-http-code)
  * [Basic response with HTTP Code and extra headers](#basic-response-with-http-code-and-extra-headers)
  * [Basic response with string content](#basic-response-with-string-content)
  * [Basic response with string content and extra headers](#basic-response-with-string-content-and-extra-headers)
  * [Respond with content coming from a Stream](#respond-with-content-coming-from-a-stream)
  * [Respond with content coming from a Stream and extra headers](#respond-with-content-coming-from-a-stream-and-extra-headers)
  * [Respond with content coming from a Stream containing templates](#respond-with-content-coming-from-a-stream-containing-templates)
  * [Respond with content coming from a Stream containing templates and extra headers](#respond-with-content-coming-from-a-stream-containing-templates-and-extra-headers)
  * [Respond with content using a callback](#respond-with-content-using-a-callback)
  * [Respond with content using a callback and extra headers](#respond-with-content-using-a-callback-and-extra-headers)
  * [Respond with content using a callback containing templates](#respond-with-content-using-a-callback-containing-templates)
  * [Respond with content using a callback containing templates and extra headers](#respond-with-content-using-a-callback-containing-templates-and-extra-headers)
  * [Chunked Response](#chunked-response)
  * [Chunked Response containing templates](#chunked-response-containing-templates)
  * [Print to response](#print-to-response)
  * [ArduinoJson Basic Response](#arduinojson-basic-response)
  * [ArduinoJson Advanced Response](#arduinojson-advanced-response)
* [Param Rewrite With Matching](#param-rewrite-with-matching)
* [Using filters](#using-filters)
* [Bad Responses](#bad-responses)
  * [Respond with content using a callback without content length to HTTP/1.0 clients](#respond-with-content-using-a-callback-without-content-length-to-http10-clients)
* [Async WebSocket Plugin](#async-websocket-plugin)
  * [Async WebSocket Event](#async-websocket-event)
  * [Methods for sending data to a socket client](#methods-for-sending-data-to-a-socket-client)
  * [Direct access to web socket message buffer](#direct-access-to-web-socket-message-buffer)
  * [Limiting the number of web socket clients](#limiting-the-number-of-web-socket-clients)
* [Async Event Source Plugin](#async-event-source-plugin)
  * [Setup Event Source on the server](#setup-event-source-on-the-server)
  * [Setup Event Source in the browser](#setup-event-source-in-the-browser)
* [Remove handlers and rewrites](#remove-handlers-and-rewrites)
* [Setting up the server](#setting-up-the-server)
  * [Setup global and class functions as request handlers](#setup-global-and-class-functions-as-request-handlers)
  * [Methods for controlling websocket connections](#methods-for-controlling-websocket-connections)
  * [Adding Default Headers](#adding-default-headers)
  * [Path variable](#path-variable)
* [Examples](#examples) 
  * [ 1. Async_AdvancedWebServer](examples/Async_AdvancedWebServer)
  * [ 2. Async_HelloServer](examples/Async_HelloServer)
  * [ 3. Async_HelloServer2](examples/Async_HelloServer2)
  * [ 4. Async_HttpBasicAuth](examples/Async_HttpBasicAuth)
  * [ 5. AsyncMultiWebServer](examples/AsyncMultiWebServer)
  * [ 6. Async_PostServer](examples/Async_PostServer)
  * [ 7. Async_RegexPatterns](examples/Async_RegexPatterns)
  * [ 8. Async_SimpleWebServer](examples/Async_SimpleWebServer)
  * [ 9. WebClientRepeating](examples/WebClientRepeating)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncMultiWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet](#1-AsyncMultiWebServer-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_W5500-Ethernet)
  * [2. WebClientRepeating on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet](#2-WebClientRepeating-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_W5500-Ethernet)
  * [3. Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet](#3-Async_AdvancedWebServer-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_ENC28J60-Ethernet)
  * [4. Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet](#4-Async_AdvancedWebServer-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_W5500-Ethernet)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AsyncWebServer_Ethernet library](https://github.com/khoih-prog/AsyncWebServer_Ethernet)

#### Features

This library is based on, modified from:

1. [Hristo Gochkov's ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)

to apply the better and faster **asynchronous** feature of the **powerful** [ESPAsyncWebServer Library](https://github.com/me-no-dev/ESPAsyncWebServer) into **ESP8266 boards using W5x00 or ENC28J60 Ethernet** using [lwIP_w5100](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5100), [lwIP_w5500](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5500) or [lwIP_enc28j60](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_enc28j60) library.


#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- **You are called once the request is ready and parsed**
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- **Easy to use API, HTTP Basic and Digest MD5 Authentication (default), ChunkedResponse**
- Easily extensible to handle **any type of content**
- Supports Continue 100
- **Async WebSocket plugin offering different locations without extra servers or ports**
- Async EventSource (Server-Sent Events) plugin to send events to the browser
- URL Rewrite plugin for conditional and permanent url rewrites
- ServeStatic plugin that supports cache, Last-Modified, default index and more
- Simple template processing engine to handle templates


---

#### Currently supported Boards

1. **ESP8266 boards using W5x00 or ENC28J60 Ethernet** with [lwIP_w5100](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5100), [lwIP_w5500](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5500) or [lwIP_enc28j60](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_enc28j60) library.

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/).
 3. [`ESPAsyncTCP library v1.2.2+`](https://github.com/me-no-dev/ESPAsyncTCP).

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `AsyncWebServer_Ethernet`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncWebServer_Ethernet.svg?)](https://www.ardu-badge.com/AsyncWebServer_Ethernet) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncWebServer_Ethernet](https://github.com/khoih-prog/AsyncWebServer_Ethernet) page.
2. Download the latest release `AsyncWebServer_Ethernet-master.zip`.
3. Extract the zip file to `AsyncWebServer_Ethernet-master` directory 
4. Copy the whole `AsyncWebServer_Ethernet-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncWebServer_Ethernet** library](https://registry.platformio.org/libraries/khoih-prog/AsyncWebServer_Ethernet) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncWebServer_Ethernet/installation). Search for **AsyncWebServer_Ethernet** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

## Important things to remember

- This is fully asynchronous server and as such does not run on the loop thread.
- You can not use yield() or delay() or any function that uses them inside the callbacks
- The server is smart enough to know when to close the connection and free resources
- You can not send more than one response to a single request

---

## Principles of operation

### The Async Web server

- Listens for connections
- Wraps the new clients into ```Request```
- Keeps track of clients and cleans memory
- Manages ```Rewrites``` and apply them on the request url
- Manages ```Handlers``` and attaches them to Requests

### Request Life Cycle

- TCP connection is received by the server
- The connection is wrapped inside ```Request``` object
- When the request head is received (type, url, get params, http version and host),
  the server goes through all ```Rewrites``` (in the order they were added) to rewrite the url and inject query parameters,
  next, it goes through all attached ```Handlers```(in the order they were added) trying to find one
  that ```canHandle``` the given request. If none are found, the default(catch-all) handler is attached.
- The rest of the request is received, calling the ```handleUpload``` or ```handleBody``` methods of the ```Handler``` if they are needed (POST+File/Body)
- When the whole request is parsed, the result is given to the ```handleRequest``` method of the ```Handler``` and is ready to be responded to
- In the ```handleRequest``` method, to the ```Request``` is attached a ```Response``` object (see below) that will serve the response data back to the client
- When the ```Response``` is sent, the client is closed and freed from the memory

### Rewrites and how do they work

- The ```Rewrites``` are used to rewrite the request url and/or inject get parameters for a specific request url path.
- All ```Rewrites``` are evaluated on the request in the order they have been added to the server.
- The ```Rewrite``` will change the request url only if the request url (excluding get parameters) is fully match
  the rewrite url, and when the optional ```Filter``` callback return true.
- Setting a ```Filter``` to the ```Rewrite``` enables to control when to apply the rewrite, decision can be based on
  request url, http version, request host/port/target host, get parameters or the request client's localIP or remoteIP.
- The ```Rewrite``` can specify a target url with optional get parameters, e.g. ```/to-url?with=params```

### Handlers and how do they work

- The ```Handlers``` are used for executing specific actions to particular requests
- One ```Handler``` instance can be attached to any request and lives together with the server
- Setting a ```Filter``` to the ```Handler``` enables to control when to apply the handler, decision can be based on
  request url, http version, request host/port/target host, get parameters or the request client's localIP or remoteIP.
- The ```canHandle``` method is used for handler specific control on whether the requests can be handled
  and for declaring any interesting headers that the ```Request``` should parse. Decision can be based on request
  method, request url, http version, request host/port/target host and get parameters
- Once a ```Handler``` is attached to given ```Request``` (```canHandle``` returned true)
  that ```Handler``` takes care to receive any file/data upload and attach a ```Response```
  once the ```Request``` has been fully parsed
- ```Handlers``` are evaluated in the order they are attached to the server. The ```canHandle``` is called only
  if the ```Filter``` that was set to the ```Handler``` return true.
- The first ```Handler``` that can handle the request is selected, not further ```Filter``` and ```canHandle``` are called.

### Responses and how do they work

- The ```Response``` objects are used to send the response data back to the client
- The ```Response``` object lives with the ```Request``` and is freed on end or disconnect
- Different techniques are used depending on the response type to send the data in packets
  returning back almost immediately and sending the next packet when this one is received.
  Any time in between is spent to run the user loop and handle other network packets
- Responding asynchronously is probably the most difficult thing for most to understand
- Many different options exist for the user to make responding a background task

### Template processing

- AsyncWebServer_Ethernet contains simple template processing engine.
- Template processing can be added to most response types.
- Currently it supports only replacing template placeholders with actual values. No conditional processing, cycles, etc.
- Placeholders are delimited with ```%``` symbols. Like this: ```%TEMPLATE_PLACEHOLDER%```.
- It works by extracting placeholder name from response text and passing it to user provided function which should return actual value to be used instead of placeholder.
- Since it's user provided function, it is possible for library users to implement conditional processing and cycles themselves.
- Since it's impossible to know the actual response size after template processing step in advance (and, therefore, to include it in response headers), the response becomes [chunked](#chunked-response).

---

## Request Variables

### Common Variables

```cpp
request->version();       // uint8_t: 0 = HTTP/1.0, 1 = HTTP/1.1
request->method();        // enum:    HTTP_GET, HTTP_POST, HTTP_DELETE, HTTP_PUT, HTTP_PATCH, HTTP_HEAD, HTTP_OPTIONS
request->url();           // String:  URL of the request (not including host, port or GET parameters)
request->host();          // String:  The requested host (can be used for virtual hosting)
request->contentType();   // String:  ContentType of the request (not avaiable in Handler::canHandle)
request->contentLength(); // size_t:  ContentLength of the request (not avaiable in Handler::canHandle)
request->multipart();     // bool:    True if the request has content type "multipart"
```

### Headers

```cpp
//List all collected headers
int headers = request->headers();
int i;

for(i=0;i<headers;i++)
{
  AsyncWebHeader* h = request->getHeader(i);
  Serial.printf("HEADER[%s]: %s\n", h->name().c_str(), h->value().c_str());
}

//get specific header by name
if(request->hasHeader("MyHeader"))
{
  AsyncWebHeader* h = request->getHeader("MyHeader");
  Serial.printf("MyHeader: %s\n", h->value().c_str());
}

//List all collected headers (Compatibility)
int headers = request->headers();
int i;

for(i=0;i<headers;i++)
{
  Serial.printf("HEADER[%s]: %s\n", request->headerName(i).c_str(), request->header(i).c_str());
}

//get specific header by name (Compatibility)
if(request->hasHeader("MyHeader"))
{
  Serial.printf("MyHeader: %s\n", request->header("MyHeader").c_str());
}
```

### GET, POST and FILE parameters

```cpp
//List all parameters
int params = request->params();

for(int i=0;i<params;i++)
{
  AsyncWebParameter* p = request->getParam(i);
  
  if(p->isFile())
  { 
    //p->isPost() is also true
    Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
  } 
  else if(p->isPost())
  {
    Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
  } 
  else 
  {
    Serial.printf("GET[%s]: %s\n", p->name().c_str(), p->value().c_str());
  }
}

//Check if GET parameter exists
if(request->hasParam("download"))
  AsyncWebParameter* p = request->getParam("download");

//Check if POST (but not File) parameter exists
if(request->hasParam("download", true))
  AsyncWebParameter* p = request->getParam("download", true);

//Check if FILE was uploaded
if(request->hasParam("download", true, true))
  AsyncWebParameter* p = request->getParam("download", true, true);

//List all parameters (Compatibility)
int args = request->args();

for(int i=0;i<args;i++)
{
  Serial.printf("ARG[%s]: %s\n", request->argName(i).c_str(), request->arg(i).c_str());
}

//Check if parameter exists (Compatibility)
if(request->hasArg("download"))
  String arg = request->arg("download");
```

### JSON body handling with ArduinoJson

Endpoints which consume JSON can use a special handler to get ready to use JSON data in the request callback:

```cpp
#include "AsyncJson.h"
#include "ArduinoJson.h"

AsyncCallbackJsonWebHandler* handler = new AsyncCallbackJsonWebHandler("/rest/endpoint", [](AsyncWebServerRequest *request, JsonVariant &json) 
{
  JsonObject& jsonObj = json.as<JsonObject>();
  // ...
});

server.addHandler(handler);
```
---

## Responses

### Redirect to another URL

```cpp
//to local url
request->redirect("/login");

//to external url
request->redirect("http://esp8266.com");
```

### Basic response with HTTP Code

```cpp
request->send(404); //Sends 404 File Not Found
```

### Basic response with HTTP Code and extra headers

```cpp
AsyncWebServerResponse *response = request->beginResponse(404); //Sends 404 File Not Found
response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Basic response with string content

```cpp
request->send(200, "text/plain", "Hello World!");
```

### Basic response with string content and extra headers

```cpp
AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Hello World!");
response->addHeader("Server","AsyncWebServer");
request->send(response);
```

### Respond with content coming from a Stream

```cpp
//read 12 bytes from Serial and send them as Content Type text/plain
request->send(Serial, "text/plain", 12);
```

### Respond with content coming from a Stream and extra headers

```cpp
//read 12 bytes from Serial and send them as Content Type text/plain
AsyncWebServerResponse *response = request->beginResponse(Serial, "text/plain", 12);
response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Respond with content coming from a Stream containing templates

```cpp
String processor(const String& var)
{
  if(var == "HELLO_FROM_TEMPLATE")
    return F("Hello world!");
    
  return String();
}

// ...

//read 12 bytes from Serial and send them as Content Type text/plain
request->send(Serial, "text/plain", 12, processor);
```

### Respond with content coming from a Stream containing templates and extra headers

```cpp
String processor(const String& var)
{
  if(var == "HELLO_FROM_TEMPLATE")
    return F("Hello world!");
  return String();
}

// ...

//read 12 bytes from Serial and send them as Content Type text/plain
AsyncWebServerResponse *response = request->beginResponse(Serial, "text/plain", 12, processor);
response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Respond with content using a callback

```cpp
//send 128 bytes as plain text
request->send("text/plain", 128, [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will not be asked for more bytes once the content length has been reached.
  //Keep in mind that you can not delay or yield waiting for more data!
  //Send what you currently have and you will be asked for more again
  return mySource.read(buffer, maxLen);
});
```

### Respond with content using a callback and extra headers

```cpp
//send 128 bytes as plain text
AsyncWebServerResponse *response = request->beginResponse("text/plain", 128, [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will not be asked for more bytes once the content length has been reached.
  //Keep in mind that you can not delay or yield waiting for more data!
  //Send what you currently have and you will be asked for more again
  return mySource.read(buffer, maxLen);
});

response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Respond with content using a callback containing templates

```cpp
String processor(const String& var)
{
  if(var == "HELLO_FROM_TEMPLATE")
    return F("Hello world!");
    
  return String();
}

// ...

//send 128 bytes as plain text
request->send("text/plain", 128, [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will not be asked for more bytes once the content length has been reached.
  //Keep in mind that you can not delay or yield waiting for more data!
  //Send what you currently have and you will be asked for more again
  return mySource.read(buffer, maxLen);
}, processor);
```

### Respond with content using a callback containing templates and extra headers

```cpp
String processor(const String& var)
{
  if(var == "HELLO_FROM_TEMPLATE")
    return F("Hello world!");
  return String();
}

// ...

//send 128 bytes as plain text
AsyncWebServerResponse *response = request->beginResponse("text/plain", 128, [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will not be asked for more bytes once the content length has been reached.
  //Keep in mind that you can not delay or yield waiting for more data!
  //Send what you currently have and you will be asked for more again
  return mySource.read(buffer, maxLen);
}, processor);

response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Chunked Response

Used when content length is unknown. Works best if the client supports HTTP/1.1

```cpp
AsyncWebServerResponse *response = request->beginChunkedResponse("text/plain", [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will be asked for more data until 0 is returned
  //Keep in mind that you can not delay or yield waiting for more data!
  return mySource.read(buffer, maxLen);
});

response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Chunked Response containing templates

Used when content length is unknown. Works best if the client supports HTTP/1.1

```cpp
String processor(const String& var)
{
  if(var == "HELLO_FROM_TEMPLATE")
    return F("Hello world!");
    
  return String();
}

// ...

AsyncWebServerResponse *response = request->beginChunkedResponse("text/plain", [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //index equals the amount of bytes that have been already sent
  //You will be asked for more data until 0 is returned
  //Keep in mind that you can not delay or yield waiting for more data!
  return mySource.read(buffer, maxLen);
}, processor);

response->addHeader("Server","AsyncWebServer_Ethernet");
request->send(response);
```

### Print to response

```cpp
AsyncResponseStream *response = request->beginResponseStream("text/html");
response->addHeader("Server","AsyncWebServer_Ethernet");
response->printf("<!DOCTYPE html><html><head><title>Webpage at %s</title></head><body>", request->url().c_str());

response->print("<h2>Hello ");
response->print(request->client()->remoteIP());
response->print("</h2>");

response->print("<h3>General</h3>");
response->print("<ul>");
response->printf("<li>Version: HTTP/1.%u</li>", request->version());
response->printf("<li>Method: %s</li>", request->methodToString());
response->printf("<li>URL: %s</li>", request->url().c_str());
response->printf("<li>Host: %s</li>", request->host().c_str());
response->printf("<li>ContentType: %s</li>", request->contentType().c_str());
response->printf("<li>ContentLength: %u</li>", request->contentLength());
response->printf("<li>Multipart: %s</li>", request->multipart()?"true":"false");
response->print("</ul>");

response->print("<h3>Headers</h3>");
response->print("<ul>");
int headers = request->headers();

for(int i=0;i<headers;i++)
{
  AsyncWebHeader* h = request->getHeader(i);
  response->printf("<li>%s: %s</li>", h->name().c_str(), h->value().c_str());
}

response->print("</ul>");

response->print("<h3>Parameters</h3>");
response->print("<ul>");

int params = request->params();

for(int i=0;i<params;i++)
{
  AsyncWebParameter* p = request->getParam(i);
  
  if(p->isFile())
  {
    response->printf("<li>FILE[%s]: %s, size: %u</li>", p->name().c_str(), p->value().c_str(), p->size());
  } 
  else if(p->isPost())
  {
    response->printf("<li>POST[%s]: %s</li>", p->name().c_str(), p->value().c_str());
  } 
  else 
  {
    response->printf("<li>GET[%s]: %s</li>", p->name().c_str(), p->value().c_str());
  }
}

response->print("</ul>");

response->print("</body></html>");
//send the response last
request->send(response);
```

### ArduinoJson Basic Response

This way of sending Json is great for when the result is **below 4KB**

```cpp
#include "AsyncJson.h"
#include "ArduinoJson.h"


AsyncResponseStream *response = request->beginResponseStream("application/json");
DynamicJsonBuffer jsonBuffer;
JsonObject &root = jsonBuffer.createObject();
root["heap"] = ESP.getFreeHeap();
root["ssid"] = WiFi.SSID();
root.printTo(*response);

request->send(response);
```

### ArduinoJson Advanced Response

This response can handle really **large Json objects (tested to 40KB)**

There isn't any noticeable speed decrease for small results with the method above

Since ArduinoJson does not allow reading parts of the string, the whole Json has to be passed every time a 
chunks needs to be sent, which shows speed decrease proportional to the resulting json packets

```cpp
#include "AsyncJson.h"
#include "ArduinoJson.h"

AsyncJsonResponse * response = new AsyncJsonResponse();
response->addHeader("Server","AsyncWebServer");
JsonObject& root = response->getRoot();
root["IP"] = Ethernet.localIP();
response->setLength();

request->send(response);
```
---

## Param Rewrite With Matching
It is possible to rewrite the request url with parameter matchg. Here is an example with one parameter:
Rewrite for example "/radio/{frequence}" -> "/radio?f={frequence}"

```cpp
class OneParamRewrite : public AsyncWebRewrite
{
  protected:
    String _urlPrefix;
    int _paramIndex;
    String _paramsBackup;

  public:
  OneParamRewrite(const char* from, const char* to)
    : AsyncWebRewrite(from, to) 
    {

      _paramIndex = _from.indexOf('{');

      if( _paramIndex >=0 && _from.endsWith("}")) 
      {
        _urlPrefix = _from.substring(0, _paramIndex);
        int index = _params.indexOf('{');
        
        if(index >= 0) 
        {
          _params = _params.substring(0, index);
        }
      } 
      else 
      {
        _urlPrefix = _from;
      }
      
      _paramsBackup = _params;
  }

  bool match(AsyncWebServerRequest *request) override 
  {
    if(request->url().startsWith(_urlPrefix)) 
    {
      if(_paramIndex >= 0) 
      {
        _params = _paramsBackup + request->url().substring(_paramIndex);
      } 
      else 
      {
        _params = _paramsBackup;
      }
      
      return true;

    } 
    else 
    {
      return false;
    }
  }
};
```

Usage:

```cpp
  server.addRewrite( new OneParamRewrite("/radio/{frequence}", "/radio?f={frequence}") );
```
---

## Using filters

Filters can be set to `Rewrite` or `Handler` in order to control when to apply the rewrite and consider the handler.
A filter is a callback function that evaluates the request and return a boolean `true` to include the item
or `false` to exclude it.

---

## Bad Responses

Some responses are implemented, but you should not use them, because they do not conform to HTTP.
The following example will lead to unclean close of the connection and more time wasted
than providing the length of the content

### Respond with content using a callback without content length to HTTP/1.0 clients

```cpp
//This is used as fallback for chunked responses to HTTP/1.0 Clients
request->send("text/plain", 0, [](uint8_t *buffer, size_t maxLen, size_t index) -> size_t 
{
  //Write up to "maxLen" bytes into "buffer" and return the amount written.
  //You will be asked for more data until 0 is returned
  //Keep in mind that you can not delay or yield waiting for more data!
  return mySource.read(buffer, maxLen);
});
```
---

## Async WebSocket Plugin

The server includes a web socket plugin which lets you define different WebSocket locations to connect to
without starting another listening service or using different port

### Async WebSocket Event

```cpp

void onEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len)
{
  if(type == WS_EVT_CONNECT)
  {
    //client connected
    Serial.printf("ws[%s][%u] connect\n", server->url(), client->id());
    client->printf("Hello Client %u :)", client->id());
    client->ping();
  } 
  else if(type == WS_EVT_DISCONNECT)
  {
    //client disconnected
    Serial.printf("ws[%s][%u] disconnect: %u\n", server->url(), client->id());
  } 
  else if(type == WS_EVT_ERROR)
  {
    //error was received from the other end
    Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t*)arg), (char*)data);
  } 
  else if(type == WS_EVT_PONG)
  {
    //pong message was received (in response to a ping request maybe)
    Serial.printf("ws[%s][%u] pong[%u]: %s\n", server->url(), client->id(), len, (len)?(char*)data:"");
  } 
  else if(type == WS_EVT_DATA)
  {
    //data packet
    AwsFrameInfo * info = (AwsFrameInfo*)arg;
    
    if(info->final && info->index == 0 && info->len == len)
    {
      //the whole message is in a single frame and we got all of it's data
      Serial.printf("ws[%s][%u] %s-message[%llu]: ", server->url(), client->id(), (info->opcode == WS_TEXT)?"text":"binary", info->len);
      
      if(info->opcode == WS_TEXT)
      {
        data[len] = 0;
        Serial.printf("%s\n", (char*)data);
      } 
      else 
      {
        for(size_t i=0; i < info->len; i++)
        {
          Serial.printf("%02x ", data[i]);
        }
        
        Serial.printf("\n");
      }
      
      if(info->opcode == WS_TEXT)
        client->text("I got your text message");
      else
        client->binary("I got your binary message");
    } 
    else 
    {
      //message is comprised of multiple frames or the frame is split into multiple packets
      if(info->index == 0)
      {
        if(info->num == 0)
          Serial.printf("ws[%s][%u] %s-message start\n", server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
          
        Serial.printf("ws[%s][%u] frame[%u] start[%llu]\n", server->url(), client->id(), info->num, info->len);
      }

      Serial.printf("ws[%s][%u] frame[%u] %s[%llu - %llu]: ", server->url(), client->id(), info->num, (info->message_opcode == WS_TEXT)?"text":"binary", info->index, info->index + len);
      
      if(info->message_opcode == WS_TEXT)
      {
        data[len] = 0;
        Serial.printf("%s\n", (char*)data);
      } 
      else 
      {
        for(size_t i=0; i < len; i++){
          Serial.printf("%02x ", data[i]);
        }
        Serial.printf("\n");
      }

      if((info->index + len) == info->len)
      {
        Serial.printf("ws[%s][%u] frame[%u] end[%llu]\n", server->url(), client->id(), info->num, info->len);
        
        if(info->final)
        {
          Serial.printf("ws[%s][%u] %s-message end\n", server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
          
          if(info->message_opcode == WS_TEXT)
            client->text("I got your text message");
          else
            client->binary("I got your binary message");
        }
      }
    }
  }
}
```

### Methods for sending data to a socket client

```cpp
//Server methods
AsyncWebSocket ws("/ws");
//printf to a client
ws.printf((uint32_t)client_id, arguments...);
//printf to all clients
ws.printfAll(arguments...);
//send text to a client
ws.text((uint32_t)client_id, (char*)text);
ws.text((uint32_t)client_id, (uint8_t*)text, (size_t)len);
//send text to all clients
ws.textAll((char*)text);
ws.textAll((uint8_t*)text, (size_t)len);
//send binary to a client
ws.binary((uint32_t)client_id, (char*)binary);
ws.binary((uint32_t)client_id, (uint8_t*)binary, (size_t)len);
ws.binary((uint32_t)client_id, flash_binary, 4);
//send binary to all clients
ws.binaryAll((char*)binary);
ws.binaryAll((uint8_t*)binary, (size_t)len);
//HTTP Authenticate before switch to Websocket protocol
ws.setAuthentication("user", "pass");

//client methods
AsyncWebSocketClient * client;
//printf
client->printf(arguments...);
//send text
client->text((char*)text);
client->text((uint8_t*)text, (size_t)len);
//send binary
client->binary((char*)binary);
client->binary((uint8_t*)binary, (size_t)len);
```

### Direct access to web socket message buffer

When sending a web socket message using the above methods a buffer is created.  Under certain circumstances you might want to manipulate or populate this buffer directly from your application, for example to prevent unnecessary duplications of the data.  This example below shows how to create a buffer and print data to it from an ArduinoJson object then send it.

```cpp
void sendDataWs(AsyncWebSocketClient * client)
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["a"] = "abc";
    root["b"] = "abcd";
    root["c"] = "abcde";
    root["d"] = "abcdef";
    root["e"] = "abcdefg";
    size_t len = root.measureLength();
    AsyncWebSocketMessageBuffer * buffer = ws.makeBuffer(len); //  creates a buffer (len + 1) for you.
    
    if (buffer) 
    {
        root.printTo((char *)buffer->get(), len + 1);
        
        if (client) 
        {
            client->text(buffer);
        } 
        else 
        {
            ws.textAll(buffer);
        }
    }
}
```

### Limiting the number of web socket clients

Browsers sometimes do not correctly close the websocket connection, even when the close() function is called in javascript.  This will eventually exhaust the web server's resources and will cause the server to crash.  Periodically calling the cleanClients() function from the main loop() function limits the number of clients by closing the oldest client when the maximum number of clients has been exceeded.  This can called be every cycle, however, if you wish to use less power, then calling as infrequently as once per second is sufficient.

```cpp
void loop(){
  ws.cleanupClients();
}
```

---

## Async Event Source Plugin

The server includes EventSource (Server-Sent Events) plugin which can be used to send short text events to the browser.
Difference between EventSource and WebSockets is that EventSource is single direction, text-only protocol.

### Setup Event Source on the server

```cpp
AsyncWebServer server(80);
AsyncEventSource events("/events");

void setup()
{
  // setup ......
  events.onConnect([](AsyncEventSourceClient *client)
  {
    if(client->lastId())
    {
      Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
    }
    
    //send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!",NULL,millis(),1000);
  });
  
  //HTTP Basic authentication
  events.setAuthentication("user", "pass");
  server.addHandler(&events);
  // setup ......
}

void loop()
{
  if(eventTriggered){ // your logic here
    //send event "myevent"
    events.send("my event content","myevent",millis());
  }
}
```

### Setup Event Source in the browser

```javascript
if (!!window.EventSource) 
{
  var source = new EventSource('/events');

  source.addEventListener('open', function(e) 
  {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function(e) 
  {
    if (e.target.readyState != EventSource.OPEN) 
    {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('message', function(e) 
  {
    console.log("message", e.data);
  }, false);

  source.addEventListener('myevent', function(e) 
  {
    console.log("myevent", e.data);
  }, false);
}
```
---

## Remove handlers and rewrites

Server goes through handlers in same order as they were added. You can't simple add handler with same path to override them.
To remove handler:

```arduino
// save callback for particular URL path
auto handler = server.on("/some/path", [](AsyncWebServerRequest *request){
  //do something useful
});

// when you don't need handler anymore remove it
server.removeHandler(&handler);

// same with rewrites
server.removeRewrite(&someRewrite);

server.onNotFound([](AsyncWebServerRequest *request){
  request->send(404);
});

// remove server.onNotFound handler
server.onNotFound(NULL);

// remove all rewrites, handlers and onNotFound/onFileUpload/onRequestBody callbacks
server.reset();
```
---

## Setting up the server

```cpp
#if !( defined(ESP8266) )
  #error This code is designed for ESP8266 platform! Please check your Tools->Board setting.
#endif

#include <Arduino.h>

#define _AWS_ETHERNET_LOGLEVEL_       4

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

#include <ESPAsyncTCP.h>

#include <AsyncWebServer_Ethernet.h>

AsyncWebServer    server(80);

void handleRoot(AsyncWebServerRequest *request)
{
  request->send(200, "text/plain", String("Hello from Async_HelloServer on ") + BOARD_NAME );
}

void handleNotFound(AsyncWebServerRequest *request)
{
  String message = "File Not Found\n\n";

  message += "URI: ";
  //message += server.uri();
  message += request->url();
  message += "\nMethod: ";
  message += (request->method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += request->args();
  message += "\n";

  for (uint8_t i = 0; i < request->args(); i++)
  {
    message += " " + request->argName(i) + ": " + request->arg(i) + "\n";
  }

  request->send(404, "text/plain", message);
}

void setup(void)
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart Async_HelloServer on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(ASYNC_WEBSERVER_WT32_ETH01_VERSION);

  //bool begin(uint8_t phy_addr=ETH_PHY_ADDR, int power=ETH_PHY_POWER, int mdc=ETH_PHY_MDC, int mdio=ETH_PHY_MDIO, 
  //           eth_phy_type_t type=ETH_PHY_TYPE, eth_clock_mode_t clk_mode=ETH_CLK_MODE);
  //ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER, ETH_PHY_MDC, ETH_PHY_MDIO, ETH_PHY_TYPE, ETH_CLK_MODE);
  ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);

  // Static IP, leave without this line to get IP via DHCP
  //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
  ETH.config(myIP, myGW, mySN, myDNS);

  WT32_ETH01_onEvent();

  WT32_ETH01_waitForConnect();
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    handleRoot(request);
  });

  server.on("/inline", [](AsyncWebServerRequest * request)
  {
    request->send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(ETH.localIP());
}

void loop(void)
{
}
```
---

### Setup global and class functions as request handlers

```cpp
#include <Arduino.h>

#include <AsyncWebServer_Ethernet.h>

...

void handleRequest(AsyncWebServerRequest *request){}

class WebClass 
{
public :
  AsyncWebServer classWebServer = AsyncWebServer(81);

  WebClass(){};

  void classRequest (AsyncWebServerRequest *request){}

  void begin()
  {
    // attach global request handler
    classWebServer.on("/example", HTTP_ANY, handleRequest);

    // attach class request handler
    classWebServer.on("/example", HTTP_ANY, std::bind(&WebClass::classRequest, this, std::placeholders::_1));
  }
};

AsyncWebServer globalWebServer(80);
WebClass webClassInstance;

void setup() 
{
  // attach global request handler
  globalWebServer.on("/example", HTTP_ANY, handleRequest);

  // attach class request handler
  globalWebServer.on("/example", HTTP_ANY, std::bind(&WebClass::classRequest, webClassInstance, std::placeholders::_1));
}

void loop() 
{

}
```

### Methods for controlling websocket connections

```cpp
  // Disable client connections if it was activated
  if ( ws.enabled() )
    ws.enable(false);

  // enable client connections if it was disabled
  if ( !ws.enabled() )
    ws.enable(true);
```


### Adding Default Headers

In some cases, such as when working with CORS, or with some sort of custom authentication system, 
you might need to define a header that should get added to all responses (including static, websocket and EventSource).
The DefaultHeaders singleton allows you to do this.

Example:

```cpp
DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
webServer.begin();
```

*NOTE*: You will still need to respond to the OPTIONS method for CORS pre-flight in most cases. (unless you are only using GET)

This is one option:

```cpp
webServer.onNotFound([](AsyncWebServerRequest *request) 
{
  if (request->method() == HTTP_OPTIONS) {
    request->send(200);
  } else {
    request->send(404);
  }
});
```

### Path variable

With path variable you can create a custom regex rule for a specific parameter in a route. 
For example we want a `sensorId` parameter in a route rule to match only a integer.

```cpp
  server.on("^\\/sensor\\/([0-9]+)$", HTTP_GET, [] (AsyncWebServerRequest *request) 
  {
      String sensorId = request->pathArg(0);
  });
```
*NOTE*: All regex patterns starts with `^` and ends with `$`

To enable the `Path variable` support, you have to define the buildflag `-DASYNCWEBSERVER_REGEX`.


For Arduino IDE create/update `platform.local.txt`:

`Windows`: C:\Users\(username)\AppData\Local\Arduino15\packages\\`{espxxxx}`\hardware\\`espxxxx`\\`{version}`\platform.local.txt

`Linux`: ~/.arduino15/packages/`{espxxxx}`/hardware/`{espxxxx}`/`{version}`/platform.local.txt

Add/Update the following line:
```
  compiler.cpp.extra_flags=-DDASYNCWEBSERVER_REGEX
```

For platformio modify `platformio.ini`:
```ini
[env:myboard]
build_flags = 
  -DASYNCWEBSERVER_REGEX
```

*NOTE*: By enabling `ASYNCWEBSERVER_REGEX`, `<regex>` will be included. This will add an 100k to your binary.


---
---

### Examples

 1. [Async_AdvancedWebServer](examples/Async_AdvancedWebServer)
 2. [Async_HelloServer](examples/Async_HelloServer) 
 3. [Async_HelloServer2](examples/Async_HelloServer2)
 4. [Async_HttpBasicAuth](examples/Async_HttpBasicAuth)
 5. [AsyncMultiWebServer](examples/AsyncMultiWebServer)
 6. [Async_PostServer](examples/Async_PostServer)
 7. [Async_RegexPatterns](examples/Async_RegexPatterns)
 8. [Async_SimpleWebServer](examples/Async_SimpleWebServer)
 9. [WebClientRepeating](examples/WebClientRepeating)

---
---

### Example [Async_AdvancedWebServer](examples/Async_AdvancedWebServer)

```cpp
#if !( defined(ESP8266) )
  #error This code is designed for ESP8266 platform! Please check your Tools->Board setting.
#endif

#include <Arduino.h>

#define _AWS_ETHERNET_LOGLEVEL_       2

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

#include <ESPAsyncTCP.h>

#include <AsyncWebServer_Ethernet.h>

AsyncWebServer    server(80);

int reqCount = 0;                // number of requests received

void handleRoot(AsyncWebServerRequest *request)
{
#define BUFFER_SIZE     400

  char temp[BUFFER_SIZE];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='5'/>\
<title>AsyncWebServer-%s</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h2>AsyncWebServer_Ethernet!</h2>\
<h3>running on %s</h3>\
<p>Uptime: %d d %02d:%02d:%02d</p>\
<img src=\"/test.svg\" />\
</body>\
</html>", BOARD_NAME, BOARD_NAME, day, hr % 24, min % 60, sec % 60);

  request->send(200, "text/html", temp);
}

void handleNotFound(AsyncWebServerRequest *request)
{
  String message = "File Not Found\n\n";

  message += "URI: ";
  message += request->url();
  message += "\nMethod: ";
  message += (request->method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += request->args();
  message += "\n";

  for (uint8_t i = 0; i < request->args(); i++)
  {
    message += " " + request->argName(i) + ": " + request->arg(i) + "\n";
  }

  request->send(404, "text/plain", message);
}

void drawGraph(AsyncWebServerRequest *request)
{
  String out;

  out.reserve(3000);
  char temp[70];
  
  out += "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n";
  out += "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"2\" stroke=\"rgb(0, 0, 0)\" />\n";
  out += "<g stroke=\"blue\">\n";
  int y = rand() % 130;

  for (int x = 10; x < 300; x += 10)
  {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n</svg>\n";

  request->send(200, "image/svg+xml", out);
}


void setup(void)
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart AsyncSimpleServer_WT32_ETH01 on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(ASYNC_WEBSERVER_WT32_ETH01_VERSION);

  // To be called before ETH.begin()
  WT32_ETH01_onEvent();

  //bool begin(uint8_t phy_addr=ETH_PHY_ADDR, int power=ETH_PHY_POWER, int mdc=ETH_PHY_MDC, int mdio=ETH_PHY_MDIO, 
  //           eth_phy_type_t type=ETH_PHY_TYPE, eth_clock_mode_t clk_mode=ETH_CLK_MODE);
  //ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER, ETH_PHY_MDC, ETH_PHY_MDIO, ETH_PHY_TYPE, ETH_CLK_MODE);
  ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);

  // Static IP, leave without this line to get IP via DHCP
  //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
  ETH.config(myIP, myGW, mySN, myDNS);

  WT32_ETH01_waitForConnect();
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    handleRoot(request);
  });

  server.on("/test.svg", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    drawGraph(request);
  });

  server.on("/inline", [](AsyncWebServerRequest * request)
  {
    request->send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(ETH.localIP());
}

void loop(void)
{
}
```

You can access the Async Advanced WebServer @ the server IP

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/Async_AdvancedWebServer.png">
</p>

---
---

### Debug Terminal Output Samples

#### 1. AsyncMultiWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

Following are debug terminal output and screen shots when running example [AsyncMultiWebServer](examples/AsyncMultiWebServer) on ESP8266_NODEMCU_ESP12E with W5500 Ethernet, to demonstrate the operation of 3 independent AsyncWebServers on 3 different ports and how to handle the complicated AsyncMultiWebServers.


```
Start AsyncMultiWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncWebServer_Ethernet v1.4.1
Connecting to network : ........
Ethernet DHCP IP address: 192.168.2.188
Initialize multiServer OK, serverIndex = 0, port = 8080
HTTP server started at ports 8080
Initialize multiServer OK, serverIndex = 1, port = 8081
HTTP server started at ports 8081
Initialize multiServer OK, serverIndex = 2, port = 8082
HTTP server started at ports 8082
```

You can access the Async Advanced WebServers @ the server IP and corresponding ports (8080, 8081 and 8082)

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/AsyncMultiWebServer_SVR1.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/AsyncMultiWebServer_SVR2.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/AsyncMultiWebServer_SVR3.png">
</p>


---

#### 2. WebClientRepeating on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

Following is debug terminal output when running example [WebClientRepeating](examples/WebClientRepeating) on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

```
Start WebClientRepeating on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncWebServer_Ethernet v1.4.1
Connecting to network : ..
Ethernet DHCP IP address: 192.168.2.188

Connecting...
HTTP/1.1 200 OK
Date: Fri, 15 Apr 2022 02:42:22 GMT
Content-Type: text/plain
Content-Length: 2263
Connection: close
x-amz-id-2: 5NgMsdI//7SWxkHWqMXj1R6Dt9mkyDg/gAH03EHhpoId3vFF85RZ5WuYlF9sJ0SDA7HzJPyiGn0=
x-amz-request-id: AMMCJDSRYBXT8BRE
Last-Modified: Wed, 23 Feb 2022 14:56:42 GMT
ETag: "667cf48afcc12c38c8c1637947a04224"
CF-Cache-Status: DYNAMIC
Report-To: {"endpoints":[{"url":"https:\/\/a.nel.cloudflare.com\/report\/v3?s=Nfap3Zu77r%2FeaiVo3fe9Oi2Xihbs5PICFFmalUAiexrx3NHe02YiItNSyQSwuFRwx2lPQQ2Q02nCzg%2Bq8llSxDEbVUbIT5ibNRtha3Lym0d61YBc2pmV0fCZWIt04oI%3D"}],"group":"cf-nel","max_age":604800}
NEL: {"success_fraction":0,"report_to":"cf-nel","max_age":604800}
Server: cloudflare
CF-RAY: 6fc153dabe64a252-YYZ
alt-svc: h3=":443"; ma=86400, h3-29=":443"; ma=86400


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;   
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;  
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;  
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;  
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;  
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;   
```

---

#### 3. Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet

The following are debug terminal output and screen shot when running example [Async_AdvancedWebServer](examples/Async_AdvancedWebServer) on **ESP8266_NODEMCU_ESP12E** with `ESP8266_ENC28J60` Ethernet

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/Async_AdvancedWebServer_ENC28J60.png">
</p>

```
Start Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet
AsyncWebServer_Ethernet v1.4.1
Connecting to network : ...
Ethernet DHCP IP address: 192.168.2.187
HTTP EthernetWebServer is @ IP : 192.168.2.187
```

---

#### 4. Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

The following are debug terminal output and screen shot when running example [Async_AdvancedWebServer](examples/Async_AdvancedWebServer) on **ESP8266_NODEMCU_ESP12E** with `ESP8266_W5500` Ethernet

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/pics/Async_AdvancedWebServer_W5500.png">
</p>

```
Start Async_AdvancedWebServer on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncWebServer_Ethernet v1.4.1
Connecting to network : .
Ethernet DHCP IP address: 192.168.2.188
HTTP EthernetWebServer is @ IP : 192.168.2.188
```

---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _ETHERNET_WEBSERVER_LOGLEVEL_ to 0

```cpp
// Use this to output debug msgs to Serial
#define ASYNCWEBSERVER_ETHERNET_DEBUG_PORT       Serial
// Use this to disable all output debug msgs
// Debug Level from 0 to 4
#define _AWS_ETHERNET_LOGLEVEL_                  0
```

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of Arduino IDE, the Arduino `ESP8266` core or depending libraries.

Sometimes, the library will only work if you update the `ESP8266` core to the latest version because I'm always using the latest cores /libraries.

---

### Issues ###

Submit issues to: [AsyncWebServer_Ethernet issues](https://github.com/khoih-prog/AsyncWebServer_Ethernet/issues)

---
---

## TO DO

 1. Fix bug. Add enhancement


## DONE

 1. Initial port to ESP8266 boards using W5x00 / ENC28J60 Ethernet
 2. Add more examples.
 3. Add debugging features.
 4. Add Table-of-Contents and Version String
 

---
---


### Contributions and Thanks

1. Based on and modified from [Hristo Gochkov's ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer). Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for great [ESPAsyncWebServer Library](https://github.com/me-no-dev/ESPAsyncWebServer)


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/AsyncWebServer_Ethernet/blob/main/LICENSE)

---

## Copyright

- Copyright 2016- Hristo Gochkov

- Copyright 2022- Khoi Hoang



