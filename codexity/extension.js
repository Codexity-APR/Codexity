const vscode = require('vscode');
const fs = require('fs');
const path = require('path');


function activate(context) {


    let disposable = vscode.commands.registerCommand('Codexity.option', async () => {




		console.log('Congratulations, your extension "MyExtension" is now active!');
	const activeTextEditor = vscode.window.activeTextEditor;
	if (!activeTextEditor) {
		vscode.window.showErrorMessage('No active text editor.');
		return;
	}

	const savedFolderPath = context.globalState.get('selectedFolderPath');
	const modifyPath = await vscode.window.showQuickPick(
		['Yes', 'No'],
		{
			placeHolder: savedFolderPath
				? `Modify the saved path?\nCurrent Path: ${savedFolderPath}`
				: 'Select a path for the first time',
		}
	);

	let selectedFolderPath = savedFolderPath;

	if (modifyPath === 'Yes') {
		const folderUri = await vscode.window.showOpenDialog({
			canSelectFiles: false,
			canSelectFolders: true,
			canSelectMany: false,
			openLabel: 'Select Folder',
			defaultUri: savedFolderPath ? vscode.Uri.file(savedFolderPath) : undefined,
		});

		if (!folderUri || folderUri.length === 0) {
			vscode.window.showErrorMessage('Folder not selected.');
			return;
		}

		selectedFolderPath = folderUri[0].fsPath;
		context.globalState.update('selectedFolderPath', selectedFolderPath);
	}

	const selectedCode = activeTextEditor.document.getText(activeTextEditor.selection);
	const selection = activeTextEditor.selection;

	if (!selectedCode) {
		vscode.window.showErrorMessage('No code is selected.');
		return;
	}

	
	

        // Display a message box to the user
    const choice = await vscode.window.showQuickPick(['Iteration Repair', 'Preshot Repair'], {
            placeHolder: 'Choose an option',
        })
	if (choice === 'Iteration Repair') {
		selectedFolderPath = path.join(selectedFolderPath, 'Iteration')
		const fileName1 = 'scenario/result.c'; // Change this to your desired output file name
        const filePath1 = path.join(selectedFolderPath, fileName1);

        fs.writeFile(filePath1, selectedCode, (err) => {
            if (err) {
                vscode.window.showErrorMessage('Failed to write to C file.');
            } else {
                vscode.window.showInformationMessage(`Selected code copied to ${fileName1}.`);
            }
        });

        const pythonScriptName = "/iteration.py"; // Replace with the actual path
        const pythonScriptPath = path.join(selectedFolderPath, pythonScriptName);

        
        const markerFileName = 'result/python_script_completed.txt'
        const markerFilePath = path.join(selectedFolderPath, markerFileName);
        // Run the Python script in the terminal
        const terminal = vscode.window.createTerminal('Python Runner');
        terminal.sendText(`python3 "${pythonScriptPath}"`, true); // Run Python script in the terminal
        terminal.show();

        
        const pollInterval = 1000; 
        const maxPollAttempts = 70; 
        let pollAttempts = 0;

        const pollForMarkerFile = () => {
            if (fs.existsSync(markerFilePath) || pollAttempts >= maxPollAttempts) {
                // The marker file exists or the maximum poll attempts are reached
                vscode.window.showInformationMessage('Python script execution completed.');

                
                const fileName = 'result/final.c'; 
                
                const filePath = path.join(selectedFolderPath, fileName);

                fs.readFile(filePath, 'utf8', (err, data) => {
                    if (err) {
                        vscode.window.showErrorMessage('Failed to read C file.');
                    } else {
                        const newText = data.toString();
                        activeTextEditor.edit(editBuilder => {
                            editBuilder.replace(selection, newText);
                        });
                        vscode.window.showInformationMessage(`Code replaced.`);
                    }
                });

                
                if (fs.existsSync(markerFilePath)) {
                    fs.unlinkSync(markerFilePath);
                }
            } else {
                
                pollAttempts++;
                setTimeout(pollForMarkerFile, pollInterval);
            }
        };

        
        pollForMarkerFile();
	
	} else if (choice === 'Preshot Repair') {
		const executionType = await vscode.window.showQuickPick(['CPU', 'GPU'], {
			placeHolder: 'Do you want to execute using CPU or GPU?',
		});
	
		if (!executionType) {
			vscode.window.showErrorMessage('No execution type selected.');
			return;
		}


		selectedFolderPath = path.join(selectedFolderPath, 'Preshot')
		let pythonScriptName = '';
		if (executionType === 'CPU') {
			pythonScriptName = '/santa.py';
		} else if (executionType === 'GPU') {
			// If GPU is selected, ask the user to choose one of three scripts
			const selectedScript = await vscode.window.showQuickPick(['starcoder.py'], {
				placeHolder: 'Choose a Python script to execute:',
			});
	
			if (!selectedScript) {
				vscode.window.showErrorMessage('No script selected.');
				return;
			}
	
			// Based on the user's choice, update the script name
			pythonScriptName = '/' + selectedScript;
		}
        
        const pythonScriptPath = path.join(selectedFolderPath, pythonScriptName);

        const selectedCode = activeTextEditor.document.getText(activeTextEditor.selection);

        if (!selectedCode) {
            vscode.window.showErrorMessage('No code is selected.');
            return;
        }

        // Save the selected code to a specific file within the selected folder
        const fileName1 = 'scenario/code.c'; // Change this to your desired output file name
        const filePath1 = path.join(selectedFolderPath, fileName1);

        fs.writeFile(filePath1, selectedCode, (err) => {
            if (err) {
                vscode.window.showErrorMessage('Failed to write to C file.');
            } else {
                vscode.window.showInformationMessage(`Selected code copied to ${fileName1}.`);
            }
        });




        const markerFileName = 'result/gpt_starcoder_code.c';
        const markerFilePath = path.join(selectedFolderPath, markerFileName);

        // Create a terminal to run the Python script
        const terminal = vscode.window.createTerminal('Python Runner');

   
        const clearMarkerFile = () => {
            if (fs.existsSync(markerFilePath)) {
                fs.unlinkSync(markerFilePath);
            }
        };



        clearMarkerFile();  

		const removeDirectory = (dirPath) => {
			if (fs.existsSync(dirPath)) {
				fs.readdirSync(dirPath).forEach((file) => {
					const curPath = path.join(dirPath, file);
					if (fs.lstatSync(curPath).isDirectory()) {
						removeDirectory(curPath);
					} else {
						fs.unlinkSync(curPath);
					}
				});
				fs.rmdirSync(dirPath);
			}
		};
		
		const inferOutDir = path.join(selectedFolderPath, "/result/infer-out");
		removeDirectory(inferOutDir);

        terminal.sendText(`python3 "${pythonScriptPath}"`, true); // Run Python script in the terminal
        terminal.show();

  
        const pollInterval = 1000; 
        const maxPollAttempts = 70; 
        let pollAttempts = 0;

        const pollForMarkerFile = () => {
            if (fs.existsSync(markerFilePath) || pollAttempts >= maxPollAttempts) {
  
                vscode.window.showInformationMessage('Python script execution completed.');

    
                const fileName = 'result/gpt_starcoder_code.c'; 
                const filePath = path.join(selectedFolderPath, fileName);

                fs.readFile(filePath, 'utf8', (err, data) => {
                    if (err) {
                        vscode.window.showErrorMessage('Failed to read C file.');
                        return;
                    }

                    const newText = data.toString();
                    activeTextEditor.edit(editBuilder => {
                        editBuilder.replace(activeTextEditor.selection, newText);
                    }).then(success => {
                        if (success) {
                            vscode.window.showInformationMessage('Code replaced with content from C file.');
                        } else {
                            vscode.window.showErrorMessage('Failed to edit text in the editor.');
                        }
                    });
                });

            } else {

                pollAttempts++;
                setTimeout(pollForMarkerFile, pollInterval);
            }
        };


        pollForMarkerFile();

	
	} else {

		console.log("You didn't select any option.");
	}
    });

    context.subscriptions.push(disposable);
}

function deactivate() {}

module.exports = {
    activate,
    deactivate
}
