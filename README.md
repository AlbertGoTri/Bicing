**<h1>BICING IMPLEMENTATION USING BINTREES</h1>**
This project simulates the different functionalities that an urban bike management app would have, such as Bicing.  
**Usage**  
1. Compile using Makefile  
   <code>./make</code>
2. Execute the program:  
2.1. Option 1: Execute with own input  
   <code>./program.exe</code>  
2.2. Option 2: Execute with sample given input  
   <code>./program.exe < sample_input.txt</code>  
2.3. Option 3: Execute with sample given input and compare with expected output  
   <code>./program.exe < sample_input.txt > temporal_output.txt</code>  
   <code>diff temporal_output.txt sample_output.txt</code>  
   If this last command doesn't provide any output, no differences have been found between the files, therefore the execution completed successfully. temporal_output can be safely deleted with
   <code>rm temporal_output.txt</code>  
