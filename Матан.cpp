#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

const double Pi = acos(-1); 

  double ctg(double x) { 
	double a = cos(x);
	double b = sin(x);
    return (a / b);
}

struct Leksema //описывает любое число или операцию
{
	char type; // "+" для операции сложения ...
	double value; //значение только для чисел
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { 
	double a, b, c;
	a = Stack_n.top().value; 
	Stack_n.pop(); 
	switch (Stack_o.top().type) { 
	case '+': 
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); //результат операции кладется обратно в стек с числами
		Stack_o.pop();
		break;

	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '^':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = pow(b, a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '/':
		b = Stack_n.top().value;
		if (a == 0) 
		{
			cout << "\nНа 0 делить нельзя!\n";
			return false;
		}
		else 
		{
			Stack_n.pop();
			c = (b / a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 's':
		c = sin(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'a':
		c = asin(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'c':
		c = cos(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'm':
		c = acos(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 't':
		if (cos(a) == 0)
		{
			cout << "\nНеверный аргумент для тангенса!\n";
			return false;
		}
		else 
		{
			c = tan(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'g':
		if (sin(a) == 0)
		{
			cout << "\nНеверный аргумент для котангенса!\n";
			return false;
		}
		else
		{
			c = ctg(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'e':
		c = exp(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'n':
		if (a == 0)
		{
			cout << "\nНеверный аргумент для ln!\n";
			return false;
		}
		else
		{
			c = log(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'l':
		b = Stack_n.top().value;
		Stack_n.pop();
		if (a > 0 || b>0 || a!=1)
		{
			c = log(b)/log(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}
		else
		{
			cout << "\nНеверно заданые параметры логарифма!\n";
			return false;
		
		}

	default:
		cout << "\nОшибка!\n";
		return false;
		break;
	}
	return true;
}

int Rang(char Ch) { //возвращает приоритет операции: "1" для сложения и вычитания, "2" для умножения и деления и т.д.
	if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e'|| Ch=='l') return 4;
	if (Ch == '^')return 3;
	if (Ch == '*' || Ch == '/')return 2;
	if (Ch == '+' || Ch == '-')return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "   Для испрользования числа Пи введите 'p', для использования числа e введите 'exp(1)' \n";
	cout << "   Для использования тригонометрических функций,например,sin x.\n";
	cout << "   Возведение в x степень n - x^n; натуральный логарифм-ln (x)\n";
	cout << "   Логарифм числа b по основанию a- log b a\n";
	cout << "   Для использование функций arcsin или arccos-as x и ac x,соотвественно\n";
	cout << "   Другие допустимые знаки +,-,*,/,()\n";
	cout << "   Введите выражение: ";

	char Ch; //записываем суда текующий обрабатываемый символ 
	double value;
	bool flag = 1;  //унарный минус 
	stack <Leksema> Stack_n; 
	stack <Leksema> Stack_o;
	Leksema item; 
	while (1) {
		Ch = cin.peek(); //1 символ
		if (Ch == '\n') break; //если достигнут конец строки, выходим из цикла
		if (Ch == ' '){ //не смотрим на пробелы
			cin.ignore();
			continue;
		}
		if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e' || Ch == 'n' || Ch=='l' || Ch=='a' || Ch=='m') {
			char foo[3]; 
			for (int i = 0; i < 3; i++)
			{
				Ch = cin.peek();
				foo[i] = Ch;
				cin.ignore();
			}

			if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') { 
				item.type = 's';
				item.value = 0;
				Stack_o.push(item); //операция кладется в стек с операциями
				continue;
			}

			if (foo[0] == 'a' && foo[1] == 's') { 
				item.type = 'a';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}

			

			if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { 
				item.type = 'c';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}

			if (foo[0] == 'a' && foo[1] == 'c') { 
				item.type = 'm';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}

			if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { 
				item.type = 't';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}

			if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { 
				item.type = 'g';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}

			if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') { 
				item.type = 'e';
				item.value = 0;
				Stack_o.push(item);
				continue;
			}

			if (foo[0] == 'l' && foo[1] == 'n') { 
				item.type = 'n';
				item.value = 0;
				Stack_o.push(item);
				continue;
			}

			if (foo[0] == 'l' && foo[1] == 'o' && foo[2]=='g') { 
				item.type = 'l';
				item.value = 0;
				Stack_o.push(item); 
				continue;
			}
			
		}
		if (Ch == 'p') { 
			item.type = '0';
			item.value = Pi;
			Stack_n.push(item); 
			flag = 0;
			cin.ignore();
			continue;
		}
		if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) { 
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item); 
			flag = 0;
			continue;
		}
		if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') {
			if (Stack_o.size() == 0) { //если стек с операциями пуст
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item);
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && Rang(Ch) > Rang(Stack_o.top().type)) { 
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item); 
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && Rang(Ch) <= Rang(Stack_o.top().type)) {
				if (Maths(Stack_n, Stack_o, item) == false) 
				{ 
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (Ch == '(') { 
			item.type = Ch;
			item.value = 0;
			Stack_o.push(item); 
			cin.ignore();
			continue;
		}
		if (Ch == ')') { 
			while (Stack_o.top().type != '(') 
			{
				if (Maths(Stack_n, Stack_o, item) == false) 
				{ 
					system("pause");
					return 0;
				}
				else continue;	
			}
			Stack_o.pop();
			cin.ignore();
			continue;
		}
		else 
		{ 
			cout << "\nНеверно введено выражение!\n";
			system("pause");
			return 0;
		}
	}
	while (Stack_o.size() != 0) { 
		if (Maths(Stack_n, Stack_o, item) == false) { 
			system("pause");
			return 0;
		}
		else continue; 	
	}
	cout << "   Ответ: " << Stack_n.top().value << endl; 
	system("pause");
	return 0;
} 