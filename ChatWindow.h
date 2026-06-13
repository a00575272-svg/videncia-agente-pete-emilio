#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include "ChatController.h"
#include <string>
#include "PersistenceManager.h"

class ChatWindow : public QMainWindow, public ChatController{
    Q_OBJECT
//private:
    //std::string modelsAvailable[] = {string("gemma3:4b")};

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow() override;

private slots:
    void sendPrompt();

private:
    QLabel      *titleLabel;
    QLabel      *promptLabel;
    QLabel      *modelLabel;
    QLabel      *answerLabel;
    QPushButton *sendPromptButton;
    QComboBox   *modelCombobox;
    QLineEdit   *prompLineEdit;
    QTextEdit   *modelAnswer;
PersistenceManager *persistence;
    
};
