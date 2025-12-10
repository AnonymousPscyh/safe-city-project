**Safe City Project** is a simple traffic management system written in C++ to track vehicle entries, record traffic violations, calculate fines, and blacklist offenders. It is designed to help maintain road safety in a city environment.

---

## Features

- Log vehicle entries with registration number, type, and checkpoint.
- Record traffic violations such as:
  - Speeding
  - Red signal violation
  - Wrong-way driving
  - Other minor violations
- Automatically calculate fines based on violations.
- Track total violations for each vehicle.
- Blacklist vehicles with 3 or more violations.
- Search for a vehicle's record.
- Display all offending vehicles and type-wise analysis.

---

## How to Run

1. Make sure you have a C++ compiler (e.g., Visual Studio, GCC, or Code::Blocks).
2. Open the project in your IDE.
3. Compile `MyFirstCpp.cpp` (or the project solution in Visual Studio).
4. Run the executable.
5. Use the menu to:
   - Enter vehicle information
   - Record traffic violations
   - Search vehicles
   - Display offenders

---

## Sample Menu

============== Welcome to Safe City Project =================

1.Enter Vehicle Information
2.Record Vehicle's Violation
3.Search for Vehicle
4.Display all Offenders
Enter 0 to exit
What would you like to perform: 


## File Structure

- `MyFirstCpp.cpp` — main program  
- `MyFirstCpp.vcxproj` — Visual Studio project file  
- `MyFirstCpp.vcxproj.filters` — project filters  
- `MyFirstCpp.vcxproj.user` — user settings  
- `blacklist.txt` — stores blacklisted vehicles  

> Note: The `x64/Debug` folder contains build files and can be ignored.

---

## Author

**Mesum Raza**  
GitHub: [https://github.com/AnonymousPscyh](https://github.com/AnonymousPscyh)

---

## Future Improvements

- Add a GUI interface for easier interaction.  
- Save all vehicle records in a proper database instead of memory.  
- Add more violation types and customizable fines.  
- Implement user authentication for traffic officers.