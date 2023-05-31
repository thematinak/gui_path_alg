# gui_path_alg

Excercise Repo for basic data structures sutch as **vector**, **queue**, **stack**, **heap**

For grafical representation we used: https://www.sfml-dev.org/

# Build command - Windows
```
robocopy .\src\resources\ %targetLocation% > nul
g++ .\src\core\*.cpp .\src\*.cpp -o %targetLocation%/main.exe -lsfml-graphics -lsfml-window -lsfml-system -Wall
```

Don't forget to link **sfml** library
