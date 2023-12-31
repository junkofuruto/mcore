#include "shell.h"

void shell::post(const post_type& type, const std::string& message)
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    char time_buffer[80];
    std::strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &timeInfo);

    std::cout << "\033[1m\033[33m[" << time_buffer << "." << std::setfill('0') << std::setw(3) << millisec % 1000 << "]: "
        << "\033[0m\033[3" << (char)type << "m" << message << "\033[0m" << std::endl;
}