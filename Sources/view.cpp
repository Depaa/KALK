#include <QApplication>
#include <QFont>
#include <QLabel>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include "view.h"
#include "control.h"
#include <iostream>
#include <QTime>
#include <QMessageBox>

view::view(QWidget* parent) : QWidget(parent), timerOra(), timerData(), timerFuso(), timerSole() {
    setWindowTitle("Kalk");
    contGrid = new QGridLayout();
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowCloseButtonHint);
    //setFixedSize(800,500);
    /*
    timerOra= new QTimer(this);
    timerData= new QTimer(this);
    timerFuso= new QTimer(this);
    timerSole= new QTimer(this);
*/
    Orario = new QPushButton("Inserisci\nOrario", this); //QPushButton(const QString & text, QWidget * parent = 0)
    Orario -> setFont(QFont("Arial", 10));
    Orario->setFixedSize(170,170);
    contGrid->addWidget(Orario, 0, 0); //riga, colonna

    Data = new QPushButton("Inserisci\nData", this);
    Data -> setFont(QFont("Arial", 10));
    Data->setFixedSize(170,170);
    contGrid->addWidget(Data, 1, 0);

    Fuso = new QPushButton("Inserisci\nFuso", this);
    Fuso -> setFont(QFont("Arial", 10));
    Fuso->setFixedSize(170,170);
    contGrid->addWidget(Fuso, 2, 0);

    Sole = new QPushButton("Inserisci\nSole", this);
    Sole -> setFont(QFont("Arial", 10));
    Sole->setFixedSize(170,170);
    contGrid->addWidget(Sole, 3, 0);

    clearButton=new QPushButton("RESET", this);
    clearButton -> setFont(QFont("Arial", 10));
    contGrid->addWidget(clearButton, 4, 0);

    time = new QLabel(this);
    time->setFixedSize(200,50);
    time->setStyleSheet(QString("border: 2px solid black"));
    time->setAlignment(Qt::AlignCenter);
    time->setFont(QFont( "Arial", 10, QFont::Bold));
    time->hide();
    contGrid->addWidget(time, 0, 2);

    date = new QLabel(this);
    date->setFixedSize(200,50);
    date->setStyleSheet(QString("border: 2px solid black"));
    date->setAlignment(Qt::AlignCenter);
    date->setFont(QFont( "Arial", 10, QFont::Bold));
    date->hide();
    contGrid->addWidget(date, 1, 2);

    fuso = new QLabel(this);
    fuso->setFixedSize(200,50);
    fuso->setStyleSheet(QString("border: 2px solid black"));
    fuso->setAlignment(Qt::AlignCenter);
    fuso->setFont(QFont( "Arial", 10, QFont::Bold));
    fuso->hide();
    contGrid->addWidget(fuso, 2, 2);

    sole = new QLabel(this);
    sole->setFixedSize(200,50);
    sole->setStyleSheet(QString("border: 2px solid black"));
    sole->setAlignment(Qt::AlignCenter);
    sole->setFont(QFont( "Arial", 10, QFont::Bold));

    sole->hide();
    contGrid->addWidget(sole, 3, 2);

    QGridLayout* gOrario=new QGridLayout();
    sommaButton= new QPushButton("+", this);
    sommaButton->setFont(QFont("Arial", 10));
    sommaButton->setFixedSize(60,60);
    gOrario->addWidget(sommaButton, 0, 0);

    sottrazioneButton= new QPushButton("-", this);
    sottrazioneButton->setFont(QFont("Arial", 10));
    sottrazioneButton->setFixedSize(60,60);
    gOrario->addWidget(sottrazioneButton, 1, 0);

    //metodi solo di orario
    velocitaButton = new QPushButton("Velocita", this) ;
    velocitaButton->setFont(QFont("Arial", 10));
    velocitaButton->setFixedSize(60,60);
    gOrario->addWidget(velocitaButton, 0, 1);

    orarioFormButton = new QPushButton("Form", this) ;
    orarioFormButton->setFont(QFont("Arial", 10));
    orarioFormButton->setFixedSize(60,60);
    gOrario->addWidget(orarioFormButton, 1, 1);

    dividiButton = new QPushButton("/", this) ;
    dividiButton->setFont(QFont("Arial", 10));
    dividiButton->setFixedSize(60,60);
    //gOrario->setRowMinimumHeight(2, 140);
    gOrario->addWidget(dividiButton, 0, 2, Qt::AlignCenter);

    //metodi solo di data
    QGridLayout* gData=new QGridLayout();
    settimanaButton = new QPushButton("N.\nSett", this) ; //numero settimana
    settimanaButton->setFont(QFont("Arial", 10));
    settimanaButton->setFixedSize(60,60);
    gData->addWidget(settimanaButton, 0, 0);

    giornoAnnoButton = new QPushButton("N.\nGiorno", this) ; //numero
    giornoAnnoButton->setFont(QFont("Arial", 10));
    giornoAnnoButton->setFixedSize(60,60);
    gData->addWidget(giornoAnnoButton, 1, 0);

    giornoSettButton = new QPushButton("Giorno", this) ; //nome giorno.
    giornoSettButton->setFont(QFont("Arial", 10));
    giornoSettButton->setFixedSize(60,60);
    gData->addWidget(giornoSettButton, 0, 1);

    stagioneButton = new QPushButton("Stag.", this) ;
    stagioneButton->setFont(QFont("Arial", 10));
    stagioneButton->setFixedSize(60,60);
    gData->addWidget(stagioneButton, 1, 1);

    dataFormButton = new QPushButton("Form", this) ;
    dataFormButton->setFont(QFont("Arial", 10));
    dataFormButton->setFixedSize(60,60);
    gData->addWidget(dataFormButton, 0, 2);

    durataButton = new QPushButton("Durata", this) ;
    durataButton->setFont(QFont("Arial", 7));
    durataButton->setFixedSize(60,60);
    gData->addWidget(durataButton, 1, 2);

    //metodi solo di fuso
    QGridLayout* gFuso=new QGridLayout();
    fusoButton = new QPushButton("Fuso", this) ;
    fusoButton->setFont(QFont("Arial", 10));
    fusoButton->setFixedSize(60,60);
    gFuso->addWidget(fusoButton, 0, 0);

    latButton = new QPushButton("Lat", this) ;
    latButton->setFont(QFont("Arial", 10));
    latButton->setFixedSize(60,60);
    gFuso->addWidget(latButton, 1, 0);

    lonButton = new QPushButton("Lon", this) ;
    lonButton->setFont(QFont("Arial", 10));
    lonButton->setFixedSize(60,60);
    gFuso->addWidget(lonButton, 0, 1);

    emisButton = new QPushButton("Emis", this) ;
    emisButton->setFont(QFont("Arial", 10));
    emisButton->setFixedSize(60,60);
    gFuso->addWidget(emisButton, 1, 1);

    differenzaButton = new QPushButton("-", this) ;
    differenzaButton->setFont(QFont("Arial",10));
    differenzaButton->setFixedSize(60,60);
    gFuso->addWidget(differenzaButton, 0, 2);

    orarioAltraCittaButton = new QPushButton("Citta", this) ;
    orarioAltraCittaButton->setFont(QFont("Arial", 10));
    orarioAltraCittaButton->setFixedSize(60,60);
    gFuso->addWidget(orarioAltraCittaButton, 1, 2);

    //metodi solo di sole
    QGridLayout* gSole=new QGridLayout();
    sunriseButton = new QPushButton("Rise", this) ;
    sunriseButton->setFont(QFont("Arial", 10));
    sunriseButton->setFixedSize(60,60);
    gSole->addWidget(sunriseButton, 0, 0);

    sunsetButton = new QPushButton("Set", this) ;
    sunsetButton->setFont(QFont("Arial", 10));
    sunsetButton->setFixedSize(60,60);
    gSole->addWidget(sunsetButton, 0, 1);

    noonButton = new QPushButton("Noon", this) ;
    noonButton->setFont(QFont("Arial", 10));
    noonButton->setFixedSize(60,60);
    gSole->addWidget(noonButton, 0, 2);

    //okOra= new QAbstractState;

    //connessioni
    /*
    connect(okOra, SIGNAL(okOra), this, SLOT(clickMostraOrario()));
    connect(date, SIGNAL(show()), this, SLOT(clickMostraData()));
    connect(fuso, SIGNAL(show()), this, SLOT(clickMostraFuso()));
    connect(sole, SIGNAL(show()), this, SLOT(clickMostraSole()));
    */

    connect(Orario, SIGNAL(clicked(bool)), this, SLOT(clickCreaOrario()));
    connect(Data, SIGNAL(clicked(bool)), this, SLOT(clickCreaData()));
    connect(Fuso, SIGNAL(clicked(bool)), this, SLOT(clickCreaFuso()));
    connect(Sole, SIGNAL(clicked(bool)), this, SLOT(clickCreaSole()));

    connect(sommaButton, SIGNAL(clicked(bool)), this, SLOT(clickSomma()));
    connect(sottrazioneButton, SIGNAL(clicked(bool)), this, SLOT(clickSottrazione()));
    connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(clickClear()));

    connect(velocitaButton, SIGNAL(clicked(bool)), this, SLOT(clickVelocita()));
    connect(orarioFormButton, SIGNAL(clicked(bool)), this, SLOT(clickOrarioForm()));
    connect(dividiButton, SIGNAL(clicked(bool)), this, SLOT(clickDividi()));

    connect(settimanaButton, SIGNAL(clicked(bool)), this, SLOT(clickSettimana()));
    connect(giornoAnnoButton, SIGNAL(clicked(bool)), this, SLOT(clickGiornoAnno()));
    connect(giornoSettButton, SIGNAL(clicked(bool)), this, SLOT(clickGiornoSett()));
    connect(stagioneButton, SIGNAL(clicked(bool)), this, SLOT(clickStagione()));
    connect(dataFormButton, SIGNAL(clicked(bool)), this, SLOT(clickDataForm()));
    connect(durataButton, SIGNAL(clicked(bool)), this, SLOT(clickDurata()));

    connect(fusoButton, SIGNAL(clicked(bool)), this, SLOT(clickFuso()));
    connect(latButton, SIGNAL(clicked(bool)), this, SLOT(clickLat()));
    connect(lonButton, SIGNAL(clicked(bool)), this, SLOT(clickLon()));
    connect(emisButton, SIGNAL(clicked(bool)), this, SLOT(clickEmis()));
    connect(differenzaButton, SIGNAL(clicked(bool)), this, SLOT(clickDifferenza()));
    connect(orarioAltraCittaButton, SIGNAL(clicked(bool)), this, SLOT(clickOrarioAltraCitta()));

    connect(sunriseButton, SIGNAL(clicked(bool)), this, SLOT(clickSunrise()));
    connect(sunsetButton, SIGNAL(clicked(bool)), this, SLOT(clickSunset()));
    connect(noonButton, SIGNAL(clicked(bool)), this, SLOT(clickNoon()));


    contGrid->setRowMinimumHeight(0, 200);
    contGrid->setRowMinimumHeight(1, 230);
    contGrid->setRowMinimumHeight(2, 230);

    contGrid->setColumnMinimumWidth(0,200);
    contGrid->setColumnMinimumWidth(1,200);
    contGrid->setColumnMinimumWidth(2,200);

    contGrid->addLayout(gOrario, 0,1,Qt::AlignCenter);
    contGrid->addLayout(gData, 1,1,Qt::AlignCenter);
    contGrid->addLayout(gFuso, 2,1,Qt::AlignCenter);
    contGrid->addLayout(gSole, 3,1,Qt::AlignCenter);
    setLayout(contGrid);
}

view::~view() {}

void view::setControl(control* c) {
    controller=c;
}

void view::clickCreaOrario() {
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Orario"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Ore: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Minuti: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Secondi: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        s= s+line1->text() + ":" + line2->text() + ":" + line3->text();
        sent= controller->onClickCreaOrario(s);
        if (sent)
        {
            mostraOra=s;
            time->setText(mostraOra);
            time->show();
        }
        else
        {
            QMessageBox m;
            m.setText("Hai sbagliato coglione");
            m.exec();
        }
    }
}

void view::clickCreaData() {
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Data"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Giorno: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Mese: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Anno: ");
    QLineEdit* line4= new QLineEdit(dialog);
    QString textline4=QString("Ore: ");
    QLineEdit* line5= new QLineEdit(dialog);
    QString textline5=QString("Minuti: ");
    QLineEdit* line6= new QLineEdit(dialog);
    QString textline6=QString("Secondi: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);
    form.addRow(textline4, line4);
    form.addRow(textline5, line5);
    form.addRow(textline6, line6);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    dialog->exec();
}


void view::clickCreaFuso(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Citta"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Nome Citta': ");
    form.addRow(textline1, line1);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    QString s;
    bool sent=true;


    if(sent && dialog->exec()==QDialog::Accepted) {
        s= s+line1->text();
        mostraFuso=s;
        fuso->show();
        fuso->setText(mostraFuso);

    }
}

void view::clickCreaSole(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Sole"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Latitudine: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Longitudine: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Fuso Orario: ");
    QLineEdit* line4= new QLineEdit(dialog);
    QString textline4=QString("Giorno : ");
    QLineEdit* line5= new QLineEdit(dialog);
    QString textline5=QString("Mese: ");
    QLineEdit* line6= new QLineEdit(dialog);
    QString textline6=QString("Anno: ");
    QLineEdit* line7= new QLineEdit(dialog);
    QString textline7=QString("Ora (attuali): ");
    QLineEdit* line8= new QLineEdit(dialog);
    QString textline8=QString("Minuti (attuali): ");
    QLineEdit* line9= new QLineEdit(dialog);
    QString textline9=QString("Secondi (attuali): ");
    QLineEdit* line10= new QLineEdit(dialog);
    QString textline10=QString("Ora Legale (1 o 0): ");
    QLineEdit* line11= new QLineEdit(dialog);
    QString textline11=QString("Equazione del Tempo: ");
    QLineEdit* line12= new QLineEdit(dialog);
    QString textline12=QString("Declinazione Solare: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);
    form.addRow(textline4, line4);
    form.addRow(textline5, line5);
    form.addRow(textline6, line6);
    form.addRow(textline7, line7);
    form.addRow(textline8, line8);
    form.addRow(textline9, line9);
    form.addRow(textline10, line10);
    form.addRow(textline11, line11);
    form.addRow(textline12, line12);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    QString s;
    bool sent=true;


}

/*
void view::clickMostraOrario() {
    time->setText(mostraOra);
    time->show();
    date->hide();
    fuso->hide();
    sole->hide();
}

void view::clickMostraData() {

}

void view::clickMostraFuso(){

}

void view::clickMostraSole(){

}
*/

//METODI VIRTUALI
void view::clickSomma(){

}

void view::clickSottrazione(){

}

void view::clickClear(){

}


//metodi solo di orario
void view::clickVelocita(){

}

void view::clickOrarioForm(){

}

void view::clickDividi(){

}


//metodi solo di data
void view::clickSettimana(){

}

void view::clickGiornoAnno(){

}

void view::clickGiornoSett() {

}

void view::clickStagione(){

}

void view::clickDataForm(){

}

void view::clickDurata(){

}


//metodi solo di fuso
void view::clickFuso(){

}

void view::clickLat(){

}

void view::clickLon(){

}

void view::clickEmis(){

}

void view::clickDifferenza(){

}

void view::clickOrarioAltraCitta(){

}


//metodi solo di sole
void view::clickSunrise(){

}

void view::clickSunset(){

}

void view::clickNoon(){

}
