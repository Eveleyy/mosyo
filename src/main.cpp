#include <iostream>
#include <fstream>
#include <string>
#include "Bot.h"

std::string read_token_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string token;
    if (file.is_open()) {
        std::getline(file, token);
        file.close();
    } else {
        std::cerr << "Unable to open token file" << std::endl;
        exit(1);
    }
    return token;
}

int main() {
    std::string token = read_token_from_file("token");
    Bot discord_bot(token);
    discord_bot.run();
    return 0;
}
