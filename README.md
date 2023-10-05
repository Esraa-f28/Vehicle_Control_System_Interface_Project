
# Vehicle Control System Interface Project

## Overview
This C programming project implements a comprehensive vehicle control system with user-friendly interfaces and various functionalities. The system allows users to interact with the vehicle, control its engine, manage environmental factors, and respond to traffic conditions.

## Features
1. **Engine Control**:
   - Turn on the vehicle engine.
   - Turn off the vehicle engine.
   - Quit the system.

2. **Engine State Management**:
   - When "Turn on the vehicle engine" is selected, the program provides a submenu to control various aspects of the engine.

3. **Traffic Light Control**:
   - Adjusts vehicle speed based on the traffic light color.

4. **Air Conditioning (AC) Control**:
   - Regulates AC settings based on room temperature.

5. **Engine Temperature Control**:
   - Manages the "Engine Temperature Controller" based on engine temperature.

6. **Special Actions**:
   - Takes specific actions when the vehicle speed reaches 30 km/hr.

## Usage
1. Run the program, and you will be presented with a main menu.
   - Choose "Turn on the vehicle engine" to access the engine control submenu.
   - Select "Turn off the vehicle engine" to turn off the engine and return to the main menu.
   - Opt for "Quit the system" to exit the program.

2. Engine Control Submenu:
   - Within this submenu, you can:
     - Turn off the engine.
     - Set the traffic light color.
     - Set the room temperature.
     - Set the engine temperature.

3. Traffic Light Control:
   - Adjusts the vehicle's speed based on the current traffic light color.

4. Air Conditioning (AC) Control:
   - Manages the AC settings to maintain a comfortable environment inside the vehicle based on room temperature.

5. Engine Temperature Control (Optional):
   - Manages the "Engine Temperature Controller" based on engine temperature. This feature can be enabled by defining `WITH_ENGINE_TEMP_CONTROLLER` as 1 and compiling the code with it. To exclude this feature, set it to 0.

6. Special Actions:
   - The program takes specific actions when the vehicle speed reaches 30 km/hr.

## Displaying Vehicle State
- The program continuously displays the current vehicle state, including:
   - Engine status (on/off).
   - AC status and settings.
   - Vehicle speed.
   - Room temperature.
   - Engine temperature controller status.
   - Engine temperature.

