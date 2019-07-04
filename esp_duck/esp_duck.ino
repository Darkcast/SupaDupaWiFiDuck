/*
   Copyright (c) 2019 Stefan Kremser
   This software is licensed under the MIT License. See the license file for details.
   Source: github.com/spacehuhn/WiFiDuck
 */

// #define ENABLE_DEFAULT_DELAY
// #define LED_TEST
// #define OPEN_NOTEPAD
// #define HELLO_WORLD
// #define DELAY_TEST
// #define REPEAT_TEST
// #define REPEAT_TEST
// #define US_CHAR_TEST
// #define DE_CHAR_TEST
// #define GB_CHAR_TEST
// #define OVERFLOW_TEST
// #define KEYCODE_TEST
// #define CLOSE_NOTEPAD

#include "DuckyTransmitter.h"

DuckyTransmitter duck;

void setup() {
    Serial.begin(115200);
    Serial.println();

    duck.begin();

    Serial.println("Started");

    if (duck.connected()) {
        Serial.println("Connected!");

        duck.sendMessage("LED 0 100 0\n");

        delay(2000);

#ifdef ENABLE_DEFAULT_DELAY
        duck.sendMessage("DEFAULTDELAY 200\n");
#endif // ifdef ENABLE_DEFAULT_DELAY

#ifdef LED_TEST
        duck.sendMessage("LED 255 0 0\n");
        duck.sendMessage("DELAY 1000\n");
        duck.sendMessage("LED 0 255 0\n");
        duck.sendMessage("DELAY 1000\n");
        duck.sendMessage("LED 0 0 255\n");
#endif // ifdef ENABLE_DEFAULT_DELAY

#ifdef OPEN_NOTEPAD
        duck.sendMessage("GUI r\n");
        duck.sendMessage("STRING notepad\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef OPEN_NOTEPAD

#ifdef HELLO_WORLD
        duck.sendMessage("STRING Hello World! \n");
        duck.sendMessage("ENTER\n");
#endif // ifdef HELLO_WORLD

#ifdef DELAY_TEST
        duck.sendMessage("DELAY 1000\n");
        duck.sendMessage(".\n");
        duck.sendMessage("DELAY 3000\n");
        duck.sendMessage(".\n");
        duck.sendMessage("DELAY 5000\n");
        duck.sendMessage(".\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef HELLO_WORLD

#ifdef REPEAT_TEST
        duck.sendMessage("STRING Hello World! \n");
        duck.sendMessage("REPEAT 2\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef REPEAT_TEST

#ifdef US_CHAR_TEST
        duck.sendMessage("LOCALE US\n");
        duck.sendMessage("STRING !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}~`\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef ALL_CHAR_TEST

#ifdef DE_CHAR_TEST
        duck.sendMessage("LOCALE DE\n");
        duck.sendMessage("STRING !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}~²³äöüÄÖÜß€°§` \n");
        duck.sendMessage("ENTER\n");
#endif // ifdef ALL_CHAR_TEST

#ifdef GB_CHAR_TEST
        duck.sendMessage("LOCALE GB\n");
        duck.sendMessage("STRING !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}~£¦¬éíúóÉÍÚÓ€\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef ALL_CHAR_TEST

#ifdef OVERFLOW_TEST
        duck.sendMessage("STRING 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 01234567890 \n");
        duck.sendMessage("ENTER\n");
#endif // ifdef OVERFLOW_TEST

#ifdef KEYCODE_TEST
        duck.sendMessage("A\n");
        duck.sendMessage("KEYCODE 0x02 0x04\n");
        duck.sendMessage("KEYCODE 2 4\n");
#endif // ifdef ALL_CHAR_TEST

#ifdef CLOSE_NOTEPAD
        duck.sendMessage("DELAY 5000\n");
        duck.sendMessage("ALT F4\n");
        duck.sendMessage("RIGHT\n");
        duck.sendMessage("ENTER\n");
#endif // ifdef CLOSE_NOTEPAD
    } else {
        Serial.println("Connection error");
    }
}

void loop() {}