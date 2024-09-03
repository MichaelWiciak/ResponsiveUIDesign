# Project README

## Overview
This project is a Qt-based application designed to create a responsive user interface with various interactive elements. The project demonstrates the implementation of custom Qt widgets and layouts to create a dynamic user interface that adjusts to different screen sizes and orientations.

## Project Structure
The project consists of the following key components:

1. **Main Application (`main.cpp`)**
   - Initializes the Qt application.
   - Provides two modes of operation:
     - **Test Mode:** Activated with the `test` command-line argument, which runs the `Screenshot` class to capture screenshots of the interface.
     - **Interactive Mode:** Default mode that runs the `ResponsiveWindow` class, presenting a responsive user interface.

2. **Responsive Scroll Area (`responsiveQScrollArea.cpp` and `responsiveQScrollArea.h`)**
   - Extends the `QScrollArea` class to provide additional margins around the content, improving the layout's responsiveness.

3. **Responsive Label (`responsive_label.cpp` and `responsive_label.h`)**
   - Custom `QLabel` class that adjusts its appearance based on the provided label name and color.
   - Predefined labels such as `home`, `sign-in`, `menu-button`, and others are associated with specific colors.

4. **Responsive Layout (`responsive_layout.cpp`)**
   - Custom layout class that dynamically positions and sizes widgets based on the window's dimensions.
   - Adapts to different screen sizes and orientations (e.g., horizontal, vertical, compact modes).
   - Implements logic to manage the layout of various UI elements such as navigation tabs, search results, and buttons.

## Dependencies
- **Qt Framework**: This project uses the Qt framework for the graphical user interface. Ensure that Qt is installed and properly set up in your development environment.
- **C++11 or later**: The code is written in C++ and uses features from C++11.

## Compilation
To compile the project, ensure that you have a C++ compiler that supports the required libraries and that Qt is properly installed.

### Linux/Unix
```bash
g++ -std=c++11 main.cpp responsiveQScrollArea.cpp responsive_label.cpp responsive_layout.cpp -o my_app -lQt5Widgets -lQt5Core
```

### Windows
```bash
g++ -std=c++11 main.cpp responsiveQScrollArea.cpp responsive_label.cpp responsive_layout.cpp -o my_app.exe -lQt5Widgets -lQt5Core
```

## Running the Application
### Test Mode
To run the application in test mode:
```bash
./my_app test <source_folder>
```
This mode is primarily for grading and debugging purposes.

### Interactive Mode
To run the application in interactive mode, simply execute the binary without arguments:
```bash
./my_app
```
This mode launches the full interactive UI.

## Features
- **Responsive UI:** The layout automatically adjusts to different screen sizes and orientations, ensuring a consistent user experience across devices.
- **Custom Widgets:** Enhanced Qt widgets like `ResponsiveLabel` and `responsiveQScrollArea` provide better control over the UI elements.
- **Dynamic Layout Management:** The `ResponsiveLayout` class handles the dynamic arrangement of widgets, making the interface adaptable to various display conditions.


### How the Project Works

This project is a responsive GUI application developed using the Qt framework, designed to adapt its layout and appearance based on the size and orientation of the window or device. The key components include a custom layout manager (`ResponsiveLayout`), specialized widgets like `ResponsiveLabel`, and enhanced UI elements like `responsiveQScrollArea`.

Here’s a breakdown of how the project works:

#### 1. **Entry Point (main.cpp)**
   - The `main.cpp` file is the entry point of the application. It initializes the Qt application, checks the Qt version, and processes command-line arguments to determine whether the application runs in a test mode (using `Screenshot`) or in an interactive mode (using `ResponsiveWindow`).
   - The `mkdir_()` function handles directory creation across different operating systems (Windows and Unix-based systems).

#### 2. **Responsive Layout (responsive_layout.cpp & responsive_layout.h)**
   - The `ResponsiveLayout` class extends the `QLayout` class to create a custom layout that adjusts dynamically based on the window size and aspect ratio.
   - **Layout Modes:** The layout adapts between horizontal, vertical, and compact modes based on the window dimensions and aspect ratio:
     - **Horizontal Mode:** Used for wide windows, where elements are arranged side by side.
     - **Vertical Mode:** Used for narrow, tall windows, arranging elements vertically.
     - **Compact Mode:** For very small windows, elements are stacked closely together.
   - The `setGeometry()` function in `ResponsiveLayout` is responsible for determining the positioning and sizing of all child widgets within the layout, ensuring that the UI remains usable and visually appealing in any mode.

#### 3. **Responsive Labels (responsive_label.cpp & responsive_label.h)**
   - The `ResponsiveLabel` class is a custom widget derived from `QLabel`. It includes specific styling and behavior tailored to the application’s needs.
   - **Dynamic Styling:** Each label has an associated color defined in a map (`kColours`), which is used to set the background and border colors dynamically. This makes the UI visually consistent and easily recognizable.
   - Labels represent different elements of the UI, such as navigation buttons, search results, and control buttons, with each label being placed according to the layout logic defined in `ResponsiveLayout`.

#### 4. **Enhanced Scroll Area (responsiveQScrollArea.cpp & responsiveQScrollArea.h)**
   - The `responsiveQScrollArea` class is an extension of the standard `QScrollArea`, designed to improve its functionality. It overrides the `sizeHint()` method to add extra margins around the scroll area, enhancing the appearance and usability of the scrollable content.

#### 5. **Screenshot Mode**
   - In test mode (activated via command-line arguments), the application enters a grading mode where a `Screenshot` object is created and displayed. This mode is intended for automated testing or grading purposes, where screenshots of the UI can be captured for evaluation.

#### 6. **Interactive Mode**
   - In the default interactive mode, the `ResponsiveWindow` object is instantiated, which is the main window of the application. It includes all the responsive UI elements and adjusts its layout dynamically based on the window size and user interactions.

#### 7. **Platform-Specific Code**
   - The project includes platform-specific code to ensure compatibility with both Windows and Unix-based systems.
