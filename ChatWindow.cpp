#include <QVBoxLayout>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QMenu>
#include <QMenuBar>
#include <QDebug>

#include "ChatWindow.h"

// prueba de la clase OllamaProvider

ChatWindow::ChatWindow(QWidget *parent):
    QMainWindow(parent),
    ChatController(),
    titleLabel(new QLabel("Chat con Ollama", this)),
    promptLabel(new QLabel("Promp:", this)),
    modelLabel(new QLabel("Modelo:", this)),
    answerLabel(new QLabel("Respuesta:", this)),
    sendPromptButton(new QPushButton("→", this)),
    modelCombobox(new QComboBox(this)),
    prompLineEdit(new QLineEdit(this)),
    modelAnswer(new QTextEdit(this))
{
    // Config the window
    setWindowTitle("ChatWindow");
    resize(720, 480);

    // 2) Barra de menú con acción "Salir"
    QMenu *fileMenu = menuBar()->addMenu("&Archivo");
    QAction *exitAction = fileMenu->addAction("Salir");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // 3) Barra de estado
    //statusBar()->showMessage("Listo. Verifica que Ollama esté activo en http://127.0.0.1:11434");

    // 4) Barra de herramientas que reutiliza la acción "Salir"
    //QToolBar *toolbar = addToolBar("Principal");
    //toolbar->addAction(exitAction);

    // 5) Conectar acciones de envío
    connect(sendPromptButton, &QPushButton::clicked, this, &ChatWindow::sendPrompt);
    connect(prompLineEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendPrompt);

    // 6) Crear un widget central con layout
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(titleLabel);

    // Selector mínimo de modelo
    QHBoxLayout *modelBox = new QHBoxLayout;
    modelBox->addWidget(modelLabel);
    modelCombobox->addItem("gemma3:4b");
    modelBox->addWidget(modelCombobox);

    vbox->addLayout(modelBox);

    // Entrada de prompt + botón
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(promptLabel);
    prompLineEdit->setPlaceholderText("Escribe un comando para la IA...");
    hbox->addWidget(prompLineEdit);
    hbox->addWidget(sendPromptButton);
    vbox->addLayout(hbox);

    // Área de conversación
    vbox->addWidget(answerLabel);
    modelAnswer->setReadOnly(true);
    modelAnswer->append("Sistema:\nEscribe un prompt y presiona \"Enter\" o el botón.\n");
    vbox->addWidget(modelAnswer);

    central->setLayout(vbox);

   persistence.initialize();

UserProfile profile;

profile.setUserName("Usuario");
profile.setPreferredModel("gemma3:4b");

persistence.saveUserProfile(profile);
    persistence = new PersistenceManager();

persistence->initialize();

UserProfile profile;

profile.setUserName("Usuario");
profile.setPreferredModel("gemma3:4b");

persistence->saveUserProfile(profile);

}

ChatWindow::~ChatWindow()
{
    delete persistence;
}


void ChatWindow::sendPrompt()
{
    QString inputUser =
            prompLineEdit->text().trimmed();

    if (inputUser.isEmpty())
    {
        QMessageBox::warning(
                    this,
                    "Error",
                    "Tu prompt no puede estar vacio");

        prompLineEdit->setFocus();
        return;
    }

    QString originalPrompt =
            inputUser;

    QString response =
            processPrompt(originalPrompt);

    modelAnswer->append(
                "Usuario:\n" +
                originalPrompt + "\n");

    modelAnswer->append(
                "AgentePETE:\n" +
                response + "\n");

    persistence.saveConversation(
                originalPrompt,
                response);

    prompLineEdit->clear();
}
