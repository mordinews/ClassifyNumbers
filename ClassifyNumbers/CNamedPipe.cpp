#include "CNamedPipe.h"


#include <iostream>
#include <windows.h>

#define PIPE_NAME L"\\\\.\\pipe\\MyPipe"

int CNamedPipe::init()
{
    HANDLE hPipe, hEvent;
    OVERLAPPED overlap = { 0 };
    char buffer[128];
    DWORD written;

    // Create a named pipe
    hPipe = CreateNamedPipe(
        PIPE_NAME,
        PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1, 128, 128, 0, NULL);


    // Create an event object for asynchronous operations
    hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (hEvent == NULL) {
        std::cerr << "Failed to create event." << std::endl;
        CloseHandle(hPipe);
        return 1;
    }
    overlap.hEvent = hEvent;
    bool connected = false;
    // Connect to the pipe
    if (!ConnectNamedPipe(hPipe, &overlap)) {
        if (GetLastError() == ERROR_IO_PENDING || GetLastError() == ERROR_PIPE_CONNECTED) {
            WaitForSingleObject(hEvent, INFINITE);
        }
        else {
            std::cerr << "Failed to connect to pipe." << std::endl;
        }
    }
    connected = true;

    // Write to the pipe
    if (connected) {
        std::cout << "Enter message: ";
        std::cin.ignore(); // Flush the newline character from the buffer
        std::cin.getline(buffer, sizeof(buffer));

        WriteFile(hPipe, buffer, strlen(buffer) + 1, &written, &overlap);
        WaitForSingleObject(hEvent, INFINITE);
        std::cout << "Message sent." << std::endl;
    }
    else {
        std::cout << "Not connected to any client." << std::endl;
    }

    // Disconnect the pipe
    DisconnectNamedPipe(hPipe);
    connected = false;
    std::cout << "Disconnected." << std::endl;

    return 1;
}
