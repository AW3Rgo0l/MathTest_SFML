Algebra test made on C++ using SFML library

To try this application you should download this repository and in folder "Release"(not in "smfl" folder) launch .exe file.

----------------------------------------------------
Or to compile this project on your own you should:
1. Download this repository and unzip in folder for project.

2. Open .sln file in Visual Studio.

3. In project properties in C/C++ -> General -> Additional Include Directories:               
   Edit and put the directory to "include" folder which is located in your project folder and apply.
   
4. In project properties in C/C++ -> Preprocessor -> Preprocessor Definitions:           
   Type "SFML_STATIC;" before the "_MBCS..." and apply.
   
5. In project properties in Linker -> General -> Additional Library Directories:              
   Edit and put the directory to "lib" folder which is located in your project folder and apply.
   
6. In project properties in Linker -> Input -> Additional Dependencies:               
   Edit and paste there the .lib files which is located in "Libs.txt" in your project folder and apply.
   
   That's all
