#include "MyTableView.h"

int MyTableModel::rowCount(const QModelIndex& parent) const 
{
	return tasks.size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		Task tsk = tasks.at(index.row());

		if (index.column() == 0)
			return QString::fromStdString(std::to_string(tsk.get_id()));

		if (index.column() == 1)
			return QString::fromStdString(tsk.get_descriere());

		if (index.column() == 2)
			return QString::fromStdString(tsk.get_stare());

		if(index.column() == 3)
			return QString::fromStdString(std::to_string(serv.nr_prgrm(tsk)));
	}

	return QVariant();
}

void MyTableModel::setTsks(const std::vector<Task>& tsk)
{
	tasks = tsk;

	auto topLeft = createIndex(0, 0);
	auto bottomRight = createIndex(rowCount(), columnCount());
	emit dataChanged(topLeft, bottomRight);
	emit layoutChanged();
}