// complex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>

using namespace std;

class Complex       
{
private:
  double re, im;     

public:

Complex ()
  { };
 Complex (double r)   
  {  re = r;  im = 0; }
 Complex (double r, double i)
  {  re = r; im = i; }
 ~Complex ()
  { }
 Complex& operator = (Complex &c)   
  {  re = c.re; im = c.im;  return (*this); }
 Complex operator + (const Complex &c)   
  {  return Complex (re + c.re, im + c.im);  }
 Complex operator - (const Complex &c)   
  {   return Complex(re - c.re, im - c.im); }
 Complex Complex::operator * (const Complex &c)
   { return Complex(re*c.re - im*c.im, re*c.im + im*c.re);} 
 Complex Complex::operator/(const Complex &c)
{  return Complex((re*c.re + im*c.im) / (c.re*c.re + c.im*c.im), (c.re*im - re*c.im) / (c.re*c.re + c.im*c.im)); }
 
 
double Complex::Modul(const Complex &c)
{
	return double(re*c.re + im*c.im);
}



void pcomplex (Complex &c)
{
if (c.im>=0)
cout<<c.re<<"+"<<c.im<<"i"<<endl;
else
cout<<c.re<<c.im<<"i"<<endl;
}


  friend ostream & operator<< (ostream &, const Complex &);   
  friend istream & operator>> (istream &, Complex &);  

};


ostream& operator<< (ostream &out, const Complex &c)
{
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

istream& operator>> (istream &in, Complex &c)
{
  in >> c.re >> c.im;
  return in;
}

int main()
{
setlocale(LC_ALL, "rus");
  Complex a (5, 2);
  cout << "А ="<< a << endl;
  
  Complex b = a;
  cout << "B = A ="<< b << endl;

  Complex c (3, -3);
  cout << "C ="<< c << endl;
  Complex s = a + c;
 cout << "A + C ="<< s << endl;

  cout << "A - C ="<< a - c << endl;

  cout << "A / B =" << a / b<< endl;

  cout << "A * B ="<< a * b<< endl;

  cout << "A модуль ="<<a.Modul(a) << endl;
}

