// Copyright (c) 2008  GeometryFactory Sarl (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL: https://github.com/CGAL/cgal/blob/v5.3.1/Hyperbolic_triangulation_2/demo/Hyperbolic_triangulation_2/include/internal/Qt/TriangulationPointInputAndConflictZone.h $
// $Id: TriangulationPointInputAndConflictZone.h 0779373 2020-03-26T13:31:46+01:00 Sébastien Loriot
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
// Author(s)     : Andreas Fabri <Andreas.Fabri@geometryfactory.com>
//

#ifndef CGAL_QT_POINT_INPUT_AND_TRIANGULATION_CONFLICT_ZONE
#define CGAL_QT_POINT_INPUT_AND_TRIANGULATION_CONFLICT_ZONE

#include <CGAL/Qt/GraphicsViewInput.h>
#include <CGAL/Qt/Converter.h>
#include <QGraphicsSceneMouseEvent>
#include <QEvent>
#include <list>



namespace CGAL {
namespace Qt {

template <typename DT>
class TriangulationPointInputAndConflictZone : public GraphicsViewInput
{
public:
  typedef typename DT::Geom_traits K;
  typedef typename DT::Face_handle Face_handle;
  typedef typename DT::Point Point;

  TriangulationPointInputAndConflictZone(QGraphicsScene* s, DT  * dt_, QObject* parent);

protected:
  void localize_and_insert_point(QPointF qt_point);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
  bool eventFilter(QObject *obj, QEvent *event);

  std::list<Face_handle> faces;
  std::list<QGraphicsPolygonItem*> qfaces;
  DT * dt;
  Converter<K> convert;
  QGraphicsScene *scene_;
  Point p;
};


template <typename T>
TriangulationPointInputAndConflictZone<T>::TriangulationPointInputAndConflictZone(QGraphicsScene* s,
                                                        T * dt_,
                                                        QObject* parent)
  :  GraphicsViewInput(parent), dt(dt_), scene_(s)
{}




template <typename T>
void
TriangulationPointInputAndConflictZone<T>::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  p = convert(event->scenePos());
  if(dt->dimension() < 2 ||
     event->modifiers() != 0 ||
     event->button() != ::Qt::LeftButton) {
    return;
  }


  dt->find_conflicts(p, std::back_inserter(faces));
  for(typename std::list<Face_handle>::iterator it = faces.begin();
      it != faces.end();
      ++it){
    if(dt->is_Delaunay_hyperbolic(*it)){
      QGraphicsPolygonItem *item = new QGraphicsPolygonItem(convert(dt->hyperbolic_triangle(*it)));
      QColor color(::Qt::blue);
      color.setAlpha(150);
      item->setBrush(color);
      scene_->addItem(item);
      qfaces.push_back(item);
    }
  }
}


template <typename T>
void
TriangulationPointInputAndConflictZone<T>::mouseReleaseEvent(QGraphicsSceneMouseEvent * /*event*/)
{
  faces.clear();
  for(std::list<QGraphicsPolygonItem*>::iterator it = qfaces.begin();
      it != qfaces.end();
      ++it){
    scene_->removeItem(*it);
    delete *it;
  }
  qfaces.clear();
  emit (generate(CGAL::make_object(p)));
}



template <typename T>
bool
TriangulationPointInputAndConflictZone<T>::eventFilter(QObject *obj, QEvent *event)
{
  if(event->type() == QEvent::GraphicsSceneMousePress) {
    QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
    mousePressEvent(mouseEvent);
    return true;
  } else if(event->type() == QEvent::GraphicsSceneMouseRelease) {
    QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
    mouseReleaseEvent(mouseEvent);
    return true;
  } else{
    // standard event processing
    return QObject::eventFilter(obj, event);
  }
}


} // namespace Qt
} // namespace CGAL

#endif // CGAL_QT_POINT_INPUT_AND_TRIANGULATION_CONFLICT_ZONE
