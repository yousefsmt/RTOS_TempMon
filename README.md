# STM32F103 FreeRTOS Temperature and Humidity Monitoring

## Overview

This project is a simple temperature and humidity monitoring system built on the **STM32F103C8T6 (Blue Pill)** using **FreeRTOS** and **CMSIS**.

It reads environmental data from the **SHT11** temperature and humidity sensor and displays the measured values on a **16x2 LCD** driven by the **HD44780** controller.

The main purpose of this project is to provide a practical and easy-to-understand example of how to build a small embedded application using **FreeRTOS** on STM32. It is designed as a learning-oriented project that demonstrates the fundamentals of:

* Task creation and scheduling with FreeRTOS
* Sensor interfacing with the SHT11
* LCD communication using the HD44780 driver
* Basic embedded software structure using CMSIS
* Modular and maintainable firmware design

This first release focuses on establishing a clean and functional baseline implementation on the STM32F103 platform.

Future releases will include:

* Improved debugging workflow
* Better software architecture and code refinement
* Additional monitoring and diagnostic features
* Enhanced reliability and system observability

This repository is intended for learning, experimentation, and as a reference for developers getting started with **STM32**, **FreeRTOS**, and basic embedded system design.
