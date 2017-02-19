/*
Copyright (c) 2017 Brian Lough. All right reserved.

Pushsafer - Library to send Pushsafer notifications.
Ref. Library at https:github/esp8266/Arduino

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef Pushsafer_h
#define Pushsafer_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Client.h>

#define HOST "www.pushsafer.com"
#define SSL_PORT 443

struct PushSaferInput{
  String message;
  String title;
  String sound;
  String vibration;
  String icon;
  String device;
  String url;
  String urlTitle;
  String Time2Live;
  String picture;
  String picture2;
  String picture3;
};

class Pushsafer
{
  public:
    Pushsafer (String key, Client &client);
    String sendEvent(PushSaferInput input);
    bool debug = false;

  private:
    //JsonObject * parseUpdates(String response);
    String buildString(String boundary, String name, String value);

    String _key;
    Client *client;
};

#endif
