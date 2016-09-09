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
// $Source: /CVSROOT/CGAL/Packages/Alpha_shapes_2/include/CGAL/predicates/in_smallest_orthogonalcircle_ftC2.h,v $
// $Revision: 1.7 $ $Date: 2003/09/18 10:19:13 $
// $Name: CGAL_3_0_1  $
//
// Author(s)     : Tran Kai Frank DA <Frank.Da@sophia.inria.fr>

#ifndef CGAL_IN_SMALLEST_ORTHOGONALCIRCLE_FTC2_H 
#define CGAL_IN_SMALLEST_ORTHOGONALCIRCLE_FTC2_H

#include <CGAL/determinant.h>
#include <CGAL/enum.h>

//-------------------------------------------------------------------
CGAL_BEGIN_NAMESPACE
//-------------------------------------------------------------------

template< class FT >
CGAL_MEDIUM_INLINE
Bounded_side
in_smallest_orthogonalcircleC2(const FT &px, const FT &py, const FT  &pw,
			       const FT &qx, const FT &qy, const FT  &qw,  
			       const FT &tx, const FT &ty, const FT  &tw)
{
  FT dpx = px-qx;
  FT dpy = py-qy;
  FT dtx = tx-qx;
  FT dty = ty-qy;
  FT dpz = CGAL_NTS square(dpx)+CGAL_NTS square(dpy);
 
  return Bounded_side 
    (CGAL_NTS sign(-(CGAL_NTS square(dtx)+CGAL_NTS square(dty)-tw+qw)*dpz
		   +(dpz-pw+qw)*(dpx*dtx+dpy*dty)));
}

//-------------------------------------------------------------------
CGAL_END_NAMESPACE
//-------------------------------------------------------------------

#endif //CGAL_IN_SMALLEST_ORTHOGONALCIRCLEC2_H