#ifndef CONTROL_H
#define CONTROL_H
#include"model.h"
#include<QString>
#include<QTime>
#include<QDate>
#include <QDateTime>

/*
The Controller can ask the Model to update its data.
The Controller can ask the View to change its presentation,
e.g. Showing a Dialog instead of Outputing to Console.
Basically it is a component that takes input from the user and
sends commands to the View or Model.

Controller:
Intermediary between Model & View
Updates the view when the model changes
Updates the model when the user manipulates the view
Typically where the app logic lives

conversioni dai tipi QT ai tipi nostri

*/

class control
{
    private:
        model* mod;
    public:
        control(model*);

        virtual ~control();

        bool onClickCreaOrario(QString) const;
        bool onClickCreaData(QString) const;
        bool onClickCreaFuso(QString) const;
        bool onClickCreaSole(QString) const;

        //METODI VIRTUALI
        bool onClickSomma(QString) const;
        bool onClickSottrazione(QString) const;
        void onClickClear();

        //metodi solo di orario
        double onClickVelocita(double) const;
        QTime onClickOrarioForm() const;
        QTime onClickDividi(int) const;

        //metodi solo di data
        int onClickSettimana() const; //numero settimana
        int onClickGiornoAnno() const; //numero
        string onClickGiornoSett() const; //nome giorno
        string onClickStagione() const;
        QString onClickDataForm() const;
        int onClickDurata(QString) const;
        void onClickAggGiorni(int);

        //metodi solo di fuso
        int onClickFuso() const;
        double onClickLat() const;
        double onClickLon() const;
        QString onClickEmis() const;
        int onClickDifferenza(string) const;
        //getDateTime per non ripetere 4 volte solite operazioni
        QTime getTime() const;
        QDate getDate() const;
        QDateTime getDateTime() const;
        QString getFuso() const;

        QDateTime onClickOrarioAltraCitta(string) const;

        //metodi solo di sole
        QDateTime onClickSunrise() const;
        QDateTime onClickSunset() const;
        QDateTime onClickNoon() const;

};

#endif // CONTROL_H
