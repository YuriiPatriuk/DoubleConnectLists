#include <iostream>
#include<list>
#include <vector>
#include "DoubleConnectLists.h"
#include "DList.h"
using namespace std;
//
//Створити шаблон класу Двозв’язний список(CDlist<T>).Визначити методи у шаблонному класі
//додавання нового елементу на початок списку+
//додавання нового елементу у хвіст списку+
//видалення елемента з голови списку+
//видалення елемента з хвоста списку+
//видалення всіх елементів+
//видалення елемента за значенням+
//перегляд елементів списку зліва направо+
//перегляд елементів списку справа наліво+
//вставка нового вузла до заданого
//вставка нового вузла після заданого
//пошук та заміна заданого елементу(метод повертає число виконаних замін)
//* обертання списку(бажано виконувати перестановку вузлів, не значень у вузлах)
//операція + для конкатенації(злиття) двох списків у третій(результат операції, при цьому списки, що зливаються не змінюються)
//операцією * для утворення перерізу двох списків у третьому списку(результат операції), переріз двох списків містить їх спільні елементи без повторів


int main()
{
 //   list<int> li{ 10,23,5,55 };
	//printList(li);
	//li.push_back(100);
	//printList(li);
	//++li.back();
	//printList(li);
	////vector <double> v{ 5.7, 6.3 ,7.9 };
	////li.assign(v.begin(),v.end());
	////printList(li);
	//*li.rbegin() = 44; //li.back()=44;
	//printList(li);
	//auto it = li.begin();
	//advance(it,2);
	//li.erase(it);
	//printList(li);
	//li.insert(li.begin(),124);
	//printList(li);
	//auto itR = find_if(li.begin(), li.end(), isDiv_5); //шукаємо перше число кратне 5
	//if (itR != li.end())
	//	li.insert(itR, { 0,8,88 });
	//printList(li);
	DList<int> l;
	DList<int> l1;


	l.pushBack(1);
	l.pushBack(2);
	l1.pushBack(2);
	l1.pushBack(3);
	l1.pushBack(1);
	l1.pushBack(1);

	//l.print();
	//l.pushBack(4);
	//l.pushBack(5);
	//l.print();
	//cout << "Empty: " << boolalpha << l.isEmpty() << endl;
	//cout << "Size: " << l.getSize() << endl;
	//l.popBack();
	//l.print();
	//l.popFront();
	//l.print();
	///*l.clear();
	//l.print();*/
	//cout << "Empty: " << boolalpha << l.isEmpty() << endl;
	//cout << "Size: " << l.getSize() << endl;
	//l.popByData(1);
	//l.print();
	//l.printR();
	//cout << "Size: " << l.getSize() << endl;
	/*l.pushFrontByData(1,9);
	l.pushBackByData(9,11);*/
	//l.pushBackByData(2,11);
	//l.pushBackByData(11,11);
	//l.print();
	//cout << l.searchAndChangeData(11, 0) << endl;
	l.print();
	l.reverse();
	l.print();
	DList<int> test;
	test = l1 * l;
	test.print();
	cout << "Size: " << test.getSize() << endl;

    return 0;
}

//void printList(list<int>& li)
//{
//	for (auto& elem : li)
//	{
//		cout << elem << " ";
//	}
//	cout << endl;
//}
//
//bool isDiv_5(const int value)
//{
//	return value % 5 == 0;
//}