//C-  -*- C++ -*-
//C- -------------------------------------------------------------------
//C- DjView4
//C- Copyright (c) 2006  Leon Bottou
//C-
//C- This software is subject to, and may be distributed under, the
//C- GNU General Public License. The license should have
//C- accompanied the software or you may obtain a copy of the license
//C- from the Free Software Foundation at http://www.fsf.org .
//C-
//C- This program is distributed in the hope that it will be useful,
//C- but WITHOUT ANY WARRANTY; without even the implied warranty of
//C- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//C- GNU General Public License for more details.
//C-  ------------------------------------------------------------------

// $Id$

#ifndef QDJVIEWSIDEBAR_H
#define QDJVIEWSIDEBAR_H

#include <Qt>
#include <QObject>
#include <QModelIndex>
#include <QString>
#include <QUrl>
#include <QWidget>

#include <libdjvu/miniexp.h>
#include <libdjvu/ddjvuapi.h>

#include "qdjvu.h"
#include "qdjvuwidget.h"
#include "qdjview.h"

class QAction;
class QContextMenuEvent;
class QItemSelectionModel;
class QListView;
class QMenu;
class QTreeWidget;
class QTreeWidgetItem;

// ----------------------------------------
// OUTLINE


class QDjViewOutline : public QWidget
{
  Q_OBJECT
public:
  QDjViewOutline(QDjView *djview);
public slots:
  void clear(); 
  void refresh(); 
  void pageChanged(int pageno);
protected slots:
  void itemActivated(QTreeWidgetItem *item);
private:
  QDjView *djview;
  QTreeWidget *tree;
  bool loaded;
  void fillItems(QTreeWidgetItem *item, miniexp_t expr);
  void searchItem(QTreeWidgetItem *item, int pageno, 
                  QTreeWidgetItem *&fi, int &fp);
};



// ----------------------------------------
// THUMBNAILS


class QDjViewThumbnails : public QWidget
{
  Q_OBJECT
  Q_PROPERTY(int size READ size WRITE setSize)
  Q_PROPERTY(bool smart READ smart WRITE setSmart)
public:
  QDjViewThumbnails(QDjView *djview);
  int size();
  bool smart();
public slots:
  void pageChanged(int pageno);
  void setSize(int);
  void setSmart(bool);
protected slots:
  void setSize();
  void activated(const QModelIndex &index);
protected:
  void contextMenuEvent(QContextMenuEvent *event);
  void updateActions();
private:
  class View;
  class Model;
  QDjView             *djview;
  Model               *model;
  View                *view;
  QItemSelectionModel *selection;
  QMenu               *menu;
};




#endif
/* -------------------------------------------------------------
   Local Variables:
   c++-font-lock-extra-types: ( "\\sw+_t" "[A-Z]\\sw*[a-z]\\sw*" )
   End:
   ------------------------------------------------------------- */