#pragma once
#include "qtableview.h"
#include "Service.h"

class MyTableModel : public QAbstractTableModel
{
private:

	std::vector<Task> tasks;
	Service& serv;

public:

	MyTableModel(const std::vector<Task>& tasks, Service& serv) : tasks{ tasks }, serv { serv } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index = QModelIndex(), int role = Qt::DisplayRole) const override;

	void setTsks(const std::vector<Task>& tsk);
};