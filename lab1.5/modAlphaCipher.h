/** @file modAlphaCipher
 * @author Коросткин А.П.
 * @version 1.0
 * @date 16.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Классы для шифрования методом Гронсвельда
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <cctype>
#include <UnitTest++/UnitTest++.h>
using namespace std;

/**
 * @brief класс для шифровки методом Гронсвельда
 * @details Класс может работать на русском.
*/

class modAlphaCipher
{
private:
/**
 * @brief Cоздается экземпляр объекта codec типа wstring_convert, который использует codecvt_utf8 для преобразования между wchar_t и UTF-8 кодировкой.
 * @details wstring_convert предоставляет интерфейс для преобразования между различными форматами строк, а codecvt_utf8 обеспечивает конвертацию между wchar_t и UTF-8.
*/
 wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
/**
 * @brief Создается объект numAlpha типа wstring, который является алфавитом
*/
 wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
/**
 * @brief Объявляется переменная alphaNum как объект типа map, которая отображает значения типа wchar_t (широкие символы) на значения типа int
 * @details Таким образом, это создает ассоциативный массив, который позволяет хранить связи между широкими символами и целыми числами.
*/
 map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
/**
 * @brief Объявляется переменная key как объект типа vector, которая представляет собой динамический массив, содержащий элементы типа int
 * @details Таким образом, это создает контейнер, который может хранить целочисленные значения и обеспечивает удобный доступ к этим значениям по индексу.
*/
 vector <int> key; //ключ
/**
 * @brief Преобразование строка-вектор
 * @details Объявляется функция convert, которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа vector<int>. Эта функция преобразует каждый элемент входной строки типа wstring в целочисленное значение типа int и возвращает vector, содержащий преобразованные значения.
*/
 vector<int> convert(const wstring& s); //преобразование строка-вектор
/**
 * @brief Преобразование вектор-строка
 * @details Объявляется функция convert, которая принимает константную ссылку на объект типа vector<int> в качестве аргумента и возвращает объект типа wstring. Эта функция преобразует каждый элемент входного вектора типа int в широкий символ (wstring) и возвращает строку типа wstring, содержащую преобразованные значения.
*/
 wstring convert(const vector<int>& v); //преобразование вектор-строка
/**
 * @brief Объявляется функция getValidKey,которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
 wstring getValidKey(const wstring & s);
/**
 * @brief Объявляется функция getValidOpenText,которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
 wstring getValidOpenText(const wstring & s);
/**
 * @brief Объявляется функция getValidCipherText,которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
 wstring getValidCipherText(const wstring & s);
public:
/**
 * @brief Удаление конструкторов без параметров
*/
 modAlphaCipher()=delete; //запретим конструктор без параметров
/**
 * @brief Объявляется конструктор для класса modAlphaCipher, который принимает константную ссылку на объект типа wstring в качестве аргумента.
 * @details Этот конструктор предназначен для инициализации объекта класса modAlphaCipher с использованием строки ключа типа wstring.
*/
 modAlphaCipher(const wstring& skey); //конструктор для установки ключа
/**
 * @brief Объявляется функция encrypt, которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
 wstring encrypt(const wstring& open_text); //зашифрование
/**
 * @brief Объявляется функция decrypt, которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
 wstring decrypt(const wstring& cipher_text);//расшифрование
 };
/**
 * @brief Класс для вывода ошибок при шифровании
*/

class cipher_error: public invalid_argument 
{
public:
/**
 * @brief Определяется явный конструктор cipher_error, который принимает ссылку на объект типа string в качестве аргумента what_arg
 * @details Внутри конструктора вызывается конструктор базового класса invalid_argument с переданным аргументом what_arg
*/
	explicit cipher_error (const string& what_arg):
		invalid_argument(what_arg) {}
/**
 * @brief Определяется явный конструктор cipher_error, который принимает ссылку на объект типа char в качестве аргумента what_arg
 * @details Внутри конструктора вызывается конструктор базового класса invalid_argument с переданным аргументом what_arg
*/
	explicit cipher_error (const char* what_arg):
		invalid_argument(what_arg) {}
};

