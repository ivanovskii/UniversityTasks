#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class RLE
{
private:
	std::string str, CStr, CStr2, DStr;
public:

	RLE() { };

	RLE(std::string s) { str = s; };

	//Есть ли в строке символ?
	bool find(std::string str, char key)
	{
		bool result = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == key) result = true;
		}
		return result;
	}

	//Добавить в encStr неповторяющиеся символы, начиная с i-ого элемента
	std::string diffSymbols(std::string encStr, std::string str, int j)
	{
		std::string secStr = "";
		int index = 0;
		for (int i = j; i < str.size(); i++)
		{
			if (str[i] != str[i + 1]) secStr += str[i];
			if (i < str.size() - 1 && str[i + 1] == str[i + 2]) break;
		}
		return (encStr + std::to_string(secStr.size()) + secStr);
	}

	//Сжатие строки
	void Compress()
	{
		std::string set = "", out = "";
		if (str[1] != str[0]) out = diffSymbols(out, str, 0); ///Когда начинается с неповторяющихся символов строка
		for (int i = 0; i < str.size(); i++)
		{
			//Если множество пусто - добавить i элемент
			if (set == "") set = str[i];
			else
				//Если множество не пусто, то если i элемент есть во множестве, то добавляем его во множество
				if (find(set, str[i]))
				{
					set += str[i];
					if (i == str.size() - 1) out = out + std::to_string(set.size()) + set[0]; ///Когда повторяющиеся символы в конце
				}
				else //Если i-ого элемента нет во множестве, выписываем сжато множество, если оно не единично, .
				{
					if (set.size() > 1)
					{
						out = out + std::to_string(set.size()) + set[0];
						set = "";
						if (str[i] != str[i + 1]) out = diffSymbols(out, str, i);
					}
					set = str[i];
				}
		}
		CStr = out;
	}

	//Декодирование строки
	void Decompress()
	{
		int num = 0;
		std::string numStr = "", decStr = "";
		for (int i = 0; i < CStr.size(); i++)
		{
			if (CStr[i] >= '0' && CStr[i] <= '9') numStr += CStr[i];
			else
			{
				std::istringstream buf(numStr);
				buf >> num;
				numStr = "";
				if (i == CStr.size() - 1 || CStr[i + 1] >= '1' && CStr[i + 1] <= '9')
					while (num != 0)
					{
						decStr += CStr[i];
						num--;
					}
				else
				{
					decStr += CStr[i];
					num--;
				}
			}
		}
		DStr = decStr;
	}

	std::string GetStr()
	{
		return str;
	}

	std::string GetCStr()
	{
		return CStr;
	}

	std::string GetDStr()
	{
		return DStr;
	}

	void ChangeStr(std::string s)
	{
		str = s;
	}
};