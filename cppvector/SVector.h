/* Copyright (c) 1997 by the Scientific Computation Research Center,
 *                           Rensselaer Polytechnic Institute,
 *                           Troy, NY 12180
 */

#ifndef H_SVector
#define H_SVector

#ifdef _SCOREC_NewCompiler
namespace SCOREC_Util {
#endif

class SMatrix;

// A concrete templated class for a vector of numeric values
template<class T>
class SVector{
public:
  // construct an empty vector of length zero
  SVector();

  // construct a vector of length l
  SVector(int l);

  // construct a vector of length l with all entries initialized to val
  SVector(int l, T val);

  /* construct a vector of length l with entries initialized to the
    contents of the array val */
  SVector(int l, const T *val);

 /* encapsulate the array val inside an SVector, the ownership
    of val is taken by the SVector (val will be deleted when the
    vector is deleted. The third argument is a dummy value. */
  SVector(int l, T *val, int);  // this one takes ownerships of val

  //
  SVector(const SVector<T>&);

  //
  ~SVector() {delete [] v;};

  // assignment  
  SVector<T> & operator = (const SVector<T> &);

  // assignment of all elements of vector to given value
  SVector<T> & operator = (T val);
  
  // SVector-matrix operations
  
  /*@name SVector-SVector operations */
  //@{  
  //
  friend T operator * (const SVector<T> &, const SVector<T> &);
  //
  friend SVector<T> operator + (const SVector<T> &, const SVector<T> &);
  //
  friend SVector<T> operator - (const SVector<T> &, const SVector<T> &);
  
  //
  SVector<T> & operator += (const SVector<T> &);
  //
  SVector<T> & operator -= (const SVector<T> &);
  //
  SVector<T> operator -();
  //@}

  /**@name SVector-scalar operations */
  // The friend declaration had to be eliminated. Otherwise the SUN C 5.0
  // linker would complain that the functions are missing.
  //@{
  //
  //friend SVector<T> operator + (const SVector<T> &, T);
  //
  friend SVector<T> operator - (const SVector<T> &, T);
  //
  //friend SVector<T> operator * (const SVector<T> &,T mult);
  //
  //friend SVector<T> operator * (T mult, const SVector<T> &);
  //
  //friend SVector<T> operator / (const SVector<T> &, T);
  //
  SVector<T> & operator *= (T);
  //@}
  
  // stream output
  
  // element modification, e.g. v(i)=b
  T & operator () (int n);
  // element access, e.g. b = v(i)
  T operator () (int n) const;
  
  // get size
  int size() const;
  
  void setSize(int);

  void print();
protected:
friend class SMatrix;
  T *v;
  int Size;
};

template<class T>
T dot(const SVector<T> &a, const SVector<T> &b);

template<class T>
T dot(const SVector<T> &a, const SVector<T> &b)
{
  T val(0);
  for(int i = 0; i < a.size(); i++)
    val += a(i)*b(i);
  return val;
}


template<class T>
inline T & SVector<T>::operator () (int n)
{
  return( v[n]);
}

template<class T>
inline T SVector<T>::operator () (int n) const
{
  return( v[n]);
}

#if 0
// these are needed by Sun CC 4.0.1, not sure about others
template<class T> T operator * (const SVector<T> &, const SVector<T> &);
template<class T> SVector<T> operator + (const SVector<T> &, const SVector<T> &);
template<class T> SVector<T> operator - (const SVector<T> &, const SVector<T> &);
template<class T> SVector<T> operator + (const SVector<T> &, T);
template<class T> SVector<T> operator - (const SVector<T> &, T);
template<class T> SVector<T> operator * (const SVector<T> &, T);
template<class T> SVector<T> operator * (T,const SVector<T> &);
template<class T> SVector<T> operator / (const SVector<T> &, T);
#endif

template<class T>
inline SVector<T>::SVector()
{
  Size = 0;
  v = 0;
}

template<class T>
inline SVector<T>::SVector(int l)
{
  Size = l;
  v = new T[l];
}

template<class T>
SVector<T>::SVector(int l, T val)
{
  Size = l;
  v = new T[l];
  for(int i=0; i < l; i++)
    v[i] = val;
}

template<class T>
SVector<T>::SVector(int l, const T *val)
{
  Size = l;
  v = new T[l];
  for(int i=0; i < l; i++)
    v[i] = val[i];
}

template<class T>
inline SVector<T>::SVector(int l, T *val, int)
{
  Size = l;
  v = val;
}

template<class T>
SVector<T>::SVector(const SVector<T> &vec)
{
  Size = vec.Size;
  v = new T[Size];
  for(int i=0; i < Size; i++)
    v[i] = vec.v[i];
}

template<class T>
inline int SVector<T>::size() const
{ return Size; }

template<class T>
void SVector<T>::setSize(int size)
{
  if(v)
    delete [] v;
  v = new T[size];
  Size = size;
}

template<class T>
SVector<T> & SVector<T>::operator += (const SVector<T> &vec)
{
#ifdef _SCOREC_NewCompiler
  if(Size != vec.Size)
    throw InvalidOperation(__FILE__,__LINE__);
#endif
    //"SVector<T>::operator+= size mismatch\n";
  for(int i = 0; i < Size; i++)
    v[i] += vec.v[i];
  return *this;
}

template<class T>
inline SVector<T> & SVector<T>::operator *= (T mult)
{
  int i;
  for(i = 0; i < Size; i++)
    v[i] *= mult;
  return *this;
}

template<class T>
inline SVector<T> & SVector<T>::operator = (T val)
{
  int i;
  for(i = 0; i < Size; i++)
    v[i] = val;
  return *this;
}

template<class T>
SVector<T> & SVector<T>::operator = (const SVector<T> &vec)
{
  if(Size != vec.Size)
    setSize(vec.Size);
  for(int i = 0; i < Size; i++)
    v[i] = vec(i);
  return *this;
}

template<class T>
SVector<T> & SVector<T>::operator -= (const SVector<T> &vec)
{
#ifdef _SCOREC_NewCompiler
  if(Size != vec.Size)
    throw InvalidOperation(__FILE__,__LINE__);
#endif
    //"SVector<T>::operator+= size mismatch\n";
  for(int i = 0; i < Size; i++)
    v[i] -= vec.v[i];
  return *this;
}

template<class T>
SVector<T> SVector<T>::operator - ()
{
  SVector<T> vec(Size);

  for(int i = 0; i < Size; i++)
    vec.v[i] = -v[i];
  return vec;
}

template<class T>
SVector<T> operator + (const SVector<T> &v, T s)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)+s;
  return vec;
}

template<class T>
SVector<T> operator - (const SVector<T> &v, T s)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)-s;
  return vec;
}

template<class T>
SVector<T> operator * (const SVector<T> &v, T s)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)*s;
  return vec;
}

template<class T>
SVector<T> operator * (T s,const SVector<T> &v)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)*s;
  return vec;
}

template<class T>
SVector<T> operator / (const SVector<T> &v, T s)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)/s;
  return vec;
}


template<class T>
SVector<T> operator - (const SVector<T> &v, const SVector<T> &v2)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)-v2(i);
  return vec;
}

template<class T>
SVector<T> operator + (const SVector<T> &v, const SVector<T> &v2)
{
  SVector<T> vec(v.size());
  for(int i = 0; i < v.size(); i++)
    vec(i) = v(i)+v2(i);
  return vec;
}


template<class T>
T operator * (const SVector<T> &v, const SVector<T> &v2)
{
  T result(0.0);
  for(int i = 0; i < v.size(); i++)
    result += v(i)*v2(i);
  return result;
}

template<class T>
void SVector<T>::print()
{
  int i;
  for(i=0; i < size(); i++)
    cerr << v[i] << " ";
}

#ifdef _SCOREC_NewCompiler
} // end of namespace SCOREC_Util
#endif

#endif
