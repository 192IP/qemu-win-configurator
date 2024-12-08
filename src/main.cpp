#include <iostream>
#include <string>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getUserInput(const std::string& prompt, const std::string& defaultValue = "") {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input.empty() ? defaultValue : input;
}

int getUserIntInput(const std::string& prompt, int defaultValue) {
    int value;
    std::cout << prompt << " [" << defaultValue << "]: ";
    if (!(std::cin >> value)) {
        clearInput();
        value = defaultValue;
    }
    clearInput();
    return value;
}

int main() {
    std::cout << "=== QEMU Command Generator ===" << std::endl;

    int choice;
    std::cout << "Choose an action:\n"
              << "1. Install Windows\n"
              << "2. Start installed Windows\n"
              << "Your choice: ";
    std::cin >> choice;
    clearInput();

    if (choice != 1 && choice != 2) {
        std::cerr << "Invalid choice. Exiting program." << std::endl;
        return 1;
    }

    std::string windowsImage = getUserInput("Enter the path to the virtual disk (windows.img): ", "windows.img");

    int memory = getUserIntInput("Enter the memory size (in MB)", 4096);
    int cpus = getUserIntInput("Enter the number of CPU cores", 2);

    std::string qemuCommand;

    if (choice == 1) {
        std::string windowsISO = getUserInput("Enter the path to the Windows ISO file: ");
        std::string virtioISO = getUserInput("Enter the path to the VirtIO drivers ISO file: ");

        qemuCommand =
            "qemu-system-x86_64 -m " + std::to_string(memory) + "M "
            "-enable-kvm "
            "-cpu host "
            "-smp " + std::to_string(cpus) + " "
            "-drive file=" + windowsImage + ",format=qcow2 "
            "-cdrom " + windowsISO + " "
            "-boot d "
            "-vga qxl "
            "-device virtio-net,netdev=usernet "
            "-netdev user,id=usernet "
            "-usb -device usb-tablet "
            "-drive file=" + virtioISO + ",media=cdrom";
    } else if (choice == 2) {
        qemuCommand =
            "qemu-system-x86_64 -m " + std::to_string(memory) + "M "
            "-enable-kvm "
            "-cpu host "
            "-smp " + std::to_string(cpus) + " "
            "-drive file=" + windowsImage + ",format=qcow2 "
            "-vga qxl "
            "-device virtio-net,netdev=usernet "
            "-netdev user,id=usernet "
            "-usb -device usb-tablet";
    }

    std::cout << "\nGenerated QEMU command:\n" << qemuCommand << std::endl;
    return 0;
}
