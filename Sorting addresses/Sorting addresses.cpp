// Sorting addresses.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

#include <cstdlib>


class Address {
private:
    std::string сityName;
    std::string streetName;
    int houseNumber;
    int apartmentNumber;
public:
    Address()
    {
        this->сityName = "c";
        streetName = "S";
        houseNumber = 0;
        apartmentNumber = 0;
    }
    
    Address(std::string сityName, std::string streetName, int houseNumber, int apartmentNumber)
    {
        this->сityName = сityName;
        this->streetName = streetName;
        this->houseNumber= houseNumber;
        this->apartmentNumber = apartmentNumber;
    }



   
   
    
    std::string  get_output_address()
    {
        return сityName + "," + streetName + "," + std::to_string(houseNumber) + "," + std::to_string(apartmentNumber);
    }

    void getPrint()
    {
        std::cout << сityName << " " << streetName << " " << houseNumber << " " << apartmentNumber << std::endl;
    }
    std::string getсityName()
    {
        return сityName;
    }


 

  void sort(Address* address, int n) {

      
       while (n--)
       {
           bool swapped = false;

           for (int i = 0; i < n; i++)
           {
               if ( address[i].getсityName() > address[i + 1].getсityName())
               {
                   std::swap(address[i], address[i + 1]);
                   swapped = true;
               }
           }

           if (swapped == false)
               break;
       }

  
    }



    
};






int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");


    /*std::ofstream fout("in.txt"); // открыли файл C:\in.txt на запись
      fout << 5 << std::endl;
      fout << "Moscow" << std::endl;// записали в файл C:\in.txt строку
      fout << "Builders" << std::endl;
      fout << 34 << std::endl;
      fout << 12 << std::endl;
      fout << "Novokuznetsk" << std::endl;
      fout << "Sciences" << std::endl;
      fout << 5 << std::endl;
      fout << 16 << std::endl;
      fout << "Omsk" << std::endl;
      fout << "Pushkin" << std::endl;
      fout << 2 << std::endl;
      fout << 13 << std::endl;
      fout << "Moscow" << std::endl;// записали в файл C:\in.txt строку
      fout << "Arbat" << std::endl;
      fout << 4 << std::endl;
      fout << 1 << std::endl;
      fout << "Novosibirsk" << std::endl;
      fout << "Peace" << std::endl;
      fout << 85 << std::endl;
      fout << 64 << std::endl;
      fout.close(); // закрыли файл
    */ 

    int sizeArr{ 1 };
    int N{};
    std::string сityName{};
    std::string streetName{};
    int houseNumber{};
    int apartmentNumber{};
    std::ifstream f("in.txt");
    if (f.is_open() == 0)
    {
        std::cout << "Ошибка открытия файла" << std::endl;
    }



    f >> sizeArr;

    Address* address = new Address[sizeArr];// создаю указатель на обект и иницииализирую конструктором по умолчанию




    for (int i = 0; i < sizeArr; i++)
    {

      

        f >> сityName;
     
        f >> streetName;
      
        f >> houseNumber;
       
        f >> apartmentNumber;
       
       
        address[i] = Address(сityName, streetName, houseNumber, apartmentNumber);//иницииализирую данными из файла 

    }
    //address[1].getPrint();
    int n = sizeArr;

    address[sizeArr+1].sort(address,  n);
   
   
   

    std::ofstream fout("out.txt"); // открыли файл C:\out.txt на запись
    fout << sizeArr << std::endl;
   

    for (int i =0 ;i < sizeArr; i++)
    {
        fout << address[i].get_output_address() << std::endl;
         address[i].getPrint();
    }

   

    f.close();
    delete[] address;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
