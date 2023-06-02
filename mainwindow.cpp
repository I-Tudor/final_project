
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUI();
}

MainWindow::~MainWindow()
{
    delete m_leftVLayout;
    delete m_centralWidget;
}

void MainWindow::setupUI()
{
    m_centralWidget = new QWidget();
    m_mainLayout = new QHBoxLayout();
    m_leftVLayout = new QVBoxLayout();
    m_leftButtons = new QGridLayout();

    m_listSongsLabel = new QLabel("All songs:");
    m_listSongs = new QTableWidget();
    m_leftFormLayout = new QFormLayout();

    m_titleLable = new QLabel("Title:");
    m_titleText = new QLineEdit();

    m_artistLable = new QLabel("Artist:");
    m_artistText = new QLineEdit();

    m_durationLable = new QLabel("Duration:");
    m_durationText = new QLineEdit();

    m_linkLable = new QLabel("Link:");
    m_linkText = new QLineEdit();

    m_leftFormLayout->addRow(m_titleLable, m_titleText);
    m_leftFormLayout->addRow(m_artistLable, m_artistText);
    m_leftFormLayout->addRow(m_durationLable, m_durationText);
    m_leftFormLayout->addRow(m_linkLable, m_linkText);

    m_addButton = new QPushButton("Add");
    m_deleteButton = new QPushButton("Delete");
    m_updateButton = new QPushButton("Update");
    m_filterButton = new QPushButton("Filter");

    m_leftButtons->addWidget(m_addButton, 0, 0);
    m_leftButtons->addWidget(m_deleteButton, 0, 1);
    m_leftButtons->addWidget(m_updateButton, 0, 2);
    m_leftButtons->addWidget(m_filterButton, 1, 1);

    m_leftVLayout->addWidget(m_listSongsLabel);
    m_leftVLayout->addWidget(m_listSongs);
    m_leftVLayout->addLayout(m_leftFormLayout);
    m_leftVLayout->addLayout(m_leftButtons);

    m_centerButton = new QPushButton(">");

    m_rightVLayout = new QVBoxLayout();

    m_playlistLabel = new QLabel("Playlist");
    m_playlist = new QTableWidget();

    m_rightButtons = new QHBoxLayout();
    m_playButton = new QPushButton("Play");
    m_nextButton = new QPushButton("Next");

    m_rightButtons->addWidget(m_playButton);
    m_rightButtons->addWidget(m_nextButton);

    m_rightVLayout->addWidget(m_playlistLabel);
    m_rightVLayout->addWidget(m_playlist);
    m_rightVLayout->addLayout(m_rightButtons);

    m_mainLayout->addLayout(m_leftVLayout);
    m_mainLayout->addWidget(m_centerButton);
    m_mainLayout->addLayout(m_rightVLayout);

    m_centralWidget->setLayout(m_mainLayout);
    this->setCentralWidget(m_centralWidget);
    connectUI();
}

void MainWindow::connectUI() {
    QObject::connect(m_addButton, &QPushButton::released, this, &MainWindow::onButtonAdd);
    QObject::connect(m_deleteButton, &QPushButton::released, this, &MainWindow::onButtonDelete);
    QObject::connect(m_updateButton, &QPushButton::released, this, &MainWindow::onButtonUpdate);
    QObject::connect(m_filterButton, &QPushButton::released, this, &MainWindow::onButtonFilter);
    QObject::connect(m_centerButton, &QPushButton::released, this, &MainWindow::onButtonArrow);
}

void MainWindow::onButtonAdd() {
    std::string title = m_titleText->text().toStdString();
    std::string artist = m_artistText->text().toStdString();
    std::string duration = m_durationText->text().toStdString();
    std::string link = m_linkText->text().toStdString();

    Song song = Song(artist, title, duration, link);
    allSongsList.addSong(song);

    updateAllSongs();
}

void MainWindow::updateAllSongs() {

    m_listSongs->setRowCount(allSongsList.getSongs().size());
    m_listSongs->setColumnCount(4);

    for(int i=0; i< m_listSongs->rowCount(); i++)
    {
        QTableWidgetItem *pCell0 = m_listSongs->item(i, 0);
        if(!pCell0)
        {
            pCell0 = new QTableWidgetItem;
            m_listSongs->setItem(i, 0, pCell0);
        }
        pCell0->setText(QString::fromStdString(allSongsList.getSong(i).getTitle()));

        QTableWidgetItem *pCell1 = m_listSongs->item(i, 1);
        if(!pCell1)
        {
            pCell1 = new QTableWidgetItem;
            m_listSongs->setItem(i, 1, pCell1);
        }
        pCell1->setText(QString::fromStdString(allSongsList.getSong(i).getArtist()));

        QTableWidgetItem *pCell2 = m_listSongs->item(i, 2);
        if(!pCell2)
        {
            pCell2 = new QTableWidgetItem;
            m_listSongs->setItem(i, 2, pCell2);
        }
        pCell2->setText(QString::fromStdString(allSongsList.getSong(i).getDuration()));

        QTableWidgetItem *pCell3 = m_listSongs->item(i, 3);
        if(!pCell3)
        {
            pCell3 = new QTableWidgetItem;
            m_listSongs->setItem(i, 3, pCell3);
        }
        pCell3->setText(QString::fromStdString(allSongsList.getSong(i).getLink()));
    }
    m_listSongs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_listSongs->resizeColumnsToContents();
    return;
}

void MainWindow::updatePlaylist() {
    m_playlist->setRowCount(playlist.getSongs().size());
    m_playlist->setColumnCount(4);

    for(int i=0; i< m_playlist->rowCount(); i++)
    {
        QTableWidgetItem *pCell0 = m_playlist->item(i, 0);
        if(!pCell0)
        {
            pCell0 = new QTableWidgetItem;
            m_playlist->setItem(i, 0, pCell0);
        }
        pCell0->setText(QString::fromStdString(playlist.getSong(i).getTitle()));

        QTableWidgetItem *pCell1 = m_playlist->item(i, 1);
        if(!pCell1)
        {
            pCell1 = new QTableWidgetItem;
            m_playlist->setItem(i, 1, pCell1);
        }
        pCell1->setText(QString::fromStdString(playlist.getSong(i).getArtist()));

        QTableWidgetItem *pCell2 = m_playlist->item(i, 2);
        if(!pCell2)
        {
            pCell2 = new QTableWidgetItem;
            m_playlist->setItem(i, 2, pCell2);
        }
        pCell2->setText(QString::fromStdString(playlist.getSong(i).getDuration()));

        QTableWidgetItem *pCell3 = m_playlist->item(i, 3);
        if(!pCell3)
        {
            pCell3 = new QTableWidgetItem;
            m_playlist->setItem(i, 3, pCell3);
        }
        pCell3->setText(QString::fromStdString(playlist.getSong(i).getLink()));
    }
    m_playlist->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_playlist->resizeColumnsToContents();
    return;
}

void MainWindow::onButtonDelete() {
    QModelIndexList selectedIndexes = m_listSongs->selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();
        allSongsList.deleteSong(row);
        updateAllSongs();
    }
}

void MainWindow::onButtonUpdate() {
    QMessageBox::information(this,"Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onButtonFilter() {
    QMessageBox::information(this,"Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onButtonArrow() {
    QModelIndexList selectedIndexes = m_listSongs->selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();
        std::string title = m_listSongs->item(row, 0)->data(Qt::DisplayRole).toString().toStdString();
        std::string artist = m_listSongs->item(row, 1)->data(Qt::DisplayRole).toString().toStdString();
        std::string duration = m_listSongs->item(row, 2)->data(Qt::DisplayRole).toString().toStdString();
        std::string link = m_listSongs->item(row, 3)->data(Qt::DisplayRole).toString().toStdString();

        Song song = Song(artist, title, duration, link);

        playlist.addSong(song);

        updatePlaylist();
    }
}

