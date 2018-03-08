#include "todomodel.h"

todomodel::todomodel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex todomodel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
   // return QModelIndex();
}

QModelIndex todomodel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    //return QModelIndex();
}

int todomodel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
//    if (parent.isValid())
//        return 0;

    return 100;
}

int todomodel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    //return 1;
}

QVariant todomodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
        case DoneRole:
        return QVariant(false);
    case DescriptionRole:
        return QVariant(QStringLiteral("Test description"));
    }
    return QVariant();
}

bool todomodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags todomodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> todomodel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescriptionRole] = "description";
    return names;
}
