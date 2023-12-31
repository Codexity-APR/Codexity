# VS Code Extension


## Prerequisite

The requirements for the python program are listed in requirement.txt. If the only model used is SantaCoder, then the openai requirement is enough. 


Two SAST tools are required for the extension to work: Infer, CppCheck. It is easy to install (usually just one command line depending on the OS).

For Infer:https://fbinfer.com/docs/next/getting-started
For CppCheck: https://cppcheck.sourceforge.io/

The extension works for CppCheck 2.9 (and above if the output format is the same) and Infer 1.1.0.

 


## Installation
 
The folder codexity contains the extension files. The folder Codexity_main contains all the necessary Python files to run the model and do the repair. These two folders can be in different places.

## Model Installation

The preshot repair works with three models: SantaCoder and StarCoder. The installation of SantaCoder must follow the instructions of https://github.com/bigcode-project/starcoder.cpp. The starcoder.cpp folder must be placed at Codexity_main/Preshot. The SantaCoder model should be at  Codexity_main/Preshot/starcoder.cpp/models/bigcode as precised in the relevant GitHub explanation.

For StarCoder, the default path is set to the respective HugginFace repositories. The path to the model can be modified in their respective Python files.

## Openai API key

An Openai key is necessary to run the programs. The key must be placed in the files Codexity_main/Iteration/gen.py and Codexity_main/preshot/santa.py (starcoder.py)

## Launching the Extension

A simple example of how to use the VS Code extension is shown in this video: https://youtu.be/3Lh8qQN9nhY

The user needs to first launch the extension. For that, the user needs to open the extenson.js file and press F5. This will launch the extension. Then, the user can select the project he/she is working on. To complete a code, the code snippet has to be highlighted. After launching Codexity, the user can select between the two mechanisms (iteration or preshot repair). The extension will then complete the code.

 
## Dataset

The Dataset is inside the folder Data. Inside it, the Prompt folder has 90 prompts. The folder ChatGPT contains the codes generated using ChatGPT. The Iteration and the Preshot folders correspond to the results using these two mechanisms. More details are explained inside these folders.



