/*
 *
 * Copyright (C) 2020, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: zhangjiaping <zhangjiaping@kylinos.cn>
 *
 */
#ifndef SEARCHITEM_H
#define SEARCHITEM_H

#include <QObject>
#include <QPixmap>
#include "search-item-model.h"
#include "file-utils.h"

class SearchItem : public QObject
{
    friend class SearchItemModel;
    friend class SearchListView;
    Q_OBJECT
public:
    explicit SearchItem(QObject *parent = nullptr);
    ~SearchItem();

    enum SearchType {
        Best,
        Apps,
        Settings,
        Dirs,
        Files,
        Contents
    };

    void setSearchList(const int&, const QStringList&);
    void removeItem(QString);
    int getCurrentSize();
    void clear();

private:
//    SearchItem * m_parent = nullptr;
//    QVector<SearchItem*> * m_children = nullptr;

    int m_searchtype = 0;
    QStringList m_pathlist;

    QIcon getIcon(int);
    QString getName(int);

Q_SIGNALS:

};

#endif // SEARCHITEM_H
