
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QTableWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include "songlist.h"
#include <QtGui>
#include "song.h"

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onButtonAdd();
    void onButtonDelete();
    void onButtonUpdate();
    void onButtonFilter();
    void onButtonArrow();

private:
    void setupUI();

    songList allSongsList = songList();
    songList playlist = songList();


    QWidget* m_centralWidget;
    QHBoxLayout *m_mainLayout;
    QVBoxLayout* m_leftVLayout;
    QFormLayout* m_leftFormLayout;
    QGridLayout* m_leftButtons;

    // form layout
    QLabel* m_titleLable;
    QLineEdit* m_titleText;

    QLabel* m_artistLable;
    QLineEdit* m_artistText;

    QLabel* m_durationLable;
    QLineEdit* m_durationText;

    QLabel* m_linkLable;
    QLineEdit* m_linkText;

    QLabel* m_listSongsLabel;
    QTableWidget* m_listSongs;

    //buttons
    QPushButton *m_addButton;
    QPushButton *m_deleteButton;
    QPushButton *m_updateButton;
    QPushButton *m_filterButton;

    //center button
    QPushButton *m_centerButton;

    //playlist
    QVBoxLayout* m_rightVLayout;
    QLabel *m_playlistLabel;
    QTableWidget *m_playlist;

    QHBoxLayout* m_rightButtons;
    QPushButton* m_playButton;
    QPushButton* m_nextButton;

    void connectUI();

    void updateAllSongs();
    void updatePlaylist();
};

#endif // MAINWINDOW_H
