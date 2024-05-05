// ConsoleApplication44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <memory>


template <class container>
void print(const container& c)
{
    
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << "\t";
    };
    std::cout << "\n";
}
class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix>  clone()
    {
        return (std::make_unique<tridiagonal_matrix>(m_down, m_upper,m_middle));
    };
};

int main()

{
    setlocale(LC_ALL, "Russian");
    //std::cout << "Hello World!\n";
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );
    std::cout << "Изначальный обьект!\n";
    std::cout << "Вектор m_down\n";
    print(matrix->m_down);

    std::cout << "Вектор m_upper\n";
    print(matrix->m_upper);

    std::cout << "Вектор m_middle\n";
    print(matrix->m_middle);


    auto matrix_clone = matrix->clone();
    std::cout << "Скопированный обьект!\n";
   std::cout << "Вектор m_down\n";
   print(matrix_clone->m_down);

   std::cout << "Вектор m_upper\n";
   print(matrix_clone->m_upper);

   std::cout << "Вектор m_middle\n";
   print(matrix_clone->m_middle);
    

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
