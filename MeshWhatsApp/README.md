# 🌐 MeshWhatsApp

**MeshWhatsApp** is a sophisticated multi-process chat application built using **Qt C++** that demonstrates advanced Operating Systems concepts including **TCP Socket Communication** and **Shared Memory IPC (Inter-Process Communication)** with various CPU scheduling algorithms for message processing.

![Version](https://img.shields.io/badge/version-0.1-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Qt](https://img.shields.io/badge/Qt-5%2F6-brightgreen)

---

## ✨ Features

### 🔌 Dual Communication Modes
- **Socket-based Communication**: Real-time TCP socket messaging between clients and servers
- **Shared Memory Communication**: High-performance IPC using Qt's shared memory mechanisms

### 🧠 CPU Scheduling Algorithms
Experience different message processing strategies through multiple scheduling algorithms:
- **FCFS (First-Come, First-Served)**: Process messages in arrival order
- **Priority Scheduling**: Handle high-priority messages first
- **Round Robin (RR)**: Time-sliced fair message processing
- **SJF (Shortest Job First)**: Process shortest messages first

### 🎨 Modern Qt GUI
- Clean and intuitive user interface
- Real-time message display
- Connection status indicators
- Algorithm selection dropdown
- Separate views for socket and shared memory communications

### 🔄 Multi-Threading & Synchronization
- Thread-safe shared memory access using semaphores
- Producer-Consumer pattern implementation
- Real-time message polling with Qt timers

---

## 🏗️ Project Structure

```
MeshWhatsApp/
├── main.cpp                 # Application entry point
├── mainwindow.h/.cpp/.ui    # Main GUI window and logic
├── sockethandler.h/.cpp     # TCP socket communication handler
├── shmhandler.h/.cpp        # Shared memory IPC handler
├── common.h                 # Shared data structures and constants
├── CMakeLists.txt           # CMake build configuration
├── app_icon.ico             # Application icon
└── Server/                  # Server-side implementation (if separate)
```

---

## 🛠️ Technologies & Concepts

### Core Technologies
- **C++17**: Modern C++ standard
- **Qt Framework**: Cross-platform application framework
  - `Qt Widgets`: GUI components
  - `Qt Network`: TCP socket functionality
  - `QSharedMemory`: Shared memory implementation
  - `QSystemSemaphore`: Synchronization primitives

### Operating Systems Concepts
- **Inter-Process Communication (IPC)**
  - Shared Memory
  - Semaphores (Slots & Items)
- **Network Programming**
  - TCP Sockets
  - Client-Server Architecture
- **Process Synchronization**
  - Producer-Consumer Problem
  - Mutual Exclusion
- **CPU Scheduling Algorithms**
  - FCFS, Priority, Round Robin, SJF

---

## 📋 Prerequisites

Before building and running MeshWhatsApp, ensure you have:

- **CMake** (version 3.16 or higher)
- **Qt Framework** (Qt 5 or Qt 6)
  - Qt Widgets module
  - Qt Network module
- **C++ Compiler** with C++17 support
  - MSVC (Visual Studio 2019/2022) on Windows
  - GCC/Clang on Linux/macOS

---

## 🚀 Building the Project

### Using CMake (Recommended)

```bash
# Create build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build
cmake --build .

# Run
./MeshWhatsApp  # Linux/macOS
MeshWhatsApp.exe  # Windows
```

### Using Qt Creator

1. Open `CMakeLists.txt` in Qt Creator
2. Configure the project with your Qt kit
3. Build the project (Ctrl+B)
4. Run the application (Ctrl+R)

---

## 📖 How to Use

### Socket Communication Mode

1. **Start the Server**: Run a separate instance or server application
2. **Connect to Server**:
   - Enter server IP address (e.g., `127.0.0.1` for localhost)
   - Enter port number (e.g., `12345`)
   - Click "Connect"
3. **Send Messages**:
   - Type your message
   - Click "Send" to transmit via socket

### Shared Memory Mode

1. **Initialize Shared Memory**:
   - Click "Initialize SHM" to create/attach to shared memory
   - Set your username
2. **Select Scheduling Algorithm**:
   - Choose from dropdown: FCFS, Priority, Round Robin, or SJF
3. **Send Messages**:
   - Type your message
   - Set priority (if using Priority scheduling)
   - Click "Send SHM"
4. **Receive Messages**:
   - Messages are automatically polled and processed
   - Algorithm determines the order of message retrieval

---

## 🔍 Key Components Explained

### SharedBuffer Structure
```cpp
struct ChatMessage {
    int msg_id;           // Unique message identifier
    char sender[32];      // Sender username
    char text[256];       // Message content
    int priority;         // Message priority (0-10)
    char timestamp[32];   // Send timestamp
};

struct SharedBuffer {
    int count;                          // Number of messages
    ChatMessage messages[MAX_MESSAGES]; // Message queue (50 max)
};
```

### Semaphore Synchronization
- **semSlots**: Counts available slots in shared memory (starts at MAX_MESSAGES)
- **semItems**: Counts filled slots with messages (starts at 0)
- Ensures producer-consumer synchronization

---

## 🎯 Learning Outcomes

This project demonstrates:
- ✅ **Socket Programming**: TCP client-server communication
- ✅ **Shared Memory IPC**: Fast inter-process data exchange
- ✅ **Synchronization**: Semaphores for thread/process safety
- ✅ **Scheduling Algorithms**: Practical implementation of OS concepts
- ✅ **GUI Development**: Modern Qt application design
- ✅ **CMake Build Systems**: Cross-platform build configuration

---

## 🐛 Troubleshooting

### Common Issues

**Shared Memory Access Error**
- Ensure no other instance is holding the shared memory
- On Windows, check Task Manager for zombie processes
- Try rebooting if semaphores are stuck

**Socket Connection Failed**
- Verify server is running and listening
- Check firewall settings
- Ensure correct IP and port

**Build Errors**
- Verify Qt installation path
- Check CMake finds Qt correctly (`CMAKE_PREFIX_PATH`)
- Ensure all required Qt modules are installed

---

## 📚 Future Enhancements

- [ ] Encryption for socket messages (SSL/TLS)
- [ ] File transfer support
- [ ] Group chat functionality
- [ ] Message persistence (database integration)
- [ ] Network discovery (auto-find peers)
- [ ] Emoji and rich text support
- [ ] Cross-platform testing and optimization

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

Built as an Operating Systems course project demonstrating practical implementation of OS concepts.

---

## 🙏 Acknowledgments

- Qt Framework for excellent cross-platform tools
- Operating Systems course materials and concepts
- Open-source community for inspiration

---

**⭐ If you find this project helpful, please consider giving it a star!**
