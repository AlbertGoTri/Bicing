# **BICING IMPLEMENTATION USING BINTREES**
This project simulates the different functionalities that an urban bike management app would have, such as Bicing.  
  
**Usage**  
1. Compile using Makefile  
   ```bash
   ./make
   
2. Execute the program:
2.1. Option 1: Execute with own input
   ```bash
   ./program.exe
2.2. Option 2: Execute with sample given input
   ```bash
./program.exe < sample_input.txt     
2.3. Option 3: Execute with sample given input and compare with expected output   
   ```bash
./program.exe < sample_input.txt > temporal_output.txt
diff temporal_output.txt sample_output.txt  
   If this last command doesn't provide any output, no differences have been found between the files, therefore the execution completed successfully. temporal_output can be safely deleted with   
   ```bash
rm temporal_output.txt
