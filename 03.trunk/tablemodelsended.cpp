#include "tablemodelsended.h"
#define CHECK_BOX_COLUMN 0

tablemodelSended::tablemodelSended(int rowCount,int pageSize,bool allchecked,QObject *parent,QList<Mail> dataList)
    : QAbstractTableModel(parent)
{
    this->m_pageSize=pageSize;
    this->m_rowCount=dataList.count();
    this->allSelected=allchecked;
    this->m_dataList=dataList;

    populateModel();
}


QVariant tablemodelSended::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
        return header[section];
    return QAbstractTableModel::headerData(section,orientation,role);
}

int tablemodelSended::rowCount(const QModelIndex &parent) const
{
    return m_rowCount;
}

int tablemodelSended::columnCount(const QModelIndex &parent) const
{
    return 4;

    // FIXME: Implement me!
}

QVariant tablemodelSended::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(Qt::DisplayRole==role&&index.column()!=CHECK_BOX_COLUMN){
        int i=indexOfROw(index.row());
        auto v = dataList.at(i);

        switch(index.column())
        {
            case 1:
                return v.getSenderName();
                break;
            case 2:

                return v.getTime();
               break;
            case 3:
                return v.getTheme();
                break;
            defualt:
                return QVariant();
        }

    }
    if(role==Qt::CheckStateRole){
        if(index.column()==CHECK_BOX_COLUMN){
            if(rowCheckStateMap.contains(index.row()))
                return rowCheckStateMap[index.row()]==Qt::Checked?Qt::Checked:Qt::Unchecked;
            return Qt::Unchecked;//有问题
        }
    }

    // FIXME: Implement me!
    return QVariant();
}
Qt::ItemFlags tablemodelSended::flags(const QModelIndex &index) const{
    if(!index.isValid())
        return QAbstractItemModel::flags(index);

    Qt::ItemFlags flags=Qt::ItemIsEnabled|Qt::ItemIsSelectable;
    if(index.column()==CHECK_BOX_COLUMN)
        flags|=Qt::ItemIsUserCheckable;
     return  flags;
}
bool tablemodelSended::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid())
        return false;
    if(role==Qt::CheckStateRole&&index.column()==CHECK_BOX_COLUMN){
        /*if(allSelected){
            rowCheckStateMap[index.row()]=Qt::Checked;//全选后设置每一项被check
            return true;
        }*/
        if(value==Qt::Checked){
            rowCheckStateMap[index.row()]=Qt::Checked;
            if(dataList.size()>index.row())
                emit dataChanged(index,index);//如果该复选框被选中执行的操作
        }else{
            rowCheckStateMap[index.row()]=Qt::Unchecked;
            if(dataList.size()>index.row())
                emit dataChanged(index,index);
        }
    }
    return true;
}
int tablemodelSended::indexOfROw(int row) const{
    int page=row/m_pageSize;
    if(!m_pageHash.contains(page)){
        (const_cast<tablemodelSended*>(this))->fetchData(page);
    }
    return m_pageHash.value(page)+row%m_pageSize;
}
void tablemodelSended::fetchData(int page){
    int pageStartIndex=dataList.count();
    m_pageHash.insert(page,pageStartIndex);

    for(int i=0;i<m_pageSize;++i){
        int data=page*m_pageSize+i;
        int sum=m_dataList.count();
        if(data>=sum){
            break;
        }else{
            dataList.append(m_dataList.at(data));//dataList保存已加载的数据
        }
    }
}

void tablemodelSended::populateModel(){
    header<<tr("选择")<<tr("收件人")<<tr("时间")<<tr("主题");
}
