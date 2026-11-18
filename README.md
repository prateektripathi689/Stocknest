# STOCKNEST – Inventory Management System

A C++ OOPS mini-project with a separate dark green browser dashboard.

## Files
- `cpp/main.cpp` – menu-driven C++ inventory application.
- `web/index.html` – responsive dashboard with sample stock data.

## Dashboard
Open `web/index.html` in a browser. Add, edit, search and delete items. Browser demo data is stored in localStorage.

## Compile C++
macOS / Linux:
```bash
cd cpp
g++ -std=c++11 -Wall -Wextra main.cpp -o stocknest
./stocknest
```
Windows (MinGW):
```bash
g++ -std=c++11 main.cpp -o stocknest.exe
stocknest.exe
```

## OOPS concepts
- Class and object: `Product`, `StockNest`.
- Encapsulation: private product data and public methods.
- Inheritance: `Product` derives from abstract `Printable`.
- Abstraction: pure virtual `display()` function.
- Runtime polymorphism: overridden virtual `display()`.
- File handling: save product records to a text file.

The browser dashboard is a standalone demo and does not connect to the C++ console program.
ttps://prateektripathi689.github.io/Stocknest/
