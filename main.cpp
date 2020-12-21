#include "headerfile.h"
#include "widget.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QApplication a(argc, argv);

    if(!CreatConnection()){
        return 1;
    }

    widget w;
    w.show();
    return a.exec();
}
