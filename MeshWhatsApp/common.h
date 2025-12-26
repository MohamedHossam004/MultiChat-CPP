#pragma once
#include <QString>

// Inline constants to prevent multiple definition errors
inline const char* SHM_KEY = "MeshWhatsApp_SharedMemory_Key";
inline const char* SEM_SLOTS_KEY = "MeshWhatsApp_Slots_Sem";
inline const char* SEM_ITEMS_KEY = "MeshWhatsApp_Items_Sem";

const int MAX_MESSAGES = 50;
const int TEXT_SIZE = 256;

struct ChatMessage {
    int msg_id;
    char sender[32];
    char text[TEXT_SIZE];
    int priority;
    char timestamp[32];
};

struct SharedBuffer {
    int count;
    ChatMessage messages[MAX_MESSAGES];
};
