#include<iostream>
#include<locale>
using namespace std;
__forceinline double f(double x)
{
	return exp(x)+x*x-2;
}
__forceinline double f_1(double x)
{
	return exp(x) + 2*x;
}
void inter_method(double eps, double del, double x0)
{
	double c = -0.05, a =0, b = 3;
	int n = 0;
	double x2;
	auto old = cout.setf(ios_base::fixed | ios_base::right, ios_base::floatfield | ios_base::adjustfield);
	cout.precision(6);
	cout << " _____________________________________________________" << endl;
	cout << "| n |   X(n)  |  X(n+1) | |X(n+1)-X(n)| | |f(X(n+1))| |" << endl;
	cout << "|---|---------|---------|---------------|-------------|" << endl;
	while (true)
	{
		n++;
		cout << "|";
		cout.width(3);
		cout << n << "|";
		x2 = x0 + c*f(x0);
		cout.width(9);
		cout << x0<<"|";
		cout.width(9);
		cout << x2 << "|";
		cout.width(15);
		cout << fabsf(x2 - x0) << "|";
		cout.width(13);
		cout << fabsf(f(x2)) << "|";
		if (fabsf(x2 - x0) <= eps&&fabsf(f(x2)) <= del)
			break;
		x0 = x2;
		cout << endl;
	}
	cout << endl;
	cout << " -----------------------------------------------------" << endl;
	cout.setf(old);
	/*cout << "rez: " << x0 << endl;
	cout << "X(n+1): " << x2 << endl;
	cout << "n=" << n << endl;*/
}
void newton_method(double eps, double del, double x0)
{
	double a = 0, b = 3;
	int n = 0;
	double x2;
	auto old = cout.setf(ios_base::fixed | ios_base::right, ios_base::floatfield | ios_base::adjustfield);
	cout.precision(6);
	cout << " _____________________________________________________" << endl;
	cout << "| n |   X(n)  |  X(n+1) | |X(n+1)-X(n)| | |f(X(n+1))| |" << endl;
	cout << "|---|---------|---------|---------------|-------------|" << endl;
	while (true)
	{
		n++;
		cout << "|";
		cout.width(3);
		cout << n << "|";
		x2 = x0 - f(x0) / f_1(x0);
		cout.width(9);
		cout << x0 << "|";
		cout.width(9);
		cout << x2 << "|";
		cout.width(15);
		cout << fabsf(x2 - x0) << "|";
		cout.width(13);
		cout << fabsf(f(x2)) << "|";
		if (fabsf(x2 - x0) <= eps&&fabsf(f(x2)) <= del)
			break;
		x0 = x2;
		cout << endl;
	}
	cout << endl;
	cout << " -----------------------------------------------------" << endl;
	cout.setf(old);
	/*cout << "rez: " << x0 << endl;
	cout << "X(n+1): " << x2 << endl;
	cout << "n=" << n << endl;*/
}
void nioton_method_new(double eps, double del, double x0)
{
	double a = 0, b = 3;
	double point = x0;
	int n = 0;
	double x2;
	auto old = cout.setf(ios_base::fixed | ios_base::right, ios_base::floatfield | ios_base::adjustfield);
	cout.precision(6);
	cout << " _____________________________________________________" << endl;
	cout << "| n |   X(n)  |  X(n+1) | |X(n+1)-X(n)| | |f(X(n+1))| |" << endl;
	cout << "|---|---------|---------|---------------|-------------|" << endl;
	while (true)
	{
		n++;
		cout << "|";
		cout.width(3);
		cout << n << "|";
		x2 = x0 - f(x0) / f_1(point);
		cout.width(9);
		cout << x0 << "|";
		cout.width(9);
		cout << x2 << "|";
		cout.width(15);
		cout << fabsf(x2 - x0) << "|";
		cout.width(13);
		cout << fabsf(f(x2)) << "|";
		if (fabsf(x2 - x0) <= eps&&fabsf(f(x2)) <= del)
			break;
		x0 = x2;
		cout << endl;
	}
	cout << endl;
	cout << " -----------------------------------------------------" << endl;
	cout.setf(old);
	/*cout << "rez: " << x0 << endl;
	cout << "X(n+1): " << x2 << endl;
	cout << "n=" << n << endl;*/
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double x0;
	cout << "Введите начальное приближение: "; cin >> x0;
	cout << endl;
	cout.width(15);
	cout << "Точность eps=0.001 del=0.001" << endl;
	cout << "Метод итерации" << endl;
	inter_method(0.001, 0.001, x0);
	cout << endl << "Метод Ньютона" << endl;
	
	if (f(x0)*(exp(x0) + 2) > 0)
	{
		newton_method(0.001, 0.001, x0);
	}
	else
	{
		cout << "Не выполняется достаточное условие сходимости" << endl;
		cout << endl;
	}
	cout << endl << "Модифицированный метод Ньютона" << endl;
	if (f(x0)*(exp(x0) + 2) > 0)
	{
		
		nioton_method_new(0.001, 0.001, x0);
	}
	else
	{
		cout << "Не выполняется достаточное условие сходимости" << endl;
		cout << endl;
	}
	cout << endl;
	cout.width(15);
	cout << "Точность eps=0.00001 del=0.00001" << endl;
	cout << "Метод итерации" << endl;
	inter_method(0.00001, 0.00001, x0);
	cout << endl << "Метод Ньютона" << endl;
	if (f(x0)*(exp(x0) + 2) > 0)
	{
		newton_method(0.00001, 0.00001, x0);
	}
	else
	{
		cout << "Не выполняется достаточное условие сходимости" << endl;
		cout << endl;
	}
	cout << endl << "Модифицированный метод Ньютона" << endl;
	if (f(x0)*(exp(x0) + 2) > 0)
	{

		nioton_method_new(0.00001, 0.00001, x0);
	}
	else
	{
		cout << "Не выполняется достаточное условие сходимости" << endl;
		cout << endl;
	}
	system("pause");
}
