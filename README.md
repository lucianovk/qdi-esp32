# qdi-esp32
Quick and Dirty Interface for ESP32

## Description
 This is a base project that I use to create Quick and Dirty Web Interfaces for ESP32 based prototypes. 
 
 ### Features
 - Static files are stored using SPIFFS.
 - No external dependencies in Javascript.
 

## Environment
https://code.visualstudio.com/

https://platformio.org

## Instructions
- Install Visual Studio Code;

- Install PlatformIO for VSCode;
  
  If it's your first time using Platformio I suggest this [tutorial](https://docs.platformio.org/en/stable/tutorials/espressif32/arduino_debugging_unit_testing.html);

- Clone qdi-esp32 repository;

  `git clone https://github.com/lucianovk/qdi-esp32.git`

- Open qdi-esp32 project using VSCode;

- Select your ESP32 board model in: PIO Home -> Projects & Configuration;

- Verify your board connection;

- Build and upload application and data running the tasks in: PIO Home -> PROJECT TASKS;

    1 - Build File System;

    2 - Upload File System Image;

    3 - Build;

    4 - Upload;

- Connect your computer or mobile device on **qdi-esp32** wifi network using **12345678** password and open the interface pointing your web browser to [http://192.168.4.1](http://192.168.4.1);




