#include <iostream>

using namespace std;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string word {};
    cout << "Enter the word you want to encrypt: ";
    getline(cin ,word);

    string encrypted_word {};
    for (auto letter: word)
    {
        size_t index = alphabet.find(letter);
        if (index != string::npos)
        {
            encrypted_word.push_back(key.at(index));
        } else
        {
            encrypted_word.push_back(letter);
        }
    }
    cout << "Encrypted message is : " << encrypted_word << endl;

    string decrypted_word {};
    for (auto letter: encrypted_word)
    {
        size_t index = key.find(letter);
        if (index != string::npos)
        {
            decrypted_word.push_back(alphabet.at(index));
        } else
        {
            decrypted_word.push_back(letter);
        }
    }
    cout << "Decrypted message is : " << decrypted_word << endl;

    return 0;
}
