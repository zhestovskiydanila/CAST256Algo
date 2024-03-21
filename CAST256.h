//
// Created by zhest on 19.01.2024.
//

#ifndef CAST256_
#define CAST256_

#include <algorithm>
#include <vector>


#include "cryptomath.h"
#include "includes.h"

#include "CAST_Const.h"

typedef uint32_t Msg32[4];

union Msg {
    Msg32 message32;
};

class CAST256 {
private:
    uint32_t A, B, C, D, a, b, c, d, e, f, g, h;
    std::vector <std::vector <uint8_t> > Kr, Tr;
    std::vector <std::vector <uint32_t> > Km, Tm;
    uint32_t F1(uint32_t Data, uint32_t Kmi, uint8_t Kri);
    uint32_t F2(uint32_t Data, uint32_t Kmi, uint8_t Kri);
    uint32_t F3(uint32_t Data, uint32_t Kmi, uint8_t Kri);
    void W(uint8_t i);
    std::vector <uint8_t> kr();
    std::vector <uint32_t> km();
    void Q(const uint8_t & i);
    void QBAR(const uint8_t & i);
    Msg run(const Msg & data);
    bool keyset;

public:
    CAST256();
    explicit CAST256(const std::string & KEY);
    void setkey(std::string KEY);
    Msg encrypt(const Msg & DATA);
    Msg decrypt(const Msg & DATA);
};

#endif
