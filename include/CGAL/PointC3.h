// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium
//
// This software and related documentation is part of the
// Computational Geometry Algorithms Library (CGAL).
//
// Every use of CGAL requires a license. Licenses come in three kinds:
//
// - For academic research and teaching purposes, permission to use and
//   copy the software and its documentation is hereby granted free of  
//   charge, provided that
//   (1) it is not a component of a commercial product, and
//   (2) this notice appears in all copies of the software and
//       related documentation.
// - Development licenses grant access to the source code of the library 
//   to develop programs. These programs may be sold to other parties as 
//   executable code. To obtain a development license, please contact
//   the CGAL Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the CGAL Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Max-Planck-Institute Saarbrucken
// (Germany), RISC Linz (Austria), and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-1.1
// release_date  : 1998, July 24
//
// file          : include/CGAL/PointC3.h
// package       : C3 (1.4)
// source        : web/PointC3.fw
// revision      : $Revision: 1.6 $
// revision_date : $Date: 1998/03/24 14:41:53 $
// author(s)     : Andreas.Fabri
//
// coordinator   : INRIA Sophia-Antipolis
//
// email         : cgal@cs.uu.nl
//
// ======================================================================


#ifndef CGAL_POINTC3_H
#define CGAL_POINTC3_H

#include <CGAL/Threetuple.h>

template < class FT >
inline
CGAL_PointC3<FT>
operator+(const CGAL_Origin &o, const CGAL_VectorC3<FT> &v);

template < class FT >
inline
CGAL_PointC3<FT>
operator-(const CGAL_Origin &o, const CGAL_VectorC3<FT> &v);

template < class FT >
class CGAL_PointC3 : public CGAL_Handle
{
friend inline CGAL_PointC3<FT> operator+ CGAL_NULL_TMPL_ARGS(
                                         const CGAL_Origin &o,
                                         const CGAL_VectorC3<FT> &v);
friend inline CGAL_PointC3<FT> operator- CGAL_NULL_TMPL_ARGS(
                                         const CGAL_Origin &o,
                                         const CGAL_VectorC3<FT> &v);
public:
                   CGAL_PointC3();
                   CGAL_PointC3(const CGAL_Origin &o);
                   CGAL_PointC3(const CGAL_PointC3<FT> &p);
                   CGAL_PointC3(const FT &x, const FT &y, const FT &z);
                   CGAL_PointC3(const FT &x, const FT &y, const FT &z,
                                const FT &hw);
                   ~CGAL_PointC3();

  CGAL_PointC3<FT> &operator=(const CGAL_PointC3<FT> &p);

  bool             operator==(const CGAL_PointC3<FT> &p) const;
  bool             operator!=(const CGAL_PointC3<FT> &p) const;
  int              id() const;

  FT               x() const;
  FT               y() const;
  FT               z() const;

  FT               hx() const;
  FT               hy() const;
  FT               hz() const;
  FT               hw() const;

  FT               cartesian(int i) const;
  FT               operator[](int i) const;

  FT               homogeneous(int i) const;

  int              dimension() const;
  CGAL_Bbox_3      bbox() const;

  CGAL_PointC3<FT> transform( const CGAL_Aff_transformationC3<FT> &) const;


protected:
                   CGAL_PointC3(const CGAL_VectorC3<FT> &v);
private:
  CGAL__Threetuple<FT>*   ptr() const;

};

template < class FT >
inline CGAL__Threetuple<FT>* CGAL_PointC3<FT>::ptr() const
{
  return (CGAL__Threetuple<FT>*)PTR;
}


#include <CGAL/Origin.h>
#include <CGAL/VectorC3.h>

#include <CGAL/Aff_transformationC3.h>

#include <CGAL/Bbox_3.h>
#include <CGAL/number_utils.h>

template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3()
{
  PTR = new CGAL__Threetuple<FT>(FT(0), FT(0), FT(0));
}

template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3(const CGAL_Origin &)
{
  PTR = new CGAL__Threetuple<FT>(FT(0), FT(0), FT(0));
}

template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3(const CGAL_PointC3<FT> &p) :
  CGAL_Handle((CGAL_Handle&)p)
{

}

template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3(const FT &x, const FT &y, const FT &z)
{
  PTR = new CGAL__Threetuple<FT>(x, y, z);
}

template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3(const FT &x, const FT &y, const FT &z,
                               const FT &w)
{
  if( w != FT(1)) {
    PTR = new CGAL__Threetuple<FT>(x/w, y/w, z/w);
  } else {
    PTR = new CGAL__Threetuple<FT>(x, y, z);
  }
}

template < class FT >
CGAL_PointC3<FT>::~CGAL_PointC3()
{}



template < class FT >
CGAL_PointC3<FT> &CGAL_PointC3<FT>::operator=(const CGAL_PointC3<FT> &p)
{
  CGAL_Handle::operator=(p);
  return *this;
}
template < class FT >
CGAL_PointC3<FT>::CGAL_PointC3(const CGAL_VectorC3<FT> &v) :
  CGAL_Handle((CGAL_Handle&)v)
{}
template < class FT >
bool CGAL_PointC3<FT>::operator==(const CGAL_PointC3<FT>& p) const
{
  return  ((x() == p.x()) && (y() == p.y()) && (z() == p.z())) ;
}

template < class FT >
inline bool  CGAL_PointC3<FT>::operator!=(const CGAL_PointC3<FT>& p) const
{
  return !(*this == p);
}

template < class FT >
int CGAL_PointC3<FT>::id() const
{
  return (int) PTR ;
}

template < class FT >
FT CGAL_PointC3<FT>::x()  const
{
  return ptr()->e0;
}


template < class FT >
FT CGAL_PointC3<FT>::y()  const
{
  return  ptr()->e1 ;
}


template < class FT >
FT CGAL_PointC3<FT>::z()  const
{
  return  ptr()->e2 ;
}


template < class FT >
int CGAL_PointC3<FT>::dimension() const
{
  return 3;
}


template < class FT >
FT  CGAL_PointC3<FT>::cartesian(int i) const
{
  CGAL_kernel_precondition( i == 0 || i == 1 || i == 2 );
  switch (i)
    {
    case 0: return x();
    case 1: return y();
    };
  return z();
}


template < class FT >
inline FT CGAL_PointC3<FT>::operator[](int i) const
{
  return cartesian(i);
}


template < class FT >
FT CGAL_PointC3<FT>::hx()  const
{
  return ptr()->e0;
}


template < class FT >
FT CGAL_PointC3<FT>::hy()  const
{
  return ptr()->e1;
}


template < class FT >
FT CGAL_PointC3<FT>::hz()  const
{
  return ptr()->e2;
}


template < class FT >
FT CGAL_PointC3<FT>::hw()  const
{
  return FT(1);
}

template < class FT >
FT  CGAL_PointC3<FT>::homogeneous(int i) const
{
 CGAL_kernel_precondition((i>=0) && (i<=3));
  if (i<3){
    return cartesian(i);
  }
  return FT(1);
}

template < class FT >
inline CGAL_PointC3<FT> operator+(const CGAL_PointC3<FT> &p,
                                  const CGAL_VectorC3<FT> &v)
{
  return CGAL_PointC3<FT>(p.x() + v.x(), p.y() + v.y(), p.z() + v.z()) ;
}

template < class FT >
inline CGAL_PointC3<FT> operator-(const CGAL_PointC3<FT> &p,
                                  const CGAL_VectorC3<FT> &v)
{
  return CGAL_PointC3<FT>(p.x() - v.x(), p.y() - v.y(), p.z() - v.z()) ;
}

template < class FT >
inline CGAL_PointC3<FT> operator+(const CGAL_Origin &,
                                  const CGAL_VectorC3<FT> &v)
{
  return CGAL_PointC3<FT>(v) ;
}

template < class FT >
inline CGAL_PointC3<FT> operator-(const CGAL_Origin &,
                                  const CGAL_VectorC3<FT> &v)
{
  return CGAL_PointC3<FT>(-v) ;
}

template < class FT >
inline CGAL_VectorC3<FT> operator-(const CGAL_PointC3<FT> &p,
                                   const CGAL_PointC3<FT> &q)
{
  return CGAL_VectorC3<FT>(p.x() - q.x(), p.y() - q.y(), p.z() - q.z()) ;
}


template < class FT >
inline CGAL_VectorC3<FT> operator-(const CGAL_PointC3<FT> &p,
                                   const CGAL_Origin &)
{
  return CGAL_VectorC3<FT>(p) ;
}


template < class FT >
inline CGAL_VectorC3<FT> operator-(const CGAL_Origin &,
                                   const CGAL_PointC3<FT> &p)
{
  return CGAL_VectorC3<FT>(-p.x(), -p.y(), -p.z()) ;
}


template < class FT >
CGAL_PointC3<FT> CGAL_PointC3<FT>::transform(
                                 const CGAL_Aff_transformationC3<FT> &t) const
{
  return t.transform(*this);
}


template < class FT >
CGAL_Bbox_3 CGAL_PointC3<FT>::bbox() const
{
  double bx = CGAL_to_double(x());
  double by = CGAL_to_double(y());
  double bz = CGAL_to_double(z());
  return CGAL_Bbox_3(bx, by, bz, bx, by, bz);
}


#ifndef CGAL_NO_OSTREAM_INSERT_POINTC3
template < class FT >
ostream &operator<<(ostream &os, const CGAL_PointC3<FT> &p)
{
    switch(os.iword(CGAL_IO::mode)) {
    case CGAL_IO::ASCII :
        return os << p.x() << ' ' << p.y()  << ' ' << p.z();
    case CGAL_IO::BINARY :
        CGAL_write(os, p.x());
        CGAL_write(os, p.y());
        CGAL_write(os, p.z());
        return os;
    default:
        os << "PointC3(" << p.x() << ", " << p.y()  << ", " << p.z() << ")";
        return os;
    }
}
#endif // CGAL_NO_OSTREAM_INSERT_POINTC3

#ifndef CGAL_NO_ISTREAM_EXTRACT_POINTC3
template < class FT >
istream &operator>>(istream &is, CGAL_PointC3<FT> &p)
{
    FT x, y, z;
    switch(is.iword(CGAL_IO::mode)) {
    case CGAL_IO::ASCII :
        is >> x >> y >> z;
        break;
    case CGAL_IO::BINARY :
        CGAL_read(is, x);
        CGAL_read(is, y);
        CGAL_read(is, z);
        break;
    default:
        cerr << "" << endl;
        cerr << "Stream must be in ascii or binary mode" << endl;
        break;
    }
    p = CGAL_PointC3<FT>(x, y, z);
    return is;
}
#endif // CGAL_NO_ISTREAM_EXTRACT_POINTC3


#endif // CGAL_POINTC3_H