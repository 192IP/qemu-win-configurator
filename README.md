# QEMU Command Generator

This program generates QEMU commands for installing or starting a Windows virtual machine. It allows users to specify various parameters, such as memory size, CPU cores, and file paths, in an interactive way.

## Features

- Interactive menu to select between installing or starting a Windows virtual machine.
- Prompts for key parameters like memory size, CPU cores, and file paths.
- Generates a QEMU command based on user input.
- Displays the generated command for manual execution.

## Requirements

- A Linux-based system with QEMU installed.
- A Windows ISO file for installation.
- VirtIO drivers ISO (if installing Windows).
- A pre-allocated virtual disk file (e.g., windows.img).
- A C++ compiler (e.g., g++) to compile the program.

## Usage

### Compilation

Compile the program using g++:

```g++ qemu_command_generator.cpp -o qemu_command_generator```
### Running the Program

Run the compiled program:

```./qemu_command_generator```
### Options

1. Install Windows: Prompts for the paths to the Windows ISO file, VirtIO drivers ISO file, and other settings to generate a command for installing Windows.
2. Start installed Windows: Prompts for the path to the virtual disk and other settings to generate a command for starting an existing Windows virtual machine.


### Notes

- Ensure the specified paths to the files are correct.
- The virtual disk (windows.img) should be created beforehand, e.g., using the qemu-img tool:
 
```  qemu-img create -f qcow2 windows.img 50G```
  

## License

This program is distributed under the GPL-2 License.
