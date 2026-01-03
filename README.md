# OOPM (Object-Oriented Programming in C++)

This folder is organized by OOPM topics. Each `.cpp` file is **standalone** (it contains its own `main()`), so compile and run them one-by-one.

## Folder structure

- `ObjectOrientedBasics/`
- `Encapsulation_Classes/`
- `Relationships_Inheritance/`
- `Polymorphism/`
- `AdvancedConcepts/`

## Build & run

### Option A: g++ (MinGW)

From the workspace root:

```bash
g++ -std=c++17 ObjectOrientedBasics/oop_vs_procedural.cpp -o oop_vs_procedural
./oop_vs_procedural
```

For threading example:

```bash
g++ -std=c++17 AdvancedConcepts/multithreading.cpp -o multithreading
./multithreading
```

### Option B: MSVC (Developer Command Prompt)

```bat
cl /EHsc /std:c++17 ObjectOrientedBasics\oop_vs_procedural.cpp
oop_vs_procedural.exe
```

## Notes

- If you see encoding issues in the console, set your terminal to UTF-8.
- The case studies are small interactive programs you can extend.
