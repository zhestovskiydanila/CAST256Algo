//
// Created by zhest on 20.01.2024.
//


#include <iostream>
#include "CAST256.h"
#include "libmd5-master/md5.cpp"
#include <fstream>
#include <cstring>
#include <cstdio>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <key> <filename>" << std::endl;
        return -1;
    }

    const std::string keyBuff = argv[1];

    CAST256 cast256(MD5::hash(argv[1]));

    std::FILE* file = fopen(argv[2], "rb");
    std::FILE* out = fopen("decrypted.txt", "wb");

    if (!file) {
        throw std::runtime_error("No such file found");
    }

    while (!feof(file)) {
        auto message = (Msg*) malloc(sizeof(Msg));
        fread(message, sizeof(Msg), 1, file);
        *message = cast256.decrypt(*message);
        fwrite(message, sizeof(Msg), 1, out);
        free(message);
    }

    fclose(file);
    fclose(out);

    return 0;
}