/*
    Copyright (C) 2013  Adam Nash

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

  */

#ifndef PLUGINLISTMODEL_H
#define PLUGINLISTMODEL_H

#include <QAbstractListModel>

/*!

\class PluginListModel pluginlistmodel.h
\brief A simple QAbstractListModel for the list of available plugins

\see ControlBlock

*/
class PluginListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PluginListModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    QMimeData *mimeData(const QModelIndexList &indexes) const;
    QStringList mimeTypes() const;
    int rowCount(const QModelIndex &parent) const;

    void addPlugin(QString name, QString absoluteFileName);

private:
    QList<QString> m_plugins;
    QHash<QString, QString> m_pluginFileNameMap;
};

#endif // PLUGINLISTMODEL_H
