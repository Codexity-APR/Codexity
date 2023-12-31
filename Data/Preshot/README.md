# Preshot Dataset
The StarCoder and SantaCoder folders contain the result of the preshot repair using the starcoder and santacoder model respectively.
These two folders have different folders containing the codes generated. Each sub folder correspond the to the prompt used to generate the code. For example, folder 1 has the codes using the prompt 1. 

## File name
Each file name is composed of different elements separated by "_". The first number is the corresponding prompt number. The last number is to separate the files between them. If the file has a vulnerability, then it is indicated by the "CWE" in the name. In this case, any numbers following the "CWE" (except the last number) corresponds to a CWE detected in this file. Moreover, a vulnerability name can also be present in the name. If a '/' or ':' (depending on the OS) follows a CWE number or a vulnerability name, it indicated the number of occurence of the vulnerability.  Also, the number following 'time' corresponds to the time it took to generate the code. Finally, the element temp0 in the name indicate that this file was generated at temperature 0. If this indication is not present, then the code was generated using temperature 0.8.  For example, the name 72_CWE_Null-Dereference/4_Nullptr-Dereference/4_Buffer-Overrun-L3_temp0_10_time_78.8 indicates: 

- The prompt is the prompt 72
- Vulnerabilities were detected
- Null-Dereference and Nullptr-Dereference were detected 4 times, Buffer-Overrun-L3 only once.
- temp0 indicate that this code was generated using temperature 0
- It took 78.8 seconds






