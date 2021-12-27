# Operations on Sparse Matrices Using Linked Lists

Programmed addition.subtraction,multiplication, and inverse operations, node insertion/deletion, and calculated run-time on sparse matrices represented as linked lists in C++ to analyze how operating on this data structure is more memory efficient and makes computations less expensive in comparison to vectors and arrays. 

Integrated SFML in C++ to provide a sleek graphical user interface with features to enhance intuitiveness and provide information about the project. 

## Installation

It is recommended that the user should use Microsoft Visual Studio 2019 to open and run this program as the project was configured to run in this IDE. In order to gain access to the SFML libraries please follow the following instructions:

1.) Clone repository and ensure that all .dll , matrix and button folders are located in the project directory.

2.) Download the SFML file. LINK: https://www.sfml-dev.org/download.php

3.)Open up project in Visual Studio and navigate to the project properties. 

<img src="https://user-images.githubusercontent.com/77069472/144729122-c6ec36e6-8cfa-493c-ab6d-3e148e3fc15e.png" width=25% height=25%>

4.) Set configuration to ALL configuration. Then enter file path to the SFML include directory in the field "Additional Include Directories." 

<img src="https://user-images.githubusercontent.com/77069472/144729301-ec925306-821c-434e-b166-2a5ae374ee88.png" width=35% height=35%>

5.) Go to Linker -> General, then set path to SFML lib directory in the field "Additional Library Directories."

<img src="https://user-images.githubusercontent.com/77069472/144729356-57af32d6-bd3c-4be9-9c40-46d3a9f4854e.png" width=35% height=35%>

6.) Go to Linker -> Input, got to "Additional Dependencies" and add sfml-graphics.lib; sfml-window.lib; sfml-system.lib; sfml-audio.lib; to begining of text that is already there.

<img src="https://user-images.githubusercontent.com/77069472/144729392-65d462c7-dc16-40ed-98b3-02ad73ce62ab.png" width=35% height=35%>

7.) Switch Configuration to Debug and add -d to all .lib files 

<img src="https://user-images.githubusercontent.com/77069472/144729414-d649f0c7-699b-48ac-91ae-39d873cac456.png" width=35% height=35%>

8.) Switch Configuration to Release and add -s to all lib files.

<img src="https://user-images.githubusercontent.com/77069472/144729449-667f14bd-1f4f-4c40-90b5-b4431f9b0793.png" width=35% height=35%>

9.) Open the edit property and add "winmm.lib", "opengl32.lib" and "freetype.lib" to the Additional Dependencies field.

<img src="https://user-images.githubusercontent.com/77069472/144729481-443884e5-4dd2-471f-83e8-a97337e582dc.png" width=35% height=35%>

<img src="https://user-images.githubusercontent.com/77069472/144729496-5e943ea6-f250-4d1d-b7b8-1b2f0730e416.png" width=35% height=35%>

10.) Go to C/C++ -> Preprocessor, then add SFML_STATIC; to text already present.

<img src="https://user-images.githubusercontent.com/77069472/144729529-0908094c-3afe-4ada-bd8b-1ecdca37b4e2.png" width=35% height=35%>

11.) If any issues insue, please view this link. LINK: https://www.youtube.com/watch?v=YfMQyOw1zik

Tutorial for VSCODE. LINK: https://www.youtube.com/watch?v=mqH-EnR0N6A

## Usage

To use this application please input two command line arguements. These arguements should be .txt files that contain a sparse matrix that is seperated by one white space with no trailing white space. As a rule the, first command line arguement will become the first operator and the second command line arguement will be the second operator. For example, commandline arguement 1 + commmandline argument 2 = results. When running the application, please navigate the menus by pressing the black with white text buttons with the mouse. To reset the program at anytime, press ENTER. To close the program, press ESCAPE. 


NOTE: Only one set of matrices may be used per application execution. Please enter 2 other .txt files to have new sprase matrices. There are named examples in the matrices folder. 


## Developers

Emily Gautreaux,
Mathew Ferreira,
Amoy Scott,
Whitney Schoellerman.



