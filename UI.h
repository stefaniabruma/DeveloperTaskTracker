#pragma once
#include "Service.h"
#include <qwidget.h>
#include "MyTableView.h"
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qformlayout.h>
#include <qmessagebox.h>

class UserInterface : public QWidget
{
private:
	Service& serv;

	MyTableModel* model = new MyTableModel{ serv.get_all_serv(), serv };
	QTableView* lista = new QTableView;

	QLineEdit* idTxt = new QLineEdit;
	QLineEdit* descTxt = new QLineEdit;
	QLineEdit* prg1 = new QLineEdit;
	QLineEdit* prg2 = new QLineEdit;
	QLineEdit* prg3 = new QLineEdit;
	QLineEdit* prg4 = new QLineEdit;
	QLineEdit* stareTxt = new QLineEdit;

	QPushButton* adaugaBtn = new QPushButton{ "&Adauga" };

	QLineEdit* filtruPrg = new QLineEdit;
	QPushButton* filtreazaBtn = new QPushButton{ "&Cauta task-uri" };

	QWidget extra_open;
	MyTableModel* model_open = new MyTableModel{ serv.filtreaza_stare("open"), serv };
	QTableView* lista_open = new QTableView;

	QWidget extra_inprogress;
	MyTableModel* model_inprogress = new MyTableModel{ serv.filtreaza_stare("inprogress"), serv };
	QTableView* lista_inprogress = new QTableView;

	QWidget extra_closed;
	MyTableModel* model_closed = new MyTableModel{ serv.filtreaza_stare("closed"), serv };
	QTableView* lista_closed = new QTableView;

	QPushButton* openBtn = new QPushButton{ "&Open" };
	QPushButton* inpprogressBtn = new QPushButton{ "&In progress" };
	QPushButton* closedBtn = new QPushButton{ "&Closed" };

	QPushButton* openBtn2 = new QPushButton{ "&Open" };
	QPushButton* inpprogressBtn2 = new QPushButton{ "&In progress" };
	QPushButton* closedBtn2 = new QPushButton{ "&Closed" };

	QPushButton* openBtn3 = new QPushButton{ "&Open" };
	QPushButton* inpprogressBtn3 = new QPushButton{ "&In progress" };
	QPushButton* closedBtn3 = new QPushButton{ "&Closed" };

	void setUp();
	void connectMethods();

public:

	UserInterface(Service& serv) : serv{ serv } { setUp(); connectMethods(); }

	~UserInterface() = default;
};