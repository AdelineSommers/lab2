#pragma once

#define _TMATRIX_H
#include <conio.h>
#include <iomanip>
#include <iostream>

template <class ValType>
class TVector {
public:
	ValType *pVector;
	int Size;
	int StartIndex;
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);
	~TVector();
	int GetSize() { return Size; }
	int GetStartIndex() { return StartIndex; }
	//ValType & GetValue(int pos);
	ValType & operator[] (int pos);
	//int operator== (const TVector &v);
	TVector & operator = (const TVector &v);
	TVector operator+ (const ValType &val);
	TVector operator- (const ValType &val);
	TVector operator* (const ValType &val);
	TVector operator+ (const TVector &v);
	TVector operator- (const TVector &v);
	TVector operator* (const TVector &v);
	friend std::istream & operator>>(std::istream &in, TVector &v) {
		for (int i = 0; i < v.Size; i++) in >> v.pVector[i];
		return in;
	}
	friend std::ostream& operator<<(std::ostream &out, const TVector &v) {
		for (int i = 0; i < v.Size; i++) out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si) {
	pVector = new ValType[s];
	Size = s; StartIndex = si;
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType> &v) {
	pVector = new ValType[v.Size];
	Size - v.Size; StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++) pVector[i] = v.pVector[i];
}
template <class ValType>
TVector<ValType>:: ~TVector() {
	delete[] pVector;
}

//template <class ValType>
//ValType& GetValue(int pos) {
//
//}

template <class ValType>
ValType & TVector<ValType>::operator[] (int pos) {
	return pVector[pos - StartIndex];
}

template <class ValType>
TVector<ValType> & TVector<ValType>::operator= (const TVector &v) {
	if (this != &v) {
		if (Size != v.Size) {
			delete[] pVector;
			pVector = new ValType[v.Size];
		}
		Size = v.Size; StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++) pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator+(const ValType & val) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator-(const ValType& val) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator*(const ValType& val) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator+(const TVector<ValType> &v) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator-(const TVector<ValType>& v) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] - v.pVector[i];
	return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>:: operator*(const TVector<ValType>& v) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] * v.pVector[i];
	return temp;
}


template <class ValType>
class TMatrix : public TVector<TVector<ValType> > {
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);
	TMatrix(const TVector<TVector<ValType>> &mt);
	//TMatrix & operator==(const TMatrix &mt);
	TMatrix & operator=(const TMatrix &mt);
	TMatrix  operator+(const TMatrix &mt);
	TMatrix  operator-(const TMatrix &mt);
	TMatrix  operator*(const TMatrix &mt);

	friend std::istream& operator>>(std::istream &in, TMatrix &mt) {
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend std::ostream& operator<<(std::ostream &out, const TMatrix &mt) {
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << std::endl;
		return out;
	}
};
template <class ValType>
TMatrix<ValType> ::TMatrix(int s) : TVector<TVector<ValType> >(s) {
	for (int i = 0; i < s; i++)
		pVector[i] = TVector<ValType>(s - i, i);
}
template <class ValType>
TMatrix<ValType> ::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType>
TMatrix<ValType> ::TMatrix(const TVector<TVector<ValType> > &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType>
TMatrix<ValType> & TMatrix<ValType>:: operator=(const TMatrix<ValType> &mt) {
	if (this != &mt){
	if (Size != mt.Size) {
		delete[] pVector;
		pVector = new TVector<ValType>[mt.Size];
	}
	Size = mt.Size; StartIndex = mt.StartIndex;
	for (int i = 0; i < Size; i++) pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>:: operator+(const TMatrix<ValType> &mt) {
	return TVector<TVector<ValType> > ::operator+(mt);
}
template <class ValType>
TMatrix<ValType> TMatrix<ValType>:: operator-(const TMatrix<ValType>& mt) {
	return TVector<TVector<ValType> > ::operator-(mt);
}
template <class ValType>
TMatrix<ValType> TMatrix<ValType>:: operator*(const TMatrix<ValType>& mt) {
	return TVector<TVector<ValType> > ::operator*(mt);
}