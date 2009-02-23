#ifndef QOM_SETTINGS
#define QOM_SETTINGS

#include <QDragEnterEvent>
#include <QMessageBox>
#include <QUrl>

#include "ui_settings.h"

class QSettings;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *);
    
    ~SettingsDialog()
    {
        delete settings;
        settings = NULL;
    };
    
    void dragEnterEvent(QDragEnterEvent *evt)
    {
        if(evt->mimeData()->hasUrls())
        {
            evt->acceptProposedAction();
        }
    };
    
    void dropEvent(QDropEvent *);

private slots:
    void on_buttonBox_accepted();
    
    void on_customGrpButton_clicked();
    
private:
    Ui::SettingsDialog ui;
    QSettings *settings;
    
    void loadSettings();
    
signals:
    // custom signal because if the listener listens to accept()
    // it might happen that our changes aren't synced yet
    void settingsChanged();
};

#endif