# Iteration Dataset
The Non_Vuln folder contains the files generated without a vulnerability. The Fixed folder contains the sub-folders of vulnerable codes successfully repaired. The Vuln folder has the sub-folders of the vulnerable codes that the iteration method did not manage to repair. Each sub-folder corresponds to the prompt used to generate the code. For example, folder 1 has the codes using the prompt 1. 


## File name for Non_Vuln folder
Each file name is composed of different elements separated by "_". The first number is the corresponding prompt number. The last number is to separate the files between them. If the file has a vulnerability, then it is indicated by the "CWE" in the name. In this case, any numbers following the "CWE" (except the last number) correspond to a CWE detected in this file. Moreover, a vulnerability name can also be present in the name. If a '/' or ':' (depending on the OS) follows a CWE number or a vulnerability name, it indicates the number of occurrences of the vulnerability. Also, the number following 'time' corresponds to the time it took to generate the code. Finally, the element temp0 in the name indicates that this file was generated at temperature 0. If this indication is not present, then the code was generated using temperature 0.8. For example, the name 72_CWE_Null-Dereference/4_Nullptr-Dereference/4_Buffer-Overrun-L3_temp0_10_time_78.8 indicates: 

- The prompt is the prompt 72
- Vulnerabilities were detected
- Null-Dereference and Nullptr-Dereference were detected 4 times, Buffer-Overrun-L3 only once.
- temp0 indicates that this code was generated using temperature 0
- It took 78.8 seconds


## Fixed and Vuln folders structure
In these folders, each subfolder contains folders. The name of the folders follows the same logic as the file explained above. Inside each folder, there are different round folders corresponding to the iteration done during the repair. In a round folder, the gen0 folder contains the code generated. The scenario folder contains the same code but with the vulnerabilities written on the file.



