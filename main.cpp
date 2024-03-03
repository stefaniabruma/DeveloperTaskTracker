#include "OOPModelPractic3.h"
#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repository repo{ "tasks.txt" };
    Service serv{ repo };
    UserInterface ui{ serv };

    ui.show();

    return a.exec();
}
