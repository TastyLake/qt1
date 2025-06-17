#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QProgressBar>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
  
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    QGroupBox* groupBox = new QGroupBox("Select Option");
    QVBoxLayout* groupBoxLayout = new QVBoxLayout(groupBox);
    radioButton1 = new QRadioButton();
    radioButton2 = new QRadioButton();
    groupBoxLayout->addWidget(radioButton1);
    groupBoxLayout->addWidget(radioButton2);

    comboBox = new QComboBox();
    button = new QPushButton();
    progressBar = new QProgressBar();

   

    
    radioButton1->setText("Option A");
    radioButton2->setText("Option B");

    // Выпадающий список
    comboBox->addItem("Item 1");
    comboBox->addItem("Item 2");
    comboBox->addItem("Item 3");
    comboBox->addItem("Item 4");
    comboBox->addItem("Item 5");
    comboBox->addItem("Item 6");
    comboBox->addItem("Item 7");
    comboBox->addItem("Item 8");
    comboBox->addItem("Item 9");
    comboBox->addItem("Item 10");


 
    button->setText("Increment Progress");
    button->setCheckable(true); 

   
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);  


    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(comboBox);
    mainLayout->addWidget(button);
    mainLayout->addWidget(progressBar);

    centralWidget->setLayout(mainLayout); 
    setCentralWidget(centralWidget);       

  
    connect(button, &QPushButton::clicked, this, &MainWindow::updateProgressBar);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateProgressBar()
{
    int currentValue = progressBar->value();
    int newValue = currentValue + 10;

    if (newValue > 100) {
        newValue = 0;
    }

    progressBar->setValue(newValue);

    qDebug() << "Progress bar value: " << newValue;
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
