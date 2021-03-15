#include <iostream>
#include <cmath>
#define N 100
using namespace std;

class LargeNumber
{
private:
	int* arr;
	int n;
public:
	LargeNumber (int size);
	void Input();
	void Print();
	void Sum(LargeNumber& M1, LargeNumber& M2);
	void Dif(LargeNumber& M1, LargeNumber& M2);
	void Comp(LargeNumber& M1, LargeNumber& M2);
	~LargeNumber();
};

LargeNumber::LargeNumber(int size)
{
	n = size;
	arr = new int [n];
	for (int i = 0; i < n; i++)
			arr [i] = 0;
	cout << "\n";
}

LargeNumber::~LargeNumber()
{
		delete[]arr;
}

void LargeNumber::Input()
{
	for (int i = 0; i < n; i++)
		{
			cout << "\t" << i+1 << " цифра числа = ";
			cin >> arr[i];
			cout << "\n";
		}
}

void LargeNumber::Print()
{
	cout << "\t Велике число: " ;
	for (int i = 0; i < n; i++)
			cout << arr[i];
		cout << "\n";
	
}

void LargeNumber::Sum(LargeNumber& M1, LargeNumber& M2)
{
	int a, result = 0, k=1;
	for (; n>0; n--) {
		a = M1.arr[n - 1] + M2.arr[n - 1];
		result = result + a*k;
		k = k * 10;
	}
	cout << "\t Сума великих чисел : "<< result;
}

void LargeNumber::Dif(LargeNumber& M1, LargeNumber& M2)
{
	int a, result = 0, k = 1;
	for (; n > 0; n--) {
		a = M1.arr[n - 1] - M2.arr[n - 1];
		result = result + a * k;
		k = k * 10;
	}
	cout << "\t Різниця великих чисел : " << result;
}

void LargeNumber::Comp(LargeNumber& M1, LargeNumber& M2)
{
	int a=0, b=0, k = 1;
	for (; n > 0; n--) {
		a =a+ M1.arr[n - 1] *k;
		b =b+ M2.arr[n - 1] * k;
		k = k * 10;
	}
	if (a > b)
		cout << "\tЧисло " << a << " більше ніж число " << b;
	if (a < b)
		cout << "\tЧисло " << a << " менше ніж число " << b;
	if (a == b)
		cout << "\tЧисло " << a << " дорівнює " << b;
	cout << "\n";
}

int main()
{
	system("chcp 1251");
	int n;
	cout << "\t Кількість цифр числа : ";
	cin >> n;
	LargeNumber A(n);
	A.Input();
	A.Print();
	LargeNumber B(n);
	B.Input();
	B.Print();
	LargeNumber obj1(n);
	obj1.Sum(A, B);
	LargeNumber obj2(n);
	obj2.Dif(A, B);
	LargeNumber obj3(n);
	obj3.Comp(A, B);
	return 0;
}