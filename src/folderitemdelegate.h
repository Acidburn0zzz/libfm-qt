/*
 * Copyright (C) 2012 - 2015  Hong Jen Yee (PCMan) <pcman.tw@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef FM_FOLDERITEMDELEGATE_H
#define FM_FOLDERITEMDELEGATE_H

#include "libfmqtglobals.h"
#include <QStyledItemDelegate>
class QAbstractItemView;

namespace Fm {

class LIBFM_QT_API FolderItemDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit FolderItemDelegate(QAbstractItemView* view, QObject* parent = nullptr);

    virtual ~FolderItemDelegate();

    inline void setItemSize(QSize size) {
        itemSize_ = size;
    }

    inline QSize itemSize() const {
        return itemSize_;
    }

    inline void setIconSize(QSize size) {
        iconSize_ = size;
    }

    inline QSize iconSize() const {
        return iconSize_;
    }

    int fileInfoRole() {
        return fileInfoRole_;
    }

    void setFileInfoRole(int role) {
        fileInfoRole_ = role;
    }

    int iconInfoRole() {
        return iconInfoRole_;
    }

    void setIconInfoRole(int role) {
        iconInfoRole_ = role;
    }

    // only support vertical layout (icon view mode: text below icon)
    void setShadowColor(const QColor& shadowColor) {
      shadowColor_ = shadowColor;
    }

    // only support vertical layout (icon view mode: text below icon)
    const QColor& shadowColor() const {
      return shadowColor_;
    }

    // only support vertical layout (icon view mode: text below icon)
    void setMargins(QSize margins) {
      margins_ = margins.expandedTo(QSize(0, 0));
    }

    QSize getMargins() const {
      return margins_;
    }

    bool hasEditor() const {
        return hasEditor_;
    }

    virtual QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;

    virtual bool eventFilter(QObject* object, QEvent* event);

    virtual void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    QSize iconViewTextSize(const QModelIndex& index) const;

private:
    void drawText(QPainter* painter, QStyleOptionViewItem& opt, QRectF& textRect) const;

    static QIcon::Mode iconModeFromState(QStyle::State state);

private:
    QIcon symlinkIcon_;
    QSize iconSize_;
    QSize itemSize_;
    int fileInfoRole_;
    int iconInfoRole_;
    QColor shadowColor_;
    QSize margins_;
    mutable bool hasEditor_;
};

}

#endif // FM_FOLDERITEMDELEGATE_H
