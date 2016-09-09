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
// file          : include/CGAL/IO/Color.h
// package       : iostream (1.8)
// source        :
// revision      : $Revision: 1.5 $
// revision_date : $Date: 1998/07/22 12:49:21 $
// author(s)     : Andreas Fabri
//
// coordinator   : Herve Bronnimann
//
// email         : cgal@cs.uu.nl
//
// ======================================================================


// Source: Color.h
// Author: Andreas Fabri

#ifndef CGAL_COLOR_H
#define CGAL_COLOR_H

class CGAL_Color {
public:
  CGAL_Color() {}
  CGAL_Color(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue)
  {}

  int r() const {return _red;}
  int g() const {return _green;}
  int b() const {return _blue;}

  int red() const {return _red;}
  int green() const {return _green;}
  int blue() const {return _blue;}

  bool operator==(const CGAL_Color &c) const
  {
    return ( (red() == c.red()) &&
             (green() == c.green()) &&
             (blue() == c.blue()) );
  }

  bool operator!=(CGAL_Color &c) const
  {
    return !( (*this) == c);
  }

  CGAL_Color& operator=(const CGAL_Color &c)
  {
    _red = c.red();
    _green = c.green();
    _blue = c.blue();
    return *this;
  }

private:
  int _red;
  int _green;
  int _blue;
};


const CGAL_Color CGAL_BLACK  = CGAL_Color(0, 0, 0);
const CGAL_Color CGAL_WHITE  = CGAL_Color(255, 255, 255);
const CGAL_Color CGAL_RED    = CGAL_Color(255, 0, 0);
const CGAL_Color CGAL_GREEN  = CGAL_Color(0, 255, 0);
const CGAL_Color CGAL_BLUE   = CGAL_Color(0, 0, 255);
const CGAL_Color CGAL_VIOLET = CGAL_Color(255, 0, 255);
const CGAL_Color CGAL_ORANGE = CGAL_Color(255, 170, 0);


#endif  // CGAL_COLOR_H