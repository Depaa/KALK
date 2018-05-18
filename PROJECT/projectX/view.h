#ifndef VIEW_H
#define VIEW_H
#include <QWidget>
#include <QString>
#include "control.h"

class QPushButton;
class QGridLayout;
class QLabel;
class QDialog;

class view : public QWidget
{
    Q_OBJECT

    public:
        view(QWidget* parent=0);

        virtual ~view();

        void setControl(control*);

    public slots:
        void clickCreaOrario();
        void clickCreaData();
        void clickCreaFuso();
        void clickCreaSole();

        //METODI VIRTUALI
        void clickSomma();
        void clickSottrazione();
        void clickClear();

        //metodi solo di orario
        void clickVelocita();
        void clickOrarioForm();
        void clickDividi();

        //metodi solo di data
        void clickSettimana(); //numero settimana
        void clickGiornoAnno(); //numero
        void clickGiornoSett(); //nome giorno
        void clickStagione();
        void clickDataForm();
        void clickDurata();
        void clickAggGiorni();
        void clickTogliGiorni();

        //metodi solo di fuso
        void clickFuso();
        void clickLat();
        void clickLon();
        void clickEmis();
        void clickDifferenza();
        void clickOrarioAltraCitta();

        //metodi solo di sole
        void clickSunrise();
        void clickSunset();
        void clickNoon();

    private:
        control* controller;
        QString mostraOra;
        QString mostraFuso;
        QString mostraData;
        QString mostraSole;

        QString nomeApp;
        QGridLayout* contGrid;

        QPushButton* Orario;
        QPushButton* Data;
        QPushButton* Fuso;
        QPushButton* Sole;

        QLabel* time;
        QLabel* date;
        QLabel* fuso;
        QLabel* sole;

        //METODI VIRTUALI
        QPushButton* sommaButton;
        QPushButton* sottrazioneButton;
        QPushButton* clearButton;

        //metodi solo di orario
        QPushButton* velocitaButton;
        QPushButton* orarioFormButton;
        QPushButton* dividiButton;

        //metodi solo di data
        QPushButton* settimanaButton; //numero settimana
        QPushButton* giornoAnnoButton; //numero
        QPushButton* giornoSettButton; //nome giorno
        QPushButton* stagioneButton;
        QPushButton* dataFormButton;
        QPushButton* durataButton;
        QPushButton* aggGiorniButton;
        QPushButton* togliGiorniButton;

        //metodi solo di fuso
        QPushButton* fusoButton;
        QPushButton* latButton;
        QPushButton* lonButton;
        QPushButton* emisButton;
        QPushButton* differenzaButton;
        QPushButton* orarioAltraCittaButton;

        //metodi solo di sole
        QPushButton* sunriseButton;
        QPushButton* sunsetButton;
        QPushButton* noonButton;
};

#endif // VIEW_H
