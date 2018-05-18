#include"model.h"
#include"view.h"
#include"control.h"
#include<QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    view v;
    model m;
    control c(&m);
    v.setControl(&c);
    v.show();
    return app.exec();

}
