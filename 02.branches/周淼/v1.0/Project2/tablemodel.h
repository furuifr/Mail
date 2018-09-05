#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableModel(int rowCount=100,int pageSize=10,bool allChecked=false,QObject *parent = nullptr);

    QList<int> m_dataList;
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    signals:
    void mailInfoIsChecked(const int i);




private:
    QHash<int,int>m_pageHash;

    int m_pageSize;
    int m_rowCount;
    QStringList  header;
    int indexOfROw(int row)const;
    void fetchData(int page);
    void populateModel();
    int colNumberWithCheckBox;
     QMap<int,Qt::CheckState> rowCheckStateMap;
     bool allSelected;
};

#endif // TABLEMODEL_H
