// Copyright (c) 1997-2002  Max-Planck-Institute Saarbruecken (Germany).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Nef_3/include/CGAL/Nef_3/Bounding_box_3.h $
// $Id: Bounding_box_3.h 43830 2008-06-27 11:27:53Z hachenb $
// 
//
// Author(s)     : Miguel Granados <granados@mpi-sb.mpg.de>

#ifndef CGAL_BOUNDING_BOX_3_H
#define CGAL_BOUNDING_BOX_3_H

#include <CGAL/basic.h>
#include <CGAL/Handle_for.h>
#include <CGAL/box_intersection_d.h>
#include <CGAL/Box_intersection_d/box_limits.h>

CGAL_BEGIN_NAMESPACE

template <typename Extended_tag, typename Kernel> class Bounding_box_3;

template <typename Extended_tag, typename Kernel>
class Bounding_box_3 : 
public Box_intersection_d::Box_d< double, 3> {

  typedef Box_intersection_d::Box_d< double, 3>  Base;
  typedef typename Kernel::Point_3               Point_3;

public:
  Bounding_box_3() : Base(false) {
    CGAL_error_msg( "code not stable");
  }

  Bounding_box_3(double q[3]) : Base(q,q) {}
    
  void extend( const Point_3& p) {
    std::pair<double, double> q[3];
    q[0] = CGAL::to_interval( p.x() );
    q[1] = CGAL::to_interval( p.y() );
    q[2] = CGAL::to_interval( p.z() );
    Base::extend(q);
  }	
};

template <typename Kernel>
class Bounding_box_3<Tag_true, Kernel> : 
public Box_intersection_d::Box_d<typename Kernel::FT, 3> {
  
  typedef typename Kernel::FT               FT;
  typedef Box_intersection_d::Box_d<FT, 3>  Base;
  typedef typename Kernel::Point_3          Point_3;

  bool initialized;

public:
  Bounding_box_3() : Base(), initialized(false) {}

  Bounding_box_3(FT q[3]) : Base(q,q), initialized(true) {}
    
  void extend(FT q[3]) {
    if(initialized)
      Base::extend(q);
    else {
      initialized = true;
      (Base) *this = Base(q,q);
    }
  }

  void extend(const Point_3& p) {
    FT q[3];
    q[0] = p.x();
    q[1] = p.y();
    q[2] = p.z();

    if(initialized)
      Base::extend(q);
    else {
      initialized = true;
      std::copy( q, q + 3, Base::lo );
      std::copy( q, q + 3, Base::hi );     
    }
  }	  
};

CGAL_END_NAMESPACE
#endif // CGAL_BOUNDING_BOX_3_H
