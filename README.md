# **BICING IMPLEMENTATION USING BINTREES**
This project simulates the different functionalities that an urban bike management app would have, such as Bicing.  
  
## **Usage**  

**Compile using Makefile**  
   ```
   ./make
   ```
**Execute the program**
   
Option 1: Execute with own input
   ```
   ./program.exe  
   ```
Option 2: Execute with sample given input
   ```
   ./program.exe < sample_input.txt     
   ```
Option 3: Execute with sample given input and compare with expected output   
   ```
   ./program.exe < sample_input.txt > temporal_output.txt
   diff temporal_output.txt sample_output.txt  
   ```
   If this last command doesn't provide any output, no differences have been found between the files, therefore the execution completed successfully. temporal_output can be safely deleted with   
   ```
   rm temporal_output.txt
   ```
