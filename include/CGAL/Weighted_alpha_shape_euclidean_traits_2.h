// Copyright (c) 1997  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Source: /CVSROOT/CGAL/Packages/Alpha_shapes_2/include/CGAL/Weighted_alpha_shape_euclidean_traits_2.h,v $
// $Revision: 1.16 $ $Date: 2003/10/01 19:27:16 $
// $Name: CGAL_3_0_1  $
//
// Author(s)     : Tran Kai Frank DA <Frank.Da@sophia.inria.fr>
//                 Andreas Fabri <Andreas.Fabri@geometryfactory.com>

#ifndef CGAL_WEIGHTED_ALPHA_SHAPE_EUCLIDEAN_TRAITS_H
#define CGAL_WEIGHTED_ALPHA_SHAPE_EUCLIDEAN_TRAITS_H

#include <CGAL/basic.h>

#include <CGAL/squared_distance_2.h>

#include <CGAL/predicates/in_smallest_orthogonalcircle_ftC2.h>
#include <CGAL/constructions/squared_radius_smallest_orthogonalcircle_ftC2.h>

#include <CGAL/Regular_triangulation_euclidean_traits_2.h>

//-------------------------------------------------------------------
CGAL_BEGIN_NAMESPACE
//-------------------------------------------------------------------

//------------------ Function Objects----------------------------------

template < class return_type, class K >
class Compute_squared_radius_orthogonalcircleC2
{
public:
  typedef return_type result_type;
  typedef Arity_tag< 3 >   Arity;
  typedef typename K::Point T;

  result_type operator()(const T& p, const T& q, const T& r)
  {
    typedef typename  K::FT FT;
    FT px(p.point().x());
    FT py(p.point().y());
    FT pw(p.weight());
    FT qx(q.point().x());
    FT qy(q.point().y());
    FT qw(q.weight());
    FT rx(r.point().x());
    FT ry(r.point().y());
    FT rw(r.weight()); 
    
    result_type res = squared_radius_orthogonalcircleC2(px, py, pw,
							qx, qy, qw,
							rx, ry, rw);
      
    return max(return_type(0), res);
  }

  result_type operator()(const T& p, const T& q)
    {
      typedef typename  K::FT FT;
      FT px(p.point().x());
      FT py(p.point().y());
      FT pw(p.weight());
      FT qx(q.point().x());
      FT qy(q.point().y());
      FT qw(q.weight());
  
      result_type res =  squared_radius_smallest_orthogonalcircleC2(px, py, pw,
								    qx, qy, qw);
      return max(return_type(0), res);
    }
};

//-------------------------------------------------------------------

template < class K >
class Side_of_bounded_orthogonalcircleC2
{
public:
  typedef Bounded_side result_type;
  typedef Arity_tag< 3 >   Arity;
  typedef typename K::Point Point;
  result_type operator()(const Point& p, const Point& q, const Point& t)
  {  
    typedef typename K::FT FT;
    FT px(p.point().x());
    FT py(p.point().y());
    FT pw(p.weight());
    FT qx(q.point().x());
    FT qy(q.point().y());
    FT qw(q.weight());
    FT tx(t.point().x());
    FT ty(t.point().y());
    FT tw(t.weight());
    
    return in_smallest_orthogonalcircleC2(px, py, pw,
					  qx, qy, qw,
					  tx, ty, tw);
  }
};

//------------------ Traits class -------------------------------------

template< class R >
class Weighted_alpha_shape_euclidean_traits_2 : public
Regular_triangulation_euclidean_traits_2<R, typename R::FT> 
{

public: 
  
  typedef Weighted_alpha_shape_euclidean_traits_2<R> Self;
  typedef typename R::FT FT;
  typedef typename 
   Regular_triangulation_euclidean_traits_2<R, typename R::FT>::Weighted_point 
     Point;

  typedef CGAL::Compute_squared_radius_orthogonalcircleC2<FT, Self>
  Compute_squared_radius_orthogonalcircle_2;
  typedef CGAL::Side_of_bounded_orthogonalcircleC2<Self>
  Side_of_bounded_orthogonalcircle_2;
  
  //------------------------------------------------------------------

  Compute_squared_radius_orthogonalcircle_2
  compute_squared_radius_2_object() const
    {
      return Compute_squared_radius_orthogonalcircle_2();
    }

  //------------------------------------------------------------------

  Side_of_bounded_orthogonalcircle_2 side_of_bounded_circle_2_object() const
    {
      return Side_of_bounded_orthogonalcircle_2();
    }
};
  
//-------------------------------------------------------------------
CGAL_END_NAMESPACE
//-------------------------------------------------------------------

#endif