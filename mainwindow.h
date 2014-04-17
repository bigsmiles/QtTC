#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <vector>
#include <iostream>
#include <set>

#include "resultdialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadVSM();
    void loadDic();
    void loadFeature();//两个都加载
    void loadBayes();
    void textBagOfWords(std::set<std::string> &featureDic,std::map<std::string,int> &text,int &textSize);
    void textKNN(double(&trainVSM)[3903][1000],std::map<std::string,int> &IDFDic,std::set<std::string> &featureDic);
    void textNaiveBayes(double(&bayes)[8][1000],std::set<std::string>& featureDic);

public slots:
    //void onFileBrowseButton();
    void textClassify();
signals:
    void textClassifyCompleted(QString textClassify);

public:
    QString fileName;
    double vsm[1000];
    //double vsmOnCHI [3903][1000];
    //double vsmOnECE [3903][1000];
    std::map<std::string,int>IDFDicOnCHI; //只提取字典中IDF(即最后那对值)的字典
    std::map<std::string,int>IDFDicOnECE;
    std::set<std::string> featureDicOnCHI;//CHI选择出的特征词词词典,没有特征词的权值，区别于myFeatureDic
    std::set<std::string> featureDicOnECE;//ECE选择出的特征词词典

private:
    Ui::MainWindow *ui;
    ResultDialog *resultdialog;

};

#endif // MAINWINDOW_H
