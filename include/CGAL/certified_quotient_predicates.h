// Copyright (c) 2006 Fernando Luis Cacciola Carballal. All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Straight_skeleton_2/include/CGAL/certified_quotient_predicates.h $
// $Id: certified_quotient_predicates.h 32602 2006-07-18 15:58:01Z fcacciola $
//
// Author(s)     : Fernando Cacciola <fernando_cacciola@ciudad.com.ar>
//
#ifndef CGAL_CERTIFIED_QUOTIENT_PREDICATES_H 
#define CGAL_CERTIFIED_QUOTIENT_PREDICATES_H
 
#include <CGAL/certified_numeric_predicates.h>
#include <CGAL/Quotient.h>

CGAL_BEGIN_NAMESPACE 

template <class NT>
inline Uncertain<bool> certified_quotient_is_positive(const Quotient<NT>& x) 
{
  Uncertain<Sign> signum = CGAL_NTS certified_sign(x.num) ;
  Uncertain<Sign> sigden = CGAL_NTS certified_sign(x.den) ;
  Uncertain<Sign> zero(ZERO);
  return signum != zero & signum == sigden ;
}

template <class NT> 
inline Uncertain<bool> certified_quotient_is_negative(const Quotient<NT>& x)
{
  Uncertain<Sign> signum = CGAL_NTS certified_sign(x.num) ;
  Uncertain<Sign> sigden = CGAL_NTS certified_sign(x.den) ;
  Uncertain<Sign> zero(ZERO);

  return signum != zero & signum != sigden ;
}

template <class NT>
inline Uncertain<bool> certified_quotient_is_zero(const Quotient<NT>& x)
{
  return CGAL_NTS certified_is_zero(x.num) ; 
}
 
template <class NT> 
CGAL_MEDIUM_INLINE
Uncertain<Sign> certified_quotient_sign(const Quotient<NT>& x)
{
  Uncertain<Sign> r = Uncertain<Sign>::indeterminate();

  Uncertain<Sign> signum = CGAL_NTS certified_sign(x.num) ;
  Uncertain<Sign> sigden = CGAL_NTS certified_sign(x.den) ;

  // No assumptions on the sign of  den  are made
  
  // code assumes this
  CGAL_precondition(  NEGATIVE == static_cast<Sign>(-1) 
                   && ZERO     == static_cast<Sign>(0) 
                   && POSITIVE == static_cast<Sign>(1) 
                   );

  if ( !is_indeterminate(signum) && !is_indeterminate(sigden) )
    r = make_uncertain( static_cast<Sign>(signum * sigden) ) ;

  return r ;
}

template <class NT1, class NT2>
CGAL_MEDIUM_INLINE
Uncertain<Comparison_result> certified_quotient_compare(const Quotient<NT1>& x, const Quotient<NT2>& y)
{
  Uncertain<Comparison_result> r = Uncertain<Comparison_result>::indeterminate();

  // No assumptions on the sign of  den  are made

  // code assumes that SMALLER == - 1;
  CGAL_precondition( SMALLER == static_cast<Comparison_result>(-1) );

  Uncertain<Sign> xnumsign = CGAL_NTS certified_sign(x.num) ;
  Uncertain<Sign> xdensign = CGAL_NTS certified_sign(x.den) ;
  Uncertain<Sign> ynumsign = CGAL_NTS certified_sign(y.num) ;
  Uncertain<Sign> ydensign = CGAL_NTS certified_sign(y.den) ;

  if (  !is_indeterminate(xnumsign)
     && !is_indeterminate(xdensign)
     && !is_indeterminate(ynumsign)
     && !is_indeterminate(ydensign)
     )
  {
    int xsign = xnumsign * xdensign ;
    int ysign = ynumsign * ydensign ;
    if (xsign == 0) return make_uncertain(static_cast<Comparison_result>(-ysign));
    if (ysign == 0) return make_uncertain(static_cast<Comparison_result>(xsign));
    // now (x != 0) && (y != 0)
    int diff = xsign - ysign;
    if (diff == 0)
    {
      int msign = xdensign * ydensign;
      NT1 leftop  = x.num * y.den * msign;
      NT1 rightop = y.num * x.den * msign;
      r = certified_compare(leftop, rightop);
    }
    else
    {
      r = make_uncertain((xsign < ysign) ? SMALLER : LARGER);
    }
  }

  return r ;
}

template <class NT>
inline Uncertain<bool> certified_is_zero(const Quotient<NT>& n)
{
  return certified_quotient_is_zero(n);
}
template <class NT>
inline Uncertain<bool> certified_is_positive(const Quotient<NT>& n)
{
  return certified_quotient_is_positive(n);
}
template <class NT>
inline Uncertain<bool> certified_is_negative(const Quotient<NT>& n)
{
  return certified_quotient_is_negative(n);
}
template <class NT>
inline Uncertain<Sign> certified_sign(const Quotient<NT>& n)
{
  return certified_quotient_sign(n);
}

template <class NT1, class NT2>
inline Uncertain<Comparison_result> certified_compare(const Quotient<NT1>& n1, const Quotient<NT2>& n2)
{
  return certified_quotient_compare(n1,n2);
}

CGAL_END_NAMESPACE

#endif // CGAL_CERTIFIED_QUOTIENT_PREDICATES_H
