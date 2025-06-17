#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QRadioButton;
class QComboBox;
class QPushButton;
class QProgressBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void updateProgressBar();

private:
    QRadioButton* radioButton1;
    QRadioButton* radioButton2;
    QComboBox* comboBox;
    QPushButton* button;
    QProgressBar* progressBar;
};
#endif 
#pragma once
