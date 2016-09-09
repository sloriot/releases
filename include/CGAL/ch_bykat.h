// ======================================================================
//
// Copyright (c) 1998 The CGAL Consortium
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
// release       : CGAL-1.1
// release_date  : 1998, July 24
//
// file          : include/CGAL/ch_bykat.h
// package       : Convex_hull (1.2.3)
// source        : convex_hull_2.lw
// revision      : 1.2.3
// revision_date : 07 Apr 1998
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
//
// email         : cgal@cs.uu.nl
//
// ======================================================================


#ifndef CGAL_CH_BYKAT_H
#define CGAL_CH_BYKAT_H

#include <CGAL/ch_utils.h>
#ifdef CGAL_REP_CLASS_DEFINED
#include <CGAL/convex_hull_traits_2.h>
#ifdef CGAL_STL_GCC
#ifndef CGAL_GNU_ISTREAM_ITERATOR_VALUE_TYPE_FIX_H
#include <CGAL/gnu_istream_iterator_value_type_fix.h>
#endif // CGAL_GNU_ISTREAM_ITERATOR_VALUE_TYPE_FIX_H
#endif // CGAL_STL_GCC
#endif // CGAL_REP_CLASS_DEFINED
#ifndef CGAL_CH_NO_POSTCONDITIONS
#include <CGAL/convexity_check_2.h>

#endif // CGAL_CH_NO_POSTCONDITIONS


#include <CGAL/ch_selected_extreme_points_2.h>
#include <list.h>
#include <algo.h>
#include <CGAL/stl_extensions.h>
#include <CGAL/ch_graham_andrew.h>
/*{\Moptions
outfile=cgal_ch_I_b.man
}*/

/*{\Mtext [[\#include <CGAL/ch_bykat.h>]]
}*/

template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
CGAL_ch_bykat(InputIterator first, InputIterator last, 
             OutputIterator  result,
             const Traits& ch_traits);
/*{\Mfuncl 
same as |CGAL_convex_hull_points_2(first,last,result)|.\\
{\sc traits}: uses |Traits::Point_2|, |Traits::Less_dist_to_line|, 
|Traits::Right_of_line|, and |Traits::Less_xy|.
}*/

template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
CGAL_ch_bykat_with_threshold(InputIterator first, InputIterator last, 
                             OutputIterator  result,
                             const Traits& ch_traits);
#ifdef CGAL_POINT_2_H
/*{\Moptions
outfile=cgal_ch_b.man
}*/

template <class InputIterator, class OutputIterator, class R>
inline
OutputIterator
CGAL_ch__bykat(InputIterator first, InputIterator last, 
              OutputIterator  result,
              CGAL_Point_2<R>* )
{
  return CGAL_ch_bykat(first, last, result, CGAL_convex_hull_traits_2<R>() );
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator
CGAL_ch_bykat(InputIterator first, InputIterator last, OutputIterator  result)
{
  return CGAL_ch__bykat( first, last, result, value_type(first) );
}
/*{\Mfuncl 
same as |CGAL_convex_hull_points_2(first,last,result)|.
}*/

template <class InputIterator, class OutputIterator, class R>
inline
OutputIterator
CGAL_ch__bykat_with_threshold(InputIterator first, InputIterator last, 
                              OutputIterator  result,
                              CGAL_Point_2<R>* )
{
  return CGAL_ch_bykat_with_threshold(first, last, result, 
                                      CGAL_convex_hull_traits_2<R>() );
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator
CGAL_ch_bykat_with_threshold(InputIterator first, InputIterator last, 
                             OutputIterator  result)
{
  return CGAL_ch__bykat_with_threshold( first, last, result, 
                                        value_type(first) );
}
/*{\Mfuncl 
same as |CGAL_convex_hull_points_2(first,last,result)|.
}*/
#endif // CGAL_POINT_2_H

#ifdef CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION
#include <CGAL/ch_bykat.C>
#endif // CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION

#endif // CGAL_CH_BYKAT_H
