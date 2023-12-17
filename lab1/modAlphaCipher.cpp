#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const string& newkey)
{
	
}
string modAlphaCipher::decrypt(const string& cipher_st) 
{
	string s = getValidOpenText(cipher_st);
    string n_s = s;
    int l0ng, position, line, a; 
    l0ng = cipher_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = newkey*line_number+colum_number; 
            if (position-1 < l0ng) {
                n_s[position-1] = cipher_st[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::encrypt(const string& open_st) 
{
	string s = getValidOpenText(open_st);
    string n_s = s;
    int l0ng, line, position, a; 
    l0ng = open_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = colum_number+newkey*line_number;
            if (position-1 < l0ng) {
                n_s[a] = open_st[position-1];
                a++;
            }
        }
    }
    return n_s;
}
inline string modAlphaCipher::getValidOpenText(const string & s)
{
	if (s.empty()) {
        throw cipher_error("Input text cannot be empty");
    }
    // Проверка длины ключа
    if (newkey > s.length()) {
        throw cipher_error("Invalid key");
        }
    // Проверка на недопустимые символы
    for (char c : s) {
        if (!isalpha(c)) {
            throw cipher_error("Invalid characters");
        }
    }
    // Возвращаем длину строки, если все проверки пройдены
    return s;

}


 
