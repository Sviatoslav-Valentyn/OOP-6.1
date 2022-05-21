#pragma once
#include <iostream>
using namespace std;

class Array
{
public:
	typedef unsigned int UINT;
	typedef double value_type;
	typedef double* iterator;
	typedef const double* const_iterator;
	typedef double& reference;
	typedef const double& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10; // м≥н≥мальний розм≥р масиву
	size_type Size;  // вид≥лено памТ€т≥ дл€ елемент≥в
	size_type Count;  // к≥льк≥сть елемент≥в в масив≥
	size_type First;  // значенн€ ≥ндексу першого елемента в масив≥
	value_type* elems;  // вказ≥вник на дан≥
public:
	// конструктори/коп≥юванн€/деструктор
	Array(const size_type& n = minsize)
		throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const iterator first, const iterator last)
		throw(bad_alloc, invalid_argument);
	Array(const size_type first, const size_type last)
		throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);


	// ≥тератори
	iterator begin() { return elems; }
	const_iterator begin() const { return elems; }
	iterator end() { return elems + Count; }
	const_iterator end() const { return elems + Count; }

	// розм≥ри
	size_type size() const;   // поточний розм≥р
	bool empty() const;		// €кщо Ї елементи
	size_type capacity() const;    // потенц≥йний розм≥р
	void resize(size_type newsize)    // зм≥нити розм≥р
		throw(bad_alloc);

	// доступ до елемент≥в
	reference operator[](size_type) throw(out_of_range);
	const_reference operator[](size_type) const throw(out_of_range);
	reference front() { return elems[0]; }
	const_reference front() const { return elems[0]; }
	reference back() { return elems[size() - 1]; }
	const_reference back() const { return elems[size() - 1]; }

	// методи-модиф≥катори
	void push_back(const value_type& v);   // добавити елемент в к≥нець
	value_type pop_back() throw(out_of_range);  // видалити останн≥й елемент Ц реал≥зувати самост≥йно
	void clear() { Count = 0; }			// очистити масив
	void swap(Array& other);				// пом≥н€ти з другим масивом
	void assign(const value_type& v);			// заповнити масив Ц реал≥зувати самост≥йно

	// дружн≥ функц≥њ вводу/виводу
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);

	value_type sum();
	value_type abs_mean() throw(logic_error);
	void add_mean();
};