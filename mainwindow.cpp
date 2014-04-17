#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFileInfo>
#include <QFile.h>
#include <QProgressDialog>
#include <string>
#include <set>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "COMMON.h"
#include "ICTCLAS50.h"
std::vector<std::pair<int,double> > knn;

double vsmOnCHI [3903][1000];
double vsmOnECE [3903][1000];
double bayesOnCHI [8][1000];
double bayesOnECE [8][1000];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultdialog = new ResultDialog;

    loadFeature();
    loadDic();
    loadVSM();
    loadBayes();

    //connect(ui->FileBrowse,SIGNAL(clicked()),this,SLOT(onFileBrowseButton()));
    connect(ui->Run,SIGNAL(clicked()),this,SLOT(textClassify()));
    connect(this,SIGNAL(textClassifyCompleted(QString)),resultdialog,SLOT(showResult(QString)));

    QTextCodec *codec=QTextCodec::codecForName("System");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);

}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::loadBayes()
{
    std::ifstream bayesOnCHIFile("E:\\final\\Qtfinal\\myData\\bayesOnCHI.txt");
    std::ifstream bayesOnECEFile("E:\\final\\Qtfinal\\myData\\bayesOnECE.txt");

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 1000; j++)
            bayesOnCHIFile>>bayesOnCHI[i][j];
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 1000; j++)
            bayesOnECEFile>>bayesOnECE[i][j];
    bayesOnCHIFile.close();
    bayesOnECEFile.close();

}

void MainWindow::loadVSM()
{

    std::ifstream vsmOnCHIFile("E:\\final\\Qtfinal\\myData\\textOfTrainVSMOnCHI.txt");
    std::ifstream vsmOnECEFile("E:\\final\\Qtfinal\\myData\\textOfTrainVSMOnCross.txt");
    std::string str;
    int cnt = 0;
    int id;
    double val = 0;
    int len = 0;
    while(vsmOnCHIFile>>str)
    {
        vsmOnCHIFile>>len;
        for(int i = 0; i < len; i++)
        {
            vsmOnCHIFile>>id>>val;
            vsmOnCHI[cnt][id] = val;
        }
        cnt++;
    }
    vsmOnCHIFile.close();
    cnt = 0;
    while(vsmOnECEFile>>str)
    {
        vsmOnECEFile>>len;
        for(int i = 0; i < len; i++)
        {
            vsmOnECEFile>>id>>val;
            vsmOnECE[cnt][id] = val;
        }
        cnt++;
    }
    vsmOnECEFile.close();

}
void MainWindow::loadDic()
{
    std::ifstream dicFile("E:\\final\\Qtfinal\\myData\\myDic.txt");
    std::string  term;
    int id,cn,df;
    while(dicFile>>term)
    {

        dicFile>>id>>cn;
        for(int i = 0; i < cn; i++)
        {
            dicFile>>id>>df;
        }
        if(featureDicOnCHI.count(term))
        {
            IDFDicOnCHI[term] = df;
        }
        if(featureDicOnECE.count(term))
        {
            IDFDicOnECE[term] = df;
        }
    }
    dicFile.close();
}
void MainWindow::loadFeature()
{
     std::ifstream featureFile("E:\\final\\Qtfinal\\myData\\featureDic.txt");
     std::ifstream crossfeatureFile("E:\\final\\Qtfinal\\myData\\crossfeatureDic.txt");
     std::string words;
     double val;
     while(featureFile>>words>>val)
     {
        featureDicOnCHI.insert(words);
     }
     while(crossfeatureFile>>words>>val)
     {
        featureDicOnECE.insert(words);
     }
    featureFile.close();
    crossfeatureFile.close();
}
void MainWindow::textClassify()
{
    if(ui->CHI->isChecked() && ui->KNN->isChecked())
    {
        textKNN(vsmOnCHI,IDFDicOnCHI,featureDicOnCHI);
    }
    else if(ui->ECE->isChecked() && ui->KNN->isChecked())
    {
        textKNN(vsmOnECE,IDFDicOnECE,featureDicOnECE);
    }
    else if(ui->CHI->isChecked() && ui->Bayes->isChecked())
    {
        textNaiveBayes(bayesOnCHI,featureDicOnCHI);
    }
    else if(ui->ECE->isChecked() && ui->Bayes->isChecked())
    {
        textNaiveBayes(bayesOnECE,featureDicOnECE);
    }
    else
    {
        //错误情况，没有选完
         QMessageBox::warning(this,"Warnning","请选择完整！",QMessageBox::Yes);
    }

}
void MainWindow::textBagOfWords(std::set<std::string> &featureDic, std::map<std::string, int> &text,int &textSize)
{
    if(!ICTCLAS_Init()) //初始化分词组件。
    {
            QMessageBox::warning(this,"Warnning","Init fails",QMessageBox::Yes);
            return;
    }
    else
    {
            printf("Init ok\n");
    }
    ICTCLAS_SetPOSmap(2);

    QString myStr = ui->text->toPlainText();
    QByteArray ba = myStr.toLocal8Bit();
    char* sText;
    char* sSentence = (char*)malloc(ba.size()+10);
    sText = ba.data();

    int len = 0;
    //这样读入为了将换行符去掉，ASCII码10、13
    for(int i = 0; sText[i] != '\0'; i++)
    {
        if(sText[i] == '\n' || sText[i] == '\r')continue;
        sSentence[len++] = sText[i];
    }
    sSentence[len] = '\0';

    unsigned int nPaLen=strlen(sSentence); // 需要分词的长度
    char* sRst=0;   //用户自行分配空间，用于保存结果；
    sRst=(char*)malloc(nPaLen*6); //建议长度为字符串长度的6倍。

    int nRstLen=0; //分词结果的长度

    nRstLen = ICTCLAS_ParagraphProcess(sSentence,nPaLen,sRst,CODE_TYPE_UNKNOWN,0);  //字符串处理

    //free(sText);
    free(sSentence);

    //收集单词，形成字典
    std::string words;
    std::istringstream istream(sRst);
    std::set<std::string> txtWords;
    while(istream>>words)
    {
        txtWords.insert(words);
        if(featureDic.count(words))
        {
            text[words]++;
        }
    }
    textSize = txtWords.size();
    free(sRst);
    txtWords.clear();
    istream.clear();
    ICTCLAS_Exit();	//释放资源退出
    return;

}

void MainWindow::textNaiveBayes(double (&bayes)[8][1000],std::set<std::string>&featureDic)
{
    std::map<std::string,int> text;
    int textSize = 0;
    textBagOfWords(featureDic,text,textSize);
    int k = 0;
    //int TF = 0;
    for(std::set<std::string>::iterator setItor = featureDic.begin(); setItor != featureDic.end(); setItor++)
    {
        vsm[k++] = text[(*setItor)];
    }
    double p[8];
    int i = 0, j = 0;
    for( i = 0; i < 8; i++)p[i] = 0;
    for( i = 0; i < 1000; i++)
    {
        if(vsm[i] != 0)
        {
            for( j = 0; j < 8; j++)
                p[j] += vsm[i] * log(bayes[j][i]);
        }
     }
     double max = -999999999;
     int ans;
     for(i = 0; i < 8; i++)
     {
      //qDebug()<<p[i];
      if(max < p[i])
           {
               max = p[i];
               ans = i;
           }
      }
     QString article[8] = {"art","history","space","computer","enviornment","agriculture","ecnomy","sports"};
     qDebug()<<"类别是："<<article[ans];
     emit textClassifyCompleted(article[ans]);

}

void MainWindow::textKNN(double (&trainVSM)[3903][1000], std::map<std::string, int> &IDFDic, std::set<std::string> &featureDic)
{
    int myKNN[9];
    std::map<std::string,int> text;
    int textSize = 0;
    double TF;
    textBagOfWords(featureDic,text,textSize);


    double total = 3903;
    int k = 0;
    for(std::set<std::string>::iterator setItor = featureDic.begin(); setItor != featureDic.end(); setItor++)
    {

        TF = (1.0*text[(*setItor)]) / textSize;
        TF *= log(0.01 + total/IDFDic[(*setItor)]);
        vsm[k++] =TF;
        //qDebug()<<txt[*setItor]<<txtWords.size()<<IDFDic[(*setItor)]<<log(0.01 + total/IDFDic[(*setItor)])<<TF;
    }

    double ans,v,s,t;

    for(int i = 0; i < 3903; i++)
     {
        ans = 0;
        v = 0;
        s = 0; t = 0;
        for(int j = 0; j < 1000; j++)
        {
            v += trainVSM[i][j] * vsm[j];
            s += trainVSM[i][j] * trainVSM[i][j];
            t += vsm[j] * vsm[j];
        }
        ans = v/(sqrt(s)*sqrt(t));
        //qDebug()<<v<<s<<t;
        knn.push_back(std::make_pair(i,ans));
     }
     //qDebug()<<"here!";
     stable_sort(knn.begin(),knn.end(),cmp);
     memset(myKNN,0,sizeof(myKNN));


     for( int i = 0; i < 100; i++)
     {
         int w = knn[i].first;
         //qDebug()<<knn[i].second;

         if(w >= 0 && w < 471)
             myKNN[0]++;
         else if(w >= 471 && w < 963)
         {
             myKNN[1]++;
             //qDebug()<<"Computer";
         }
         else if(w >= 963 && w < 1479)
         {
             myKNN[2]++;
             //qDebug()<<"art";
         }
         else if(w >= 1479 && w < 1970)
             myKNN[3]++;
         else if(w >= 1970 && w < 2458)
             myKNN[4]++;
         else if(w >= 2458 && w < 2958)
             myKNN[5]++;
         else if(w >= 2958 && w < 3456)
             myKNN[6]++;
         else
             myKNN[7]++;
     }

     int flag = 0;
     int tmp = 0;
     for( int i = 0; i < 8; i++)
     {
         qDebug()<<myKNN[i]<<" ";
         if(myKNN[i] > tmp)
         {
             tmp = myKNN[i];
             flag = i;
         }
     }
     QString article[8] = {"space","computer","art","enviornment","agriculture","ecnomy","sports","history"};
     qDebug()<<"类别是："<<article[flag];
     knn.clear();
     emit textClassifyCompleted(article[flag]);

}
