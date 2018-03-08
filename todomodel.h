#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractItemModel>
//#include <QModelIndex>

class todomodel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit todomodel(QObject *parent = nullptr);
    enum {
        DoneRole = Qt::UserRole,
        DescriptionRole
    };

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


private:
};

#endif // TODOMODEL_H
