#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric> 
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    vector<int> v;
    vector<int>::iterator pos, min_abs_pos, max_abs_pos;

    int n = 10; 
    cout << "����� ������: " << n << endl;

    for (int i = 0; i < n; ++i)
        v.push_back(rand() % 201 - 100); 

    cout << "�����: ";
    for (const auto& elem : v)
        cout << elem << " ";
    cout << "\n";

    int sum_positive = accumulate(v.begin(), v.end(), 0, [](int sum, int x) {
        return x > 0 ? sum + x : sum;
        });
    cout << "���� ������� ��������: " << sum_positive << endl;

    min_abs_pos = min_element(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });
    max_abs_pos = max_element(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    cout << "̳�������� �� ������ �������: " << *min_abs_pos << " �� ������� " << (min_abs_pos - v.begin()) << endl;
    cout << "������������ �� ������ �������: " << *max_abs_pos << " �� ������� " << (max_abs_pos - v.begin()) << endl;

    if (min_abs_pos > max_abs_pos)
        swap(min_abs_pos, max_abs_pos);

    int product = accumulate(min_abs_pos + 1, max_abs_pos, 1, multiplies<int>());
    cout << "������� �������� �� ��������� �� ������ �� ������������ �� ������: " << product << endl;

    sort(v.begin(), v.end(), greater<int>());
    cout << "����� ���� ���������� �� ��������: ";
    for (const auto& elem : v)
        cout << elem << " ";
    cout << endl;

    system("pause");
    return 0;
}
