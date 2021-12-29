#include "text.h"

using namespace std;
using namespace CryptoPP;

CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];


Text::Text()
{

}


Text::Text(QString str)
{
    this->stdstr = str.toStdString();
    for (int i = 0; i < stdstr.length(); i++)
    {
        bitsetV.push_back(bitset<7>(stdstr[i]));
    }
}


Text::Text(string str)
{
    this->stdstr = str;
    for (int i = 0; i < stdstr.length(); i++)
    {
        bitsetV.push_back(bitset<7>(stdstr[i]));
    }
}



QString Text::toQString()
{
    return QString::fromStdString(stdstr);
}

std::string Text::Getstdstr()
{
    return stdstr;
}

std::string* Text::Setstdstr()
{
    return &stdstr;
}

std::vector<std::bitset<7>> Text::GetbitsetV()
{
    return bitsetV;
}

std::vector<std::bitset<7>>* Text::SetbitsetV()
{
    return &bitsetV;
}

Text* Text::Encrypt(Text* plainText, std::vector<CryptoPP::byte> key, std::vector<CryptoPP::byte> iv)
{
    string cipherText;
    Text* ciphered;
    CryptoPP::AES::Encryption aesEncryption(&key.at(0), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, &iv.at(0));
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plainText->stdstr.c_str()), plainText->stdstr.length() + 1);
    stfEncryptor.MessageEnd();

    string cipherTextHex;
    for (int i = 0; i < cipherText.size(); i++)
    {
        char ch[3] = { 0 };
        sprintf_s(ch, "%02x", static_cast<uint8_t>(cipherText[i]));
        cipherTextHex += ch;
    }
    ciphered = new Text(cipherTextHex);
    return ciphered;
}


Text* Text::Decrypt(Text* ciphered, std::vector<CryptoPP::byte> key, std::vector<CryptoPP::byte> iv)
{
    Text* plain;
    string cipherText;
    string decryptedText;
    int i = 0;
    while (true)
    {
        char c;
        int x;
        stringstream ss;
        ss << hex << ciphered->stdstr.substr(i, 2).c_str();
        ss >> x;
        c = (char)x;
        cipherText += c;
        if (i >= ciphered->stdstr.length() - 2)break;
        i += 2;
    }
    CryptoPP::AES::Decryption aesDecryption(&key.at(0), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, &iv.at(0));
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(cipherText.c_str()), cipherText.size());
    stfDecryptor.MessageEnd();
    plain = new Text(decryptedText);
    return plain;
}



