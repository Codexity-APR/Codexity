# secure-language-model

## Prerequisite

The CodeQL CLI is needed for now. It can be downloaded using the following link : https://github.com/github/codeql-cli-binaries/releases

Once extracted, you can run CodeQL processes by running the codeql executable in a couple of ways:

- **1:** By executing <extraction-root>/codeql/codeql, where <extraction-root> is the folder where you extracted the CodeQL CLI package.
- **2:** By adding <extraction-root>/codeql to your PATH, so that you can run the executable as just codeql.

Then you can verify hat you are correctly set up to create and analyze databases: 
- **.** Run codeql resolve languages to show which languages are available for database creation. This will list the languages supported by default in your CodeQL CLI package.

Because there are not enought queries avaible, you can dowload the CodeQL github repository and put it inside the repository containing CodeQL CLI.

The main_snyk.py is the version with snyk. All you need to do is to install snyk CLI. The installation depends on the OS of the computer : https://docs.snyk.io/snyk-cli/install-the-snyk-cli
 After installing it, just run main_snyk.py. 

For the ICSE method, you need three SASTS: Infer, CppCheck and flawfinder. It is easy to install (usually just one command line depending on the OS).

For Infer:https://fbinfer.com/docs/next/getting-started
For CppCheck: https://cppcheck.sourceforge.io/
For Flawfinder: https://dwheeler.com/flawfinder/

Make sure to install a recent version of Flawfinder it the installation is done on Linux.
 
## Files organization

The "scenario" file contains the inital prompts. The "logit_biais"  and "comment" contain the logit biais and the new comment we want to add. 

Once the generation finished, the files are organized as follows :

- **Round file:** For every round, there is a file name roundx, where "x" is the corresponding round.
- **generation file:** For every temperature, there is a corresponding file called genx, where x is the temperature. 
- **CodeQL files:** The "data" file  is the codes transform into database. The "results" file contain the CodeQL anaysis for each gen file in cvs.
- **Scenario files:** For each temperature, the vulnerable code is modified and and modified prompt is then created and placed into the corresponding file. Those serve as futur prompt for the next round.

With the "snyk" version", we don't use the logit bias for now.

## Running the automated program
 
In the ICSE directory, you can go to 'iteration method' and launch the programm with the commande line 'python3 icse.py'. It will take all the files in the repository 'scenario'.
 
## Dataset

Because, I am using ChatGPT, the rate of vulnerable code generation is significantly lower. I had to find another way to create a dataset of vulnerable code. The detail is explained here: https://docs.google.com/document/d/1s1X0H-zv2RvL3MZLU3wv7hvIzgr8G8b0ZmfF_FRGOzQ/edit?usp=sharing

For now, the vulnerability are mostly detected by CppCheck and Flawfinder.

 ## Ground Truth
 
 This dataset is easier to use. Inside each CWEs files, the subjects are separated into two parts: vulnerable and not. For C files, there is a non-vulnerable version of the subject. A CWE file with a "\*" in its name means that Flawinder detects the vulnerability. When it's a "**" instead, it means that only a part of the subjects are detected (indicated by a "\*" inside the CWE file)


