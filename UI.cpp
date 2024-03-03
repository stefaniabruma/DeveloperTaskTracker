#include "UI.h"

void UserInterface::setUp()
{
	QHBoxLayout* mainLy = new QHBoxLayout;
	setLayout(mainLy);

	lista->setModel(model);

	mainLy->addWidget(lista);

	QVBoxLayout* scndly = new QVBoxLayout;

	QFormLayout* formly = new QFormLayout;
	formly->addRow("Id:", idTxt);
	formly->addRow("Desc:", descTxt);
	formly->addRow("Programator 1:", prg1);
	formly->addRow("Programator 2:", prg2);
	formly->addRow("Programator 3:", prg3);
	formly->addRow("Programator 4:", prg4);
	formly->addRow("Stare:", stareTxt);

	scndly->addLayout(formly);
	scndly->addWidget(adaugaBtn);
	mainLy->addLayout(scndly);

	QVBoxLayout* thrdly = new QVBoxLayout;
	QFormLayout* formly2 = new QFormLayout;
	formly2->addRow("Programator:", filtruPrg);
	thrdly->addLayout(formly2);
	thrdly->addWidget(filtreazaBtn);
	mainLy->addLayout(thrdly);

	QHBoxLayout* btnly = new QHBoxLayout;
	btnly->addWidget(openBtn);
	btnly->addWidget(inpprogressBtn);
	btnly->addWidget(closedBtn);

	QVBoxLayout* mainly1 = new QVBoxLayout;
	lista_open->setModel(model_open);
	mainly1->addWidget(lista_open);
	mainly1->addLayout(btnly);
	extra_open.setLayout(mainly1);

	extra_open.show();

	QHBoxLayout* btnly2 = new QHBoxLayout;
	btnly2->addWidget(openBtn2);
	btnly2->addWidget(inpprogressBtn2);
	btnly2->addWidget(closedBtn2);


	QVBoxLayout* mainly2 = new QVBoxLayout;
	lista_inprogress->setModel(model_inprogress);
	mainly2->addWidget(lista_inprogress);
	mainly2->addLayout(btnly2);
	extra_inprogress.setLayout(mainly2);

	extra_inprogress.show();

	QHBoxLayout* btnly3 = new QHBoxLayout;
	btnly3->addWidget(openBtn3);
	btnly3->addWidget(inpprogressBtn3);
	btnly3->addWidget(closedBtn3);


	QVBoxLayout* mainly3 = new QVBoxLayout;
	lista_closed->setModel(model_closed);
	mainly3->addWidget(lista_closed);
	mainly3->addLayout(btnly3);
	extra_closed.setLayout(mainly3);

	extra_closed.show();
}

void UserInterface::connectMethods()
{
	QObject::connect(adaugaBtn, &QPushButton::clicked, [&]()
		{
			if (idTxt->text() == "")
			{
				descTxt->clear();
				prg1->clear();
				prg2->clear();
				prg3->clear();
				prg4->clear();
				stareTxt->clear();
				return;
			}
			auto id = idTxt->text().toInt();
			auto desc = descTxt->text().toStdString();
			auto p1 = prg1->text().toStdString();
			auto p2 = prg2->text().toStdString();
			auto p3 = prg3->text().toStdString();
			auto p4 = prg4->text().toStdString();
			auto stare = stareTxt->text().toStdString();

			idTxt->clear();
			descTxt->clear();
			prg1->clear();
			prg2->clear();
			prg3->clear();
			prg4->clear();
			stareTxt->clear();

			if (p1.size() == 0 && p2.size() == 0 && p3.size() == 0 && p4.size() == 0)
			{
				QMessageBox::information(nullptr, "Info", "Invalid!\n");
				return;
			}

			std::vector<std::string> prg;
			if (p1.size() > 0)
				prg.push_back(p1);

			if (p2.size() > 0)
				prg.push_back(p2);

			if (p3.size() > 0)
				prg.push_back(p3);

			if (p4.size() > 0)
				prg.push_back(p4);

			try
			{
				serv.adauga_serv(id, desc, prg, stare);
			}
			catch (std::exception e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}
			model->setTsks(serv.get_all_serv());
		});

	QObject::connect(filtreazaBtn, &QPushButton::clicked, [&]()
		{
			if (filtruPrg->text().size() == 0)
			{
				model->setTsks(serv.get_all_serv());
				return;
			}

			auto prg = filtruPrg->text().toStdString();
			filtruPrg->clear();

			auto f = serv.filtreaza_programator(prg);

			for (auto& s : f)
			{
				qDebug() << s.get_id();
			}

			model->setTsks(f);
		});

	QObject::connect(openBtn, &QPushButton::clicked, [&]()
		{
			if (lista_open->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_open->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_open->model()->index(sel_row, 0);
			auto id = lista_open->model()->data(index).toInt();

			serv.modifica_stare(id, "open");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(openBtn2, &QPushButton::clicked, [&]()
		{
			if (lista_inprogress->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_inprogress->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_inprogress->model()->index(sel_row, 0);
			auto id = lista_inprogress->model()->data(index).toInt();

			serv.modifica_stare(id, "open");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(openBtn3, &QPushButton::clicked, [&]()
		{
			if (lista_closed->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_closed->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_closed->model()->index(sel_row, 0);
			auto id = lista_closed->model()->data(index).toInt();

			serv.modifica_stare(id, "open");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});


	QObject::connect(inpprogressBtn, &QPushButton::clicked, [&]()
		{
			if (lista_open->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_open->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_open->model()->index(sel_row, 0);
			auto id = lista_open->model()->data(index).toInt();

			serv.modifica_stare(id, "inprogress");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(inpprogressBtn2, &QPushButton::clicked, [&]()
		{
			if (lista_inprogress->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_inprogress->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_inprogress->model()->index(sel_row, 0);
			auto id = lista_inprogress->model()->data(index).toInt();

			serv.modifica_stare(id, "inprogress");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(inpprogressBtn3, &QPushButton::clicked, [&]()
		{
			if (lista_closed->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_closed->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_closed->model()->index(sel_row, 0);
			auto id = lista_closed->model()->data(index).toInt();

			serv.modifica_stare(id, "inprogress");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});


	QObject::connect(closedBtn, &QPushButton::clicked, [&]()
		{
			if (lista_open->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_open->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_open->model()->index(sel_row, 0);
			auto id = lista_open->model()->data(index).toInt();

			serv.modifica_stare(id, "closed");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(closedBtn2, &QPushButton::clicked, [&]()
		{
			if (lista_inprogress->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_inprogress->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_inprogress->model()->index(sel_row, 0);
			auto id = lista_inprogress->model()->data(index).toInt();

			serv.modifica_stare(id, "closed");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());

		});

	QObject::connect(closedBtn3, &QPushButton::clicked, [&]()
		{
			if (lista_closed->selectionModel()->selectedIndexes().isEmpty())
			{
				return;
			}

			auto sel_row = lista_closed->selectionModel()->selectedIndexes().at(0).row();

			auto index = lista_closed->model()->index(sel_row, 0);
			auto id = lista_closed->model()->data(index).toInt();

			serv.modifica_stare(id, "closed");

			model_open->setTsks(serv.filtreaza_stare("open"));
			model_inprogress->setTsks(serv.filtreaza_stare("inprogress"));
			model_closed->setTsks(serv.filtreaza_stare("closed"));
			model->setTsks(serv.get_all_serv());
		});

}
