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
    void loadFeature();//����������
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
    std::map<std::string,int>IDFDicOnCHI; //ֻ��ȡ�ֵ���IDF(������Ƕ�ֵ)���ֵ�
    std::map<std::string,int>IDFDicOnECE;
    std::set<std::string> featureDicOnCHI;//CHIѡ����������ʴʴʵ�,û�������ʵ�Ȩֵ��������myFeatureDic
    std::set<std::string> featureDicOnECE;//ECEѡ����������ʴʵ�

private:
    Ui::MainWindow *ui;
    ResultDialog *resultdialog;

};

#endif // MAINWINDOW_H
