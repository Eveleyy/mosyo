#include <iostream>
#include <fstream>
#include <string>
#include "Bot.h"
#include <filesystem>

namespace fs = std::filesystem;

std::string read_token_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string token;
    if (file.is_open()) {
        std::getline(file, token);
        file.close();
    } else {
        std::cerr << "Unable to open token file: " << filename << std::endl;
        std::cerr << "Current working directory: " << std::filesystem::current_path() << std::endl;
        exit(1);
    }
    return token;
}

int main(int argc, char* argv[]) {
    std::string token_file = "token";
    
    if (argc > 1) {
        token_file = argv[1];
    }
    
    std::string token = read_token_from_file(token_file);
    Bot discord_bot(token);
    discord_bot.run();
    return 0;
}
