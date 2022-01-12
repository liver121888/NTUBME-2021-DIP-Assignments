/*
-------------------------
Author : Li-Wei Yang
Date : 2022/01/12
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a calss that would encrypt and decrypt a plain text.
    A Text include a std::string and a corresponding std::vetor of bitset for bit extraction.
    The encryption method is AES-128, which is considered unbreakable.
*/
#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <aes.h>
#include <filters.h>
#include <modes.h>

class Text
{
private:
    std::string stdstr;
    std::vector<std::bitset<7>> bitsetV;
public:
    Text();
    Text(QString str);
    Text(std::string str);
    QString toQString();
    std::string Getstdstr();
    std::string* Setstdstr();
    std::vector<std::bitset<7>> GetbitsetV();
    std::vector<std::bitset<7>>* SetbitsetV();
    static Text* Encrypt(Text* plainText, std::vector<CryptoPP::byte> key, std::vector<CryptoPP::byte> iv);
    static Text* Decrypt(Text* ciphered, std::vector<CryptoPP::byte> key, std::vector<CryptoPP::byte> iv);

};

#endif // TEXT_H
